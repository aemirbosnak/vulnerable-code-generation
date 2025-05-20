//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int count;
} Queue;

void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
    q->count = 0;
}

bool isEmpty(Queue* q) {
    return q->count == 0;
}

bool isFull(Queue* q) {
    return q->count == MAX_QUEUE_SIZE;
}

void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    q->count++;
}

int dequeue(Queue* q) {
    int data;
    Node* temp = q->front;

    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        exit(0);
    }

    data = temp->data;
    q->front = temp->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    q->count--;

    return data;
}

void display(Queue* q) {
    Node* temp = q->front;

    if (isEmpty(q)) {
        printf("Queue is empty!\n");
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
    Queue q;
    int choice, data;

    initQueue(&q);

    while (true) {
        printf("Enter your choice:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the data to be enqueued: ");
            scanf("%d", &data);
            enqueue(&q, data);
            break;

        case 2:
            data = dequeue(&q);
            printf("Dequeued element is: %d\n", data);
            break;

        case 3:
            display(&q);
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}