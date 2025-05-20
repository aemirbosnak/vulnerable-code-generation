//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

typedef struct Customer {
    char name[MAX_NAME_LENGTH];
} Customer;

typedef struct Queue {
    Customer *customers;
    int front;
    int rear;
    int capacity;
} Queue;

// Function prototypes
Queue* createQueue(int capacity);
void destroyQueue(Queue *queue);
int isFull(Queue *queue);
int isEmpty(Queue *queue);
void enqueue(Queue *queue, const char *name);
Customer dequeue(Queue *queue);
void displayQueue(Queue *queue);

int main() {
    int capacity;
    printf("Enter the maximum number of customers in the queue: ");
    scanf("%d", &capacity);
    
    // Create a queue
    Queue *queue = createQueue(capacity);
    if (!queue) {
        printf("Failed to create queue.\n");
        return EXIT_FAILURE;
    }

    int choice;
    char name[MAX_NAME_LENGTH];

    do {
        printf("\nCustomer Service Queue Menu:\n");
        printf("1. Add Customer\n");
        printf("2. Serve Customer\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter customer name: ");
                scanf("%s", name);
                enqueue(queue, name);
                break;
            case 2:
                if (!isEmpty(queue)) {
                    Customer served = dequeue(queue);
                    printf("Serving customer: %s\n", served.name);
                } else {
                    printf("The queue is empty.\n");
                }
                break;
            case 3:
                displayQueue(queue);
                break;
            case 4:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    // Clean up
    destroyQueue(queue);
    return 0;
}

// Function to create a queue of given capacity
Queue* createQueue(int capacity) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    queue->customers = (Customer *)malloc(capacity * sizeof(Customer));
    return queue;
}

// Function to free the allocated memory for the queue
void destroyQueue(Queue *queue) {
    if (queue) {
        free(queue->customers);
        free(queue);
    }
}

// Check if the queue is full
int isFull(Queue *queue) {
    return queue->rear == queue->capacity - 1;
}

// Check if the queue is empty
int isEmpty(Queue *queue) {
    return queue->front > queue->rear;
}

// Function to add a customer to the queue
void enqueue(Queue *queue, const char *name) {
    if (isFull(queue)) {
        printf("The queue is full. Cannot add more customers.\n");
        return;
    }
    queue->customers[++queue->rear] = (Customer) {0}; // Initialize to zero
    strncpy(queue->customers[queue->rear].name, name, MAX_NAME_LENGTH - 1);
    queue->customers[queue->rear].name[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null termination
    printf("Added customer: %s\n", name);
}

// Function to remove and return the first customer in the queue
Customer dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        Customer empty = {""};
        return empty;
    }
    return queue->customers[queue->front++];
}

// Function to display the current queue
void displayQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("The queue is currently empty.\n");
        return;
    }
    printf("Current queue:\n");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%s\n", queue->customers[i].name);
    }
}