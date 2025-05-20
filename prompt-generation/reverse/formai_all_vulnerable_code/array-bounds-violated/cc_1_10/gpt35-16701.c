//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_BUF_LEN 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s url\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char *url = argv[1];

    // Get the hostname and path from the URL
    char *hostname_start = strstr(url, "://");
    if (hostname_start != NULL) {
        hostname_start += strlen("://");
    } else {
        hostname_start = url;
    }
    char *path_start = strchr(hostname_start, '/');
    if (path_start == NULL) {
        path_start = "/";
    }

    // Construct the request string
    char request[MAX_BUF_LEN];
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %.*s\r\n\r\n", path_start, (int) (path_start - hostname_start), hostname_start);

    // Get the IP address of the host
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET; // IPv4 only
    hints.ai_socktype = SOCK_STREAM; // TCP
    struct addrinfo *result;
    int rv = getaddrinfo(hostname_start, "http", &hints, &result);
    if (rv != 0) {
        fprintf(stderr, "Failed to get address info for %s: %s\n", hostname_start, gai_strerror(rv));
        exit(EXIT_FAILURE);
    }

    // Create socket and connect to server
    struct sockaddr_in *server_addr = (struct sockaddr_in *) result->ai_addr;
    int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }
    if (connect(sockfd, (struct sockaddr *) server_addr, sizeof(*server_addr)) < 0) {
        perror("Failed to connect to server");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(result);

    // Send the request and read the response
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("Failed to send request");
        exit(EXIT_FAILURE);
    }

    char response[MAX_BUF_LEN];
    int recv_count = recv(sockfd, response, MAX_BUF_LEN - 1, 0);
    response[recv_count] = '\0';
    printf("%s", response);

    close(sockfd);
    return 0;
}