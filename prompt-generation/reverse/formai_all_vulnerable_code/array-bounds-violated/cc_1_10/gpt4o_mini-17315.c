//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

void print_response(char *response) {
    printf("Response from server:\n");
    printf("%s\n", response);
}

void perform_http_get(const char *host, const char *path) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char request[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    
    // Get the server IP address from host name
    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    // Set server address struct
    memset((char *)&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy((char *)&server_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    server_addr.sin_port = htons(80); // HTTP uses port 80

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("ERROR connecting");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Prepare HTTP GET request
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);
    
    // Send the request
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("ERROR sending request");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Read the response
    memset(response, 0, BUFFER_SIZE);
    ssize_t received = 0;
    while ((received = recv(sockfd, response, BUFFER_SIZE - 1, 0)) > 0) {
        response[received] = '\0'; // null terminate the response
        print_response(response);
    }

    if (received < 0) {
        perror("ERROR receiving response");
    }

    // Close the socket
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *host = argv[1];
    const char *path = argv[2];

    perform_http_get(host, path);

    return 0;
}