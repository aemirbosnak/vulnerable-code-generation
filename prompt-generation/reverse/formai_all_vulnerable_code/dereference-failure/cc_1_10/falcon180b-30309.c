//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} node;

node* front = NULL;
node* rear = NULL;

void enqueue(int data) {
    node* new_node = (node*)malloc(sizeof(node));

    if (new_node == NULL) {
        printf("Queue Overflow\n");
        exit(0);
    }

    new_node->data = data;
    new_node->next = NULL;

    if (front == NULL) {
        front = rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }

    printf("%d enqueued to the queue\n", data);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        exit(0);
    }

    node* temp = front;
    printf("%d dequeued from the queue\n", temp->data);

    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
    }

    free(temp);
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("Queue: ");
        node* temp = front;
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    dequeue();

    display();

    return 0;
}