//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int data;
    struct node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

void enqueue(int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Queue is full\n");
        exit(1);
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
    int data;
    Node *temp = front;
    if (front == NULL) {
        printf("Queue is empty\n");
        exit(1);
    }
    data = front->data;
    front = front->next;
    free(temp);
    return data;
}

int peek() {
    if (front == NULL) {
        printf("Queue is empty\n");
        exit(1);
    }
    return front->data;
}

int is_empty() {
    return (front == NULL);
}

int main() {
    int choice, data;
    while (1) {
        printf("Enter your choice:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Check if the queue is empty\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data to be enqueued:\n");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                data = dequeue();
                printf("Dequeued element is %d\n", data);
                break;
            case 3:
                data = peek();
                printf("Front element is %d\n", data);
                break;
            case 4:
                if (is_empty()) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue is not empty\n");
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}