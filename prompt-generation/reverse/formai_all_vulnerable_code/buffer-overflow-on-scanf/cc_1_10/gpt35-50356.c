//FormAI DATASET v1.0 Category: Queue ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#define MAXQUEUE 10

struct cqueue {
    int items[MAXQUEUE];
    int front;
    int rear;
};

void createCQueue(struct cqueue *q);
void enqueue(struct cqueue *q, int item);
int dequeue(struct cqueue *q);
void display(struct cqueue *q);

int main() {
    struct cqueue q;
    createCQueue(&q);
    int choice, item;
    do {
        printf("\n\n********* Main Menu *********\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                printf("Enter the element to be enqueued: ");
                scanf("%d", &item);
                enqueue(&q, item);
                break;
            }
            case 2: {
                item = dequeue(&q);
                printf("The dequeued element is: %d\n", item);
                break;
            }
            case 3: {
                display(&q);
                break;
            }
            case 4: {
                printf("Quitting the program...\n");
                exit(0);
            }
            default: {
                printf("Invalid choice! Try again.\n");
            }
        }
    } while(choice != 4);
    return 0;
}

void createCQueue(struct cqueue *q) {
    q->front = -1;
    q->rear = -1;
}

void enqueue(struct cqueue *q, int item) {
    if((q->rear == MAXQUEUE-1 && q->front == 0) || q->rear == q->front-1) {
        printf("Queue overflow!\n");
        return;
    }
    if(q->front == -1) {
        q->front = 0;
        q->rear = 0;
    }
    else {
        if(q->rear == MAXQUEUE-1) {
            q->rear = 0;
        }
        else {
            q->rear++;
        }
    }
    q->items[q->rear] = item;
    printf("Enqueued item %d successfully!\n", item);
}

int dequeue(struct cqueue *q) {
    if(q->front == -1) {
        printf("Queue underflow!\n");
        return -1;
    }
    int item = q->items[q->front];
    if(q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    else {
        if(q->front == MAXQUEUE-1) {
            q->front = 0;
        }
        else {
            q->front++;
        }
    }
    return item;
}

void display(struct cqueue *q) {
    if(q->front == -1) {
        printf("The queue is currently empty!\n");
        return;
    }
    printf("The current elements in the queue are:\n");
    if(q->rear >= q->front) {
        for(int i=q->front; i<=q->rear; i++) {
            printf("%d\n", q->items[i]);
        }
    }
    else {
        for(int i=q->front; i<=MAXQUEUE-1; i++) {
            printf("%d\n", q->items[i]);
        }
        for(int i=0; i<=q->rear; i++) {
            printf("%d\n", q->items[i]);
        }
    }
}