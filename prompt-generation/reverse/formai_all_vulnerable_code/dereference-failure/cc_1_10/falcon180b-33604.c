//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Node structure
struct node {
    int data;
    struct node* next;
};

// Queue structure
struct queue {
    struct node* front;
    struct node* rear;
    int size;
};

// Function to create an empty queue
struct queue* create_queue() {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

// Function to check if the queue is empty
bool is_empty(struct queue* q) {
    if (q->front == NULL) {
        return true;
    } else {
        return false;
    }
}

// Function to check if the queue is full
bool is_full(struct queue* q) {
    if (q->size == MAX_SIZE) {
        return true;
    } else {
        return false;
    }
}

// Function to enqueue an element
void enqueue(struct queue* q, int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (is_empty(q)) {
        q->front = q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
    q->size++;
}

// Function to dequeue an element
int dequeue(struct queue* q) {
    int data;
    struct node* temp = q->front;
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        data = temp->data;
        q->front = q->front->next;
        free(temp);
        q->size--;
        return data;
    }
}

// Function to display the queue
void display(struct queue* q) {
    struct node* temp = q->front;
    if (is_empty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct queue* q = create_queue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    display(q);
    dequeue(q);
    dequeue(q);
    display(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    display(q);
    return 0;
}