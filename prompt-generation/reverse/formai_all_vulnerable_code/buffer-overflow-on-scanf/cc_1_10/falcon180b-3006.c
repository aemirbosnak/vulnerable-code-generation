//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    struct node *next;
} node;

typedef struct {
    node *front;
    node *rear;
} queue;

void initQueue(queue *Q) {
    Q->front = NULL;
    Q->rear = NULL;
}

bool isEmpty(queue *Q) {
    return Q->front == NULL;
}

bool isFull(queue *Q) {
    return (Q->rear == NULL)? false : true;
}

void enqueue(queue *Q, int data) {
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Queue is full! ");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    if (Q->rear == NULL) {
        Q->front = newNode;
        Q->rear = newNode;
    } else {
        Q->rear->next = newNode;
        Q->rear = newNode;
    }
}

void dequeue(queue *Q) {
    if (isEmpty(Q)) {
        printf("Queue is empty! ");
        return;
    }
    node *temp = Q->front;
    Q->front = Q->front->next;
    if (Q->front == NULL) {
        Q->rear = NULL;
    }
    free(temp);
}

void display(queue *Q) {
    if (isEmpty(Q)) {
        printf("Queue is empty! ");
        return;
    }
    printf("Queue elements are: ");
    node *temp = Q->front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    queue Q;
    int choice, data;
    initQueue(&Q);

    while (true) {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(&Q, data);
                break;
            case 2:
                dequeue(&Q);
                break;
            case 3:
                display(&Q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! ");
        }
    }

    return 0;
}