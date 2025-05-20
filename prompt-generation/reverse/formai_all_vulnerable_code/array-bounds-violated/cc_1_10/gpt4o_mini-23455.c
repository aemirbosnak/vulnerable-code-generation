//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER "example.com"
#define PORT 80
#define BUFFER_SIZE 4096

void peaceful_http_get(const char *server, const char *path) {
    int sock;
    struct sockaddr_in server_addr;
    char request[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    int bytes_received;

    // Opening a socket in a calm environment
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setting up the peaceful connection
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(server);

    // Connecting to the serene server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Crafting a gentle HTTP GET request
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, server);

    // Sending the request to the server
    send(sock, request, strlen(request), 0);

    // Receiving a blissful response from the server
    printf("Response:\n");
    while ((bytes_received = recv(sock, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_received] = '\0';  // Null-terminate the received data
        printf("%s", response);
    }

    // Closing the socket, ending our joyful interaction
    close(sock);
}

int main() {
    const char *path = "/"; // peaceful path to the web page
  
    printf("Welcome to the Peaceful HTTP Client!\n");
    peaceful_http_get(SERVER, path);

    printf("\nThank you for using the Peaceful HTTP Client.\n");
    return 0;
}