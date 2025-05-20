//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

// Function to initialize a Queue
Queue *initQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to create a new Node
Node *newNode(int value) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;
    return temp;
}

// Function to add an element to Queue
void enqueue(Queue *q, int value) {
    Node *temp = newNode(value);
    if (!q->rear) {
        q->front = q->rear = temp;
        q->rear->next = q->front; // Circular link
    } else {
        q->rear->next = temp;
        q->rear = temp;
        q->rear->next = q->front; // Circular link
    }
}

// Function to remove an element from Queue
int dequeue(Queue *q) {
    if (!q->front) {
        printf("Queue is empty! Can't dequeue.\n");
        return -1;
    }
    Node *temp = q->front;
    int data = temp->data;

    if (q->front == q->rear) {
        q->front = q->rear = NULL; // Queue is empty after dequeuing
    } else {
        q->front = q->front->next;
        q->rear->next = q->front; // Maintain circular link
    }
    free(temp);
    return data;
}

// Function to display Queue elements
void displayQueue(Queue *q) {
    if (!q->front) {
        printf("Queue is empty!\n");
        return;
    }
    Node *temp = q->front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != q->front);
    printf("\n");
}

// Function to free the Queue memory
void freeQueue(Queue *q) {
    if (!q) return;
    Node *current = q->front;
    Node *nextNode;
    if (current) {
        do {
            nextNode = current->next;
            free(current);
            current = nextNode;
        } while (current != q->front);
    }
    free(q);
}

// Main function to test the Queue implementation
int main() {
    Queue *q = initQueue();
    int choice, value;

    while (1) {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number to enqueue: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;
            case 2:
                value = dequeue(q);
                if (value != -1) {
                    printf("Dequeued: %d\n", value);
                }
                break;
            case 3:
                printf("Queue contents: ");
                displayQueue(q);
                break;
            case 4:
                freeQueue(q);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
        printf("\n");
    }
}