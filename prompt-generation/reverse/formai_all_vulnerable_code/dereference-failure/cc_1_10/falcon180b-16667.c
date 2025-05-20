//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>

#define MAX_HOSTNAME 256
#define MAX_DATA 1024
#define DEFAULT_PORT "7"
#define DEFAULT_TIMEOUT 5
#define DEFAULT_INTERVAL 1

void sig_handler(int signum) {
    if (signum == SIGALRM) {
        printf("\nTimeout exceeded. Exiting...\n");
        exit(1);
    }
}

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in server_addr;
    char hostname[MAX_HOSTNAME];
    char data[MAX_DATA];
    int port, timeout, interval;
    int optval;
    int ret;
    fd_set readfds;

    if (argc < 4) {
        printf("Usage:./ping <hostname> <port> <timeout>\n");
        exit(1);
    }

    strcpy(hostname, argv[1]);
    port = atoi(argv[2]);
    timeout = atoi(argv[3]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    if (ret == -1) {
        printf("Error connecting to server\n");
        close(sockfd);
        exit(1);
    }

    printf("Connected to server\n");

    optval = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, &optval, sizeof(optval));

    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);

    signal(SIGALRM, sig_handler);

    while (1) {
        ret = select(sockfd + 1, &readfds, NULL, NULL, &timeout);

        if (ret == 0) {
            printf("Timeout exceeded. Exiting...\n");
            close(sockfd);
            exit(1);
        }

        if (FD_ISSET(sockfd, &readfds)) {
            ret = recv(sockfd, data, MAX_DATA, 0);

            if (ret <= 0) {
                printf("Error receiving data\n");
                close(sockfd);
                exit(1);
            }

            printf("Received data: %s\n", data);
        }

        usleep(interval * 1000);
    }

    return 0;
}