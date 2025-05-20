//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return (q->front == NULL);
}

// Function to add an item to the queue
void enqueue(Queue* q, int value) {
    Node* newNode = createNode(value);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode; 
    q->rear = newNode;
}

// Function to remove an item from the queue
int dequeue(Queue* q) {
    if (isEmpty(q))
        return -1;

    Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    
    if (q->front == NULL)
        q->rear = NULL;
    
    free(temp);
    return value;
}

// Function to get the front item of the queue
int front(Queue* q) {
    if (isEmpty(q))
        return -1;
    return q->front->data;
}

// Function to display the queue elements
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    
    Node* temp = q->front;
    printf("Queue contents: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the queue implementation
int main() {
    Queue* q = createQueue();
    int choice, value;

    do {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Front\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(q, value);
                printf("%d enqueued to the queue.\n", value);
                break;
            case 2:
                value = dequeue(q);
                if (value != -1) {
                    printf("%d dequeued from the queue.\n", value);
                } else {
                    printf("Queue is empty. Dequeue operation failed.\n");
                }
                break;
            case 3:
                value = front(q);
                if (value != -1) {
                    printf("Front element is: %d\n", value);
                } else {
                    printf("Queue is empty.\n");
                }
                break;
            case 4:
                displayQueue(q);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    // Free the allocated memory for the queue
    while (!isEmpty(q)) {
        dequeue(q);
    }
    free(q);

    return 0;
}