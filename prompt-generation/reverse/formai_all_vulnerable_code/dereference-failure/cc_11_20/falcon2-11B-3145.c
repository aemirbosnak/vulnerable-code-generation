//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <server_address>\n", argv[0]);
        exit(1);
    }

    char *server_address = argv[1];
    struct addrinfo hints, *servinfo, *p;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    int rc = getaddrinfo(server_address, "ftp", &hints, &servinfo);
    if (rc) {
        fprintf(stderr, "Error resolving server address: %s\n", gai_strerror(rc));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        int sockfd;
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            perror("connect");
            close(sockfd);
            continue;
        }

        char buffer[256];
        memset(buffer, 0, sizeof(buffer));

        printf("Connected to %s\n", p->ai_canonname);
        while (1) {
            printf("ftp> ");
            fgets(buffer, sizeof(buffer), stdin);
            if (strcmp(buffer, "quit\n") == 0) {
                break;
            }
            if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
                perror("send");
                break;
            }

            int bytes_recv = recv(sockfd, buffer, sizeof(buffer), 0);
            if (bytes_recv == -1) {
                perror("recv");
                break;
            }
            if (bytes_recv == 0) {
                printf("Server closed the connection\n");
                break;
            }
            printf("Server: %s\n", buffer);
        }

        close(sockfd);
    }

    freeaddrinfo(servinfo);
    return 0;
}