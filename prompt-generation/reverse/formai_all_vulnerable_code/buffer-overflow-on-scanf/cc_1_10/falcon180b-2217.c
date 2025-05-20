//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} node;

node* front = NULL;
node* rear = NULL;

void enqueue(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (front == NULL && rear == NULL) {
        front = newNode;
        rear = newNode;
    }
    else if (front == NULL) {
        rear->next = newNode;
        rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Enqueued value: %d\n", data);
}

void dequeue() {
    if (front == NULL && rear == NULL) {
        printf("Queue is empty\n");
        return;
    }

    node* temp = front;
    printf("Dequeued value: %d\n", temp->data);

    if (front == rear) {
        front = NULL;
        rear = NULL;
    }
    else {
        front = front->next;
    }

    free(temp);
}

void display() {
    if (front == NULL && rear == NULL) {
        printf("Queue is empty\n");
        return;
    }

    node* current = front;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int choice, data;

    printf("Enter 1 to enqueue\n");
    printf("Enter 2 to dequeue\n");
    printf("Enter 3 to display\n");
    printf("Enter 4 to exit\n");

    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}