//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PACKETS 1000
#define MAX_PACKET_SIZE 1500
#define MAX_DELAY_MS 500

typedef struct {
    int size;
    int delay;
    int sequence;
} Packet;

Packet packets[MAX_PACKETS];
int num_packets = 0;
int current_packet = 0;

void enqueue(int size, int delay) {
    if (num_packets >= MAX_PACKETS) {
        printf("Error: Packet queue is full.\n");
        exit(1);
    }
    packets[num_packets].size = size;
    packets[num_packets].delay = delay;
    packets[num_packets].sequence = num_packets;
    num_packets++;
}

void dequeue() {
    if (current_packet >= num_packets) {
        printf("Error: No packets in the queue.\n");
        exit(1);
    }
    current_packet++;
}

int main() {
    int choice, size, delay;
    char input[100];

    printf("Enter the maximum packet size (in bytes): ");
    scanf("%d", &size);

    printf("Enter the maximum packet delay (in milliseconds): ");
    scanf("%d", &delay);

    printf("Enter the number of packets to send: ");
    scanf("%d", &num_packets);

    printf("Enter the packet size and delay for each packet:\n");
    for (int i = 0; i < num_packets; i++) {
        printf("Packet %d: ", i + 1);
        scanf("%d %d", &size, &delay);
        enqueue(size, delay);
    }

    printf("Enter's' to start sending packets, 'q' to quit:\n");
    while (1) {
        scanf("%s", input);
        if (strcmp(input, "s") == 0) {
            break;
        } else if (strcmp(input, "q") == 0) {
            exit(0);
        }
    }

    while (current_packet < num_packets) {
        sleep(packets[current_packet].delay);
        printf("Sending packet %d (%d bytes)\n", packets[current_packet].sequence, packets[current_packet].size);
        dequeue();
    }

    return 0;
}