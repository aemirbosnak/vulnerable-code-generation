//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct node {
    int data;
    struct node *next;
} node;

node *front = NULL;
node *rear = NULL;
int count = 0;

void enqueue(int value) {
    node *newnode = (node *) malloc(sizeof(node));

    if (newnode == NULL) {
        printf("Memory Error\n");
        exit(0);
    }

    newnode->data = value;
    newnode->next = NULL;

    if (front == NULL) {
        front = newnode;
        rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }

    count++;
    printf("%d enqueued to the queue\n", value);
}

void dequeue() {
    node *temp = front;

    if (front == NULL) {
        printf("Queue Underflow\n");
        exit(0);
    }

    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
    count--;
    printf("%d dequeued from the queue\n", temp->data);
}

void display() {
    node *temp = front;

    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue is: ");

    while (temp!= NULL) {
        printf(" %d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("\n");

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
            exit(0);

        default:
            printf("Invalid Choice\n");
        }
    }

    return 0;
}