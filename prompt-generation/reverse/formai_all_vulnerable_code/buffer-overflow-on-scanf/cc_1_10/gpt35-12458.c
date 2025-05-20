//FormAI DATASET v1.0 Category: Queue Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

struct queue {
    int arr[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int size;
};

typedef struct queue Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
    q->size = 0;
}

int enqueue(Queue *q, int num) {
    if (q->rear == MAX_QUEUE_SIZE - 1) {
        printf("Error: Queue is full!\n");
        return 0;
    }
    else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->arr[q->rear] = num;
        q->size++;
        return 1;
    }
}

int dequeue(Queue *q) {
    if (q->front == -1) {
        printf("Error: Queue is empty!\n");
        return -1;
    }
    else {
        int num = q->arr[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
        q->size--;
        return num;
    }
}

int isEmpty(Queue *q) {
    return (q->size == 0);
}

int isFull(Queue *q) {
    return (q->size == MAX_QUEUE_SIZE);
}

int getQueueSize(Queue *q) {
    return q->size;
}

void printQueue(Queue *q) {
    int i;
    printf("Queue: ");
    for (i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    int num, selection;
    Queue q1;
    initQueue(&q1);
    
    printf("Queue Program\n");
    
    do {
        printf("\n----------------------------------------------------------\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Check if queue is empty\n");
        printf("4. Check if queue is full\n");
        printf("5. Get queue size\n");
        printf("6. Print queue\n");
        printf("7. Exit\n");
        printf("\nEnter your selection: ");
        scanf("%d", &selection);
        
        switch (selection) {
            case 1:
                printf("Enter a number to enqueue: ");
                scanf("%d", &num);
                if (enqueue(&q1, num)) {
                    printf("%d has been enqueued.\n", num);
                }
                break;
            case 2:
                num = dequeue(&q1);
                if (num != -1) {
                    printf("%d has been dequeued.\n", num);
                }
                break;
            case 3:
                if (isEmpty(&q1)) {
                    printf("Queue is empty.\n");
                }
                else {
                    printf("Queue is not empty.\n");
                }
                break;
            case 4:
                if (isFull(&q1)) {
                    printf("Queue is full.\n");
                }
                else {
                    printf("Queue is not full.\n");
                }
                break;
            case 5:
                printf("Queue size: %d\n", getQueueSize(&q1));
                break;
            case 6:
                printQueue(&q1);
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid selection!\n");
                break;
        }
    } while (selection != 7);
    
    return 0;
}