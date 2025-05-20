//FormAI DATASET v1.0 Category: Queue Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef struct {
    int front, rear;
    int items[MAX_QUEUE_SIZE];
} Queue;

Queue create_queue();
void enqueue(Queue *queue, int value);
int dequeue(Queue *queue);
void print_queue(Queue queue);

int main() {
    Queue queue = create_queue();

    int choice, value;
    do {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to be enqueued: ");
            scanf("%d", &value);
            enqueue(&queue, value);
            print_queue(queue);
            break;
        case 2:
            value = dequeue(&queue);
            if (value != -1) {
                printf("Dequeued value: %d\n", value);
            }
            print_queue(queue);
            break;
        case 3:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != 3);

    return 0;
}


Queue create_queue() {
    Queue queue;
    queue.front = -1;
    queue.rear = -1;
    return queue;
}

void enqueue(Queue *queue, int value) {
    if (queue->rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue is full. Unable to enqueue value.\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear++;
    queue->items[queue->rear] = value;
}

int dequeue(Queue *queue) {
    if (queue->front == -1 || queue->front > queue->rear) {
        printf("Queue is empty. Unable to dequeue value.\n");
        return -1;
    }
    int value = queue->items[queue->front];
    queue->front++;
    return value;
}

void print_queue(Queue queue) {
    if (queue.front == -1 || queue.front > queue.rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue:\n");
        for (int i = queue.front; i <= queue.rear; i++) {
            printf("%d\n", queue.items[i]);
        }
    }
}