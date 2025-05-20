//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: interoperable
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

int isEmpty(queue* q) {
    return q->front == NULL;
}

int isFull(queue* q) {
    node* temp = q->rear;
    while (temp!= NULL) {
        temp = temp->next;
        if (temp == q->front) {
            return 1;
        }
    }
    return 0;
}

void enqueue(queue* q, int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
        newNode->next = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
        newNode->next = q->front;
    }
}

int dequeue(queue* q) {
    int data;
    node* temp = q->front;

    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    } else if (q->front == q->rear) {
        data = q->front->data;
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
    } else {
        data = q->front->data;
        q->front = q->front->next;
        free(temp);
    }

    return data;
}

void display(queue* q) {
    node* temp = q->front;

    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp!= q->front);
    printf("\n");
}

int main() {
    queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    display(&q);

    int deqData = dequeue(&q);
    printf("Dequeued element is: %d\n", deqData);

    display(&q);

    enqueue(&q, 50);
    enqueue(&q, 60);

    printf("Is queue full? %s\n", isFull(&q)? "Yes" : "No");

    return 0;
}