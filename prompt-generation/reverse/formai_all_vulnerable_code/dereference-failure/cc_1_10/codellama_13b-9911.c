//Code Llama-13B DATASET v1.0 Category: Chat server ; Style: complete
/*
 * chat_server.c
 * A simple chat server in C
 *
 * Usage:
 *   ./chat_server <port>
 *
 * The server listens on the specified port and accepts connections.
 * Once a connection is established, the server sends a welcome message
 * to the client and waits for input. The server then sends the input
 * back to the client.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    int port = atoi(argv[1]);
    int sockfd, new_sockfd;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t cli_len = sizeof(cli_addr);
    char buffer[MAX_LINE];

    // Create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Set up the server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    // Bind the socket
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sockfd, 3) < 0) {
        perror("listen");
        exit(1);
    }

    printf("Chat server started on port %d\n", port);

    while (1) {
        // Accept incoming connection
        new_sockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &cli_len);
        if (new_sockfd < 0) {
            perror("accept");
            exit(1);
        }

        // Send welcome message
        printf("New connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
        snprintf(buffer, sizeof(buffer), "Welcome to the chat server!\n");
        send(new_sockfd, buffer, strlen(buffer), 0);

        // Receive and send messages
        while (1) {
            memset(buffer, 0, sizeof(buffer));
            if (recv(new_sockfd, buffer, MAX_LINE, 0) <= 0) {
                break;
            }
            send(new_sockfd, buffer, strlen(buffer), 0);
        }

        // Close connection
        close(new_sockfd);
    }

    // Close the socket
    close(sockfd);

    return 0;
}