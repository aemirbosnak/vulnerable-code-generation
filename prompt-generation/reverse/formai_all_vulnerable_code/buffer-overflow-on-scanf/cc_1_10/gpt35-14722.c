//FormAI DATASET v1.0 Category: Queue Implementation ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#define QUEUESIZE 5

/*
 * This is an example program demonstrating the implementation of
 * circular queue in C language.
 */

typedef struct {
    int queue[QUEUESIZE];
    int front;
    int rear;
} queue;

void init_queue(queue *que) {
    que->front = -1;
    que->rear = -1;
}

void insert(queue *que, int num) {
    if ((que->rear + 1) % QUEUESIZE == que->front) {
        printf("Queue is full!\n");
        return;
    }
    if (que->front == -1)
        que->front = 0;
    que->rear = (que->rear + 1) % QUEUESIZE;
    que->queue[que->rear] = num;
}

int delete(queue *que) {
    int num;
    if (que->front == -1) {
        printf("Queue is empty!\n");
        return -1;
    }
    num = que->queue[que->front];
    if (que->front == que->rear) {
        que->front = -1;
        que->rear = -1;
    } else {
        que->front = (que->front + 1) % QUEUESIZE;
    }
    return num;
}

void display(queue *que) {
    int i;
    if (que->front == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue Elements are:\n");
    for (i = que->front; i != que->rear; i = (i + 1) % QUEUESIZE) {
        printf("%d ", que->queue[i]);
    }
    printf("%d\n", que->queue[i]);
}

int main() {
    queue q;
    int choice, num;
    init_queue(&q);
    printf("Circular Queue Example\n");
    do {
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the number to be inserted:");
                scanf("%d", &num);
                insert(&q, num);
                break;
            case 2:
                num = delete(&q);
                if (num != -1)
                    printf("Deleted Element is:%d\n", num);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while(choice != 4);
    return 0;
}