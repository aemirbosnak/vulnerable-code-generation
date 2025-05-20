//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

// Node structure for the queue
typedef struct {
    int data;
    struct node* next;
} Node;

// Queue structure
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new queue
Queue* createQueue() {
    Queue* newQueue = (Queue*) malloc(sizeof(Queue));
    newQueue->front = NULL;
    newQueue->rear = NULL;
    return newQueue;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    if (queue->front == NULL) {
        return 1;
    } else {
        return 0;
    }
}

// Function to enqueue an element
void enqueue(Queue* queue, int data) {
    Node* newNode = createNode(data);
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue an element
int dequeue(Queue* queue) {
    Node* temp = queue->front;
    int data = temp->data;
    queue->front = temp->next;
    free(temp);
    return data;
}

// Function to display the queue
void display(Queue* queue) {
    Node* temp = queue->front;
    printf("Queue: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue* queue = createQueue();
    int choice, data;

    do {
        printf("Enter your choice:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &data);
                enqueue(queue, data);
                break;
            case 2:
                data = dequeue(queue);
                if (data!= -1) {
                    printf("Dequeued element: %d\n", data);
                }
                break;
            case 3:
                display(queue);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}