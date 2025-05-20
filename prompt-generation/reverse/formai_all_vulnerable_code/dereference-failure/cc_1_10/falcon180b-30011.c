//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int isEmpty(Queue* q) {
    if (q->front == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void enqueue(Queue* q, int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if (q->front == NULL) {
        q->front = node;
        q->rear = node;
    } else {
        q->rear->next = node;
        q->rear = node;
    }
}

int dequeue(Queue* q) {
    int data;
    Node* temp = q->front;
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    } else {
        data = temp->data;
        q->front = temp->next;
        free(temp);
        if (q->front == NULL) {
            q->rear = NULL;
        }
        return data;
    }
}

int peek(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    } else {
        return q->front->data;
    }
}

void printQueue(Queue* q) {
    Node* temp = q->front;
    if (q->front == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    printQueue(q);
    int data = dequeue(q);
    printf("Dequeued element: %d\n", data);
    printQueue(q);
    int peeked = peek(q);
    printf("Peeked element: %d\n", peeked);
    return 0;
}