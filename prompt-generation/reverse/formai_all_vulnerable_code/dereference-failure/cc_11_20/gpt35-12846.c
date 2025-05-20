//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/select.h>
#include <sys/time.h>

#define BUFSIZE 1024
#define TIMEOUT 5

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s host port\n", argv[0]);
        return 0;
    }

    char *host = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in server_addr;
    struct hostent *hp;
    int sockfd, nready, maxfd;

    fd_set rset, allset;

    if ((sockfd = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket error");
        return 1;
    }

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    if ((hp = gethostbyname(host)) == NULL) {
        perror("gethostbyname error");
        return 1;
    }

    bcopy(hp->h_addr, &server_addr.sin_addr, hp->h_length);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect error");
        return 1;
    }

    FD_ZERO(&allset);
    FD_SET(sockfd, &allset);

    maxfd = sockfd;

    while (1) {
        rset = allset;
        struct timeval tv;
        tv.tv_sec = TIMEOUT;
        tv.tv_usec = 0;

        nready = select(maxfd + 1, &rset, NULL, NULL, &tv);
        if (nready < 0) {
            perror("select error");
            continue;
        } else if (nready == 0) {
            printf("Connection timeout\n");
            break;
        }

        if (FD_ISSET(sockfd, &rset)) {
            char buf[BUFSIZE];
            int n = read(sockfd, buf, BUFSIZE);
            if (n == 0) {
                printf("Connection closed by server\n");
                break;
            } else if (n < 0) {
                perror("read error");
                break;
            } else {
                printf("%.*s", n, buf);
            }
        }
    }

    close(sockfd);
    return 0;
}