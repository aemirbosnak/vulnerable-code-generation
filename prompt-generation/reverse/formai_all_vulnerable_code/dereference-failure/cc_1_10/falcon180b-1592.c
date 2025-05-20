//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100 // maximum size of the queue

typedef struct {
    int data;
    struct node* next;
} node;

node* front = NULL; // pointer to the front of the queue
node* rear = NULL; // pointer to the rear of the queue
int size = 0; // current size of the queue

void enqueue(int value) {
    node* new_node = (node*)malloc(sizeof(node)); // create a new node
    new_node->data = value;
    new_node->next = NULL;

    if (rear == NULL) {
        front = new_node;
    } else {
        rear->next = new_node;
    }
    rear = new_node;
    size++;
}

int dequeue() {
    int value = -1;

    if (front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }

    node* temp = front;
    front = front->next;
    size--;

    value = temp->data;
    free(temp);

    return value;
}

int peek() {
    int value = -1;

    if (front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }

    value = front->data;

    return value;
}

void display() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    node* temp = front;
    printf("Queue elements are: ");
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

    int value = dequeue();
    printf("Dequeued value: %d\n", value);

    display();

    value = peek();
    printf("Peek value: %d\n", value);

    return 0;
}