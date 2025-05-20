//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct node {
    int data;
    struct node *next;
};

struct Queue {
    struct node *front;
    struct node *rear;
    int count;
};

// Create an empty queue
struct Queue *createQueue() {
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->count = 0;
    return queue;
}

// Check if the queue is empty
int isEmpty(struct Queue *queue) {
    if (queue->front == NULL && queue->rear == NULL) {
        return 1;
    } else {
        return 0;
    }
}

// Add an element to the rear of the queue
void enqueue(struct Queue *queue, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->count++;
}

// Remove an element from the front of the queue
int dequeue(struct Queue *queue) {
    struct node *temp = queue->front;
    int data = temp->data;
    queue->front = temp->next;
    free(temp);
    queue->count--;
    if (isEmpty(queue)) {
        queue->rear = NULL;
    }
    return data;
}

// Display the elements of the queue
void display(struct Queue *queue) {
    struct node *temp = queue->front;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    struct Queue *queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);
    display(queue);
    int dequeuedData = dequeue(queue);
    printf("Dequeued data: %d\n", dequeuedData);
    display(queue);
    return 0;
}