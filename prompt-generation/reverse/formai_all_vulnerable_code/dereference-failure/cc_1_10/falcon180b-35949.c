//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <netdb.h>

#define MAX_DATA_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd, ret, maxfd, connfd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_DATA_SIZE];
    fd_set readfds;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <IP address> <port number>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        fprintf(stderr, "Error: socket() failed\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        fprintf(stderr, "Error: connect() failed\n");
        exit(1);
    }

    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);
    maxfd = sockfd;

    while (1) {
        ret = select(maxfd + 1, &readfds, NULL, NULL, NULL);
        if (ret == -1) {
            fprintf(stderr, "Error: select() failed\n");
            exit(1);
        }

        if (FD_ISSET(sockfd, &readfds)) {
            ret = recv(sockfd, buffer, MAX_DATA_SIZE, 0);
            if (ret <= 0) {
                fprintf(stderr, "Error: recv() failed\n");
                exit(1);
            }

            printf("Received data: %s\n", buffer);
        }
    }

    close(sockfd);
    return 0;
}