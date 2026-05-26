#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node* next;
};
struct Node* head = NULL;
void create(int n) {
struct Node *newNode, *temp;
int data, i;
for(i = 1; i <= n; i++) {
newNode = (struct Node*)malloc(sizeof(struct Node));
printf("Enter data %d: ", i);
scanf("%d", &data);
newNode->data = data;
newNode->next = NULL;
if(head == NULL) {
head = newNode;
temp = head;
} else {
temp->next = newNode;
temp = newNode;
}
}
temp->next = head;
}
void display() {
struct Node* temp;
if(head == NULL) {
printf("List is empty\n");
return;
}
temp = head;
printf("Circular Linked List: ");
do {
printf("%d -> ", temp->data);
temp = temp->next;
} while(temp != head);
printf("(Back to Head)\n");
}
void insertBeginning(int value) {
struct Node *newNode, *temp;
newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = value;
if(head == NULL) {
head = newNode;
newNode->next = head;
} else {
temp = head;
while(temp->next != head) {
temp = temp->next;
}
newNode->next = head;
temp->next = newNode;
head = newNode;
}
}
void deleteBeginning() {
struct Node *temp, *last;
if(head == NULL) {
printf("List is empty\n");
return;
}
if(head->next == head) {
free(head);
head = NULL;
} else {
temp = head;
last = head;
while(last->next != head) {
last = last->next;
}
head = head->next;
last->next = head;
free(temp);
}
}
int main() {
int n, value;
printf("Enter number of nodes: ");
scanf("%d", &n);
create(n);
display();
printf("Enter value to insert at beginning: ");
scanf("%d", &value);
insertBeginning(value);
display();
deleteBeginning();
printf("After deletion:\n");
display();
return 0;
}
