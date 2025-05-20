//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: scientific
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* front=NULL;
struct node* rear=NULL;
int count=0;

void enqueue(int data){
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=NULL;
    if(front==NULL){
        front=rear=new_node;
    }
    else{
        rear->next=new_node;
        rear=new_node;
    }
    count++;
}

void dequeue(){
    struct node* temp=front;
    if(front!=NULL){
        front=front->next;
        free(temp);
        count--;
    }
    else{
        printf("\nQueue is empty");
    }
}

void display(){
    struct node* temp=front;
    if(front==NULL){
        printf("\nQueue is empty");
    }
    else{
        printf("\nElements in the queue are: ");
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}

void main(){
    int choice,data;
    while(1){
        printf("\nEnter 1 for enqueue, 2 for dequeue, 3 for display and 4 for exit: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                printf("\nEnter the data to be enqueued: ");
                scanf("%d",&data);
                enqueue(data);
                break;
            }
            case 2:{
                dequeue();
                break;
            }
            case 3:{
                display();
                break;
            }
            case 4:{
                exit(0);
            }
            default:{
                printf("\nInvalid choice");
            }
        }
    }
}