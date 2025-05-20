//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

struct Packet {
    char srcIP[MAX_LEN];
    char dstIP[MAX_LEN];
    char protocol[MAX_LEN];
    int packetSize;
};

int main() {
    printf("Welcome to the Intrusion Detection System!\n");

    // Initialize counters for packets processed and detected intrusions
    int packetCount = 0;
    int intrusionCount = 0;

    // Open input file to read packets
    FILE *inputFile = fopen("packets.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file!\n");
        exit(1);
    }

    // Iterate through input file and process each packet
    while (!feof(inputFile)) {
        // Read packet information from input file
        char line[MAX_LEN];
        fgets(line, MAX_LEN, inputFile);
        if (strlen(line) == 0) continue; // Skip empty lines

        // Parse packet information
        struct Packet packet;
        sscanf(line, "%s %s %s %d", packet.srcIP, packet.dstIP, packet.protocol, &packet.packetSize);

        // Check if packet is an intrusion
        if (strcmp(packet.protocol, "UDP") == 0 && packet.packetSize > 1000) {
            printf("Intrusion detected: UDP packet from %s to %s with size %d\n", packet.srcIP, packet.dstIP, packet.packetSize);
            intrusionCount++;
        }

        // Increment counter for packets processed
        packetCount++;
    }

    // Close input file
    fclose(inputFile);

    // Print statistics
    printf("Finished processing packets!\n");
    printf("Number of packets processed: %d\n", packetCount);
    printf("Number of intrusions detected: %d\n", intrusionCount);

    return 0;
}