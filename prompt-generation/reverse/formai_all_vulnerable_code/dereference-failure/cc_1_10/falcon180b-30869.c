//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: retro
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

struct node{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int value){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    if(front == NULL){
        front = newnode;
        rear = newnode;
    }
    else{
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue(){
    struct node *temp = front;
    if(front!= NULL){
        front = front->next;
        if(front == NULL){
            rear = NULL;
        }
    }
    free(temp);
}

void display(){
    struct node *temp = front;
    printf("\nQueue elements are: ");
    while(temp!= NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int main(){
    int choice,value;
    while(1){
        printf("\n\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nEnter the value to be enqueued: ");
                scanf("%d",&value);
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
                printf("\nInvalid choice!");
        }
    }
    return 0;
}