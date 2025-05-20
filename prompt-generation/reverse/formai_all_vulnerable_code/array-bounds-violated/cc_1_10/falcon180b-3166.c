//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, master_socket, client_socket[MAX_CLIENTS];
    int opt = 1, addrlen;
    struct sockaddr_in server_addr, client_addr[MAX_CLIENTS];
    char buffer[BUFFER_SIZE];
    int num_clients = 0;

    srand(time(NULL));

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set options on the socket
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        printf("Error setting options on socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding socket\n");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sockfd, MAX_CLIENTS) < 0) {
        printf("Error listening on socket\n");
        exit(1);
    }

    while (1) {
        // Accept a new connection
        addrlen = sizeof(struct sockaddr_in);
        newsockfd = accept(sockfd, (struct sockaddr *)&client_addr[num_clients], &addrlen);
        if (newsockfd < 0) {
            printf("Error accepting new connection\n");
            exit(1);
        }

        // Add the new socket to the master list
        client_socket[num_clients] = newsockfd;
        num_clients++;

        // Send welcome message to new client
        sprintf(buffer, "Welcome to the Bingo Simulator!\n");
        send(newsockfd, buffer, strlen(buffer), 0);

        // Notify all clients of the new player
        for (int i = 0; i < num_clients - 1; i++) {
            send(client_socket[i], "New player connected!\n", strlen("New player connected!\n"), 0);
        }
    }

    return 0;
}