//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_HOST_NAME 256
#define MAX_DATA_SIZE 1024

int main(int argc, char *argv[]) {
    int socket_fd;
    struct addrinfo hints, *result;
    char hostname[MAX_HOST_NAME];
    char data[MAX_DATA_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <hostname> <data>\n", argv[0]);
        return 1;
    }

    strcpy(hostname, argv[1]);
    strcpy(data, argv[2]);

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;

    if (getaddrinfo(hostname, NULL, &hints, &result)!= 0) {
        printf("getaddrinfo error: %s\n", gai_strerror(errno));
        return 1;
    }

    socket_fd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (socket_fd == -1) {
        printf("socket error: %s\n", strerror(errno));
        return 1;
    }

    if (sendto(socket_fd, data, strlen(data), 0, result->ai_addr, result->ai_addrlen) == -1) {
        printf("sendto error: %s\n", strerror(errno));
        return 1;
    }

    if (close(socket_fd) == -1) {
        printf("close error: %s\n", strerror(errno));
        return 1;
    }

    return 0;
}