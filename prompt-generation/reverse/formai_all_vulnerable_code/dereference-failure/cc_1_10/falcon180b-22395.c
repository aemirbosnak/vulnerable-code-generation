//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_HOST_LEN 1024
#define MAX_DATA_LEN 1024
#define SERVER_PORT "8080"
#define SERVER_ADDR "127.0.0.1"

int main() {
    int sockfd, newsockfd, portno, clilen, ret;
    char buffer[MAX_DATA_LEN];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    int val;
    fd_set readfds;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    val = 1;
    ret = setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char *)&val, sizeof(val));
    if (ret < 0) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(SERVER_ADDR);
    if (server == NULL) {
        fprintf(stderr, "No such host\n");
        exit(EXIT_FAILURE);
    }

    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(SERVER_PORT));

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);

    while (1) {
        ret = select(sockfd + 1, &readfds, NULL, NULL, NULL);
        if (ret < 0) {
            perror("select");
            exit(EXIT_FAILURE);
        }

        if (FD_ISSET(sockfd, &readfds)) {
            bzero(buffer, MAX_DATA_LEN);
            ret = read(sockfd, buffer, MAX_DATA_LEN);
            if (ret <= 0) {
                perror("read");
                exit(EXIT_FAILURE);
            }
            printf("Received data: %s\n", buffer);
        }
    }

    close(sockfd);
    return 0;
}