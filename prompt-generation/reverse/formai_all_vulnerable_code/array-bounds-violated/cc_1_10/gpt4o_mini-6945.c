//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: happy
// Server code: happy_server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 12345
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Create socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed!");
        return 1;
    }

    // Prepare the sockaddr_in structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET; 
    server_addr.sin_addr.s_addr = INADDR_ANY; 
    server_addr.sin_port = htons(PORT);
    
    // Bind the socket
    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed!");
        return 1;
    }

    printf("🌞 Happy Server is running on port %d! 🎉\n", PORT);

    while (1) {
        // Receive a message from the client
        int n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *) &client_addr, &addr_len);
        buffer[n] = '\0';
        printf("📬 Received from client: %s\n", buffer);

        // Send a greeting back to the client
        char message[BUFFER_SIZE];
        snprintf(message, sizeof(message), "Hello, %s! Welcome to our happy server! 😊", buffer);
        sendto(sockfd, message, strlen(message), 0, (struct sockaddr *) &client_addr, addr_len);
    }

    close(sockfd);
    return 0;
}