//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: detailed
// This program demonstrates how to build a basic HTTP client in C language using sockets

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sock, bytes, status;
    char buffer[1024];
    struct sockaddr_in serverAddress;
    
    // Check for command line arguments
    if (argc != 3) {
        printf("Usage: %s <server> <request>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }
    
    // Set server address details
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr(argv[1]);
    serverAddress.sin_port = htons(80);
    
    // Connect to the server
    status = connect(sock, (struct sockaddr *) &serverAddress, sizeof(serverAddress));
    if (status == -1) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    // Send HTTP request to server
    char request[512];
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", argv[2], argv[1]);
    status = send(sock, request, strlen(request), 0);
    if (status == -1) {
        perror("Error sending request to server");
        exit(EXIT_FAILURE);
    }

    // Receive HTTP response from server
    int totalBytes = 0;
    while ((bytes = recv(sock, buffer, 1024, 0)) > 0) {
        totalBytes += bytes;
        buffer[bytes] = '\0';
        printf("%s", buffer);
    }
    
    // Close the socket
    close(sock);
    
    return 0;
}