//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main() {
    int sockfd, newsockfd, portno;
    struct sockaddr_un serv_addr, cli_addr;
    socklen_t clilen;
    char buffer[BUFFER_SIZE];
    int n;
    int clients[MAX_CLIENTS];
    int num_clients = 0;

    // Create socket
    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Set up server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sun_family = AF_UNIX;
    strcpy(serv_addr.sun_path, "chat_server.sock");

    // Bind socket to address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sockfd, MAX_CLIENTS) < 0) {
        perror("Error listening for connections");
        exit(1);
    }

    // Accept incoming connections
    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("Error accepting connection");
            continue;
        }

        // Add new client to list of clients
        clients[num_clients] = newsockfd;
        num_clients++;

        // Fork a new process to handle the new client
        if (fork() == 0) {
            // Close the listening socket
            close(sockfd);

            // Handle the client
            while (1) {
                // Read message from client
                memset(buffer, 0, BUFFER_SIZE);
                n = read(newsockfd, buffer, BUFFER_SIZE);
                if (n <= 0) {
                    // Client has disconnected
                    close(newsockfd);
                    exit(0);
                }

                // Broadcast message to all other clients
                for (int i = 0; i < num_clients; i++) {
                    if (clients[i] != newsockfd) {
                        write(clients[i], buffer, n);
                    }
                }
            }
        }
    }

    return 0;
}