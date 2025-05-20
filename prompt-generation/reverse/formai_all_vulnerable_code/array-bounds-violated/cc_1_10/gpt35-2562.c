//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char *server_address = "127.0.0.1";
    char *server_port = "8000";
    char *request = "GET / HTTP/1.1\r\nHost: localhost:8000\r\nConnection: close\r\n\r\n";
    char buffer[BUFFER_SIZE];
    int socket_fd, bytes_received;

    struct sockaddr_in server_addr;

    // Create socket
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(server_port));

    if (inet_pton(AF_INET, server_address, &server_addr.sin_addr) == -1) {
        perror("inet_pton failed");
        exit(1);
    }

    // Connect to server
    if (connect(socket_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1) {
        perror("Connection failed");
        exit(1);
    }

    // Send request
    if (send(socket_fd, request, strlen(request), 0) == -1) {
        perror("Send failed");
        exit(1);
    }

    // Receive response
    while ((bytes_received = recv(socket_fd, buffer, BUFFER_SIZE-1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    // Close socket
    close(socket_fd);

    return 0;
}