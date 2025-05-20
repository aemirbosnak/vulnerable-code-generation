//Gemma-7B DATASET v1.0 Category: File Synchronizer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/wait.h>

#define SERVER_PORT 8080
#define MAX_CLIENT_CONN 10

struct ClientData {
    char name[20];
    int socketfd;
    struct ClientData* next;
};

void handleClient(int sockfd) {
    struct ClientData* client = malloc(sizeof(struct ClientData));
    client->socketfd = sockfd;
    sprintf(client->name, "Client %d", sockfd);
    client->next = NULL;

    // Send and receive messages
    char message[1024];
    while (1) {
        printf("Enter message: ");
        scanf("%s", message);

        send(sockfd, message, sizeof(message), 0);

        recv(sockfd, message, sizeof(message), 0);

        printf("Received message: %s\n", message);

        if (strcmp(message, "exit") == 0) {
            break;
        }
    }

    // Free client data
    free(client);
}

int main() {
    int sockfd, client_sockfd, new_sockfd;
    struct ClientData* head = NULL;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Listen for clients
    while (1) {
        client_sockfd = accept(sockfd, NULL, NULL);
        if (client_sockfd < 0) {
            perror("Error accepting client");
            continue;
        }

        // Handle client
        handleClient(client_sockfd);

        // Close client socket
        close(client_sockfd);
    }

    return 0;
}