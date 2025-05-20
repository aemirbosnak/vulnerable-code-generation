//GEMINI-pro DATASET v1.0 Category: Networking ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_CLIENTS 10
#define MAX_MSG_SIZE 1024

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Bind the socket to an address
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(1234);
    addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        exit(1);
    }

    // Listen for connections
    if (listen(sockfd, MAX_CLIENTS) == -1) {
        perror("listen");
        exit(1);
    }

    // Accept connections
    int clientfds[MAX_CLIENTS];
    int num_clients = 0;
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int clientfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (clientfd == -1) {
            perror("accept");
            exit(1);
        }

        // Add the clientfd to the list of clientfds
        clientfds[num_clients++] = clientfd;

        // Send a welcome message to the client
        char *welcome_msg = "Welcome to the server!\n";
        if (send(clientfd, welcome_msg, strlen(welcome_msg), 0) == -1) {
            perror("send");
            exit(1);
        }
    }

    // Close the socket
    close(sockfd);

    return 0;
}