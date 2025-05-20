//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

//Node structure definition
struct node{
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

//Function to create an empty queue
void create(){
    front = rear = NULL;
    printf("\nQueue created successfully!!");
}

//Function to check if the queue is empty
int isEmpty(){
    if(front == NULL && rear == NULL)
        return 1;
    else
        return 0;
}

//Function to check if the queue is full
int isFull(){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL)
        return 1;
    else{
        free(temp);
        return 0;
    }
}

//Function to add an element to the queue
void enqueue(int value){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if(isEmpty()){
        front = rear = newnode;
    }
    else{
        rear->next = newnode;
        rear = newnode;
    }
    printf("\n%d enqueued to the queue!!",value);
}

//Function to remove an element from the queue
void dequeue(){
    if(front == NULL)
        printf("\nQueue is empty!!");
    else{
        struct node *temp = front;
        front = front->next;
        printf("\n%d dequeued from the queue!!",temp->data);
        free(temp);
    }
}

//Function to display the elements in the queue
void display(){
    if(front == NULL)
        printf("\nQueue is empty!!");
    else{
        struct node *temp = front;
        while(temp!= NULL){
            printf("\n%d",temp->data);
            temp = temp->next;
        }
    }
}

int main(){
    int choice;
    do{
        printf("\n\n\t\tMENU");
        printf("\n1.Create");
        printf("\n2.Enqueue");
        printf("\n3.Dequeue");
        printf("\n4.Display");
        printf("\n5.Exit");
        printf("\n\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                create();
                break;
            case 2:
                printf("\nEnter the value to be enqueued:");
                int value;
                scanf("%d",&value);
                enqueue(value);
                break;
            case 3:
                dequeue();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("\nExiting....");
                break;
            default:
                printf("\nInvalid choice!!");
        }
    }while(choice!=5);
    return 0;
}