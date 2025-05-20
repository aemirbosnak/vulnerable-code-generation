//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define PACKET_COUNT 100

// For signal handling
#include <signal.h>

volatile sig_atomic_t running = 1;

void handle_sigint(int sig) {
    running = 0;
}

struct QoSPacket {
    int packetID;
    struct timeval timestamp;
    int responseTime; // in milliseconds
};

void printHeader() {
    printf("\n--- Network QoS Monitor ---\n");
    printf("ID\tTimestamp\t\tResponse Time (ms)\n");
    printf("-----------------------------------------------\n");
}

void simulateNetworkTest(struct QoSPacket *packets) {
    struct sockaddr_in serverAddr;
    int sock;
    
    // Configure server address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    inet_aton("127.0.0.1", &serverAddr.sin_addr);

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < PACKET_COUNT && running; i++) {
        char buffer[BUFFER_SIZE];
        gettimeofday(&packets[i].timestamp, NULL);
        packets[i].packetID = i;

        // Send a test packet
        sendto(sock, buffer, sizeof(buffer), 0, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
        
        // Start time measure
        struct timeval start, end;
        gettimeofday(&start, NULL);
        
        // Receive the echo response (simulate a block until we get a reply)
        recvfrom(sock, buffer, sizeof(buffer), 0, NULL, NULL);

        // End time measure
        gettimeofday(&end, NULL);
        packets[i].responseTime = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;

        // Print progress
        printf("Sent packet %d, Response Time: %d ms\n", packets[i].packetID, packets[i].responseTime);
        sleep(1); // Simulate waiting time between packets
    }

    close(sock);
}

void displayResults(struct QoSPacket *packets) {
    printHeader();
    for (int i = 0; i < PACKET_COUNT; i++) {
        printf("%d\t%ld.%06ld\t%d\n", packets[i].packetID,
               packets[i].timestamp.tv_sec, packets[i].timestamp.tv_usec,
               packets[i].responseTime);
    }
}

int main() {
    signal(SIGINT, handle_sigint);
    
    struct QoSPacket packets[PACKET_COUNT];
    
    printf("Initiating QoS Monitoring...\n");
    simulateNetworkTest(packets);
    
    printf("\nMonitoring Stopped.\n");
    displayResults(packets);
    
    return 0;
}