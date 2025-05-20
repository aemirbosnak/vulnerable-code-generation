//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PACKET_SIZE 100

typedef struct Packet {
    char data[MAX_PACKET_SIZE];
} Packet;

int detect_intrusion(Packet packet) {
    // Intrusion detection logic goes here
    // For example, checking for malicious keywords
    if (strstr(packet.data, "malware") != NULL) {
        return 1;
    }
    return 0;
}

int main() {
    int num_packets, i;
    printf("Enter the number of packets to process: ");
    scanf("%d", &num_packets);
    getchar(); // Consume newline character

    Packet *packets = malloc(num_packets * sizeof(Packet));
    if (packets == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for packets\n");
        exit(1);
    }

    // Read in packets from user input
    for (i = 0; i < num_packets; i++) {
        printf("Enter packet %d data: ", i+1);
        fgets(packets[i].data, MAX_PACKET_SIZE, stdin);
        // Remove trailing newline character if it exists
        if (packets[i].data[strlen(packets[i].data)-1] == '\n') {
            packets[i].data[strlen(packets[i].data)-1] = '\0';
        }
    }

    // Detect intrusions in each packet and print result
    for (i = 0; i < num_packets; i++) {
        if (detect_intrusion(packets[i])) {
            printf("Packet %d contains an intrusion!\n", i+1);
        } else {
            printf("Packet %d is clean.\n", i+1);
        }
    }

    free(packets);
    return 0;
}