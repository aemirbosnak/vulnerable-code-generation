//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure to hold each packet */
struct Packet {
    char srcIP[16];     // Source IP address
    char dstIP[16];     // Destination IP address
    int srcPort;        // Source port number
    int dstPort;        // Destination port number
    char protocol[10];  // Protocol used
};

/* Function to check if a packet is suspicious */
int isSuspicious(struct Packet pkt) {
    /* If protocol is not TCP or UDP, it's suspicious */
    if (strcmp(pkt.protocol, "TCP") != 0 && strcmp(pkt.protocol, "UDP") != 0) {
        return 1;
    }

    /* If both IP addresses are same, it's suspicious */
    if (strcmp(pkt.srcIP, pkt.dstIP) == 0) {
        return 1;
    }

    /* If source or destination port is less than 1024, it's suspicious */
    if (pkt.srcPort < 1024 || pkt.dstPort < 1024) {
        return 1;
    }

    /* Packet is not suspicious */
    return 0;
}

/* Function to print the suspicious packets */
void printSuspicious(struct Packet pkts[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (isSuspicious(pkts[i])) {
            printf("Suspicious packet found:\n");
            printf("Source IP: %s\n", pkts[i].srcIP);
            printf("Destination IP: %s\n", pkts[i].dstIP);
            printf("Source port: %d\n", pkts[i].srcPort);
            printf("Destination port: %d\n", pkts[i].dstPort);
            printf("Protocol: %s\n\n", pkts[i].protocol);
        }
    }
}

int main() {
    int n, i;
    printf("Enter the number of packets: ");
    scanf("%d", &n);

    /* Allocate memory for n packets */
    struct Packet *pkts = (struct Packet*) malloc(n * sizeof(struct Packet));

    /* Read n packets */
    for (i = 0; i < n; i++) {
        printf("\nPacket %d:\n", i+1);
        printf("Enter source IP address: ");
        scanf("%s", pkts[i].srcIP);
        printf("Enter destination IP address: ");
        scanf("%s", pkts[i].dstIP);
        printf("Enter source port number: ");
        scanf("%d", &pkts[i].srcPort);
        printf("Enter destination port number: ");
        scanf("%d", &pkts[i].dstPort);
        printf("Enter protocol used: ");
        scanf("%s", pkts[i].protocol);
    }

    /* Print suspicious packets */
    printf("\nSuspicious packets:\n");
    printSuspicious(pkts, n);

    /* Free memory */
    free(pkts);

    return 0;
}