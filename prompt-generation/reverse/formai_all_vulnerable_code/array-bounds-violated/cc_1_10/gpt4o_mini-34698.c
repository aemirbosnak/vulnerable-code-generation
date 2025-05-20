//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUF_SIZE 1024

int client_count = 0;
struct sockaddr_in clients[MAX_CLIENTS];

void *broadcast_messages(void *arg) {
    int sockfd = *(int *)arg;
    char buffer[BUF_SIZE];

    while (1) {
        // Receive message from any client
        struct sockaddr_in cli_addr;
        socklen_t cli_len = sizeof(cli_addr);
        int n = recvfrom(sockfd, buffer, BUF_SIZE, 0, (struct sockaddr *)&cli_addr, &cli_len);
        buffer[n] = '\0';

        // Send the received message to all clients
        for (int i = 0; i < client_count; i++) {
            sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&clients[i], sizeof(clients[i]));
        }
    }
    return NULL;
}

void add_client(struct sockaddr_in cli_addr) {
    if (client_count < MAX_CLIENTS) {
        clients[client_count++] = cli_addr;
        printf("Client added: %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
    } else {
        printf("Max clients reached! Could not add: %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
    }
}

int main() {
    int sockfd;
    struct sockaddr_in serv_addr;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Bind socket to the port
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (const struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Broadcast server started on port %d\n", PORT);

    // Start broadcasting thread
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, broadcast_messages, (void *)&sockfd);

    // Main loop: wait for clients to send messages
    while (1) {
        struct sockaddr_in cli_addr;
        socklen_t cli_len = sizeof(cli_addr);
        char buffer[BUF_SIZE];

        // Receive message from any client
        int n = recvfrom(sockfd, buffer, BUF_SIZE, 0, (struct sockaddr *)&cli_addr, &cli_len);
        buffer[n] = '\0';

        // Add client to the list
        add_client(cli_addr);

        printf("Received message: %s from %s:%d\n", buffer, inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
    }

    // Cleanup (this code will never be reached but can be useful for future expansions)
    close(sockfd);
    pthread_exit(NULL);
}