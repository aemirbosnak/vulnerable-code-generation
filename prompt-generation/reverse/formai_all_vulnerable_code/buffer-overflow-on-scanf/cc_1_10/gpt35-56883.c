//FormAI DATASET v1.0 Category: Queue Implementation ; Style: ultraprecise
#include <stdio.h>  // Standard Input/Output header file
#include <stdlib.h> // Standard library header file

#define MAX_SIZE 5 // Maximum size of the queue

// Queue structure
struct Queue {
    int items[MAX_SIZE]; // Array to store queue elements
    int front;           // Index to front element
    int rear;            // Index to rear element
    int size;            // Variable to keep track of number of elements in queue
};

// Function to create a new queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue)); // Allocate memory for queue
    queue->front = -1; // Initialize front and rear as -1
    queue->rear = -1;
    queue->size = 0; // Initialize size as 0
    return queue; // Return the newly created queue
}

// Function to check whether queue is empty or not
int isEmpty(struct Queue* queue) {
    if (queue->size == 0) { // If size is 0, queue is empty
        return 1;
    }
    return 0;
}

// Function to check whether queue is full or not
int isFull(struct Queue* queue) {
    if (queue->size == MAX_SIZE) { // If size is equal to MAX_SIZE, queue is full
        return 1;
    }
    return 0;
}

// Function to add an element to the queue
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) { // If queue is full, display error message
        printf("Queue is full.\n");
    } else {
        if (queue->front == -1) { // If queue is empty, initialize front and rear to 0
            queue->front = 0;
        }
        queue->rear++; // Increment rear index
        queue->items[queue->rear] = item; // Add item to queue
        queue->size++; // Increment size of queue
        printf("Element %d has been added to the queue.\n", item);
    }
}

// Function to remove an element from the queue
int dequeue(struct Queue* queue) {
    int item;
    if (isEmpty(queue)) { // If queue is empty, display error message
        printf("Queue is empty.\n");
        item = -1;
    } else {
        item = queue->items[queue->front]; // Get front item
        queue->front++; // Increment front index
        queue->size--; // Decrement size of queue
        printf("Element %d has been removed from the queue.\n", item);
    }
    return item;
}

// Function to display the queue
void display(struct Queue* queue) {
    int i;
    if (isEmpty(queue)) { // If queue is empty, display error message
        printf("Queue is empty.\n");
    } else {
        printf("Current queue elements: ");
        for (i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->items[i]); // Display elements from front to rear index
        }
        printf("\n");
    }
}

int main() {
    struct Queue* queue = createQueue(); // Create a new queue
    int choice, element;

    do {
        printf("\nQueue Operations\n");
        printf("1. Enqueue an element\n");
        printf("2. Dequeue an element\n");
        printf("3. Display the queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &element);
                enqueue(queue, element);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice != 4);

    return 0;
}