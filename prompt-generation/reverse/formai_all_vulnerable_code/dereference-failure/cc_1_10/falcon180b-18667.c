//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Post-apocalyptic queue implementation
typedef struct {
    int data;
    struct node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

void init() {
    front = NULL;
    rear = NULL;
}

bool is_empty() {
    return front == NULL;
}

bool is_full() {
    Node* temp = front;
    int count = 0;
    while (temp!= NULL) {
        count++;
        temp = temp->next;
    }
    return count == MAX_SIZE;
}

void enqueue(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;

    if (is_empty()) {
        front = new_node;
        rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
}

int dequeue() {
    int data = -1;

    if (is_empty()) {
        printf("Queue is empty\n");
        return data;
    }

    Node* temp = front;
    data = temp->data;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
    return data;
}

void display() {
    Node* temp = front;
    printf("Queue: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    init();

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    display();

    int dequeued_data = dequeue();
    printf("Dequeued data: %d\n", dequeued_data);

    display();

    enqueue(50);
    enqueue(60);

    printf("Is queue full? %s\n", is_full()? "Yes" : "No");

    return 0;
}