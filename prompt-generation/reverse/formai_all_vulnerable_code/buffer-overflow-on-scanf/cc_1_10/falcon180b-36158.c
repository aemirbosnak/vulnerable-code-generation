//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int data;
    struct node* next;
} node;

node* createNode(int data) {
    node* newNode = (node*) malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(node** front, node** rear, int data) {
    node* newNode = createNode(data);
    if (*front == NULL) {
        *front = newNode;
        *rear = newNode;
        return;
    }
    (*rear)->next = newNode;
    (*rear) = newNode;
}

int dequeue(node** front, node** rear) {
    if (*front == NULL) {
        printf("Error: Queue is empty.\n");
        return -1;
    }
    int data = (*front)->data;
    node* temp = *front;
    (*front) = (*front)->next;
    free(temp);
    if (*front == NULL) {
        (*rear) = NULL;
    }
    return data;
}

void display(node* front) {
    while (front!= NULL) {
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}

int main() {
    node* front = NULL;
    node* rear = NULL;
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
                enqueue(&front, &rear, data);
                break;
            case 2:
                data = dequeue(&front, &rear);
                if (data!= -1) {
                    printf("Dequeued data: %d\n", data);
                }
                break;
            case 3:
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