//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

// Function to send data over the socket connection
void send_data(int sockfd, const char* data) {
    int bytes_sent = send(sockfd, data, strlen(data), 0);
    if (bytes_sent < 0) {
        perror("send() failed");
        exit(EXIT_FAILURE);
    }
}

// Function to receive data from the socket connection
char* receive_data(int sockfd) {
    int bytes_recv = recv(sockfd, NULL, 0, 0);
    if (bytes_recv < 0) {
        perror("recv() failed");
        exit(EXIT_FAILURE);
    }
    char* buffer = malloc(bytes_recv + 1);
    memset(buffer, 0, bytes_recv + 1);
    bytes_recv = recv(sockfd, buffer, bytes_recv, 0);
    if (bytes_recv < 0) {
        perror("recv() failed");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_recv] = '\0';
    return buffer;
}

// Main function to establish a TCP connection and send/receive data
int main() {
    int sockfd, newsockfd;
    struct sockaddr_in server_addr;
    char* buffer = "Hello, server!";

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect() failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server!\n");

    // Send data to the server
    send_data(sockfd, buffer);

    // Receive data from the server
    char* received_data = receive_data(sockfd);
    printf("Received data from server: %s\n", received_data);

    // Close the socket connection
    close(sockfd);

    return 0;
}