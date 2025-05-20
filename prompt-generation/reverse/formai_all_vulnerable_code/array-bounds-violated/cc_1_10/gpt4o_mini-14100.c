//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void httpClient(char *hostname, char *path) {
    int sockfd;
    struct sockaddr_in server_addr;
    char request[BUFFER_SIZE], response[BUFFER_SIZE];
    
    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Error creating socket");
    }

    // Set up the server sockaddr_in structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // HTTP port
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed");
    }

    // Prepare the HTTP GET request
    snprintf(request, sizeof(request) - 1,
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n\r\n",
             path, hostname);

    // Send the request to the server
    if (send(sockfd, request, strlen(request), 0) < 0) {
        error("Error sending request");
    }

    printf("Sent request:\n%s\n", request);

    // Receive the response
    while (1) {
        int bytes_received = recv(sockfd, response, sizeof(response) - 1, 0);
        if (bytes_received <= 0) {
            break; // No more data or error
        }
        response[bytes_received] = '\0'; // Null-terminate the response
        printf("%s", response);
    }

    // Close the socket
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        exit(1);
    }

    httpClient(argv[1], argv[2]);

    return 0;
}