//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct node {
    int data;
    struct node *next;
};

struct queue {
    struct node *front;
    struct node *rear;
};

void init_queue(struct queue *q) {
    q->front = q->rear = NULL;
}

int is_empty(struct queue *q) {
    return q->front == NULL;
}

int is_full(struct queue *q) {
    struct node *temp = q->rear;
    while (temp!= q->front) {
        temp = temp->next;
        if (temp == q->rear) {
            return 0;
        }
    }
    return 1;
}

void enqueue(struct queue *q, int data) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if (is_empty(q)) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

int dequeue(struct queue *q) {
    int data;
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    struct node *temp = q->front;
    data = temp->data;
    q->front = q->front->next;
    free(temp);
    return data;
}

void display(struct queue *q) {
    struct node *temp = q->front;
    printf("Queue elements are: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct queue q;
    init_queue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    display(&q);
    dequeue(&q);
    dequeue(&q);
    display(&q);
    return 0;
}