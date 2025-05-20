//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void setupServer(struct sockaddr_in *server_addr) {
    // Create socket
    int opt = 1;
    int server_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (server_fd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("Set socket options failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address struct
    server_addr->sin_family = AF_INET;
    server_addr->sin_addr.s_addr = INADDR_ANY;
    server_addr->sin_port = htons(PORT);
    
    // Bind the server socket to the port
    if (bind(server_fd, (struct sockaddr*)server_addr, sizeof(*server_addr)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    printf("Firewall listening on port %d...\n", PORT);
}

void processPacket(int server_fd) {
    struct sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];

    // Infinite loop to listen for incoming packets
    while (1) {
        int n = recvfrom(server_fd, buffer, BUFFER_SIZE, 0, (struct sockaddr*)&client_addr, &addr_len);
        if (n < 0) {
            perror("Receive failed");
            continue;
        }

        // Null terminate the received data to safely print it
        buffer[n] = '\0';

        // Detect packet source
        char *client_ip = inet_ntoa(client_addr.sin_addr);
        printf("Received packet from %s: %s\n", client_ip, buffer);

        // Simple filtering: block packets containing the word "BLOCK"
        if (strstr(buffer, "BLOCK") != NULL) {
            printf("Blocking packet from %s\n", client_ip);
            continue;
        }

        // Echo the packet back to the client
        sendto(server_fd, buffer, n, 0, (struct sockaddr*)&client_addr, addr_len);
        printf("Echoing packet to %s\n", client_ip);
    }
}

int main() {
    struct sockaddr_in server_addr;
    setupServer(&server_addr);

    // Start processing packets
    int server_fd = socket(AF_INET, SOCK_DGRAM, 0);
    processPacket(server_fd);

    // Close the socket
    close(server_fd);
    return 0;
}