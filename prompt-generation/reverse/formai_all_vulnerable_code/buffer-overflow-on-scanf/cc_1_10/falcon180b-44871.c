//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int value) {
    struct node *newnode = (struct node *) malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Memory error\n");
        exit(0);
    }

    newnode->data = value;
    newnode->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = newnode;
    } else if (rear == NULL) {
        rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }

    printf("%d enqueued to the queue\n", value);
}

void dequeue() {
    struct node *temp = front;

    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("%d dequeued from the queue\n", front->data);

    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
    }

    free(temp);
}

void display() {
    struct node *temp = front;

    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Elements in the queue are: ");

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    int choice, value;

    do {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be enqueued: ");
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
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 4);

    return 0;
}