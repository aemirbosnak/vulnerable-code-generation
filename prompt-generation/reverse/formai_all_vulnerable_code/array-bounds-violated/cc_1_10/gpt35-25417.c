//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 80
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    if (argc < 2) {
        printf("Usage: %s <host>\n", argv[0]);
        return 1;
    }

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Failed to create socket");
        return 1;
    }

    // Prepare structure for socket connection
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    if (inet_pton(AF_INET, argv[1], &server_address.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        return 1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        return 1;
    }
    
    // Send request to server
    char request[BUFFER_SIZE];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", argv[1]);
    if (send(sock, request, strlen(request), 0) < 0) {
        perror("Failed to send request");
        return 1;
    }

    // Receive response from server
    char buffer[BUFFER_SIZE];
    int total = 0;
    int received = 0;
    while ((received = recv(sock, buffer, BUFFER_SIZE-1, 0)) > 0) {
        buffer[received] = '\0';
        total += received;
        printf("%s", buffer);
    }
    printf("\n");

    // Close connection
    close(sock);

    return 0;
}