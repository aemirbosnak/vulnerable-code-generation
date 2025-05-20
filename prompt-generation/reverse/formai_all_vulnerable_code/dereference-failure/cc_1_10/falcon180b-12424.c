//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Error: Invalid number of arguments.\n");
        return 1;
    }

    char *hostname = argv[1];
    struct addrinfo hints, *result;
    int rv;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    rv = getaddrinfo(hostname, NULL, &hints, &result);
    if (rv!= 0) {
        printf("Error: %s\n", gai_strerror(rv));
        return 2;
    }

    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd == -1) {
        printf("Error: %s\n", strerror(errno));
        return 3;
    }

    if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) {
        printf("Error: %s\n", strerror(errno));
        close(sockfd);
        return 4;
    }

    char buffer[1024];
    int bytes_received;

    while (1) {
        bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            printf("Error: %s\n", strerror(errno));
            close(sockfd);
            return 5;
        }

        printf("Received: %s", buffer);
    }

    close(sockfd);
    return 0;
}