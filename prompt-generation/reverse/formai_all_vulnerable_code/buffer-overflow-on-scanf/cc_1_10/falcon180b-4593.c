//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int next;
} node_t;

node_t *queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int value) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full\n");
        return;
    }

    if (front == -1) {
        front = 0;
    }

    if (rear == -1) {
        rear = 0;
    }

    queue[++rear] = (node_t *) malloc(sizeof(node_t));
    queue[rear]->data = value;
    queue[rear]->next = NULL;
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Dequeued value: %d\n", queue[front]->data);

    node_t *temp = queue[front];
    queue[front] = queue[front]->next;

    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front++;
    }

    free(temp);
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    node_t *temp = queue[front];

    printf("Queue elements: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value;

    do {
        printf("Enter your choice:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 4);

    return 0;
}