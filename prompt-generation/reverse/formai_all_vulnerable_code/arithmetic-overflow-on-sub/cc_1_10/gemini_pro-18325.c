//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>

#define SERVER_IP "8.8.8.8"
#define SERVER_PORT 80
#define BUF_SIZE 1024

int main() {
    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_aton(SERVER_IP, &server_addr.sin_addr) == 0) {
        perror("Error converting IP address");
        exit(EXIT_FAILURE);
    }

    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    // Send a request to the server
    const char *request = "GET / HTTP/1.1\r\nHost: " SERVER_IP "\r\nConnection: close\r\n\r\n";
    if (send(sock, request, strlen(request), 0) < 0) {
        perror("Error sending request");
        exit(EXIT_FAILURE);
    }

    // Receive the response from the server
    char buf[BUF_SIZE];
    int bytes_received = 0;
    clock_t start = clock();
    while ((bytes_received = recv(sock, buf, BUF_SIZE, 0)) > 0) {
        clock_t end = clock();
        double elapsed_time = (double) (end - start) / CLOCKS_PER_SEC;
        printf("Received %d bytes in %.3f seconds\n", bytes_received, elapsed_time);
        start = end;
    }

    if (bytes_received < 0) {
        perror("Error receiving response");
        exit(EXIT_FAILURE);
    }

    // Close the socket
    close(sock);

    return 0;
}