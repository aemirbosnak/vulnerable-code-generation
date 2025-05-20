//Code Llama-13B DATASET v1.0 Category: Chat server ; Style: real-life
/*
 * chat_server.c
 *
 * A simple chat server example in C.
 *
 * Usage: ./chat_server <port>
 *
 * Author: [Your Name]
 * Date: [Current Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock, new_sock;
    struct sockaddr_in server, client;
    socklen_t client_len = sizeof(client);
    char buffer[BUFFER_SIZE];
    char message[BUFFER_SIZE];

    // Check if port is specified
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Set server address
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(atoi(argv[1]));

    // Bind socket to address
    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind");
        return 1;
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("listen");
        return 1;
    }

    printf("Chat server listening on port %s\n", argv[1]);

    while (1) {
        // Accept incoming connection
        new_sock = accept(sock, (struct sockaddr *)&client, &client_len);
        if (new_sock < 0) {
            perror("accept");
            return 1;
        }

        printf("New connection from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

        // Receive message from client
        if (recv(new_sock, buffer, BUFFER_SIZE, 0) < 0) {
            perror("recv");
            return 1;
        }

        // Print received message
        printf("Received message from client: %s\n", buffer);

        // Send message back to client
        sprintf(message, "Message received: %s", buffer);
        if (send(new_sock, message, strlen(message), 0) < 0) {
            perror("send");
            return 1;
        }

        // Close socket
        close(new_sock);
    }

    return 0;
}