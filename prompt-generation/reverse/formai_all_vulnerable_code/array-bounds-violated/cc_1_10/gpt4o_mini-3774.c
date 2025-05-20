//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

// Define constants
#define SERVER "httpbin.org"
#define PORT 80
#define BUFFER_SIZE 1024

// Function declarations
void make_http_get_request(const char *url);

int main() {
    const char *url = "/get";
    make_http_get_request(url);
    return 0;
}

void make_http_get_request(const char *url) {
    int sock;
    struct sockaddr_in server_address;
    char request[BUFFER_SIZE], response[BUFFER_SIZE];

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Unable to create socket");
        exit(EXIT_FAILURE);
    }

    // Set up the server address struct
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    
    // Convert the server address from string to binary format
    if (inet_pton(AF_INET, "104.248.92.24", &server_address.sin_addr) <= 0) {
        perror("Invalid address/Address not supported");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Create HTTP GET request
    snprintf(request, sizeof(request),
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n\r\n", 
             url, SERVER);

    // Send the request to the server
    if (send(sock, request, strlen(request), 0) < 0) {
        perror("Failed to send request");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Read response from server
    ssize_t bytes_received;
    printf("Response:\n");
    while ((bytes_received = recv(sock, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_received] = '\0'; // Null terminate the string
        printf("%s", response);
    }

    if (bytes_received < 0) {
        perror("Error reading response");
    }

    // Close the socket
    close(sock);
}