//FormAI DATASET v1.0 Category: Queue Implementation ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 5 // Maximum size of the Queue

int front = -1; // Front pointer - starts with -1 since the queue is empty at the beginning
int rear = -1; // Rear pointer - starts with -1 since the queue is empty at the beginning

int queue[MAX_SIZE]; // The Queue using an array with MAX_SIZE

// Function to check if the queue is full
int isFull(){
    if((front == 0 && rear == MAX_SIZE-1) || front == rear+1){
        return 1; // Returns true if the condition is true
    }else{
        return 0; // Returns false if the condition is false
    }
}

// Function to check if the queue is empty
int isEmpty(){
    if(front == -1){
        return 1; // Returns true if the condition is true
    }else{
        return 0; // Returns false if the condition is false
    }
}

// Function to insert a value into the queue
void enqueue(int val){
    if(isFull()){
        printf("Queue is Full\n"); // Prints an error message when the queue is full
    }else{
        if(front == -1){
            front = 0;
        }
        rear = (rear+1)%MAX_SIZE;
        queue[rear] = val;
        printf("%d inserted to the queue\n", val); // Prints the value that is inserted into the queue
    }
}

// Function to delete a value from the queue
void dequeue(){
    if(isEmpty()){
        printf("Queue is Empty\n"); // Prints an error message when the queue is empty
    }else{
        printf("%d removed from the queue\n", queue[front]); // Prints the value that is deleted from the queue
        if(front == rear){
            front = -1;
            rear = -1;
        }else{
            front = (front+1)%MAX_SIZE;
        }
    }
}

int main(){
    int choice, value;
    while(1){
        printf("1.Enqueue 2.Dequeue 3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                exit(0);
            default:
                printf("Wrong Choice\n"); // Prints an error message when an invalid choice is entered
        }
    }
    return 0;
}