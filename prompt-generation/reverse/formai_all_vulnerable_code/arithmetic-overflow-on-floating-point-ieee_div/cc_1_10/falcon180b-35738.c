//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define SERVER_PORT 8080
#define SERVER_IP "192.168.1.1"
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sockfd, newsockfd, portno, clilen, ret;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    char *host = SERVER_IP;
    int maxfd;
    fd_set readfds;
    struct timeval tv;
    double start_time, end_time;
    double elapsed_time;
    int bytes_received;
    double speed;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("socket failed");

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(host);
    serv_addr.sin_port = htons(SERVER_PORT);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("connect failed");

    while (1) {
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);
        maxfd = sockfd;

        ret = select(maxfd + 1, &readfds, NULL, NULL, NULL);
        if (ret < 0)
            error("select failed");

        if (FD_ISSET(sockfd, &readfds)) {
            bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
            if (bytes_received <= 0)
                error("recv failed");

            start_time = (double)clock();
            while (bytes_received > 0) {
                write(1, buffer, bytes_received);
                bytes_received -= BUFFER_SIZE;
            }
            end_time = (double)clock();
            elapsed_time = (end_time - start_time) / CLOCKS_PER_SEC;
            speed = bytes_received / elapsed_time;

            printf("Download speed: %.2f KB/s\n", speed);
        }
    }

    close(sockfd);
    return 0;
}