//FormAI DATASET v1.0 Category: Queue Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5 // Maximum size of queue

int queue[MAXSIZE]; // Initializing an integer array for queue
int front = -1, rear = -1; // Initializing front and rear values as -1

void enqueue(int element) { // Function to insert element into the rear of queue
    if (rear == MAXSIZE - 1) { // Checking if the rear is already at its maximum position
        printf("\nQueue Overflow!\n"); // Displaying the respective error message
    } else {
        if (front == -1) { // If front is -1 that means the queue is initially empty
            front = 0; // Assigning front as 0 for easy insertion
        }
        rear++; // Incrementing rear as it's not at its maximum position
        queue[rear] = element; // Storing the element at the new rear position
        printf("\n%d has been enqueued into the queue.\n", element); // Displaying the successful insertion message
    }
}

void dequeue() { // Function to delete an element from the front of queue
    if (front == -1) { // Checking if front is already -1
        printf("\nQueue Underflow!\n"); // Displaying the respective error message
    } else {
        printf("\n%d has been dequeued from the queue.\n", queue[front]); // Displaying the element that has been dequeued
        front++; // Incrementing front as it's not at its maximum position
        if (front > rear) { // Checking if front is greater than rear
            front = rear = -1; // Assigning front and rear as -1 for easy deletion
        }
    }
}

void display() { // Function to display all the elements of queue
    if (rear == -1) { // Checking if rear is already -1
        printf("\nThe Queue is Empty!\n"); // Displaying the respective error message
    } else {
        printf("\nThe elements of Queue are: ");
        for (int i = front; i <= rear; i++) { // Loop to display all the elements of queue
            printf("%d  ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    printf("-----------Welcome to C Queue Implementation Program!-----------\n\n");
    int option;
    while (1) { // Loop to display menu again and again
        printf("Select an option from below menu to perform desired operation:\n\n1. Enqueue an element into Queue.\n2. Dequeue an element from Queue.\n3. Display all the elements of Queue.\n4. Exit the program.\n\nOption: ");
        scanf("%d", &option); // Taking user input for desired option
        switch (option) { // Switch case for the provided options
            case 1: {
                int element;
                printf("\nEnter an element you want to enqueue into the Queue: ");
                scanf("%d", &element); // Taking user input for the desired element
                enqueue(element); // Calling Enqueue function to insert the element into queue
                break;
            }
            case 2: {
                dequeue(); // Calling Dequeue function to delete an element from queue
                break;
            }
            case 3: {
                display(); // Calling Display function to print all the elements of queue
                break;
            }
            case 4: {
                printf("\nThank you for using the Program. Bye Bye!!\n\n"); // Displaying the exit message
                exit(0); // Exiting from the program
            }
            default: printf("\nInvalid Option! Please select a valid option from the menu.\n"); // Displaying the invalid option message
        }
    }
    return 0;
}