//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the structure of a Queue Node
typedef struct Node {
    char data[256];
    struct Node* next;
} Node;

// Define the structure of the Queue
typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Function to create a new node
Node* createNode(const char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

// Function to create a queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (!queue) {
        printf("Memory allocation for queue failed!\n");
        exit(EXIT_FAILURE);
    }
    queue->front = queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// Function to check if the queue is empty
bool isEmpty(Queue* queue) {
    return queue->size == 0;
}

// Function to add an element to the queue
void enqueue(Queue* queue, const char* data) {
    Node* newNode = createNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
    printf("Enqueued: %s\n", data);
}

// Function to remove an element from the queue
char* dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow! No elements to dequeue.\n");
        return NULL;
    }
    Node* temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    char* dequeuedData = strdup(temp->data);
    free(temp);
    queue->size--;
    printf("Dequeued: %s\n", dequeuedData);
    return dequeuedData;
}

// Function to peek at the front element of the queue
char* peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! No front element.\n");
        return NULL;
    }
    return queue->front->data;
}

// Function to display the queue contents
void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("The queue is currently empty.\n");
        return;
    }

    printf("Current Queue Contents:\n");
    Node* current = queue->front;
    while (current != NULL) {
        printf(" -> %s", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the queue and its elements
void freeQueue(Queue* queue) {
    Node* current = queue->front;
    Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    
    free(queue);
}

// Main function
int main() {
    Queue* myQueue = createQueue();
    char choice[10];
    char element[256];

    do {
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display Queue\n5. Exit\nChoose an option: ");
        scanf("%s", choice);

        switch (atoi(choice)) {
            case 1:
                printf("Enter an element to enqueue: ");
                scanf(" %[^\n]s", element);
                enqueue(myQueue, element);
                break;
            case 2:
                dequeue(myQueue);
                break;
            case 3:
                printf("Front element: %s\n", peek(myQueue));
                break;
            case 4:
                displayQueue(myQueue);
                break;
            case 5:
                printf("Exiting the queue program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (atoi(choice) != 5);

    freeQueue(myQueue);
    return 0;
}