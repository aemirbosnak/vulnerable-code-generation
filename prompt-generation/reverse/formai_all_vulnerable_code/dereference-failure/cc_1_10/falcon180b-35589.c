//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: medieval
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
    q->front = NULL;
    q->rear = NULL;
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
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        return 1;
    } else {
        free(temp);
        return 0;
    }
}

// Function to enqueue an element
void enqueue(struct queue* q, int value) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Queue Overflow\n");
        exit(0);
    } else {
        temp->data = value;
        temp->next = NULL;
        if (isEmpty(q)) {
            q->front = temp;
            q->rear = temp;
        } else {
            q->rear->next = temp;
            q->rear = temp;
        }
    }
}

// Function to dequeue an element
int dequeue(struct queue* q) {
    int value;
    struct node* temp = q->front;
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        exit(0);
    } else {
        value = temp->data;
        q->front = temp->next;
        free(temp);
        if (isEmpty(q)) {
            q->rear = NULL;
        }
    }
    return value;
}

// Function to display the queue
void display(struct queue* q) {
    struct node* temp = q->front;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}

int main() {
    struct queue q;
    createQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);
    printf("Dequeued element is: %d\n", dequeue(&q));
    display(&q);
    printf("Dequeued element is: %d\n", dequeue(&q));
    display(&q);
    return 0;
}