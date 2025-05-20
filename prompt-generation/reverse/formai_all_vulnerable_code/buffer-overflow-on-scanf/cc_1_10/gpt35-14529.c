//FormAI DATASET v1.0 Category: Queue Implementation ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int front=-1, rear=-1; 
int queue[MAX];

// Function to check if the queue is full
int isFull() {
    if((front == rear+1) || (front == 0 && rear == MAX-1))
        return 1;
    else
        return 0;
}

// Function to check if the queue is empty
int isEmpty() {
    if(front == -1)
        return 1;
    else
        return 0;
}

// Function to add an element to the queue
void enqueue(int element) {
    if(isFull()){
        printf("Queue overflow\n");
    } else {
        if(front == -1)
            front = 0;
        rear = (rear+1) % MAX;
        queue[rear] = element;
        printf("Element %d has been added to the queue\n",element);
    }
}

// Function to remove an element from the queue
int dequeue() {
    int element;
    if(isEmpty()) {
        printf("Queue underflow\n");
        return(-1);
    } else {
        element = queue[front];
        if(front == rear) {
            front = rear = -1;
        } else {
            front = (front+1) % MAX;
        }
        printf("Element %d has been removed from the queue\n",element);
        return(element);
    }
}

// Function to display the queue
void display() {
    int i;
    if(isEmpty())
        printf("Queue is empty\n");
    else {
        printf("The queue is:\n");
        for(i=front;i!=rear;i=(i+1)%MAX)
            printf("%d ",queue[i]);
        printf("%d",queue[i]);
    }
}

// Main function to control the program
int main() {
    int choice, element;
    do {
        printf("\n\n ***Futuristic Queue Implementation*** \n\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d",&element);
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program....\n");
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice!=4);
    return 0;
}