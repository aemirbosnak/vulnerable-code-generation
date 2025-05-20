//Code Llama-13B DATASET v1.0 Category: Chat server ; Style: realistic
/*
 * chat_server.c
 *
 * A simple chat server program that allows multiple clients to connect and communicate with each other.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_MESSAGE_LENGTH 1024
#define MAX_CLIENTS 10

int main(int argc, char *argv[]) {
    int sockfd, new_sockfd, portno;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char message[MAX_MESSAGE_LENGTH];
    int n;

    // Check if the port number was specified as a command-line argument
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    // Convert the port number to an integer
    portno = atoi(argv[1]);

    // Create a socket for the server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return 1;
    }

    // Set up the server address structure
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(portno);

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        return 1;
    }

    // Listen for incoming connections
    if (listen(sockfd, MAX_CLIENTS) < 0) {
        perror("Error listening for connections");
        return 1;
    }

    printf("Chat server listening on port %d...\n", portno);

    // Accept incoming connections
    while (1) {
        new_sockfd = accept(sockfd, (struct sockaddr *) &client_addr, &client_len);
        if (new_sockfd < 0) {
            perror("Error accepting connection");
            return 1;
        }

        // Receive messages from the client
        while (1) {
            n = recv(new_sockfd, message, MAX_MESSAGE_LENGTH, 0);
            if (n < 0) {
                perror("Error receiving message");
                return 1;
            }

            // Send the message to all other clients
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (i != new_sockfd) {
                    send(i, message, n, 0);
                }
            }
        }

        // Close the socket
        close(new_sockfd);
    }

    return 0;
}