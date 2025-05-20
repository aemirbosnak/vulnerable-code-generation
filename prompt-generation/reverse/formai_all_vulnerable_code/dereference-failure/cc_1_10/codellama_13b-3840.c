//Code Llama-13B DATASET v1.0 Category: Networking ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <server_address> <server_port>\n", argv[0]);
        return 1;
    }

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Initialize server address structure
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send message to server
    char message[1024] = "Hello, server!";
    if (send(sock, message, strlen(message), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive message from server
    char buffer[1024];
    if (recv(sock, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        return 1;
    }

    // Print received message
    printf("Received message: %s\n", buffer);

    // Close socket
    close(sock);

    return 0;
}