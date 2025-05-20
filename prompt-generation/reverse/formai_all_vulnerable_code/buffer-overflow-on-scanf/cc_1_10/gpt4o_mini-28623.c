//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a queue node
struct Node {
    int data;
    struct Node* next;
};

// Define the structure for the queue
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to create a new queue node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to add an item to the queue
void enqueue(struct Queue* queue, int data) {
    struct Node* temp = newNode(data);

    if (queue->rear == NULL) {
        queue->front = queue->rear = temp;
        printf("Enqueued: %d\n", data);
        return;
    }
    
    queue->rear->next = temp;
    queue->rear = temp;
    printf("Enqueued: %d\n", data);
}

// Function to remove an item from the queue
int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1; // Indicate queue is empty
    }

    struct Node* temp = queue->front;
    int data = temp->data;
    
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    printf("Dequeued: %d\n", data);
    return data;
}

// Function to display the contents of the queue
void displayQueue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    struct Node* temp = queue->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to demonstrate the queue operations
int main() {
    struct Queue* queue = createQueue();

    int choice, value;

    while (1) {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                displayQueue(queue);
                break;
            case 4:
                printf("Exiting the program.\n");
                free(queue); // Free the queue
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}