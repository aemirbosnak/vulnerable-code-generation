//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_HOSTNAME 256
#define MAX_DATA 1024
#define WAIT_TIME 5 //seconds

int main(int argc, char *argv[]) {
    int sockfd, ret;
    struct sockaddr_in servaddr;
    char hostname[MAX_HOSTNAME];
    char data[MAX_DATA];
    int port = 80; //default port for HTTP

    if (argc < 3) {
        printf("Usage:./ping_test <hostname> <port>\n");
        return 1;
    }

    strncpy(hostname, argv[1], MAX_HOSTNAME);
    port = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: socket creation failed\n");
        return 1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);

    ret = inet_pton(AF_INET, hostname, &servaddr.sin_addr);
    if (ret <= 0) {
        printf("Error: invalid hostname\n");
        close(sockfd);
        return 1;
    }

    ret = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (ret == -1) {
        printf("Error: connection failed\n");
        close(sockfd);
        return 1;
    }

    printf("Connected to %s:%d\n", hostname, port);

    while (1) {
        memset(data, 0, sizeof(data));
        snprintf(data, MAX_DATA, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", hostname);

        ret = send(sockfd, data, strlen(data), 0);
        if (ret == -1) {
            printf("Error: send failed\n");
            close(sockfd);
            return 1;
        }

        struct timeval tv;
        tv.tv_sec = WAIT_TIME;
        tv.tv_usec = 0;

        ret = setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(tv));
        if (ret == -1) {
            printf("Error: setsockopt failed\n");
            close(sockfd);
            return 1;
        }

        char buffer[MAX_DATA];
        memset(buffer, 0, sizeof(buffer));
        int bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            printf("No response received\n");
            close(sockfd);
            return 1;
        }

        if (strstr(buffer, "200 OK")) {
            printf("Server is up and running\n");
        } else {
            printf("Server is down or not responding\n");
        }

        usleep(1000000); //1 second delay between pings
    }

    close(sockfd);
    return 0;
}