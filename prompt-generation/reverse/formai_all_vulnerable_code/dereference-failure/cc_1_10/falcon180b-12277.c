//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Node structure for Queue
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create an empty Queue
void createQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

// Function to check if the Queue is empty
int isEmpty(struct Queue* q) {
    return (q->front == NULL && q->rear == NULL);
}

// Function to check if the Queue is full
int isFull(struct Queue* q) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) {
        return 1;
    }
    free(temp);
    return 0;
}

// Function to add an element to the rear of the Queue
void enqueue(struct Queue* q, int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    if (isEmpty(q)) {
        q->front = q->rear = temp;
    }
    else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

// Function to remove an element from the front of the Queue
int dequeue(struct Queue* q) {
    int data;
    struct Node* temp = q->front;

    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }

    data = temp->data;
    q->front = q->front->next;

    if (isEmpty(q)) {
        q->rear = NULL;
    }

    free(temp);
    return data;
}

// Function to display the current state of the Queue
void display(struct Queue* q) {
    struct Node* temp = q->front;

    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are: ");

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    createQueue(q);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    printf("Queue elements after enqueue operations:\n");
    display(q);

    int data = dequeue(q);
    printf("Dequeued element: %d\n", data);

    printf("Queue elements after dequeue operation:\n");
    display(q);

    return 0;
}