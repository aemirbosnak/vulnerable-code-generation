//FormAI DATASET v1.0 Category: Queue Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct queue {
    int items[MAX_QUEUE_SIZE];
    int front;
    int rear;
} queue_t;

void init(queue_t *q) {
    q->front = -1;
    q->rear = -1;
}

int is_empty(queue_t *q) {
    if (q->rear == -1)
        return 1;
    return 0;
}

int is_full(queue_t *q) {
    if (q->rear == MAX_QUEUE_SIZE - 1)
        return 1;
    return 0;
}

void enqueue(queue_t *q, int item) {
    if (is_full(q)) {
        printf("Queue overflow\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->items[q->rear] = item;
}

int dequeue(queue_t *q) {
    int item;
    if (is_empty(q)) {
        printf("Queue underflow\n");
        return -1;
    }
    item = q->items[q->front];
    if (q->front >= q->rear) {
        q->front = -1;
        q->rear = -1;
    } 
    else {
        q->front++;
    }
    return item;
}

void display(queue_t *q) {
    int i;
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return;
    }
    for (i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main()
{
    int ch, item;
    queue_t q;
    init(&q);
    do
    {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1: 
                printf("Enter the value to be enqueued: ");
                scanf("%d", &item);
                enqueue(&q, item);
                break;
            case 2: 
                item = dequeue(&q);
                if (item != -1)
                    printf("Dequeued item: %d\n", item);
                break;
            case 3: 
                display(&q);
                break;
            case 4: 
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (ch != 4);
    return 0;
}