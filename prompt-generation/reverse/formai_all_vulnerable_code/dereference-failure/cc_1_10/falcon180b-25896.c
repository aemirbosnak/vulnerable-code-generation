//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

Queue *createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

bool isEmpty(Queue *q) {
    return q->front == NULL && q->rear == NULL;
}

bool isFull(Queue *q) {
    Node *temp = q->rear;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    return temp->next == NULL;
}

void enqueue(Queue *q, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue *q) {
    int data = -1;

    if (!isEmpty(q)) {
        Node *temp = q->front;
        data = temp->data;
        q->front = temp->next;

        if (q->front == NULL) {
            q->rear = NULL;
        }

        free(temp);
    }

    return data;
}

void display(Queue *q) {
    Node *temp = q->front;

    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are: ");

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    Queue *q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    printf("Queue elements after enqueue: ");
    display(q);

    int dequeuedData = dequeue(q);
    printf("Dequeued data: %d\n", dequeuedData);

    printf("Queue elements after dequeue: ");
    display(q);

    dequeue(q);
    dequeue(q);

    printf("Queue elements after dequeue: ");
    display(q);

    return 0;
}