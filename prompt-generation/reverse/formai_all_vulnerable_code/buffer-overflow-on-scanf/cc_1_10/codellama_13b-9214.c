//Code Llama-13B DATASET v1.0 Category: Client Server Application ; Style: authentic
// Client-Server Application Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

// Client Function
void client() {
    int sockfd, n;
    char buffer[256];
    struct sockaddr_in server;

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Filling server information
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);

    // Connecting to server
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // Sending message to server
    char *message = "Hello, Server!";
    send(sockfd, message, strlen(message), 0);

    // Receiving message from server
    n = recv(sockfd, buffer, 256, 0);
    printf("Received: %s\n", buffer);

    // Closing socket file descriptor
    close(sockfd);
}

// Server Function
void server() {
    int sockfd, new_sockfd, n;
    char buffer[256];
    struct sockaddr_in server, client;
    socklen_t client_len = sizeof(client);

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Filling server information
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);

    // Binding socket with server address
    if (bind(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening to incoming connections
    listen(sockfd, 3);

    // Accepting incoming connections
    if ((new_sockfd = accept(sockfd, (struct sockaddr *)&client, &client_len)) < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    // Receiving message from client
    n = recv(new_sockfd, buffer, 256, 0);
    printf("Received: %s\n", buffer);

    // Sending message to client
    char *message = "Hello, Client!";
    send(new_sockfd, message, strlen(message), 0);

    // Closing socket file descriptors
    close(new_sockfd);
    close(sockfd);
}

// Main Function
int main() {
    int choice;

    printf("Enter 1 for client and 2 for server: ");
    scanf("%d", &choice);

    if (choice == 1) {
        client();
    } else if (choice == 2) {
        server();
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}