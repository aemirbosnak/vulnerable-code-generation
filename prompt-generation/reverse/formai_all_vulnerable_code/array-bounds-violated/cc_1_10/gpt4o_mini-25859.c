//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    
    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // Fill server information
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    // Bind the socket with the server address
    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    
    printf("Server is listening on port %d...\n", PORT);
    
    while (1) {
        // Receive ping request
        int n = recvfrom(sockfd, buffer, BUFFER_SIZE, MSG_WAITALL, 
                         (struct sockaddr *)&client_addr, &addr_len);
        buffer[n] = '\0';
        
        printf("Received ping from client: %s\n", buffer);
        
        // Send back the response
        sendto(sockfd, buffer, n, MSG_CONFIRM, 
               (const struct sockaddr *)&client_addr, addr_len);
        
        printf("Ping response sent to client.\n");
    }
    
    close(sockfd);
    return 0;
}