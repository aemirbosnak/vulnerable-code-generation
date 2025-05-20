//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} node;

node* front = NULL;
node* rear = NULL;

void init() {
    front = NULL;
    rear = NULL;
}

bool is_empty() {
    return (front == NULL && rear == NULL);
}

bool is_full() {
    node* temp = front;
    int count = 0;
    while (temp!= NULL) {
        count++;
        temp = temp->next;
    }
    return (count == MAX_SIZE);
}

void enqueue(int value) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = value;
    new_node->next = NULL;

    if (is_empty()) {
        front = new_node;
        rear = new_node;
    }
    else if (is_full()) {
        printf("Queue is full!\n");
    }
    else {
        rear->next = new_node;
        rear = new_node;
    }
}

void dequeue() {
    if (is_empty()) {
        printf("Queue is empty!\n");
    }
    else if (front == rear) {
        node* temp = front;
        front = NULL;
        rear = NULL;
        free(temp);
    }
    else {
        node* temp = front;
        front = front->next;
        free(temp);
    }
}

void display() {
    if (is_empty()) {
        printf("Queue is empty!\n");
    }
    else {
        node* temp = front;
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    init();
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    dequeue();
    enqueue(40);
    enqueue(50);
    display();
    return 0;
}