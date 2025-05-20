//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    char *port = argv[2];

    int sockfd, ret;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: socket() failed\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));
    ret = inet_pton(AF_INET, host, &server_addr.sin_addr);
    if (ret == 0) {
        printf("Error: inet_pton() failed\n");
        close(sockfd);
        return 1;
    }

    ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        printf("Error: connect() failed\n");
        close(sockfd);
        return 1;
    }

    printf("Connected to %s:%s\n", host, port);

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        ret = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (ret <= 0) {
            printf("Error: recv() failed\n");
            close(sockfd);
            return 1;
        }
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}