//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 8080
#define MAX_CLIENTS 10

struct client_info {
    int sockfd;
    struct sockaddr_in addr;
    char *name;
};

int main(void) {
    int serverfd, clientfd;
    struct sockaddr_in serveraddr, clientaddr;
    socklen_t addrlen;
    char buffer[1024];
    int n, i;
    struct client_info clients[MAX_CLIENTS];
    int num_clients = 0;

    // Create the server socket
    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set the server address
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = INADDR_ANY;
    serveraddr.sin_port = htons(SERVER_PORT);

    // Bind the server socket to the address
    if (bind(serverfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(serverfd, MAX_CLIENTS) < 0) {
        perror("listen");
        return EXIT_FAILURE;
    }

    // Main loop
    while (1) {
        // Accept incoming connections
        addrlen = sizeof(clientaddr);
        clientfd = accept(serverfd, (struct sockaddr *)&clientaddr, &addrlen);
        if (clientfd < 0) {
            perror("accept");
            continue;
        }

        // Add the new client to the list of clients
        clients[num_clients].sockfd = clientfd;
        clients[num_clients].addr = clientaddr;
        clients[num_clients].name = malloc(1024);
        strcpy(clients[num_clients].name, inet_ntoa(clientaddr.sin_addr));
        num_clients++;

        // Send a welcome message to the new client
        snprintf(buffer, sizeof(buffer), "Welcome to the chat server, %s!\n", clients[num_clients].name);
        send(clientfd, buffer, strlen(buffer), 0);

        // Broadcast the new client's name to all other clients
        for (i = 0; i < num_clients; i++) {
            if (clients[i].sockfd != clientfd) {
                snprintf(buffer, sizeof(buffer), "%s has joined the chat.\n", clients[num_clients].name);
                send(clients[i].sockfd, buffer, strlen(buffer), 0);
            }
        }

        // Main loop for the new client
        while (1) {
            // Receive a message from the client
            n = recv(clientfd, buffer, sizeof(buffer), 0);
            if (n < 0) {
                perror("recv");
                break;
            } else if (n == 0) {
                // Client disconnected
                break;
            }

            // Broadcast the message to all other clients
            for (i = 0; i < num_clients; i++) {
                if (clients[i].sockfd != clientfd) {
                    send(clients[i].sockfd, buffer, n, 0);
                }
            }
        }

        // Remove the client from the list of clients
        for (i = 0; i < num_clients; i++) {
            if (clients[i].sockfd == clientfd) {
                free(clients[i].name);
                clients[i] = clients[num_clients - 1];
                num_clients--;
                break;
            }
        }

        // Broadcast the client's departure to all other clients
        for (i = 0; i < num_clients; i++) {
            snprintf(buffer, sizeof(buffer), "%s has left the chat.\n", clients[i].name);
            send(clients[i].sockfd, buffer, strlen(buffer), 0);
        }
    }

    // Close the server socket
    close(serverfd);

    return EXIT_SUCCESS;
}