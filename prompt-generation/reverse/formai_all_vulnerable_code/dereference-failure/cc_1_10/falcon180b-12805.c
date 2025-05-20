//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int data;
    struct node* next;
} Node;

Node* queue = NULL;
int front = -1;
int rear = -1;

void init_queue() {
    queue = NULL;
    front = -1;
    rear = -1;
}

bool is_empty() {
    return front == -1;
}

bool is_full() {
    return rear == MAX_QUEUE_SIZE - 1;
}

void enqueue(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    if (is_empty()) {
        front = 0;
        rear = 0;
    } else {
        rear++;
    }
    if (rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue is full\n");
        exit(0);
    }
    if (front == -1) {
        queue = temp;
        front = 0;
    } else {
        queue->next = temp;
    }
}

void dequeue() {
    if (is_empty()) {
        printf("Queue is empty\n");
        exit(0);
    }
    Node* temp = queue;
    queue = queue->next;
    free(temp);
    front++;
    if (front > rear) {
        front = -1;
        rear = -1;
    }
}

void display() {
    Node* temp = queue;
    if (is_empty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    init_queue();
    enqueue(10);
    enqueue(20);
    display();
    dequeue();
    dequeue();
    display();
    enqueue(30);
    enqueue(40);
    display();
    return 0;
}