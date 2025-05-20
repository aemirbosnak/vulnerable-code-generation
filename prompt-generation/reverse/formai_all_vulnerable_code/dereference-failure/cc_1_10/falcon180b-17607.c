//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>

#define MAX_HOSTNAME_LEN 256
#define MAX_DATA_LEN 64
#define TIMEOUT_SEC 5
#define TIMEOUT_USEC 0

int ping(const char *hostname, int port);

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    char hostname[MAX_HOSTNAME_LEN];
    strncpy(hostname, argv[1], MAX_HOSTNAME_LEN - 1);
    int port = atoi(argv[2]);

    int result = ping(hostname, port);

    if (result == 0) {
        printf("Host is reachable\n");
    } else {
        printf("Host is not reachable\n");
    }

    return result;
}

int ping(const char *hostname, int port) {
    int sockfd;
    struct sockaddr_in serv_addr;
    int opt = 1;
    char send_data[MAX_DATA_LEN] = "PING";
    char recv_data[MAX_DATA_LEN];
    int recv_len;
    struct timeval tv;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        return -1;
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        fprintf(stderr, "Error setting socket option: %s\n", strerror(errno));
        return -2;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error connecting to host: %s\n", strerror(errno));
        return -3;
    }

    send(sockfd, send_data, strlen(send_data), 0);
    tv.tv_sec = TIMEOUT_SEC;
    tv.tv_usec = TIMEOUT_USEC;

    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(tv)) < 0) {
        fprintf(stderr, "Error setting receive timeout: %s\n", strerror(errno));
        return -4;
    }

    recv_len = recv(sockfd, recv_data, MAX_DATA_LEN, 0);
    if (recv_len <= 0) {
        fprintf(stderr, "Error receiving data from host: %s\n", strerror(errno));
        return -5;
    }

    close(sockfd);
    if (strcmp(recv_data, "PONG") == 0) {
        return 0;
    } else {
        return -6;
    }
}