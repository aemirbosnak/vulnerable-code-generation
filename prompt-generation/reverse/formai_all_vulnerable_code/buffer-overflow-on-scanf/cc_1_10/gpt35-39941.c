//FormAI DATASET v1.0 Category: Queue Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#define MAX 5 // Maximum size of the Queue

int front = -1, rear = -1; // Initializing front and rear as -1

// Function to check if Queue is full
int isFull(int* queue){
    if((front == 0 && rear == MAX-1) || front == rear + 1){
        return 1;
    }
    else{
        return 0;
    }
}

// Function to check if Queue is empty
int isEmpty(){
    if(front == -1){
        return 1;
    }
    else{
        return 0;
    }
}

// Function to add elements in the Queue
void enqueue(int* queue, int value){
    if(isFull(queue)){
        printf("Queue is full. Cannot add element\n");
    }
    else{
        if(front == -1){
            front = 0;
        }
        rear = (rear+1)%MAX;
        queue[rear] = value;
        printf("Element %d added to the Queue.\n", value);
    }
}

// Function to remove elements from the Queue
int dequeue(int* queue){
    if(isEmpty()){
        printf("Queue is empty. Cannot remove element.\n");
        return -1;
    }
    else{
        int value = queue[front];
        if(front == rear){
            front = -1;
            rear = -1;
        }
        else{
            front = (front+1)%MAX;
        }
        return value;
    }
}

// Function to display the elements of the Queue
void display(int* queue){
    if(isEmpty()){
        printf("Queue is empty. No elements to display.\n");
    }
    else{
        int i;
        printf("Elements of the Queue are: ");
        for(i=front; i!=rear; i=(i+1)%MAX){
            printf("%d ", queue[i]);
        }
        printf("%d\n", queue[i]);
    }
}

int main(){
    int queue[MAX];
    int choice, value;
    while(1){
        printf("\n-------------------\n");
        printf("Queue Implementation\n");
        printf("-------------------\n");
        printf("1. Add element to Queue\n");
        printf("2. Remove element from Queue\n");
        printf("3. Display the Queue\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the element to be added to the Queue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 2:
                value = dequeue(queue);
                if(value != -1){
                    printf("Element %d removed from the Queue.\n", value);
                }
                break;
            case 3:
                display(queue);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please choose a valid option.\n");
        }
    }
    return 0;
}