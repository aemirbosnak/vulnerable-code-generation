//Code Llama-13B DATASET v1.0 Category: Network Ping Test ; Style: dynamic
// Network Ping Test Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd, n;
    char recvBuff[1024];
    struct sockaddr_in serverAddr;
    struct hostent *server;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP address> <port>\n", argv[0]);
        return 1;
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation error");
        return 1;
    }

    // Fill in the server's address
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(atoi(argv[2]));
    serverAddr.sin_addr.s_addr = inet_addr(argv[1]);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Connection error");
        return 1;
    }

    // Send a message to the server
    n = send(sockfd, "Hello", strlen("Hello"), 0);
    if (n < 0) {
        perror("Send error");
        return 1;
    }

    // Receive the response from the server
    n = recv(sockfd, recvBuff, sizeof(recvBuff), 0);
    if (n < 0) {
        perror("Receive error");
        return 1;
    }

    // Print the response
    printf("Response: %s\n", recvBuff);

    // Close the socket
    close(sockfd);

    return 0;
}