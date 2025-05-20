//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *front = NULL, *rear = NULL;

void enqueue(int value) {
    Node *temp = (Node *) malloc(sizeof(Node));

    if (temp == NULL) {
        printf("Queue is Full\n");
        exit(0);
    }

    temp->data = value;
    temp->next = NULL;

    if (front == NULL && rear == NULL) {
        front = temp;
        rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }

    printf("%d enqueued to the queue\n", value);
}

void dequeue() {
    if (front == NULL && rear == NULL) {
        printf("Queue is Empty\n");
        exit(0);
    } else if (front == NULL) {
        rear = NULL;
        front = rear;
    } else if (rear == NULL) {
        front = NULL;
        rear = front;
    } else {
        Node *temp = front;
        front = front->next;
        printf("%d dequeued from the queue\n", temp->data);
        free(temp);
    }
}

void display() {
    if (front == NULL && rear == NULL) {
        printf("Queue is Empty\n");
    } else {
        Node *temp = front;
        printf("Elements in the queue are: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    printf("Enter 1 to Enqueue\n");
    printf("Enter 2 to Dequeue\n");
    printf("Enter 3 to Display\n");
    printf("Enter 4 to Exit\n");

    while (1) {
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
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}