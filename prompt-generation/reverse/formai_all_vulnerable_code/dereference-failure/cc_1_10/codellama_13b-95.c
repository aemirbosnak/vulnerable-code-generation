//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: safe
/*
 * Safe Queue Implementation Example
 *
 * Author: [Your Name]
 * Date:   [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for a Queue node
typedef struct QueueNode {
    int data;
    struct QueueNode *next;
} QueueNode;

// Structure for the Queue
typedef struct {
    QueueNode *front;
    QueueNode *rear;
} Queue;

// Function to create a new Queue
Queue *createQueue() {
    Queue *q = malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Function to enqueue an element in the Queue
void enqueue(Queue *q, int data) {
    QueueNode *newNode = malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to dequeue an element from the Queue
int dequeue(Queue *q) {
    if (q->front == NULL) {
        return -1;
    } else {
        QueueNode *temp = q->front;
        int data = temp->data;
        q->front = temp->next;
        free(temp);
        return data;
    }
}

// Function to display the Queue
void displayQueue(Queue *q) {
    QueueNode *temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Driver code
int main() {
    Queue *q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    displayQueue(q);
    int data = dequeue(q);
    printf("Dequeued element: %d\n", data);
    displayQueue(q);
    return 0;
}