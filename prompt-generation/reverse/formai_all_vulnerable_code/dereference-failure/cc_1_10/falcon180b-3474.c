//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int size;
} Queue;

Queue* create_queue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Error: Memory allocation failed!\n");
        return NULL;
    }
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

bool is_empty(Queue* queue) {
    return queue->front == NULL;
}

bool is_full(Queue* queue) {
    return queue->size == MAX_SIZE;
}

void enqueue(Queue* queue, int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Error: Memory allocation failed!\n");
        return;
    }
    node->data = data;
    node->next = NULL;
    if (is_empty(queue)) {
        queue->front = node;
        queue->rear = node;
    } else {
        queue->rear->next = node;
        queue->rear = node;
    }
    queue->size++;
}

int dequeue(Queue* queue) {
    if (is_empty(queue)) {
        printf("Error: Queue is empty!\n");
        return -1;
    }
    int data = queue->front->data;
    Node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    queue->size--;
    return data;
}

void display(Queue* queue) {
    if (is_empty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    Node* temp = queue->front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue* queue = create_queue();
    if (queue == NULL) {
        return 1;
    }
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    display(queue);
    dequeue(queue);
    dequeue(queue);
    display(queue);
    return 0;
}