//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Function prototypes
Queue* createQueue();
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int isEmpty(Queue* q);
void displayQueue(Queue* q);
void freeQueue(Queue* q);
void menu();

// Create a new Queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (!q) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

// Enqueue an element into the Queue
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation for new node failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (q->rear) {
        q->rear->next = newNode;
    }
    q->rear = newNode;
    if (q->front == NULL) {
        q->front = newNode;
    }
    q->size++;
    printf("Enqueued: %d\n", value);
}

// Dequeue an element from the Queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        fprintf(stderr, "Queue underflow! Unable to dequeue.\n");
        return -1; // Indicating an error
    }
    int value = q->front->data;
    Node* temp = q->front;
    q->front = q->front->next;
    free(temp);
    
    if (q->front == NULL) {
        q->rear = NULL;
    }
    q->size--;
    printf("Dequeued: %d\n", value);
    return value;
}

// Check if the Queue is empty
int isEmpty(Queue* q) {
    return q->size == 0;
}

// Display the contents of the Queue
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    Node* current = q->front;
    printf("Queue: ");
    while (current) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Free all dynamically allocated memory in the Queue
void freeQueue(Queue* q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
    free(q);
    printf("Queue memory freed successfully.\n");
}

// Display menu and handle user input
void menu() {
    Queue* q = createQueue();
    int choice, value;
    do {
        printf("\nQueue Menu:\n");
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
                enqueue(q, value);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                displayQueue(q);
                break;
            case 4:
                freeQueue(q);
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 4);
}

// Main function to start the program
int main() {
    menu();
    return 0;
}