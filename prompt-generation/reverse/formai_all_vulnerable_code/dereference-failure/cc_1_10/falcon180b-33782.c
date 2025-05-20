//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

void initQueue(struct Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(struct Queue* q) {
    if (q->front == NULL && q->rear == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

int isFull(struct Queue* q) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) {
        return 1;
    }
    else {
        free(temp);
        return 0;
    }
}

void enqueue(struct Queue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    }
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(struct Queue* q) {
    int value = -1;

    if (!isEmpty(q)) {
        struct Node* temp = q->front;
        value = temp->data;
        q->front = q->front->next;

        if (q->front == NULL) {
            q->rear = NULL;
        }

        free(temp);
    }

    return value;
}

void display(struct Queue* q) {
    struct Node* temp = q->front;

    if (isEmpty(q)) {
        printf("Queue is empty\n");
    }
    else {
        printf("Queue elements are: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    display(&q);

    int dequeuedValue = dequeue(&q);
    printf("Dequeued value: %d\n", dequeuedValue);

    display(&q);

    return 0;
}