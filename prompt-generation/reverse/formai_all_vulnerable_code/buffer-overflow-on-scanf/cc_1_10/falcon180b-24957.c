//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PACKETS 1000
#define MAX_DELAY 1000

typedef struct {
    int packet_id;
    int delay;
    int qos;
} packet_t;

void enqueue(packet_t *packet) {
    static int front = 0;
    static int rear = -1;
    static packet_t packets[MAX_PACKETS];

    if ((rear + 1) % MAX_PACKETS == front) {
        printf("Queue is full\n");
        exit(1);
    }

    if (rear == -1) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX_PACKETS;
    }

    packets[rear] = *packet;
}

packet_t dequeue() {
    static int front = 0;
    static int rear = -1;
    static packet_t packets[MAX_PACKETS];

    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        exit(1);
    }

    packet_t packet = packets[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX_PACKETS;
    }

    return packet;
}

int main() {
    packet_t packet;

    while (1) {
        printf("Enter packet ID (0 to exit): ");
        scanf("%d", &packet.packet_id);

        if (packet.packet_id == 0) {
            break;
        }

        printf("Enter delay (in ms): ");
        scanf("%d", &packet.delay);

        printf("Enter QoS (0-100): ");
        scanf("%d", &packet.qos);

        enqueue(&packet);
    }

    printf("Queue is empty\n");
    return 0;
}