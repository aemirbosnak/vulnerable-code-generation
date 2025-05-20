//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAXLINE 4096
#define DEFAULT_PORT 80

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void http_get_request(const char *hostname, const char *path) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Socket creation failed");
    }

    // Resolve hostname
    if ((host = gethostbyname(hostname)) == NULL) {
        error("Hostname resolution failed");
    }

    // Prepare server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);
    server_addr.sin_port = htons(DEFAULT_PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection to server failed");
    }

    // Creating HTTP GET request
    char request[MAXLINE];
    snprintf(request, sizeof(request),
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n\r\n",
             path, hostname);

    // Send request
    if (send(sockfd, request, strlen(request), 0) < 0) {
        error("Sending request failed");
    }

    // Receive response
    char response[MAXLINE];
    int n;
    printf("Response:\n");
    while ((n = recv(sockfd, response, sizeof(response) - 1, 0)) > 0) {
        response[n] = '\0';  // Null-terminate the response
        printf("%s", response); // Print the response
    }

    if (n < 0) {
        error("Receive failed");
    }

    // Close socket
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *path = argv[2];

    http_get_request(hostname, path);

    return 0;
}