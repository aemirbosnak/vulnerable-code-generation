//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 1000
#define MAX_DATA_SIZE 1024
#define MAX_EVENTS 10

struct event {
    int type;
    int value;
};

struct data_packet {
    int size;
    char data[MAX_DATA_SIZE];
};

struct queue {
    struct data_packet packets[MAX_QUEUE_SIZE];
    int front;
    int rear;
};

void enqueue(struct queue *q, struct data_packet p) {
    if ((q->rear + 1) % MAX_QUEUE_SIZE == q->front) {
        printf("Queue is full!\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->packets[q->rear] = p;
}

struct data_packet dequeue(struct queue *q) {
    struct data_packet p;
    if (q->front == -1 || q->rear == -1) {
        printf("Queue is empty!\n");
        return p;
    }
    p = q->packets[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return p;
}

void init_queue(struct queue *q) {
    q->front = -1;
    q->rear = -1;
}

int main() {
    struct queue q;
    init_queue(&q);

    while (1) {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                struct data_packet p;
                printf("Enter packet size: ");
                scanf("%d", &p.size);
                printf("Enter packet data: ");
                scanf("%s", p.data);
                enqueue(&q, p);
                break;
            }
            case 2: {
                struct data_packet p = dequeue(&q);
                if (p.size > 0) {
                    printf("Dequeued packet of size %d with data: %s\n", p.size, p.data);
                }
                break;
            }
            case 3: {
                int count = 0;
                struct data_packet p;
                while (count < MAX_QUEUE_SIZE && q.rear!= -1) {
                    p = dequeue(&q);
                    if (p.size > 0) {
                        printf("Dequeued packet of size %d with data: %s\n", p.size, p.data);
                        count++;
                    }
                }
                break;
            }
            case 4: {
                exit(0);
            }
            default: {
                printf("Invalid choice!\n");
            }
        }
    }

    return 0;
}