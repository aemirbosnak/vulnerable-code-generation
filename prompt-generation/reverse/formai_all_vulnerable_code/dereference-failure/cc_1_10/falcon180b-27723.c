//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    struct addrinfo hints, *result, *rp;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rp = getaddrinfo(hostname, NULL, &hints, &result))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rp));
        return 1;
    }

    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd == -1) {
        fprintf(stderr, "socket: %s\n", strerror(errno));
        return 1;
    }

    if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) {
        fprintf(stderr, "connect: %s\n", strerror(errno));
        close(sockfd);
        return 1;
    }

    char send_buffer[BUFFER_SIZE] = "PING";
    send(sockfd, send_buffer, strlen(send_buffer), 0);

    char recv_buffer[BUFFER_SIZE];
    int bytes_received = 0;

    while ((bytes_received = recv(sockfd, recv_buffer, BUFFER_SIZE, 0)) > 0) {
        recv_buffer[bytes_received] = '\0';
        printf("%s", recv_buffer);
    }

    close(sockfd);

    return 0;
}