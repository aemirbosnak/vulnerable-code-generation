//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>

#define MAX_HOST_LEN 256
#define MAX_RESPONSE_LEN 1024

void checkUptime(char* host) {
    struct addrinfo addr, *res;
    int sockfd, status;
    char response[MAX_RESPONSE_LEN];

    memset(&addr, 0, sizeof(struct addrinfo));
    addr.ai_family = AF_UNSPEC;
    addr.ai_socktype = SOCK_STREAM;

    if ((status = getaddrinfo(host, "http", &addr, &res)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        return;
    }

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        return;
    }

    if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
        perror("connect");
        return;
    }

    char request[MAX_RESPONSE_LEN];
    sprintf(request, "GET / HTTP/1.1\r\nhost: %s\r\n\r\n", host);

    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send");
        return;
    }

    int bytes_received = recv(sockfd, response, MAX_RESPONSE_LEN - 1, 0);
    if (bytes_received == -1) {
        perror("recv");
        return;
    }

    response[bytes_received] = '\0';

    if (strstr(response, "Server: Apache") != NULL || strstr(response, "Server: nginx") != NULL) {
        printf("Host %s is up and running\n", host);
    } else {
        printf("Host %s is currently down\n", host);
    }

    close(sockfd);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [hostname]\n", argv[0]);
        return EXIT_FAILURE;
    }

    char* host = argv[1];

    while (1) {
        checkUptime(host);

        // Sleep for 10 seconds before checking again
        sleep(10);
    }

    return EXIT_SUCCESS;
}