//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage:./qos_monitor <IP address> <port number>\n");
        exit(1);
    }

    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);

    int sockfd;
    struct addrinfo hints, *servinfo;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if ((getaddrinfo(ip_address, NULL, &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(errno));
        exit(1);
    }

    sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);

    if (sockfd == -1) {
        fprintf(stderr, "socket: %s\n", strerror(errno));
        exit(1);
    }

    if (connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen) == -1) {
        fprintf(stderr, "connect: %s\n", strerror(errno));
        exit(1);
    }

    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            fprintf(stderr, "recv: %s\n", strerror(errno));
            exit(1);
        }

        printf("%s", buffer);
    }

    close(sockfd);

    return 0;
}