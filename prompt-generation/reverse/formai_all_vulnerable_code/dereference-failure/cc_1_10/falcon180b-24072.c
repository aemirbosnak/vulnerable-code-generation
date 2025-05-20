//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: scalable
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
int count = 0;

void init() {
    front = NULL;
    rear = NULL;
    count = 0;
}

bool isEmpty() {
    return (front == NULL);
}

bool isFull() {
    return (rear == NULL? false : true);
}

void enqueue(int value) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty()) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    count++;
}

int dequeue() {
    int value = -1;

    if (!isEmpty()) {
        node* temp = front;
        value = temp->data;
        front = front->next;
        free(temp);
        count--;
    }

    return value;
}

int peek() {
    int value = -1;

    if (!isEmpty()) {
        value = front->data;
    }

    return value;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: ");
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
    enqueue(40);

    display();

    int value = dequeue();
    printf("Dequeued value is: %d\n", value);

    display();

    value = peek();
    printf("Peeked value is: %d\n", value);

    return 0;
}