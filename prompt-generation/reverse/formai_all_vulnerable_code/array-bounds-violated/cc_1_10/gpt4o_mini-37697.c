//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 4096
#define PORT 80

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void http_get(const char *hostname, const char *path) {
    int sockfd;
    struct sockaddr_in server_addr;
    char request[BUFFER_SIZE], response[BUFFER_SIZE];

    /* Create a socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        handle_error("Socket creation failed");
    }

    /* Server information */
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    /* Connect to the server */
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection failed");
    }

    /* Create HTTP GET request */
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);
    
    /* Send the request */
    if (send(sockfd, request, strlen(request), 0) < 0) {
        handle_error("Error sending request");
    }

    /* Read the response */
    int bytes_received;
    while ((bytes_received = recv(sockfd, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_received] = '\0'; // Null-terminate the response
        printf("%s", response);          // Print the received response
    }

    if (bytes_received < 0) {
        handle_error("Error receiving response");
    }

    /* Close the socket */
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *path = argv[2];

    // Print the request details
    printf("Sending HTTP GET request to %s for path %s\n", hostname, path);

    http_get(hostname, path);
    
    printf("\nFinished receiving response.\n");
    return 0;
}