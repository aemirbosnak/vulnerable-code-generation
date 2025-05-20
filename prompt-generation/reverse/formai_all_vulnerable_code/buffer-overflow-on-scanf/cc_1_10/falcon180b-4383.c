//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int data;
    struct node* next;
} node;

node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(node** front, node** rear, int data) {
    node* newNode = createNode(data);
    if (*rear == NULL) {
        *front = newNode;
        *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

int dequeue(node** front, node** rear) {
    int data = (*front)->data;
    node* temp = *front;
    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;
    }
    free(temp);
    return data;
}

int isEmpty(node* front) {
    return front == NULL;
}

int isFull(node* rear, node* front) {
    return (rear - front + 1) == MAX_QUEUE_SIZE;
}

void display(node* front) {
    while (front!= NULL) {
        printf("%d ", front->data);
        front = front->next;
    }
}

int main() {
    node* front = NULL;
    node* rear = NULL;
    int choice, data;

    do {
        printf("\nQueue Operations\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data to enqueue: ");
            scanf("%d", &data);
            enqueue(&front, &rear, data);
            break;
        case 2:
            data = dequeue(&front, &rear);
            printf("Dequeued data: %d\n", data);
            break;
        case 3:
            printf("Queue elements: ");
            display(front);
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