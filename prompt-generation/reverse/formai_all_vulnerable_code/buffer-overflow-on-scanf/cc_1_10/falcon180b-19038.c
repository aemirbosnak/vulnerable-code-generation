//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node{
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int value){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL){
        printf("Memory Error\n");
        exit(0);
    }

    newNode->data = value;
    newNode->next = NULL;

    if(front == NULL && rear == NULL){
        front = newNode;
        rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d has been enqueued\n",value);
}

int dequeue(){
    int value = -1;

    if(front == NULL){
        printf("Queue is Empty\n");
    }
    else if(front == rear){
        value = front->data;
        free(front);
        front = NULL;
        rear = NULL;
    }
    else{
        value = front->data;
        front = front->next;
        free(rear);
        rear = front;
    }

    return value;
}

void display(){
    struct node* temp = front;

    if(front == NULL){
        printf("Queue is Empty\n");
    }
    else{
        printf("Elements in the Queue are: ");
        while(temp!= NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
}

int main(){
    int choice, value;

    do{
        printf("\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter the value to be enqueued: ");
                scanf("%d",&value);
                enqueue(value);
                break;

            case 2:
                value = dequeue();
                if(value!= -1){
                    printf("The dequeued value is: %d\n",value);
                }
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid Choice\n");
        }
    }while(choice!= 4);

    return 0;
}