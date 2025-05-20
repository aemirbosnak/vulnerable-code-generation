//FormAI DATASET v1.0 Category: Queue Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct queue {
    int front, rear;
    int data[MAX_SIZE];
} Queue;

Queue create_queue() {
    Queue q;
    q.front = q.rear = -1;
    return q;
}

int is_empty(Queue q) {
    return (q.front == -1 && q.rear == -1);
}

int is_full(Queue q) {
    return ((q.rear + 1) % MAX_SIZE == q.front);
}

int enqueue(Queue *q, int val) {
    if (is_full(*q)) {
        printf("Thou art not strong enough, my Lord. Queue is full!\n");
        return 0;
    }
    else if (is_empty(*q)) {
        q->front = q->rear = 0;
        q->data[q->rear] = val;
        printf("Added %d to the queue, my Lord.\n", val);
        return 1;
    }
    else {
        q->rear = (q->rear + 1) % MAX_SIZE;
        q->data[q->rear] = val;
        printf("Added %d to the queue, my Lord.\n", val);
        return 1;
    }
}

int dequeue(Queue *q) {
    if (is_empty(*q)) {
        printf("Fear not, my Lord. The queue is already empty.\n");
        return -1;
    }
    else if (q->front == q->rear) {
        int val = q->data[q->front];
        q->front = q->rear = -1;
        printf("Removed %d from the queue, my Lord.\n", val);
        return val;
    }
    else {
        int val = q->data[q->front];
        q->front = (q->front + 1) % MAX_SIZE;
        printf("Removed %d from the queue, my Lord.\n", val);
        return val;
    }
}

void print_queue(Queue q) {
    if (is_empty(q)) {
        printf("The queue is empty, my Lord.\n");
        return;
    }

    printf("The current queue, my Lord:\n[");
    for (int i = q.front; i != q.rear; i = (i + 1) % MAX_SIZE) {
        printf("%d, ", q.data[i]);
    }
    printf("%d]\n", q.data[q.rear]);
}

int main() {
    Queue q = create_queue();

    printf("Greetings, my Lord! This is your Queue. Let's fill it up!\n");

    int choice, value;
    do {
        printf("What do you wish to do, my Lord?\n1) Enqueue\n2) Dequeue\n3) Print the Queue\n4) Exit\n");
        printf("Enter your choice, my Lord: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value you wish to add, my Lord: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                print_queue(q);
                break;
            case 4:
                printf("Thank thee, my Lord. May thy kingdom prosper!\n");
                break;
            default:
                printf("I cannot do that, my Lord. Please choose a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}