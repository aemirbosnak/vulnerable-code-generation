//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} node;

node* front = NULL;
node* rear = NULL;

int is_empty() {
    return front == NULL;
}

int is_full() {
    node* temp = front;
    int count = 0;
    while (temp!= NULL) {
        count++;
        temp = temp->next;
    }
    return count == MAX_SIZE;
}

void enqueue(int value) {
    node* new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = value;
    new_node->next = NULL;

    if (is_empty()) {
        front = new_node;
        rear = new_node;
    }
    else {
        rear->next = new_node;
        rear = new_node;
    }
}

int dequeue() {
    int value;
    if (is_empty()) {
        printf("Queue is empty\n");
        exit(1);
    }
    value = front->data;
    node* temp = front;
    front = front->next;
    free(temp);

    if (is_empty()) {
        rear = NULL;
    }
    return value;
}

int peek() {
    if (is_empty()) {
        printf("Queue is empty\n");
        exit(1);
    }
    return front->data;
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                printf("Dequeued value: %d\n", value);
                break;
            case 3:
                value = peek();
                printf("Peeked value: %d\n", value);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}