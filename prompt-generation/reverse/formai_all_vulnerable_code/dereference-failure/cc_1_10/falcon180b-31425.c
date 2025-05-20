//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <netdb.h>

int ping(char *hostname) {
    int sockfd, retval;
    struct sockaddr_in servaddr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error: socket creation failed\n");
        exit(1);
    }

    server = gethostbyname(hostname);

    if (server == NULL) {
        printf("Error: hostname lookup failed\n");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(1234);
    memcpy(&servaddr.sin_addr, server->h_addr, server->h_length);

    retval = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    if (retval < 0) {
        printf("Error: connection failed\n");
        exit(1);
    }

    close(sockfd);
    return 0;
}

void handler(int signum) {
    exit(0);
}

int main(int argc, char *argv[]) {
    char *hostname = argv[1];
    signal(SIGINT, handler);

    while (1) {
        ping(hostname);
        sleep(1);
    }

    return 0;
}