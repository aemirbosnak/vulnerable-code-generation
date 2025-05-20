//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define MAX_ATTEMPTS 5
#define SLEEP_TIME 1

int main(int argc, char *argv[]) {
    struct addrinfo hints, *res;
    int sockfd, retval;
    char hostname[NI_MAXHOST];
    char service[NI_MAXSERV];
    char buffer[BUFFER_SIZE];
    int attempts = 0;
    int max_attempts = MAX_ATTEMPTS;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname [port]\n", argv[0]);
        return 1;
    }

    strcpy(hostname, argv[1]);
    if (argc == 3) {
        strcpy(service, argv[2]);
    } else {
        strcpy(service, "80");
    }

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    retval = getaddrinfo(hostname, service, &hints, &res);
    if (retval!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(retval));
        return 1;
    }

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        fprintf(stderr, "socket: %s\n", strerror(errno));
        return 1;
    }

    while (attempts < max_attempts) {
        if (connect(sockfd, res->ai_addr, res->ai_addrlen) == 0) {
            break;
        }

        attempts++;
        close(sockfd);

        sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
        if (sockfd == -1) {
            fprintf(stderr, "socket: %s\n", strerror(errno));
            return 1;
        }

        usleep(SLEEP_TIME * 1000000);
    }

    if (attempts == max_attempts) {
        fprintf(stderr, "Failed to connect to %s:%s after %d attempts\n", hostname, service, max_attempts);
        return 1;
    }

    memset(buffer, 0, BUFFER_SIZE);
    retval = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (retval <= 0) {
        fprintf(stderr, "recv: %s\n", strerror(errno));
        return 1;
    }

    buffer[retval] = '\0';
    printf("Received %d bytes from %s:%s\n", retval, hostname, service);
    printf("Response: %s\n", buffer);

    close(sockfd);
    return 0;
}