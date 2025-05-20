//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 10
#define MAX_PACKET_SIZE 100

typedef struct {
    char data[MAX_PACKET_SIZE];
    int size;
} packet;

typedef struct {
    packet packets[MAX_QUEUE_SIZE];
    int front;
    int rear;
} queue;

void enqueue(queue* q, packet p) {
    if ((q->rear + 1) % MAX_QUEUE_SIZE == q->front) {
        printf("Queue is full. Dropping packet.\n");
        return;
    }
    q->packets[q->rear] = p;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
}

packet dequeue(queue* q) {
    if (q->front == -1) {
        printf("Queue is empty.\n");
        return (packet){ 0 };
    }
    packet p = q->packets[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return p;
}

int is_empty(queue* q) {
    return q->front == -1;
}

int main() {
    queue q;
    q.front = -1;
    q.rear = -1;

    while (1) {
        printf("Enter 1 to enqueue a packet, 2 to dequeue a packet, or 0 to exit:\n");
        int choice;
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        } else if (choice == 1) {
            packet p;
            printf("Enter packet data (max %d bytes):\n", MAX_PACKET_SIZE - 1);
            scanf("%s", p.data);
            p.size = strlen(p.data) + 1;
            enqueue(&q, p);
        } else if (choice == 2) {
            packet p = dequeue(&q);
            printf("Dequeued packet: %s (%d bytes)\n", p.data, p.size);
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}