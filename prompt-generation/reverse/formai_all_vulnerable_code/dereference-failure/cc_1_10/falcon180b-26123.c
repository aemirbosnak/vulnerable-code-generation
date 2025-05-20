//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define TIMEOUT 5

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int ping(char *hostname) {
    int sockfd, retval;
    struct addrinfo hints, *servinfo = NULL;
    char buffer[BUFFER_SIZE];
    int i, bytes_sent, bytes_received;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    retval = getaddrinfo(hostname, NULL, &hints, &servinfo);
    if (retval!= 0) {
        die("getaddrinfo");
    }

    sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
    if (sockfd == -1) {
        die("socket");
    }

    i = connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen);
    if (i == -1) {
        close(sockfd);
        die("connect");
    }

    bytes_sent = send(sockfd, "PING", 4, 0);
    if (bytes_sent!= 4) {
        close(sockfd);
        die("send");
    }

    bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
        close(sockfd);
        die("recv");
    }

    if (strncmp(buffer, "PONG", 4)!= 0) {
        close(sockfd);
        return 1;
    }

    close(sockfd);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    int retval = ping(hostname);

    if (retval == 0) {
        printf("%s is alive.\n", hostname);
    } else {
        printf("%s is unreachable.\n", hostname);
    }

    return retval;
}