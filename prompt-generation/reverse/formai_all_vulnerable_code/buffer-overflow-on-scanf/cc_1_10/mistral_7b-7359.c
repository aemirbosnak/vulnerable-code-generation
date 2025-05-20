//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUEUE_SIZE 10

typedef struct Queue {
    int front, rear;
    int data[QUEUE_SIZE];
} Queue;

Queue my_queue = {-1, -1};

void init_queue(Queue *q) {
    q->front = q->rear = -1;
}

int is_full(Queue *q) {
    return (q->rear + 1) % QUEUE_SIZE == q->front;
}

int is_empty(Queue *q) {
    return q->front == -1 && q->rear == -1;
}

void enqueue(Queue *q, int data) {
    if (is_full(q)) {
        printf("Error: Queue is full.\n");
        return;
    }
    q->rear = (q->rear + 1) % QUEUE_SIZE;
    q->data[q->rear] = data;
}

int dequeue(Queue *q) {
    if (is_empty(q)) {
        printf("Error: Queue is empty.\n");
        return -1;
    }
    int data = q->data[q->front];
    q->front = (q->front + 1) % QUEUE_SIZE;
    return data;
}

void print_queue(Queue q) {
    if (is_empty(&my_queue)) {
        printf("Empty Queue\n");
        return;
    }

    printf("Queue: [");
    for (int i = q.front + 1; i != q.rear; i = (i + 1) % QUEUE_SIZE) {
        printf("%d, ", q.data[i]);
    }
    printf("%d]\n", q.data[q.rear]);
}

void queue_operation(Queue *q, char op, int data) {
    switch (op) {
        case 'E':
            enqueue(q, data);
            break;
        case 'D':
            dequeue(q);
            break;
        case 'P':
            print_queue(*q);
            break;
        default:
            printf("Invalid operation.\n");
            break;
    }
}

int main(int argc, char *argv[]) {
    char operation;
    int data;

    init_queue(&my_queue);

    while (1) {
        printf("Enter operation(E/D/P) or data(for E), or Q to quit: ");
        scanf("%c", &operation);

        if (operation == 'Q') {
            break;
        }

        if (operation == 'E') {
            printf("Enter data: ");
            scanf("%d", &data);
            queue_operation(&my_queue, operation, data);
            continue;
        }

        if (is_empty(&my_queue)) {
            printf("Queue is empty.\n");
            continue;
        }

        data = dequeue(&my_queue);
        printf("Dequeued: %d\n", data);
    }

    return 0;
}