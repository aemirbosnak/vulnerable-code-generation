//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct node {
    int data;
    struct node* next;
};

// Queue structure definition
struct queue {
    struct node* front;
    struct node* rear;
};

// Function to create an empty queue
void createQueue(struct queue* q) {
    q->front = q->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(struct queue* q) {
    return (q->front == NULL);
}

// Function to add an element to the rear of the queue
void enqueue(struct queue* q, int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    }
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to remove an element from the front of the queue
int dequeue(struct queue* q) {
    int value = -1;

    if (!isEmpty(q)) {
        struct node* temp = q->front;
        value = temp->data;
        q->front = q->front->next;

        free(temp);
    }

    return value;
}

// Function to display the elements in the queue
void displayQueue(struct queue* q) {
    struct node* temp = q->front;

    if (isEmpty(q)) {
        printf("Queue is empty\n");
    }
    else {
        printf("Elements in the queue are: ");

        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }

        printf("\n");
    }
}

// Main function
int main() {
    struct queue q;
    createQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    displayQueue(&q);

    int value = dequeue(&q);
    printf("Dequeued value: %d\n", value);

    displayQueue(&q);

    return 0;
}