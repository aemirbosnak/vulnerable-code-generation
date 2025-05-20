//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_BUFFER 1024

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    const char *port_str = argv[2];
    int port = atoi(port_str);
    
    int sockfd;
    struct sockaddr_in server_address;
    char request[MAX_BUFFER];
    char response[MAX_BUFFER];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        die("Could not create socket");
    }

    // Setup server address structure
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    if (inet_pton(AF_INET, hostname, &server_address.sin_addr) <= 0) {
        die("Invalid address/ Address not supported");
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        die("Connection Failed");
    }

    // Prepare GET request
    snprintf(request, sizeof(request),
             "GET / HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n\r\n", hostname);

    // Send GET request
    if (send(sockfd, request, strlen(request), 0) < 0) {
        die("Failed to send request");
    }

    // Received response
    printf("Response:\n");
    while (1) {
        int bytes_received = recv(sockfd, response, MAX_BUFFER - 1, 0);
        if (bytes_received < 0) {
            die("Failed to receive response");
        } else if (bytes_received == 0) {
            break; // Connection closed by the server
        }

        response[bytes_received] = '\0';  // Null-terminate the received data
        printf("%s", response);
    }

    // Close socket
    close(sockfd);
    return EXIT_SUCCESS;
}