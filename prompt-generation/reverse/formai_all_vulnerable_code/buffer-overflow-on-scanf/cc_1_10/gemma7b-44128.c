//Gemma-7B DATASET v1.0 Category: Chat server ; Style: curious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_CLIENTS 10

typedef struct Client {
    char name[20];
    int socketfd;
    struct Client *next;
} Client;

Client *clients = NULL;

void handleClient(int sockfd) {
    Client *client = malloc(sizeof(Client));
    client->socketfd = sockfd;

    // Get client name
    char name[20];
    printf("Enter your name: ");
    scanf("%s", name);
    strcpy(client->name, name);

    // Add client to list
    client->next = clients;
    clients = client;

    // Client loop
    while (1) {
        char message[200];

        // Get client message
        printf("Enter your message: ");
        scanf("%s", message);

        // Broadcast message to other clients
        for (Client *c = clients; c; c = c->next) {
            if (c->socketfd != sockfd) {
                send(c->socketfd, message, sizeof(message), 0);
            }
        }

        // Check if client wants to leave
        printf("Do you want to leave? (Y/N): ");
        char leave[10];
        scanf("%s", leave);

        if (strcmp(leave, "Y") == 0) {
            break;
        }
    }

    // Remove client from list
    Client *prev = NULL;
    for (Client *c = clients; c; c = c->next) {
        if (c->socketfd == sockfd) {
            if (prev) {
                prev->next = c->next;
            } else {
                clients = c->next;
            }
            free(c);
            break;
        }
        prev = c;
    }

    // Close client socket
    close(sockfd);
    free(client);
}

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, htons(65535));

    // Bind the socket to a port
    struct sockaddr_in sockaddr;
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(8888);
    bind(sockfd, (struct sockaddr *)&sockaddr, sizeof(sockaddr));

    // Listen for clients
    int clientfd;
    while ((clientfd = accept(sockfd, NULL, NULL)) != -1) {
        handleClient(clientfd);
    }

    return 0;
}