//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_HOST_NAME 1025

/* Function to print error message and exit */
void error(char *message) {
    perror(message);
    exit(1);
}

/* Function to perform ping test */
int ping_test(char *hostname) {
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    int rv;
    int num_responses = 0;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(hostname, NULL, &hints, &servinfo))!= 0) {
        error("getaddrinfo");
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("connect");
            continue;
        }

        char buffer[MAX_HOST_NAME];
        snprintf(buffer, MAX_HOST_NAME, "PING %s\r\n", hostname);
        send(sockfd, buffer, strlen(buffer), 0);

        char response[MAX_HOST_NAME];
        memset(response, 0, sizeof(response));
        int n = recv(sockfd, response, sizeof(response), 0);

        if (n > 0) {
            response[n] = '\0';
            if (strncmp(response, "PONG", 4) == 0) {
                num_responses++;
            }
        }

        close(sockfd);
    }

    freeaddrinfo(servinfo);

    return num_responses;
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        return 1;
    }

    int num_responses = ping_test(argv[1]);

    if (num_responses > 0) {
        printf("Host %s is alive\n", argv[1]);
    } else {
        printf("Host %s is not alive\n", argv[1]);
    }

    return 0;
}