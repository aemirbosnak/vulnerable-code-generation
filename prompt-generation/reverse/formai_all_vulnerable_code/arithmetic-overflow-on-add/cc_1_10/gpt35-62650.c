//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: %s [ip address]\n", argv[0]);
        return -1;
    }

    char *ip_address = argv[1];
    int port = 80;
    char http_request[BUFFER_SIZE];

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Failed to create socket");
        return -1;
    }

    // Set up the server address structure
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    if(inet_pton(AF_INET, ip_address, &serv_addr.sin_addr) <= 0) {
        perror("Failed to convert IP address to binary");
        close(sockfd);
        return -1;
    }

    // Connect to the server
    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Failed to connect to server");
        close(sockfd);
        return -1;
    }

    // Send an HTTP GET request to the server
    snprintf(http_request, BUFFER_SIZE, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", ip_address);
    if(send(sockfd, http_request, strlen(http_request), 0) < 0) {
        perror("Failed to send HTTP request");
        close(sockfd);
        return -1;
    }

    // Receive the response from the server
    char buffer[BUFFER_SIZE];
    int total_bytes_received = 0;
    int bytes_received = 0;
    while((bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        total_bytes_received += bytes_received;
    }
    if(bytes_received < 0) {
        perror("Failed to receive data from server");
        close(sockfd);
        return -1;
    }

    printf("Received %d bytes from server\n", total_bytes_received);

    // Close the socket
    close(sockfd);

    return 0;
}