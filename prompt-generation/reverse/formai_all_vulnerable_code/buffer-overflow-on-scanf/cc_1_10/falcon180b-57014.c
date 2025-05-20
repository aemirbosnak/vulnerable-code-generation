//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

void enqueue(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Queue is full!\n");
        return;
    }
    new_node->data = data;
    new_node->next = NULL;
    if (rear == NULL) {
        front = rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
}

int dequeue() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    int data = front->data;
    Node *temp = front;
    front = front->next;
    free(temp);
    return data;
}

void display() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements are: ");
    Node *temp = front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, data;
    do {
        printf("Enter your choice:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            }
            case 2: {
                data = dequeue();
                if (data!= -1) {
                    printf("Dequeued data is %d\n", data);
                }
                break;
            }
            case 3: {
                display();
                break;
            }
            case 4: {
                printf("Exiting...\n");
                break;
            }
            default: {
                printf("Invalid choice!\n");
            }
        }
    } while (choice!= 4);
    return 0;
}