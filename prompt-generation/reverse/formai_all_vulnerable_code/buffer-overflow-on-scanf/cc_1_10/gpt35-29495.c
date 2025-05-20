//FormAI DATASET v1.0 Category: Queue Implementation ; Style: cheerful
// Welcome to my Happy Queue Implementation Program!
// This program will help you learn how to implement a Queue using C programming language
// And we're gonna have some FUN!
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5 // Change this value to modify the size of the queue 

// Global variables for the queue
int front = -1; // Points to the front of the queue
int rear = -1; // Points to the rear of the queue
int queue[MAX_SIZE]; // Array to hold the elements in the queue

// Function to check if the queue is full
int isFull() {
    if(rear == MAX_SIZE - 1) {
        return 1;
    }
    else {
        return 0;
    }
}

// Function to check if the queue is empty
int isEmpty() {
    if(front == -1 || front > rear) {
        return 1;
    }
    else {
        return 0;
    }
}

// Function to add an element to the queue
void enqueue(int value) {
    if(isFull()) {
        printf("Sorry, the queue is full!\n"); // Oops, we ran out of room!
    }
    else {
        if(front == -1) {
            front = 0;
        }
        rear++; // Move the rear pointer to the next element
        queue[rear] = value; // Add the new element to the queue
        printf("%d has been added to the queue!\n", value); // Let's celebrate!
    }
}

// Function to remove an element from the queue
void dequeue() {
    if(isEmpty()) {
        printf("Sorry, the queue is empty!\n"); // Oops, nothing to remove!
    }
    else {
        int removed = queue[front]; // Store the value that's going to be removed
        front++; // Move the front pointer to the next element
        printf("%d has been removed from the queue!\n", removed); // Let's celebrate!
    }
}

// Function to display the contents of the queue
void display() {
    if(isEmpty()) {
        printf("Sorry, the queue is empty!\n"); // Oops, nothing to display!
    }
    else {
        printf("The current contents of the queue are: ");
        for(int i=front;i<=rear;i++) {
            printf("%d ",queue[i]); // Let's show off the elements in the queue!
        }
        printf("\n"); // Let's add some space so it looks pretty!
    }
}

int main() {
    printf("Welcome to my HAPPY Queue Implementation Program!\n");
    printf("In this program, we will implement a Queue using C programming language\n");

    while(1) { // Let's infinitely loop the menu until the user decides to exit
        int choice;
        printf("\nWhat would you like to do?\n");
        printf("1. Add element to the queue\n");
        printf("2. Remove element from the queue\n");
        printf("3. Display current contents of the queue\n");
        printf("4. Exit\n");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                printf("Please enter the value you would like to add to the queue:\n");
                int addVal;
                scanf("%d",&addVal);
                enqueue(addVal);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nThanks for playing with my HAPPY Queue Implementation Program!\n");
                printf("Have a wonderful day!\n\nBye!\n");
                exit(0); // Let's gracefully exit the program
            default:
                printf("Oops! That was an invalid choice!\n"); // Oops, wrong choice!
        }
    }

    return 0;
}