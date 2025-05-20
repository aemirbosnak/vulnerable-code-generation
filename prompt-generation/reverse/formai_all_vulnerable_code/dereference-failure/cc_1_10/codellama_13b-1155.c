//Code Llama-13B DATASET v1.0 Category: Socket programming ; Style: light-weight
/*
 * socket_example.c
 *
 * A simple example of a lightweight C program that uses sockets
 * to communicate between two processes.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char *argv[]) {
    int sockfd, new_fd;
    struct sockaddr_in server, client;
    socklen_t client_len = sizeof(client);
    char buffer[256];

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    // Set up the server address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(PORT);

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *)&server, sizeof(server)) == -1) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sockfd, 3) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Server listening on port %d\n", PORT);

    // Accept an incoming connection
    new_fd = accept(sockfd, (struct sockaddr *)&client, &client_len);
    if (new_fd == -1) {
        perror("accept");
        exit(1);
    }

    printf("Connection accepted\n");

    // Send and receive data
    sprintf(buffer, "Hello, client!");
    send(new_fd, buffer, strlen(buffer), 0);
    recv(new_fd, buffer, 256, 0);
    printf("Received: %s\n", buffer);

    // Close the connection
    close(new_fd);

    return 0;
}