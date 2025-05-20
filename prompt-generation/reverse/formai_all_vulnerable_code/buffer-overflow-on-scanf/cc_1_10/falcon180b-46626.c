//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct Node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

void enqueue(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Queue is full, cannot enqueue %d\n", data);
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (front == NULL) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue() {
    if (front == NULL) {
        printf("Queue is empty, cannot dequeue\n");
        return -1;
    }
    int data = front->data;
    Node* temp = front;
    front = front->next;
    free(temp);

    if (front == NULL) {
        rear = NULL;
    }

    return data;
}

void display() {
    Node* temp = front;
    printf("Queue: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int isEmpty() {
    return front == NULL;
}

int isFull() {
    Node* temp = rear;
    while (temp!= NULL) {
        if (temp->next == NULL) {
            return 0;
        }
        temp = temp->next;
    }
    return 1;
}

int main() {
    int choice, data;

    while (1) {
        printf("Enter your choice:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data to enqueue: ");
            scanf("%d", &data);
            enqueue(data);
            break;
        case 2:
            data = dequeue();
            if (data!= -1) {
                printf("Dequeued data: %d\n", data);
            }
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice, please try again\n");
        }
    }

    return 0;
}