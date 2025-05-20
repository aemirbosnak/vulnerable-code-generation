//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} node;

typedef struct {
    node* front;
    node* rear;
} queue;

void enqueue(queue* q, int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (q->front == NULL) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

int dequeue(queue* q) {
    if (q->front == NULL) {
        return -1;
    }

    node* temp = q->front;
    int data = temp->data;
    q->front = temp->next;
    free(temp);
    return data;
}

void print_queue(queue* q) {
    node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    queue* q = (queue*)malloc(sizeof(queue));
    q->front = NULL;
    q->rear = NULL;

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    print_queue(q);

    int data = dequeue(q);
    printf("Dequeued data: %d\n", data);

    print_queue(q);

    return 0;
}