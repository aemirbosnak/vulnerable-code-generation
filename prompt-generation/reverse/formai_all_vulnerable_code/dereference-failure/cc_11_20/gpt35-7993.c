//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    /* Variables to hold command line arguments */
    char *host = NULL;
    char *path = NULL;
    char *port = "80";  // default port

    /* Check for correct number of arguments */
    if(argc < 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return 1;
    }

    /* Parse URL */
    char *url = argv[1];
    char *ptr = strstr(url, "://");
    if(ptr != NULL) {
        /* Remove protocol, if included */
        url = ptr + 3;
    }
    /* Parse host and path */
    ptr = strchr(url, '/');
    if(ptr != NULL) {
        *ptr++ = '\0';
        path = ptr;
    }
    host = url;

    /* Resolve host */
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    if(getaddrinfo(host, port, &hints, &res) != 0) {
        perror("getaddrinfo");
        return 1;
    }

    /* Connect to server */
    int sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if(sockfd == -1) {
        perror("socket");
        return 1;
    }
    if(connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
        perror("connect");
        return 1;
    }
    freeaddrinfo(res);

    /* Build HTTP request */
    char request[BUFFER_SIZE];
    if(path == NULL) {
        snprintf(request, BUFFER_SIZE, "GET / HTTP/1.1\r\nHost: %s:%s\r\n\r\n", host, port);
    }
    else {
        snprintf(request, BUFFER_SIZE, "GET /%s HTTP/1.1\r\nHost: %s:%s\r\n\r\n", path, host, port);
    }

    /* Send HTTP request */
    if(write(sockfd, request, strlen(request)) == -1) {
        perror("write");
        return 1;
    }

    /* Receive HTTP response */
    char response[BUFFER_SIZE];
    ssize_t num_bytes;
    while((num_bytes = read(sockfd, response, BUFFER_SIZE - 1)) > 0) {
        response[num_bytes] = '\0';
        printf("%s", response);
    }
    if(num_bytes == -1) {
        perror("read");
        return 1;
    }

    close(sockfd);
    return 0;
}