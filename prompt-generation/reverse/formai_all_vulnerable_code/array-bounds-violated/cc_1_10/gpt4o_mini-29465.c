//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: future-proof
// udp_server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void start_server() {
    int sock_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    socklen_t addr_len = sizeof(client_addr);

    // Create socket
    if ((sock_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Zero out the server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    
    // Fill server information
    server_addr.sin_family = AF_INET; // IPv4
    server_addr.sin_addr.s_addr = INADDR_ANY; // Any IPv4 address
    server_addr.sin_port = htons(PORT); // Port

    // Bind the socket to the specified port and address
    if (bind(sock_fd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(sock_fd);
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("Server listening on port %d...\n", PORT);
        
        // Receive message from client
        int n = recvfrom(sock_fd, buffer, BUFFER_SIZE, MSG_WAITALL, (struct sockaddr *)&client_addr, &addr_len);
        buffer[n] = '\0'; // Null terminate the received string
        
        printf("Client: %s\n", buffer);
        
        // Send acknowledgment back to client
        char *ack = "Message received";
        sendto(sock_fd, ack, strlen(ack), MSG_CONFIRM, (const struct sockaddr *)&client_addr, addr_len);
    }

    close(sock_fd);
}

int main() {
    start_server();
    return 0;
}