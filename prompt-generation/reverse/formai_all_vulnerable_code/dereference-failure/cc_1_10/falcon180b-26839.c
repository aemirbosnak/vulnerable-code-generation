//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_DATA_SIZE 1024
#define SERVER_PORT 8080

int main() {
    int sockfd, newsockfd, portno, clilen, recv_len;
    char buffer[MAX_DATA_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "No such host\n");
        exit(EXIT_FAILURE);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(SERVER_PORT);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server\n");

    while (1) {
        bzero(buffer, MAX_DATA_SIZE);
        recv_len = recv(sockfd, buffer, MAX_DATA_SIZE, 0);
        if (recv_len <= 0) {
            perror("recv failed");
            exit(EXIT_FAILURE);
        }

        printf("Received data: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}