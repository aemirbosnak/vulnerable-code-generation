//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} node;

node* front = NULL;
node* rear = NULL;
int count = 0;

void enqueue(int value) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = value;
    new_node->next = NULL;

    if (rear == NULL) {
        front = new_node;
        rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }

    count++;
}

int dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    int value = front->data;
    node* temp = front;
    front = front->next;
    free(temp);

    count--;

    if (front == NULL) {
        rear = NULL;
    }

    return value;
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
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
    enqueue(50);

    display();

    int value = dequeue();
    printf("Dequeued value is: %d\n", value);

    display();

    value = dequeue();
    printf("Dequeued value is: %d\n", value);

    display();

    value = dequeue();
    printf("Dequeued value is: %d\n", value);

    display();

    value = dequeue();
    printf("Dequeued value is: %d\n", value);

    display();

    value = dequeue();
    printf("Dequeued value is: %d\n", value);

    return 0;
}