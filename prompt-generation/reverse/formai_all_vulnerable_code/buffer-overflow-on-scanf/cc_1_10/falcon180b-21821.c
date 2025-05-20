//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct node{
    int data;
    struct node* next;
}node;

node* front = NULL;
node* rear = NULL;

void enqueue(int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    if(front == NULL && rear == NULL){
        front = newNode;
        rear = newNode;
    }else{
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue(){
    node* temp = front;
    if(front == NULL && rear == NULL){
        printf("Queue Underflow\n");
        exit(0);
    }else if(front == rear){
        front = NULL;
        rear = NULL;
    }else{
        front = front->next;
    }
    free(temp);
}

void display(){
    node* temp = front;
    if(front == NULL && rear == NULL){
        printf("Queue is empty\n");
    }else{
        printf("Queue elements are: ");
        while(temp!= NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    int choice, data;
    while(1){
        printf("Enter your choice:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the data to be enqueued: ");
                scanf("%d", &data);
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
    }
    return 0;
}