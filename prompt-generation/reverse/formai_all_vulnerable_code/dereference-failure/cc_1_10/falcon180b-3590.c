//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: peaceful
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

int main(int argc, char *argv[]) {

    int sockfd, numbytes;
    char buffer[1024];
    struct sockaddr_in serveraddr;
    struct hostent *hostinfo;
    int err;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    hostinfo = gethostbyname(argv[1]);

    if (hostinfo == NULL) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(1);
    }

    sockfd = socket(PF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(1);
    }

    memset(&serveraddr, 0, sizeof(serveraddr));

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(atoi(argv[2]));
    serveraddr.sin_addr = *((struct in_addr *) hostinfo->h_addr);

    err = connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr));

    if (err < 0) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(1);
    }

    printf("Connected to %s on port %s\n", argv[1], argv[2]);

    while (1) {
        memset(buffer, 0, sizeof(buffer));

        numbytes = recv(sockfd, buffer, sizeof(buffer), 0);

        if (numbytes <= 0) {
            printf("Disconnected\n");
            break;
        }

        printf("Received: %s", buffer);
    }

    close(sockfd);

    return 0;
}