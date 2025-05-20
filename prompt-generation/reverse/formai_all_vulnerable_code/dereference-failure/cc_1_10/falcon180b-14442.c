//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo hints, *servinfo;
    char host[NI_MAXHOST], service[NI_MAXSERV];
    int rv;
    char send_buffer[BUFFER_SIZE];
    char recv_buffer[BUFFER_SIZE];

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    rv = getaddrinfo(argv[1], argv[2], &hints, &servinfo);
    if (rv!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    sockfd = socket(servinfo->ai_family, servinfo->ai_socktype,
                    servinfo->ai_protocol);
    if (sockfd == -1) {
        fprintf(stderr, "socket: %s\n", strerror(errno));
        exit(1);
    }

    rv = connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen);
    if (rv == -1) {
        fprintf(stderr, "connect: %s\n", strerror(errno));
        exit(1);
    }

    printf("Connected to %s:%s\n", host, service);

    while (1) {
        memset(send_buffer, 0, BUFFER_SIZE);
        printf("Enter a message to send: ");
        fgets(send_buffer, BUFFER_SIZE, stdin);
        send(sockfd, send_buffer, strlen(send_buffer), 0);

        memset(recv_buffer, 0, BUFFER_SIZE);
        rv = recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
        if (rv <= 0) {
            if (rv == 0) {
                printf("Connection closed by server\n");
            } else {
                fprintf(stderr, "recv: %s\n", strerror(errno));
            }
            break;
        }

        printf("Received message: %s\n", recv_buffer);
    }

    close(sockfd);
    freeaddrinfo(servinfo);

    return 0;
}