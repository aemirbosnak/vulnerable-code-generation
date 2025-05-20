//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct Node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

void enqueue(int data) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Out of memory\n");
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
    printf("%d enqueued to the queue\n", data);
}

void dequeue() {
    if (front == NULL) {
        printf("Error: Queue is empty\n");
        exit(1);
    }
    Node *temp_node = front;
    front = front->next;
    printf("%d dequeued from the queue\n", temp_node->data);
    free(temp_node);
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    Node *temp_node = front;
    while (temp_node!= NULL) {
        printf("%d ", temp_node->data);
        temp_node = temp_node->next;
    }
    printf("\n");
}

int is_empty() {
    return (front == NULL);
}

int is_full() {
    Node *temp_node = (Node*) malloc(sizeof(Node));
    if (temp_node == NULL) {
        free(temp_node);
        return 1;
    } else {
        free(temp_node);
        return 0;
    }
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
                printf("Enter the data to be enqueued: ");
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