//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <time.h>

#define MAX_HOSTNAME 256
#define MAX_DATA 1000

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    char hostname[MAX_HOSTNAME];
    strcpy(hostname, argv[1]);

    struct addrinfo hints, *result = NULL;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(hostname, NULL, &hints, &result)!= 0) {
        printf("getaddrinfo: %s\n", gai_strerror(errno));
        return 1;
    }

    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd == -1) {
        printf("socket: %s\n", strerror(errno));
        return 1;
    }

    if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) {
        printf("connect: %s\n", strerror(errno));
        close(sockfd);
        return 1;
    }

    char send_data[MAX_DATA];
    sprintf(send_data, "PING %s\r\n", hostname);

    if (send(sockfd, send_data, strlen(send_data), 0) == -1) {
        printf("send: %s\n", strerror(errno));
        close(sockfd);
        return 1;
    }

    char recv_data[MAX_DATA];
    memset(recv_data, 0, sizeof(recv_data));

    int bytes_received = recv(sockfd, recv_data, sizeof(recv_data), 0);
    if (bytes_received <= 0) {
        printf("recv: %s\n", strerror(errno));
        close(sockfd);
        return 1;
    }

    close(sockfd);

    printf("Received response:\n%s\n", recv_data);

    return 0;
}