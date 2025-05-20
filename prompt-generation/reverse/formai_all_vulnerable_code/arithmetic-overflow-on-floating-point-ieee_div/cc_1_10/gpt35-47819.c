//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>

#define BUFFER_SIZE 10240

void speedTest(char* ipAddr, int portNumber) {
    int sock;
    struct sockaddr_in serverAddr;
    char buffer[BUFFER_SIZE];
    double totalTime;
    int sentBytes, receivedBytes;
    clock_t start, end;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1) {
        perror("Error creating socket!\n");
        exit(1);
    }

    // Initialize server address structure
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(portNumber);

    if(inet_pton(AF_INET, ipAddr, &serverAddr.sin_addr)<=0) {
        perror("Invalid IP address!\n");
        exit(1);
    }

    // Connect to server
    if(connect(sock, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Error connecting to server!\n");
        exit(1);
    }

    // Send data
    start = clock();
    sentBytes = send(sock, buffer, BUFFER_SIZE, 0);
    if(sentBytes == -1) {
        perror("Error sending data!\n");
        exit(1);
    }

    // Receive data
    receivedBytes = recv(sock, buffer, BUFFER_SIZE, 0);
    if(receivedBytes == -1) {
        perror("Error receiving data!\n");
        exit(1);
    }
    end = clock();

    // Close connection
    close(sock);

    // Calculate time taken for data to be sent and received
    totalTime = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Display result
    printf("\nSpeed Test Result:\n");
    printf("Server IP: %s\n", ipAddr);
    printf("Server Port: %d\n", portNumber);
    printf("Data Sent: %d bytes\n", sentBytes);
    printf("Data Received: %d bytes\n", receivedBytes);
    printf("Total Time: %f seconds\n", totalTime);
    printf("Data Transfer Rate: %f bytes/second\n", receivedBytes/totalTime);
}

int main(int argc, char* argv[]) {
    if(argc != 3) {
        printf("Usage: ./speedtest [Server IP Address] [Port Number]\n");
        exit(1);
    }

    char* ipAddr = argv[1];
    int portNumber = atoi(argv[2]);

    speedTest(ipAddr, portNumber);

    return 0;
}