//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Node structure for queue
struct node {
    int data;
    struct node *next;
};

// Queue structure
struct queue {
    struct node *front;
    struct node *rear;
};

// Function to create an empty queue
void create_queue(struct queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

// Function to check if the queue is empty
int is_empty(struct queue *q) {
    if (q->front == NULL)
        return 1;
    else
        return 0;
}

// Function to check if the queue is full
int is_full(struct queue *q) {
    struct node *temp = q->rear;
    while (temp!= NULL) {
        temp = temp->next;
    }
    if (temp == q->front)
        return 1;
    else
        return 0;
}

// Function to enqueue an element into the queue
void enqueue(struct queue *q, int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if (is_empty(q)) {
        q->front = newnode;
        q->rear = newnode;
    }
    else {
        q->rear->next = newnode;
        q->rear = newnode;
    }
}

// Function to dequeue an element from the queue
int dequeue(struct queue *q) {
    int data;
    struct node *temp = q->front;
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    else {
        data = temp->data;
        q->front = temp->next;
        free(temp);
        if (q->front == NULL)
            q->rear = NULL;
    }
    return data;
}

// Function to display the contents of the queue
void display(struct queue *q) {
    struct node *temp = q->front;
    if (is_empty(q))
        printf("Queue is empty\n");
    else {
        printf("Queue elements are: ");
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
    create_queue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);
    dequeue(&q);
    dequeue(&q);
    display(&q);
    dequeue(&q);
    display(&q);
    return 0;
}