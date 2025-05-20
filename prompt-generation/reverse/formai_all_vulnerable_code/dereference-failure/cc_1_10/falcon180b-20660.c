//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Queue Node structure
struct Node {
    int data;
    struct Node* next;
};

// Queue implementation using linked list
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Initializes an empty queue
void init(struct Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Checks if the queue is empty
int is_empty(struct Queue* q) {
    return q->front == NULL;
}

// Inserts an element at the rear of the queue
void enqueue(struct Queue* q, int value) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = NULL;

    if (is_empty(q)) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

// Deletes an element from the front of the queue
int dequeue(struct Queue* q) {
    int value = -1;

    if (!is_empty(q)) {
        struct Node* temp = q->front;
        value = temp->data;
        q->front = temp->next;

        if (q->front == NULL)
            q->rear = NULL;

        free(temp);
    }

    return value;
}

// Prints all the elements in the queue
void print_queue(struct Queue* q) {
    struct Node* temp = q->front;

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
    struct Queue q;
    init(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    print_queue(&q);

    dequeue(&q);
    dequeue(&q);

    print_queue(&q);

    return 0;
}