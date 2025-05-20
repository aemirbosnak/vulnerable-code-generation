//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_HOST_LEN 1024
#define MAX_DATA_LEN 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo hints, *result;
    char host[MAX_HOST_LEN];
    char data[MAX_DATA_LEN];

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <hostname> <data>\n", argv[0]);
        return 1;
    }

    strcpy(host, argv[1]);
    strcpy(data, argv[2]);

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(host, NULL, &hints, &result)!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(errno));
        return 1;
    }

    sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd == -1) {
        fprintf(stderr, "socket: %s\n", strerror(errno));
        return 1;
    }

    if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) {
        fprintf(stderr, "connect: %s\n", strerror(errno));
        close(sockfd);
        return 1;
    }

    if (send(sockfd, data, strlen(data), 0) == -1) {
        fprintf(stderr, "send: %s\n", strerror(errno));
        close(sockfd);
        return 1;
    }

    char buffer[MAX_DATA_LEN];
    int bytes_received;

    if ((bytes_received = recv(sockfd, buffer, MAX_DATA_LEN, 0)) <= 0) {
        fprintf(stderr, "recv: %s\n", strerror(errno));
        close(sockfd);
        return 1;
    }

    buffer[bytes_received] = '\0';
    printf("Received: %s\n", buffer);

    close(sockfd);
    return 0;
}