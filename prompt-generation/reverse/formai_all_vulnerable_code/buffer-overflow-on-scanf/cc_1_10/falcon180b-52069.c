//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 100

typedef struct node{
    int data;
    struct node *next;
}node;

node *front=NULL,*rear=NULL;

void enqueue(int val){
    node *newnode=malloc(sizeof(node));
    if(newnode==NULL){
        printf("\nQueue Overflow");
        exit(0);
    }
    newnode->data=val;
    newnode->next=NULL;
    if(front==NULL){
        front=rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=rear->next;
    }
    printf("\n%d enqueued to queue",val);
}

void dequeue(){
    if(front==NULL){
        printf("\nQueue Underflow");
        exit(0);
    }
    printf("\n%d dequeued from queue",front->data);
    node *temp=front;
    front=front->next;
    free(temp);
    if(front==NULL){
        rear=NULL;
    }
}

void display(){
    node *temp=front;
    if(front==NULL){
        printf("\nQueue is Empty");
    }
    else{
        printf("\nElements in the Queue are: ");
        while(temp!=NULL){
            printf(" %d ",temp->data);
            temp=temp->next;
        }
    }
}

int main(){
    int choice,val;
    while(true){
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nEnter the value to be enqueued:");
                scanf("%d",&val);
                enqueue(val);
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
                printf("\nInvalid Choice");
        }
    }
    return 0;
}