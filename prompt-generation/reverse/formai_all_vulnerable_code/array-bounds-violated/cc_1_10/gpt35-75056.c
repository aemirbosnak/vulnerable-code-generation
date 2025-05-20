//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

// a function to create a socket connection to a specified host and port
int create_socket(char *host, char *port)
{
    struct addrinfo hints, *res, *p;
    int status, sockfd;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((status = getaddrinfo(host, port, &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(1);
    }

    for(p = res; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("connect");
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "failed to connect\n");
        exit(2);
    }

    freeaddrinfo(res);

    return sockfd;
}

int main(int argc, char *argv[])
{
    // check if host and port are provided
    if (argc != 3) {
        fprintf(stderr,"usage: http_client hostname port\n");
        exit(1);
    }

    char *host = argv[1];
    char *port = argv[2];
    char request[1000];

    // create socket connection
    int sockfd = create_socket(host, port);

    // create HTTP GET request
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", host);

    // send request to server
    int request_len = strlen(request);
    int bytes_sent = send(sockfd, request, request_len, 0);
    if (bytes_sent != request_len) {
        fprintf(stderr, "failed to send request\n");
        exit(1);
    }

    // receive response from server
    char response[10000];
    int bytes_received = recv(sockfd, response, sizeof response - 1, 0);
    if (bytes_received == -1) {
        perror("recv");
        exit(1);
    }
    response[bytes_received] = '\0';
    printf("%s", response);

    // close socket connection
    close(sockfd);

    return 0;
}