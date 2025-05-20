//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: invasive
// Queue implementation using a linked list

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct queue {
    struct node *front;
    struct node *rear;
};

// function to create a new node
struct node *create_node(int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// function to create a new queue
struct queue *create_queue() {
    struct queue *new_queue = malloc(sizeof(struct queue));
    new_queue->front = NULL;
    new_queue->rear = NULL;
    return new_queue;
}

// function to enqueue an element
void enqueue(struct queue *q, int data) {
    struct node *new_node = create_node(data);
    if (q->rear == NULL) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

// function to dequeue an element
int dequeue(struct queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = q->front->data;
    struct node *temp = q->front;
    q->front = q->front->next;
    free(temp);
    return data;
}

// function to display the elements of the queue
void display(struct queue *q) {
    struct node *temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct queue *q = create_queue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    display(q);
    int data = dequeue(q);
    printf("Dequeued element: %d\n", data);
    display(q);
    return 0;
}