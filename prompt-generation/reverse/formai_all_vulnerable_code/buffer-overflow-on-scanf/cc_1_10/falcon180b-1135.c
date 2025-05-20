//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct node{
    int data;
    struct node *next;
}node;

node *front = NULL, *rear = NULL;

void enqueue(int data){
    node *temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    if(rear == NULL){
        front = temp;
        rear = temp;
    }
    else{
        rear->next = temp;
        rear = temp;
    }
    printf("%d enqueued to the queue\n", data);
}

void dequeue(){
    node *temp = front;
    if(front == NULL){
        printf("Queue is empty\n");
    }
    else{
        printf("%d dequeued from the queue\n", front->data);
        front = front->next;
        if(front == NULL){
            rear = NULL;
        }
    }
}

void display(){
    node *temp = front;
    printf("Queue elements are: ");
    if(front == NULL){
        printf("Empty\n");
    }
    else{
        while(temp!= NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    int choice, data;
    do{
        printf("Enter your choice:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(choice!= 4);
    return 0;
}