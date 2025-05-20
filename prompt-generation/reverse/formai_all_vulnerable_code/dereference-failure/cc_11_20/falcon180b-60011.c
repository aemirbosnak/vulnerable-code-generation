//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"

int main() {
    int sock;
    struct addrinfo hints, *servinfo, *p;
    char s[NI_MAXSERV];
    char h[NI_MAXHOST];
    int rv;
    int numbytes;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(SERVER_IP, SERVER_PORT, &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sock = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(sock, p->ai_addr, p->ai_addrlen) == -1) {
            close(sock);
            perror("connect");
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "failed to connect\n");
        exit(1);
    }

    freeaddrinfo(servinfo);

    while (1) {
        memset(s, 0, sizeof(s));
        memset(h, 0, sizeof(h));

        if (getnameinfo(p->ai_addr, p->ai_addrlen, h, sizeof(h), s, sizeof(s), 0) == -1) {
            perror("getnameinfo");
            exit(1);
        }

        printf("Connected to %s:%s\n", h, s);

        while (1) {
            char buffer[BUFFER_SIZE];
            memset(buffer, 0, sizeof(buffer));

            if ((numbytes = recv(sock, buffer, BUFFER_SIZE, 0)) <= 0) {
                if (numbytes == 0) {
                    printf("Disconnected from server\n");
                } else {
                    perror("recv");
                }
                break;
            }

            printf("Received data: %s", buffer);
        }

        close(sock);
    }

    return 0;
}