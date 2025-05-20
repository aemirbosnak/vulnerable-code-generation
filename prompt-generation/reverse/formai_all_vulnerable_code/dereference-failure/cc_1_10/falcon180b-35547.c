//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node *next;
} node;

node *front = NULL;
node *rear = NULL;

void enqueue(int value) {
    node *new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }

    new_node->data = value;
    new_node->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = new_node;
    } else if (rear == NULL) {
        rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }

    printf("%d enqueued successfully\n", value);
}

void dequeue() {
    if (front == NULL) {
        printf("Error: Queue is empty\n");
        return;
    }

    node *temp = front;
    printf("%d dequeued successfully\n", front->data);
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    node *temp = front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    display();

    dequeue();
    dequeue();

    display();

    enqueue(50);
    enqueue(60);

    display();

    return 0;
}