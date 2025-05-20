//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

/* Define the structure of the node */
struct Node {
    int data;
    struct Node* next;
};

/* Define the structure of the queue */
struct Queue {
    struct Node* front;
    struct Node* rear;
};

/* Function to create an empty queue */
void initQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

/* Function to check if the queue is empty */
int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

/* Function to check if the queue is full */
int isFull(struct Queue* q) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) {
        return 1;
    } else {
        free(temp);
        return 0;
    }
}

/* Function to add an element to the queue */
void enqueue(struct Queue* q, int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("Queue is full!\n");
        return;
    }
    temp->data = data;
    temp->next = NULL;
    if (isEmpty(q)) {
        q->front = temp;
        q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

/* Function to remove an element from the queue */
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    struct Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

/* Function to display the elements of the queue */
void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    struct Node* temp = q->front;
    printf("Queue elements are: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Queue q;
    initQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    display(&q);
    dequeue(&q);
    dequeue(&q);
    display(&q);
    dequeue(&q);
    dequeue(&q);
    display(&q);
    enqueue(&q, 50);
    enqueue(&q, 60);
    enqueue(&q, 70);
    display(&q);
    return 0;
}