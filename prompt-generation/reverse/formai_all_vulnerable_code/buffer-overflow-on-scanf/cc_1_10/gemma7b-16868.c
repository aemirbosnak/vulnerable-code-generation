//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define MAX_PINGS 5

int main() {

    // Initialize variables
    char hostname[256];
    int port = 53;
    int numPings = 0;
    double avgTime = 0.0;
    struct sockaddr_in serverAddr;
    int sockfd;
    struct ping_packet {
        unsigned char data[1024];
        unsigned int seqNum;
    } pingPacket;

    // Get the hostname from the user
    printf("Enter the hostname: ");
    scanf("%s", hostname);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, htons(port));

    // Connect to the server
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = inet_addr(hostname);
    connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

    // Send and receive ping packets
    for (numPings = 0; numPings < MAX_PINGS; numPings++) {
        // Send a ping packet
        pingPacket.seqNum = numPings;
        send(sockfd, &pingPacket, sizeof(pingPacket), 0);

        // Receive a ping packet
        recv(sockfd, &pingPacket, sizeof(pingPacket), 0);

        // Calculate the time taken for the ping
        double timeTaken = (double)pingPacket.seqNum * 0.001;

        // Add the time taken to the average time
        avgTime += timeTaken;
    }

    // Calculate the average time taken
    avgTime /= MAX_PINGS;

    // Print the average time taken
    printf("The average time taken for the ping is: %.2f milliseconds\n", avgTime);

    // Close the socket
    close(sockfd);

    return 0;
}