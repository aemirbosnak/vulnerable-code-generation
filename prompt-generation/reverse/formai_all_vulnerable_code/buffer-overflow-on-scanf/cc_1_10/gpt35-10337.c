//FormAI DATASET v1.0 Category: Queue Implementation ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 10  // Maximum size to which the queue can be incremented.

int front=-1;
int rear=-1;
int queue[MAX_QUEUE_SIZE];  // Queue to store the elements.

// Function to check if the queue is empty.
int is_empty(){
    if (front==-1 || front>rear)
        return 1;
    else
        return 0;
}

// Function to check if the queue is full.
int is_full(){
    if(rear==MAX_QUEUE_SIZE-1)
        return 1;
    else
        return 0;
}
// Function to add an element to the queue.
void enqueue(int value){
    if(is_full()){
        printf("Queue is full!");
    }
    else{
        if(front==-1){
            front=0;
        }
        rear++;
        queue[rear]=value;
        printf("\nElement %d is enqueued",value);
    }
}

// Function to remove an element from the queue.
void dequeue(){
    int temp;
    if(is_empty()){
        printf("Queue is empty!");
    }
    else{
        temp=queue[front];
        printf("\nElement %d dequeued",temp);
        front++;
        if(front>rear){
            front=rear=-1;
        }
    }
}

// Function to display the elements in the queue.
void display(){
    int i;
    if(is_empty()){
        printf("Queue is empty!");
    }
    else{
        printf("\nElements in the queue are: ");
        for(i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
    }
}

int main(){
    int ch,val;
    while(1){   // Menu-driven program.
        printf("\n1.Enqueue");
        printf("\n2.Dequeue");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("\nEnter the element to be enqueued: ");
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
                printf("\nInvalid choice!");
        }
    }
    return 0;
}