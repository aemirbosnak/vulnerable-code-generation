//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define NUM_REQUESTS 10
#define TIME_OUT 5

int main(int argc, char *argv[]) {
    char *server_name;
    int server_port;
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    int rv;
    int numbytes;
    char buffer[BUFFER_SIZE];
    double total_time;
    double throughput;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <server_name> <server_port>\n", argv[0]);
        exit(1);
    }

    server_name = argv[1];
    server_port = atoi(argv[2]);

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(server_name, NULL, &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
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
        fprintf(stderr, "Failed to connect\n");
        exit(1);
    }

    freeaddrinfo(servinfo);

    for (int i = 0; i < NUM_REQUESTS; i++) {
        send(sockfd, "GET / HTTP/1.1\r\nHost: example.com\r\nConnection: close\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost: example.com\r\nConnection: close\r\n\r\n"), 0);

        total_time = 0.0;
        while ((numbytes = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
            total_time += (double)numbytes / 1024.0;
        }

        throughput = total_time / TIME_OUT;
        printf("Request %d: %.2f kB/s\n", i+1, throughput);
    }

    close(sockfd);

    return 0;
}