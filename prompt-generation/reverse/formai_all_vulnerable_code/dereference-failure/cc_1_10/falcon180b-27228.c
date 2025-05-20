//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
typedef struct node {
    int data;
    struct node* next;
} Node;

// Queue structure definition
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    if (queue->front == NULL) {
        return 1;
    } else {
        return 0;
    }
}

// Function to add an element to the rear of the queue
void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to remove an element from the front of the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        int data = queue->front->data;
        Node* temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
        return data;
    }
}

// Function to display the elements in the queue
void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
    } else {
        Node* temp = queue->front;
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    display(queue);

    int data = dequeue(queue);
    printf("Dequeued element: %d\n", data);

    display(queue);

    data = dequeue(queue);
    printf("Dequeued element: %d\n", data);

    display(queue);

    data = dequeue(queue);
    printf("Dequeued element: %d\n", data);

    display(queue);

    data = dequeue(queue);
    printf("Dequeued element: %d\n", data);

    display(queue);

    return 0;
}