//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

void usage(char *progname) {
    fprintf(stderr, "Usage: %s <host> <port>\n", progname);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        usage(argv[0]);
    }

    char *host = argv[1];
    int port = atoi(argv[2]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, host, &servaddr.sin_addr);
    servaddr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        if (errno == ECONNREFUSED) {
            printf("Port %d is closed\n", port);
        } else {
            perror("connect");
        }
        close(sockfd);
        exit(1);
    } else {
        printf("Port %d is open\n", port);
    }

    close(sockfd);
    exit(0);
}