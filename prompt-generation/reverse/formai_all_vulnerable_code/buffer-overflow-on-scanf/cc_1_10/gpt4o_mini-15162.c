//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for a queue
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue structure
typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to create a queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (!queue) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// Function to check if the queue is empty
bool isEmpty(Queue* queue) {
    return queue->size == 0;
}

// Function to add an element to the queue
void enqueue(Queue* queue, int value) {
    Node* newNode = createNode(value);
    if (isEmpty(queue)) {
        queue->front = newNode;
    } else {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
    queue->size++;
}

// Function to remove and return the front element of the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1; // return an invalid value
    }
    Node* temp = queue->front;
    int value = temp->data;
    queue->front = queue->front->next;
    free(temp);
    queue->size--;
    if (isEmpty(queue)) {
        queue->rear = NULL; // Reset rear to NULL if the queue is empty
    }
    return value;
}

// Function to display the elements of the queue
void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    Node* current = queue->front;
    printf("Queue: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free all allocated memory for the queue
void freeQueue(Queue* queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
    free(queue);
}

// Driver code
int main() {
    Queue* queue = createQueue();
    int choice, value;

    while (true) {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                printf("%d enqueued to the queue.\n", value);
                break;
                
            case 2:
                value = dequeue(queue);
                if (value != -1) {
                    printf("%d dequeued from the queue.\n", value);
                }
                break;

            case 3:
                displayQueue(queue);
                break;

            case 4:
                freeQueue(queue);
                printf("Exiting program and freeing memory.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}