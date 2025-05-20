//FormAI DATASET v1.0 Category: Networking ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 12345
#define BUFFER_SIZE 1024

int main() {
    printf("Welcome to the immersive C Networking Example Program!\n");
    
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        perror("Failed to create socket");
        exit(1);
    }
    printf("Socket created successfully\n");

    // Bind the socket to a port
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    memset(&(server_addr.sin_zero), '\0', 8);

    if(bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Failed to bind socket");
        exit(1);
    }
    printf("Socket bound to port %d successfully\n", PORT);

    // Listen for incoming connections
    if(listen(sockfd, 10) == -1) {
        perror("Failed to listen for incoming connections");
        exit(1);
    }
    printf("Listening for incoming connections...\n");

    // Accept incoming connections
    struct sockaddr_in client_addr;
    socklen_t client_size = sizeof(client_addr);

    int client_sockfd = accept(sockfd, (struct sockaddr*)&client_addr, &client_size);
    if(client_sockfd == -1) {
        perror("Failed to accept incoming connection");
        exit(1);
    }
    printf("Accepted incoming connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // Receive data from the client
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(client_sockfd, buffer, BUFFER_SIZE-1, 0);
    if(bytes_received == -1) {
        perror("Failed to receive data from client");
        exit(1);
    }
    buffer[bytes_received] = '\0';
    printf("Received data from client: %s\n", buffer);

    // Send a response to the client
    char response[] = "Thanks for connecting!";
    int bytes_sent = send(client_sockfd, response, strlen(response), 0);
    if(bytes_sent == -1) {
        perror("Failed to send response to client");
        exit(1);
    }
    printf("Sent response to client: %s\n", response);

    // Close the sockets and exit
    close(client_sockfd);
    close(sockfd);
    printf("Program completed successfully\n");
    return 0;
}