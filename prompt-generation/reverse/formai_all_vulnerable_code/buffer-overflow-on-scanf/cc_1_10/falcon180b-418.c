//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int next;
} Node;

Node *front = NULL;
Node *rear = NULL;

void enqueue(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Queue is full\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue() {
    int value;
    if (front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    Node *temp = front;
    value = front->data;
    front = front->next;
    free(temp);
    return value;
}

int peek() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    return front->data;
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    Node *temp = front;
    printf("Queue: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the value to be enqueued: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            value = dequeue();
            if (value!= -1) {
                printf("Dequeued value: %d\n", value);
            }
            break;
        case 3:
            value = peek();
            if (value!= -1) {
                printf("Front element: %d\n", value);
            }
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}