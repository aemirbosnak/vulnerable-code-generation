//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096
#define REQUEST_FORMAT "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n"

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void fetch_webpage(const char *host) {
    int sockfd;
    struct sockaddr_in server_addr;
    char request[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    int bytes_received;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        handle_error("Socket creation failed");
    }
    
    // Set up the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr.s_addr = inet_addr("93.184.216.34"); // example.com IP address

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection failed");
    }

    // Create GET request
    snprintf(request, sizeof(request), REQUEST_FORMAT, host);
    
    // Send the request
    if (send(sockfd, request, strlen(request), 0) < 0) {
        handle_error("Send failed");
    }
    
    // Receive and display the response
    printf("Fetching webpage...\n");
    while ((bytes_received = recv(sockfd, response, sizeof(response)-1, 0)) > 0) {
        response[bytes_received] = '\0'; // Null-terminate the response
        printf("%s", response); // Print the response
    }
    
    if (bytes_received < 0) {
        handle_error("Receive failed");
    }

    printf("\nWebpage fetched successfully!\n");
    
    // Close the socket
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];

    printf("Starting HTTP Client...\n");
    printf("Fetching content from: %s\n", hostname);
    
    fetch_webpage(hostname);

    printf("HTTP Client finished.\n");
    return 0;
}