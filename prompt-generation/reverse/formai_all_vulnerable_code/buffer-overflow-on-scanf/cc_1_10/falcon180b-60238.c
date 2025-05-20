//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_HOSTNAME 256
#define MAX_MESSAGE 1024
#define TIMEOUT 5

int ping(char* hostname) {
    int sockfd, retval;
    struct sockaddr_in server;
    char message[MAX_MESSAGE];
    int message_len = strlen(message);
    fd_set readfds;
    struct timeval tv;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    memset(&server, 0, sizeof(struct sockaddr_in));
    server.sin_family = AF_INET;
    server.sin_port = htons(7);
    inet_pton(AF_INET, hostname, &server.sin_addr);

    retval = connect(sockfd, (struct sockaddr*)&server, sizeof(struct sockaddr_in));
    if (retval == -1) {
        perror("connect");
        close(sockfd);
        return -1;
    }

    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);

    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    retval = select(sockfd + 1, &readfds, NULL, NULL, &tv);
    if (retval == -1) {
        perror("select");
        close(sockfd);
        return -1;
    } else if (retval == 0) {
        printf("Timeout\n");
        close(sockfd);
        return -1;
    }

    send(sockfd, message, message_len, 0);

    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);

    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    retval = select(sockfd + 1, &readfds, NULL, NULL, &tv);
    if (retval == -1) {
        perror("select");
        close(sockfd);
        return -1;
    } else if (retval == 0) {
        printf("Timeout\n");
        close(sockfd);
        return -1;
    }

    retval = recv(sockfd, message, MAX_MESSAGE, 0);
    if (retval == -1) {
        perror("recv");
        close(sockfd);
        return -1;
    }

    close(sockfd);

    if (strstr(message, "PING")!= NULL) {
        printf("Host is alive\n");
        return 0;
    } else {
        printf("Host is not responding\n");
        return -1;
    }
}

int main() {
    char hostname[MAX_HOSTNAME];
    printf("Enter hostname: ");
    scanf("%s", hostname);

    int result = ping(hostname);
    if (result == 0) {
        printf("Ping successful\n");
    } else {
        printf("Ping failed\n");
    }

    return 0;
}