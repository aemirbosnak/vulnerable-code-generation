//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define PORT 80
#define BUFSIZE 1024
#define INTERVAL 5

int main(int argc, char **argv)
{
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buf[BUFSIZE];
    char *host;
    time_t start, end;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }
    host = argv[1];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(2);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, host, &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(3);
    }

    start = time(NULL);
    while (1) {
        if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
            perror("connect");
            exit(4);
        }
        n = send(sockfd, "", 1, 0);
        if (n < 0) {
            perror("send");
            exit(5);
        }
        n = recv(sockfd, buf, BUFSIZE, 0);
        if (n < 0) {
            perror("recv");
            exit(6);
        }
        close(sockfd);

        end = time(NULL);
        if (end - start >= INTERVAL) {
            printf("Uptime: %ld seconds\n", end - start);
            start = end;
        }
        sleep(1);
    }

    return 0;
}