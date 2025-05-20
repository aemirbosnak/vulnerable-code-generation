//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Node {
    int data;
    struct Node *next;
};

struct Queue {
    struct Node *front;
    struct Node *rear;
};

void initQueue(struct Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(struct Queue *q, int data) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    temp->data = data;
    temp->next = NULL;

    if (q->front == NULL) {
        q->front = temp;
        q->rear = temp;
    }
    else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

int dequeue(struct Queue *q) {
    struct Node *temp = q->front;
    int data = -1;

    if (q->front!= NULL) {
        data = q->front->data;
        q->front = q->front->next;

        if (q->front == NULL)
            q->rear = NULL;
    }

    free(temp);

    return data;
}

int isEmpty(struct Queue *q) {
    if (q->front == NULL && q->rear == NULL)
        return 1;
    else
        return 0;
}

void display(struct Queue *q) {
    struct Node *temp = q->front;

    if (q->front == NULL)
        printf("Queue is empty\n");
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

    int x = dequeue(&q);
    printf("Dequeued element is: %d\n", x);

    display(&q);

    return 0;
}