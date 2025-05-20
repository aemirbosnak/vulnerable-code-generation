//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SERVER_IP "93.184.216.34" // Example.com
#define SERVER_PORT 80
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void http_get_request(const char *url) {
    int sockfd;
    struct sockaddr_in server_addr;
    char send_buffer[BUFFER_SIZE], receive_buffer[BUFFER_SIZE];
    int bytes_received;

    // Create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("Error opening socket");

    // Set up the server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    
    // Convert IP address from text to binary form
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) 
        error("Invalid address/ Address not supported");

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) 
        error("Connection failed");

    // Prepare the HTTP GET request
    snprintf(send_buffer, sizeof(send_buffer), "GET / HTTP/1.1\r\n"
                                               "Host: %s\r\n"
                                               "Connection: close\r\n\r\n", SERVER_IP);
    
    // Send the request
    if (send(sockfd, send_buffer, strlen(send_buffer), 0) < 0) 
        error("Send failed");

    // Receive the response
    while ((bytes_received = recv(sockfd, receive_buffer, BUFFER_SIZE - 1, 0)) > 0) {
        receive_buffer[bytes_received] = '\0'; // Null-terminate the buffer
        printf("%s", receive_buffer); // Print the response to stdout
    }

    if (bytes_received < 0) 
        error("Receive failed");

    // Close the socket
    close(sockfd);
}

int main() {
    const char *url = "http://example.com";

    printf("Building HTTP client to send GET request...\n");
    http_get_request(url);

    printf("\nHTTP request completed successfully!\n");
    return 0;
}