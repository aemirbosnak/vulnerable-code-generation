//Code Llama-13B DATASET v1.0 Category: Client Server Application ; Style: future-proof
// Client.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // Check arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_ip> <message>\n", argv[0]);
        return 1;
    }

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket() failed");
        return 1;
    }

    // Setup address struct
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = inet_addr(argv[1]);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect() failed");
        return 1;
    }

    // Send message to server
    char *message = argv[2];
    if (send(sock, message, strlen(message), 0) < 0) {
        perror("send() failed");
        return 1;
    }

    // Receive message from server
    char buffer[BUFFER_SIZE];
    if (recv(sock, buffer, BUFFER_SIZE, 0) < 0) {
        perror("recv() failed");
        return 1;
    }

    // Print received message
    printf("Received message from server: %s\n", buffer);

    // Close socket
    close(sock);

    return 0;
}