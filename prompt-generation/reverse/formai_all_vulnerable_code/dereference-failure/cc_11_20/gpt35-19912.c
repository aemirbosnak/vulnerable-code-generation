//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        exit(1);
    }

    char *url = argv[1];

    //parse url to get hostname and port
    char *hostname;
    char *port = "80";
    char *path;
    char *tmp;

    tmp = strpbrk(url, ":");
    if (tmp != NULL) {
        hostname = strndup(url, tmp - url);
        tmp += 3; // skip "://"
        path = strchr(tmp, '/');
        if (path == NULL) path = "";
        else *path++ = '\0';
        tmp = strchr(tmp, ':');
        if (tmp != NULL) port = tmp + 1;
    } else {
        tmp = strpbrk(url, "/");
        if (tmp != NULL) {
            hostname = strndup(url, tmp - url);
            path = tmp + 1;
        } else {
            hostname = url;
            path = "";
        }
    }

    //get address info
    struct addrinfo hints, *res;
    int sockfd;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(hostname, port, &hints, &res) != 0) {
        perror("getaddrinfo error");
        exit(1);
    }

    //create socket
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        perror("socket error");
        exit(1);
    }

    //connect
    if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
        perror("connect error");
        exit(1);
    }

    //build request
    char *request = (char *) malloc(BUFFER_SIZE);
    snprintf(request, BUFFER_SIZE, "GET /%s HTTP/1.1\r\nHost: %s:%s\r\n\r\n", path, hostname, port);

    //send request
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send error");
        exit(1);
    }

    //receive response
    char buffer[BUFFER_SIZE];
    int n;

    while ((n = recv(sockfd, buffer, BUFFER_SIZE-1, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    if (n < 0) {
        perror("recv error");
        exit(1);
    }

    //cleanup
    freeaddrinfo(res);
    close(sockfd);
    free(request);

    return 0;
}