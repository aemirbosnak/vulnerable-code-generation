//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *url = argv[1];

    // Parse the URL to get the host, path, and port
    char *host = NULL;
    char *path = NULL;
    char *port = "80"; // default HTTP port
    char *ptr = strstr(url, "://");
    if (ptr != NULL) {
        host = ptr + 3;
    } else {
        host = url;
    }
    ptr = strchr(host, '/');
    if (ptr != NULL) {
        path = ptr;
        *ptr = '\0';
    } else {
        path = "/";
    }
    ptr = strchr(host, ':');
    if (ptr != NULL) {
        *ptr = '\0';
        port = ptr + 1;
    }

    // Get the address of the host
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET; // use IPv4
    hints.ai_socktype = SOCK_STREAM;
    int status = getaddrinfo(host, port, &hints, &res);
    if (status != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        return EXIT_FAILURE;
    }

    // Connect to the host
    int sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }
    if (connect(sockfd, res->ai_addr, res->ai_addrlen) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the HTTP request
    char request[BUF_SIZE];
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s:%s\r\nConnection: close\r\n\r\n", path, host, port);
    int n = write(sockfd, request, strlen(request));
    if (n < 0) {
        perror("write");
        return EXIT_FAILURE;
    }

    // Receive the HTTP response
    char response[BUF_SIZE];
    int total = 0;
    int nbytes;
    while ((nbytes = read(sockfd, response + total, BUF_SIZE - total - 1)) > 0) {
        total += nbytes;
        response[total] = '\0';
    }
    if (nbytes < 0) {
        perror("read");
        return EXIT_FAILURE;
    }

    printf("%s", response);

    close(sockfd);
    freeaddrinfo(res);

    return EXIT_SUCCESS;
}