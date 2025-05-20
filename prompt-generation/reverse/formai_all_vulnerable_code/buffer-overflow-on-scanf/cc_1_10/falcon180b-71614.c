//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: shocked
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct node{
    int data;
    struct node* next;
}node;

node* front=NULL;
node* rear=NULL;

void enqueue(int value){
    node* new_node=(node*)malloc(sizeof(node));
    new_node->data=value;
    new_node->next=NULL;

    if(front==NULL){
        front=rear=new_node;
    }
    else{
        rear->next=new_node;
        rear=new_node;
    }
}

void dequeue(){
    if(front==NULL){
        printf("\nQueue is empty");
        return;
    }
    else if(front==rear){
        printf("\nDeleted element is %d",front->data);
        front=rear=NULL;
    }
    else{
        printf("\nDeleted element is %d",front->data);
        front=front->next;
    }
}

void display(){
    if(front==NULL){
        printf("\nQueue is empty");
        return;
    }
    node* temp=front;
    printf("\nElements in the queue are: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main(){
    int choice,value;

    do{
        printf("\n\nMENU");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("\nEnter the value to be inserted: ");
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
                printf("\nExiting...");
                break;

            default:
                printf("\nInvalid choice! Please try again");
        }

    }while(choice!=4);

    return 0;
}