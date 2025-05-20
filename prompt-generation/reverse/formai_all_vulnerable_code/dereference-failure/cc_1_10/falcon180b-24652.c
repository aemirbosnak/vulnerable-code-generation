//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure for a node
struct node {
    int data;
    struct node* next;
};

// Structure for the queue
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
    if (q->front == NULL) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if the queue is full
int isFull(struct queue* q) {
    if ((q->rear->next = NULL) == NULL) {
        return 1;
    } else {
        return 0;
    }
}

// Function to add an element to the rear of the queue
void enqueue(struct queue* q, int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    if (isEmpty(q)) {
        q->front = temp;
        q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }

    printf("%d enqueued to the queue\n", data);
}

// Function to remove an element from the front of the queue
int dequeue(struct queue* q) {
    int data;
    struct node* temp = q->front;

    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    } else if (q->front == q->rear) {
        data = q->front->data;
        free(q->front);
        q->front = q->rear = NULL;
    } else {
        data = q->front->data;
        q->front = q->front->next;
        free(temp);
    }

    printf("%d dequeued from the queue\n", data);
    return data;
}

// Function to display the elements in the queue
void display(struct queue* q) {
    struct node* temp = q->front;

    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
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
    enqueue(&q, 40);

    display(&q);

    dequeue(&q);
    dequeue(&q);

    display(&q);

    enqueue(&q, 50);
    enqueue(&q, 60);

    display(&q);

    return 0;
}