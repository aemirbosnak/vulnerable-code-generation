//FormAI DATASET v1.0 Category: Queue Implementation ; Style: statistical
#include <stdio.h> // Header file for standard input and output
#include <stdlib.h> // Header file for standard library
#define SIZE 5 // Define the constant size of the queue

int queue[SIZE], front = -1, rear = -1; // Declare and initialize the queue and its pointers

// Function to insert an element into the queue
void enqueue(int value) {
    if(rear == SIZE - 1) { // Check if the queue is full
        printf("\nQueue is full\n"); // Display message
    } else {
        if(front == -1) { // Check if the queue is empty
            front = 0; // Set the front pointer
        }
        rear++; // Increment the rear pointer
        queue[rear] = value; // Insert the element into the queue
    }
}

// Function to delete an element from the queue
void dequeue() {
    if(front == -1) { // Check if the queue is empty
        printf("\nQueue is empty\n"); // Display message
    } else {
        printf("\nDeleted element: %d\n", queue[front]); // Display the deleted element
        front++; // Increment the front pointer
        if(front > rear) { // Check if all elements have been deleted
            front = rear = -1; // Reset the pointers
        }
    }
}

// Function to display the elements of the queue
void display() {
    if(rear == -1) { // Check if the queue is empty
        printf("\nQueue is empty\n"); // Display message
    } else {
        printf("\nQueue elements: "); // Display message
        for(int i = front; i <= rear; i++) { // Loop through the queue
            printf("%d ", queue[i]); // Display each element
        }
        printf("\n"); // Add a new line
    }
}

// Main function
int main() {
    int choice, value; // Declare variables for user input
    while(1) { // Loop infinitely
        printf("\n--Queue Operations--\n"); // Display the options
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: "); // Ask for user input
        scanf("%d", &choice); // Read the user input
        switch(choice) { // Use a switch statement to perform the selected operation
            case 1: // If user chooses to enqueue
                printf("Enter the value to be inserted: "); // Ask for user input
                scanf("%d", &value); // Read the user input
                enqueue(value); // Call the enqueue function
                break; // Break out of the switch statement
            case 2: // If user chooses to dequeue
                dequeue(); // Call the dequeue function
                break; // Break out of the switch statement
            case 3: // If user chooses to display the queue
                display(); // Call the display function
                break; // Break out of the switch statement
            case 4: // If user chooses to exit the program
                exit(0); // Exit the program with a status code of 0
            default: // If user enters an invalid choice
                printf("\nInvalid choice\n"); // Display message
        }
    }
    return 0; // End the program
}