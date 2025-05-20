//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define PING_TIMEOUT 5

int ping(const char *hostname) {
    int sockfd, retval;
    struct hostent *hostent;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int timeout;
    fd_set writefds;
    struct timeval tv;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    hostent = gethostbyname(hostname);
    if (hostent == NULL) {
        perror("gethostbyname");
        return -1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr, hostent->h_addr, hostent->h_length);
    server_addr.sin_port = htons(7);

    retval = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (retval == -1) {
        perror("connect");
        return -1;
    }

    timeout = PING_TIMEOUT;
    FD_ZERO(&writefds);
    FD_SET(sockfd, &writefds);

    tv.tv_sec = timeout;
    tv.tv_usec = 0;

    retval = select(sockfd + 1, NULL, &writefds, NULL, &tv);
    if (retval == -1) {
        perror("select");
        return -1;
    }

    if (FD_ISSET(sockfd, &writefds)) {
        retval = send(sockfd, "PING\r\n", strlen("PING\r\n"), 0);
        if (retval == -1) {
            perror("send");
            return -1;
        }

        memset(buffer, 0, BUFFER_SIZE);
        retval = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (retval == -1) {
            perror("recv");
            return -1;
        }

        if (strncmp(buffer, "PONG", 4) == 0) {
            printf("Ping successful\n");
            return 0;
        } else {
            printf("Ping failed\n");
            return -1;
        }
    } else {
        printf("Ping timeout\n");
        return -1;
    }

    return 0;
}

int main() {
    char *hostname;
    int retval;

    printf("Enter hostname to ping: ");
    scanf("%s", hostname);

    retval = ping(hostname);
    if (retval == 0) {
        printf("Ping successful\n");
    } else if (retval == -1) {
        printf("Ping failed\n");
    }

    return 0;
}