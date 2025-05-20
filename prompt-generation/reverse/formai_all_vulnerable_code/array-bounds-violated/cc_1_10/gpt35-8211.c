//FormAI DATASET v1.0 Category: Socket programming ; Style: ultraprecise
// A simple C Socket Programming Example

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[1024];
    int port = 8888;
    const char* ip_addr = "127.0.0.1";
    
    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    } else {
        printf("Socket created successfully!\n");
    }
    
    // Set the socket address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip_addr);
    
    // Connect to the server
    if (connect(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        printf("Connection error\n");
        exit(1);
    } else {
        printf("Connected to server!\n");
    }
    
    // Send data to the server
    const char* message = "Hello, server!";
    if (send(sockfd, message, strlen(message), 0) < 0) {
        printf("Error sending message\n");
        exit(1);
    } else {
        printf("Message sent to server!\n");
    }
    
    // Receive data from the server
    int num_bytes = recv(sockfd, buffer, 1024, 0);
    if (num_bytes < 0) {
        printf("Error receiving data\n");
        exit(1);
    } else {
        buffer[num_bytes] = '\0';
        printf("Received from server: %s\n", buffer);
    }
    
    // Close the socket
    close(sockfd);
    
    return 0;
}