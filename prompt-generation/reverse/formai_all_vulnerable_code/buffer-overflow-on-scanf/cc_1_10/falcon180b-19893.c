//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 100

struct node{
int data;
struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int data){
struct node* new_node = (struct node*)malloc(sizeof(struct node));

if(new_node == NULL){
printf("Queue is Full\n");
return;
}

new_node->data = data;
new_node->next = NULL;

if(front == NULL){
front = new_node;
rear = front;
}
else{
rear->next = new_node;
rear = new_node;
}
}

void dequeue(){
struct node* temp = front;

if(front == NULL){
printf("Queue is Empty\n");
return;
}

if(front == rear){
front = NULL;
rear = NULL;
}
else{
front = front->next;
}
free(temp);
}

void display(){
struct node* temp = front;

if(front == NULL){
printf("Queue is Empty\n");
return;
}

printf("Queue elements are: ");

while(temp!= NULL){
printf("%d ",temp->data);
temp = temp->next;
}
}

int main(){
int choice,data;

do{
printf("Enter 1 to enqueue\n");
printf("Enter 2 to dequeue\n");
printf("Enter 3 to display\n");
printf("Enter 4 to exit\n");
scanf("%d",&choice);

switch(choice){
case 1:
printf("Enter element to be enqueued: ");
scanf("%d",&data);
enqueue(data);
break;
case 2:
dequeue();
break;
case 3:
display();
break;
case 4:
exit(0);
default:
printf("Invalid choice\n");
}
}while(true);

return 0;
}