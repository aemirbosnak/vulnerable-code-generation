//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define PORT 80
#define TIMEOUT 2

int main() {
    char hostname[1024];
    struct hostent *host;
    struct sockaddr_in address;
    int sockfd, status, bytes_read;
    int seconds, useconds;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    address.sin_addr.s_addr = inet_addr("www.google.com");

    if (connect(sockfd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("connect");
        return 1;
    }

    seconds = 0;
    useconds = 0;

    while (seconds < 1 && useconds < 500000) {
        bytes_read = recv(sockfd, &seconds, sizeof(seconds), 0);
        if (bytes_read < 0) {
            perror("recv");
            return 1;
        }
        useconds = 0;
        while (useconds < 1000000) {
            bytes_read = recv(sockfd, &useconds, sizeof(useconds), 0);
            if (bytes_read < 0) {
                perror("recv");
                return 1;
            }
            useconds += (bytes_read > 0? bytes_read : 0);
        }
        seconds += 1;
    }

    close(sockfd);
    return 0;
}