//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define PACKET_SIZE_LIMIT 1024 // maximum packet size
#define TIMEOUT_THRESHOLD 10 // maximum delay in milliseconds
#define MAX_RETRIES 3 // maximum number of retries


// function to simulate network traffic and packet loss
bool send_packet(int size) {
    int random = rand() % 10;
    if (random < 2) {
        // packet lost
        return false;
    }
    // simulate delay
    int delay = rand() % (TIMEOUT_THRESHOLD + 1);
    usleep(delay * 1000);
    return true;
}


// recursive function to send packets until success or maximum retries reached
bool send_packet_with_retry(int size, int retries_left) {
    if (retries_left < 1) {
        // maximum retries reached
        return false;
    }
    bool success = send_packet(size);
    if (!success) {
        // packet lost, retry
        printf("Packet lost, retrying...\n");
        return send_packet_with_retry(size, retries_left - 1);
    }
    // packet sent successfully
    printf("Packet sent successfully!\n");
    return true;
}


// main function to monitor QoS for network traffic
int main() {
    srand(time(NULL)); // initialize random seed
    int packet_size;
    printf("Enter packet size in bytes (1-%d): ", PACKET_SIZE_LIMIT);
    scanf("%d", &packet_size);
    if (packet_size < 1 || packet_size > PACKET_SIZE_LIMIT) {
        printf("Invalid packet size!\n");
        return 1;
    }
    int retries_left = MAX_RETRIES;
    printf("Sending packet of size %d bytes with maximum %d retries...\n", packet_size, retries_left);
    bool success = send_packet_with_retry(packet_size, retries_left);
    if (!success) {
        printf("Packet delivery failed!\n");
        return 1;
    }
    printf("Packet delivery successful!\n");
    return 0;
}