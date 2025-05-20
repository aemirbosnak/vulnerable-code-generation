//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 4096
#define MAX_URL_LENGTH 2048

// Function to establish a connection to the server
int establish_connection(const char *url) {
    int sock;
    struct sockaddr_in server_addr;

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // Prepare the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, url, &server_addr.sin_addr) <= 0) {
        perror("Invalid address or Address not supported");
        exit(EXIT_FAILURE);
    }

    // Attempt to connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    return sock;
}

// Function to send HTTP request
void send_http_request(int sock, const char *url) {
    char request[BUFFER_SIZE];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", url);

    // Send the request
    send(sock, request, strlen(request), 0);
}

// Function to receive HTTP response
void receive_http_response(int sock) {
    char buffer[BUFFER_SIZE];
    int bytesReceived;

    // Receive data until the connection is closed
    while ((bytesReceived = recv(sock, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytesReceived] = '\0'; // Null-terminate the buffer
        printf("%s", buffer); // Print the response to console
    }

    // Check for errors during receiving
    if (bytesReceived < 0) {
        perror("Receive failed");
    }
}

// Main function handling post-apocalyptic HTTP client logic
int main() {
    char url[MAX_URL_LENGTH];

    // A relic of civilization, a tool to retrieve remnants of information
    printf("In this wasteland where data is scant,\n");
    printf("The remnants of the web still lie dormant.\n");
    printf("Enter an IP address of the archive (or domain): ");
    fgets(url, sizeof(url), stdin);
    url[strcspn(url, "\n")] = 0; // Remove newline character

    int sock = establish_connection(url);
    send_http_request(sock, url);
    receive_http_response(sock);

    // Clean up and closure
    close(sock);
    printf("\nThe journey through the web has ended.\n");
    return 0;
}