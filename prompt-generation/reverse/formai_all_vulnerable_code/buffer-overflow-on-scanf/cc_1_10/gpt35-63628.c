//FormAI DATASET v1.0 Category: Queue ; Style: complex
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 5    // Maximum size of queue

int front=-1,rear=-1,queue[MAX_SIZE];   // Initializing Queue


// Function to check if queue is empty
int isEmpty(){
    if(front==-1 && rear==-1)
        return 1;
    else
        return 0;
}

// Function to insert elements in queue
void enqueue(int element){
    if((rear+1)%MAX_SIZE==front){   // Check if queue is full
        printf("Error: Queue is full\n");
        return;
    }
    else if(isEmpty()){   // Check if queue is empty
        front=rear=0;
        queue[rear]=element;
    }
    else{
        rear=(rear+1)%MAX_SIZE;
        queue[rear]=element;
    }
}

// Function to delete elements from queue
void dequeue(){
    if(isEmpty()){   // Check if queue is empty
        printf("Error: Queue is empty\n");
        return;
    }
    else if(front==rear){   // Check if only one element is present in queue
        front=rear=-1;
    }
    else{
        front=(front+1)%MAX_SIZE;
    }
}

// Function to get front element of queue
int frontElem(){
    if(isEmpty()){   // Check if queue is empty
        printf("Error: Queue is empty\n");
        return -1;
    }
    else{
        return queue[front];
    }
}

// Function to display queue
void display(){
    int i;
    if(isEmpty()){   // Check if queue is empty
        printf("Error: Queue is empty\n");
        return;
    }
    else{
        printf("Queue is: ");
        for(i=front;i!=rear;i=(i+1)%MAX_SIZE){
            printf("%d ",queue[i]);
        }
        printf("%d",queue[i]);
        printf("\n");
    }
}


int main(){
    int choice,element;
    do{
        printf("Select operation:\n");
        printf("1.Enqueue\n2.Dequeue\n3.Get front element\n4.Display queue\n5.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter element to insert: ");
                scanf("%d",&element);
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printf("Front element is: %d\n",frontElem());
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(choice!=5);
    return 0;
}