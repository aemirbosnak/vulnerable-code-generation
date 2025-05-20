//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

void initQueue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(Queue *q) {
    if (q->front == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void enqueue(Queue *q, int data) {
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;

    if (isEmpty(q)) {
        q->front = newnode;
        q->rear = newnode;
    } else {
        q->rear->next = newnode;
        q->rear = newnode;
    }
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        Node *temp = q->front;
        int data = temp->data;
        q->front = temp->next;
        free(temp);
        return data;
    }
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        Node *temp = q->front;
        printf("Queue elements are: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    display(&q);

    int dequeuedData = dequeue(&q);
    printf("Dequeued element is: %d\n", dequeuedData);

    display(&q);

    return 0;
}