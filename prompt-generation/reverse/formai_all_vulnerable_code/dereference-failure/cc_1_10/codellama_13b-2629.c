//Code Llama-13B DATASET v1.0 Category: Networking ; Style: Romeo and Juliet
/*
* RomeoAndJuliet.c
*
* A unique C Networking example program in a Romeo and Juliet style.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define PORT 8080

int main() {
    int sock, client, n;
    struct sockaddr_in server, client_addr;
    struct hostent *host;
    char buffer[256];

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind the socket to the server address
    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server started on port %d\n", PORT);

    // Accept incoming connections
    client = accept(sock, (struct sockaddr *)&client_addr, &n);
    if (client < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    // Get the hostname and IP address of the client
    host = gethostbyaddr((const char *)&client_addr.sin_addr, sizeof(client_addr.sin_addr), AF_INET);
    if (host == NULL) {
        perror("gethostbyaddr failed");
        exit(EXIT_FAILURE);
    }

    // Print the hostname and IP address of the client
    printf("Client connected: %s (%s)\n", host->h_name, inet_ntoa(client_addr.sin_addr));

    // Send the message to the client
    n = send(client, "Hello, Romeo!\n", 13, 0);
    if (n < 0) {
        perror("Send failed");
        exit(EXIT_FAILURE);
    }

    // Close the client socket
    close(client);

    // Close the server socket
    close(sock);

    return 0;
}