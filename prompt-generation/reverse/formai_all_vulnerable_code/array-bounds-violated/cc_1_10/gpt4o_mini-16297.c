//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096
#define RESPONSE_SIZE 8192

// Function to perform HTTP GET request
void http_get(const char *hostname, const char *path) {
    struct sockaddr_in server_addr;
    struct hostent *host_info;
    int sock;
    char request[BUFFER_SIZE], response[RESPONSE_SIZE];
    
    // Resolve hostname to IP address
    host_info = gethostbyname(hostname);
    if (!host_info) {
        fprintf(stderr, "Could not resolve hostname: %s\n", hostname);
        exit(EXIT_FAILURE);
    }
    
    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }
    
    // Set up the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    memcpy(&server_addr.sin_addr, host_info->h_addr, host_info->h_length);
    
    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Could not connect to server");
        close(sock);
        exit(EXIT_FAILURE);
    }
    
    // Prepare the HTTP GET request
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);
    
    // Send the request to the server
    if (send(sock, request, strlen(request), 0) < 0) {
        perror("Could not send request");
        close(sock);
        exit(EXIT_FAILURE);
    }
    
    // Receive the response
    memset(response, 0, sizeof(response));
    int bytes_received = recv(sock, response, sizeof(response) - 1, 0);
    if (bytes_received < 0) {
        perror("Error in receiving response");
    } else {
        response[bytes_received] = '\0'; // Null-terminate the response
        printf("Response from server:\n%s\n", response);
    }
    
    // Close the socket
    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    const char *hostname = argv[1];
    const char *path = argv[2];

    // Perform the HTTP GET request
    http_get(hostname, path);

    return 0;
}