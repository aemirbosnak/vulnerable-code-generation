//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_HOSTNAME_LEN 256
#define MAX_DATA_LEN 1024
#define TIMEOUT 5

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void print_usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s <hostname>\n", prog_name);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        print_usage(argv[0]);
        return 1;
    }

    char hostname[MAX_HOSTNAME_LEN];
    strcpy(hostname, argv[1]);

    struct addrinfo hints, *result = NULL;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(hostname, NULL, &hints, &result)!= 0) {
        handle_error("getaddrinfo");
    }

    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd == -1) {
        handle_error("socket");
    }

    if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) {
        handle_error("connect");
    }

    char data[MAX_DATA_LEN];
    memset(data, 0, sizeof(data));
    strcat(data, "PING\r\n");

    if (send(sockfd, data, strlen(data), 0) == -1) {
        handle_error("send");
    }

    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    fd_set set;
    FD_ZERO(&set);
    FD_SET(sockfd, &set);

    if (select(sockfd + 1, &set, NULL, NULL, &tv) == -1) {
        handle_error("select");
    }

    int retval = 0;
    socklen_t addrlen = sizeof(result->ai_addr);
    if (getsockopt(sockfd, SOL_SOCKET, SO_ERROR, (char *)&retval, &addrlen) == -1) {
        handle_error("getsockopt");
    }

    if (retval!= 0) {
        printf("Ping failed: %s\n", strerror(retval));
        close(sockfd);
        return 1;
    }

    char buffer[MAX_DATA_LEN];
    memset(buffer, 0, sizeof(buffer));

    if (recv(sockfd, buffer, MAX_DATA_LEN, 0) == -1) {
        handle_error("recv");
    }

    printf("Ping successful: %s\n", buffer);

    close(sockfd);
    return 0;
}