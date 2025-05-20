//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Sherlock Holmes
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

void enqueue(int data) {
    node* newNode = (node*)malloc(sizeof(node));

    if (newNode == NULL) {
        printf("Error: Memory could not be allocated.\n");
        exit(0);
    }

    newNode->data = data;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue() {
    int data = -1;

    if (front == NULL) {
        printf("Error: Queue is empty.\n");
        exit(0);
    } else if (front == rear) {
        data = front->data;
        free(front);
        front = rear = NULL;
    } else {
        data = front->data;
        node* temp = front;
        front = front->next;
        free(temp);
    }

    return data;
}

void display() {
    node* temp = front;

    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    int choice, data;

    do {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to be enqueued: ");
                scanf("%d", &data);
                enqueue(data);
                break;

            case 2:
                data = dequeue();
                if (data!= -1)
                    printf("Dequeued data is: %d\n", data);
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}