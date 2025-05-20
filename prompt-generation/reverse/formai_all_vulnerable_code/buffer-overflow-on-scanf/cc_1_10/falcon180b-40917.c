//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct node{
    int data;
    struct node *next;
}node;

node *front = NULL, *rear = NULL;

void enqueue(int data){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;

    if(front == NULL && rear == NULL){
        front = newnode;
        rear = newnode;
    }
    else{
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue(){
    if(front == NULL){
        printf("\nQueue is empty!");
    }
    else{
        node *temp = front;
        printf("\nDeleted element is %d", temp->data);
        front = front->next;
        free(temp);
    }
}

void display(){
    if(front == NULL){
        printf("\nQueue is empty!");
    }
    else{
        node *temp = front;
        printf("\nQueue elements are: ");
        while(temp!= NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

void main(){
    int choice, data;

    while(1){
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter the element to be added: ");
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
                printf("\nInvalid choice!");
        }
    }
}