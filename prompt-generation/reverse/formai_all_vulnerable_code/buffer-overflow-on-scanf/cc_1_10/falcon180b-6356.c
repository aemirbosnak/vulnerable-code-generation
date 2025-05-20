//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} node;

typedef struct {
    node* front;
    node* rear;
} queue;

void initQueue(queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(queue* q, int data) {
    node* newNode = (node*) malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(queue* q) {
    int data;
    node* temp = q->front;
    if (temp == NULL) {
        printf("Queue is empty\n");
        exit(1);
    }
    data = temp->data;
    q->front = temp->next;
    free(temp);
    if (q->front == NULL) {
        q->rear = NULL;
    }
    return data;
}

int peek(queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        exit(1);
    }
    return q->front->data;
}

int isEmpty(queue* q) {
    if (q->front == NULL) {
        return 1;
    } else {
        return 0;
    }
}

int isFull(queue* q) {
    node* temp = (node*) malloc(sizeof(node));
    if (temp == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    free(temp);
    return 0;
}

int main() {
    queue q;
    initQueue(&q);
    int choice, data;
    do {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data to enqueue: ");
                scanf("%d", &data);
                enqueue(&q, data);
                break;
            case 2:
                data = dequeue(&q);
                printf("Dequeued data: %d\n", data);
                break;
            case 3:
                data = peek(&q);
                printf("Peeked data: %d\n", data);
                break;
            case 4:
                printf("Data in the queue: ");
                while (!isEmpty(&q)) {
                    data = dequeue(&q);
                    printf("%d ", data);
                }
                printf("\n");
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 5);
    return 0;
}