//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_QUEUE_SIZE 10 // Maximum size of the queue
#define MAX_PACKET_DELAY 100 // Maximum delay between packets in milliseconds
#define MAX_PACKET_SIZE 1000 // Maximum size of a packet in bytes
#define MAX_PACKETS_PER_SECOND 100 // Maximum number of packets per second
#define PACKET_LOSS_PROBABILITY 0.05 // Probability of packet loss
#define STATISTICS_UPDATE_INTERVAL 1 // Interval in seconds to update statistics

struct Packet {
    int size;
    struct timespec arrival_time;
};

struct Queue {
    struct Packet packets[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int size;
};

double elapsed_time(struct timespec start_time, struct timespec end_time) {
    double elapsed_seconds = difftime(end_time.tv_sec, start_time.tv_sec);
    long elapsed_nanos = end_time.tv_nsec - start_time.tv_nsec;
    return (elapsed_seconds + elapsed_nanos / 1e9);
}

void enqueue(struct Queue *queue, struct Packet packet) {
    if (queue->size == MAX_QUEUE_SIZE) {
        printf("Packet dropped, queue full\n");
        return;
    }
    queue->packets[queue->rear] = packet;
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    queue->size++;
}

struct Packet dequeue(struct Queue *queue) {
    struct Packet packet = queue->packets[queue->front];
    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    queue->size--;
    return packet;
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time
    struct Queue queue = { .front = 0, .rear = 0, .size = 0 };
    double total_delay = 0;
    double total_packets = 0;
    double total_packet_loss = 0;
    double total_packets_per_second = 0;
    double total_packet_size = 0;

    while (1) {
        // Generate a new packet with random size and delay
        struct Packet packet = {
            .size = rand() % MAX_PACKET_SIZE,
            .arrival_time = { 0, 0 }
        };
        packet.arrival_time.tv_nsec = (rand() % MAX_PACKET_DELAY) * 1000000; // Convert milliseconds to nanoseconds

        // Wait for the delay period
        nanosleep(&packet.arrival_time, NULL);

        // Enqueue the packet if the queue is not full
        if ((double)rand() / RAND_MAX > PACKET_LOSS_PROBABILITY) {
            enqueue(&queue, packet);
        } else {
            printf("Packet lost\n");
            total_packet_loss++;
        }

        // Dequeue packets as quickly as possible and update statistics
        while (queue.size > 0) {
            struct Packet dequeued_packet = dequeue(&queue);
            double elapsed = elapsed_time(dequeued_packet.arrival_time, (struct timespec){ 0, 0 });
            total_delay += elapsed;
            total_packets++;
            total_packet_size += dequeued_packet.size;
            if (elapsed < 1.0 / MAX_PACKETS_PER_SECOND) {
                total_packets_per_second++;
            }
        }

        // Update statistics every STATISTICS_UPDATE_INTERVAL seconds
        sleep(STATISTICS_UPDATE_INTERVAL);
        printf("Average delay: %.3f ms\n", total_delay / total_packets * 1000);
        printf("Packet loss rate: %.3f%%\n", total_packet_loss / (total_packet_loss + total_packets) * 100.0);
        printf("Average packets per second: %.3f\n", total_packets_per_second / STATISTICS_UPDATE_INTERVAL);
        printf("Average packet size: %.3f bytes\n", total_packet_size / total_packets);
        printf("=========================================\n");
    }

    return 0;
}