//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node{
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;
int count = 0;

void enqueue(int value){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    if(front == NULL && rear == NULL){
        front = newNode;
        rear = newNode;
    }
    else if(rear == NULL){
        rear = newNode;
        rear->next = front;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }

    printf("Element %d enqueued to the queue\n", value);
    count++;
}

void dequeue(){
    if(front == NULL && rear == NULL){
        printf("Queue is empty\n");
    }
    else if(front == rear){
        struct node* temp = front;
        front = NULL;
        rear = NULL;
        free(temp);
        printf("Element %d dequeued from the queue\n", temp->data);
        count--;
    }
    else{
        struct node* temp = front;
        front = front->next;
        free(temp);
        printf("Element %d dequeued from the queue\n", temp->data);
        count--;
    }
}

void display(){
    if(front == NULL && rear == NULL){
        printf("Queue is empty\n");
    }
    else{
        struct node* temp = front;
        printf("Queue: ");
        while(temp!= NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    int choice, value;

    while(1){
        printf("Enter your choice:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the value to be enqueued: ");
                scanf("%d", &value);
                enqueue(value);
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