//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <server> <path>\n", argv[0]);
        return 1;
    }

    char *server = argv[1];
    int port = 80;
    char *path = argv[2];

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Socket creation failed");
        return 1;
    }

    // Get server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    int result = inet_pton(AF_INET, server, &server_addr.sin_addr);
    if (result == 0) {
        printf("Invalid address: %s\n", server);
        return 1;
    } else if (result == -1) {
        perror("Address conversion failed");
        return 1;
    }

    // Connect to server
    result = connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr));
    if (result == -1) {
        perror("Connection failed");
        return 1;
    }

    // Send GET request
    char request[BUFFER_SIZE];
    snprintf(request, BUFFER_SIZE, "GET %s HTTP/1.0\r\nHost: %s\r\n\r\n", path, server);
    result = send(sock, request, strlen(request), 0);
    if (result == -1) {
        perror("Send failed");
        return 1;
    }

    // Receive response
    char response[BUFFER_SIZE];
    int received = 0;
    while (received < BUFFER_SIZE - 1) {
        result = recv(sock, response + received, BUFFER_SIZE - 1 - received, 0);
        if (result == -1) {
            perror("Receive failed");
            return 1;
        } else if (result == 0) {
            break;
        }
        received += result;
    }
    response[received] = '\0';

    printf("Response:\n%s", response);

    // Cleanup
    close(sock);

    return 0;
}