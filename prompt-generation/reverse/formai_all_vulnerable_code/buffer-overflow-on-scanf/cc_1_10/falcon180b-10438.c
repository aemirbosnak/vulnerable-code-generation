//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BACKLOG 10

// Function to create socket
int create_socket(int port) {
    int sockfd;
    struct sockaddr_in serv_addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    printf("Socket created\n");

    // Set port number
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    // Bind socket to port
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error binding socket\n");
        exit(1);
    }

    printf("Socket bound to port %d\n", port);

    return sockfd;
}

// Function to listen on socket
int listen_socket(int sockfd) {
    if (listen(sockfd, BACKLOG) < 0) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Socket listening\n");

    return sockfd;
}

// Function to accept connection on socket
int accept_socket(int sockfd) {
    int newsockfd;
    struct sockaddr_in cli_addr;
    socklen_t clilen;

    // Accept connection
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);

    if (newsockfd < 0) {
        printf("Error accepting connection\n");
        exit(1);
    }

    printf("Connection accepted\n");

    return newsockfd;
}

// Function to send data over socket
int send_data(int sockfd, char *message) {
    int sent;

    sent = send(sockfd, message, strlen(message), 0);

    if (sent < 0) {
        printf("Error sending data\n");
        exit(1);
    }

    printf("Data sent successfully\n");

    return sent;
}

// Function to receive data over socket
int receive_data(int sockfd, char *buffer, int bufsize) {
    int received;

    received = recv(sockfd, buffer, bufsize, 0);

    if (received < 0) {
        printf("Error receiving data\n");
        exit(1);
    }

    printf("Data received: %s\n", buffer);

    return received;
}

int main() {
    int sockfd, newsockfd, port;
    struct sockaddr_in cli_addr, serv_addr;
    char buffer[1024];

    printf("Enter port number: ");
    scanf("%d", &port);

    sockfd = create_socket(port);

    listen_socket(sockfd);

    cli_addr.sin_family = AF_INET;
    cli_addr.sin_addr.s_addr = INADDR_ANY;
    cli_addr.sin_port = htons(port);

    newsockfd = accept_socket(sockfd);

    send_data(newsockfd, "Welcome to the server!");

    receive_data(newsockfd, buffer, sizeof(buffer));

    printf("Message received: %s\n", buffer);

    close(newsockfd);
    close(sockfd);

    return 0;
}