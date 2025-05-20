//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len;
    char buffer[BUFFER_SIZE];
    int client_count = 0;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (client_count < MAX_CLIENTS) {
        int len = sizeof(client_addr);
        int n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&client_addr, &len);
        buffer[n] = '\0';

        // Broadcast the message to all clients
        printf("Received: %s\n", buffer);
        for (int i = 0; i < client_count; i++) {
            sendto(sockfd, buffer, n, 0, (const struct sockaddr *)&client_addr, len);
        }
        
        // Increment client_count (for simplicity, no actual tracking of clients)
        client_count++;
    }

    close(sockfd);
    return 0;
}