//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Define a structure for the queue
typedef struct {
    int data;
    struct node* next;
} node;

// Define the queue
typedef struct {
    node* front;
    node* rear;
} queue;

// Initialize the queue
queue* createQueue() {
    queue* q = (queue*) malloc(sizeof(queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Enqueue an element
void enqueue(queue* q, int data) {
    node* newNode = (node*) malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Dequeue an element
int dequeue(queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    free(temp);
    if (q->front == NULL) {
        q->rear = NULL;
    }
    return data;
}

// Display the queue
void display(queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("Queue: ");
        node* temp = q->front;
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);
    int x = dequeue(q);
    display(q);
    printf("Dequeued element: %d\n", x);
    return 0;
}