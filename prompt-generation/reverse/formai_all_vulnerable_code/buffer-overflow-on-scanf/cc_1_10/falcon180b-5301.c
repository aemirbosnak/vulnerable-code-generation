//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netdb.h>
#include <time.h>

#define MAXHOSTNAMELEN 1025
#define MAXBUFLEN 1024
#define TIMEOUT 5
#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[]) {
    int sockfd, retval, maxfd, connfd;
    struct addrinfo hints, *servinfo, *p;
    struct sockaddr *sa;
    char hostname[MAXHOSTNAMELEN];
    char buffer[MAXBUFLEN];
    char *message;
    struct timeval tv;
    fd_set readfds;
    int max_connections = 10;
    int num_connections = 0;
    int num_successful_connections = 0;
    int num_failed_connections = 0;
    int i;

    printf("Welcome to the Network Ping Test program!\n");
    printf("Enter the hostname or IP address to test: ");
    scanf("%s", hostname);

    if (argc > 1) {
        printf("Using custom timeout value of %d seconds...\n", TIMEOUT);
    } else {
        printf("Using default timeout value of %d seconds...\n", TIMEOUT);
    }

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_NUMERICSERV;

    retval = getaddrinfo(hostname, NULL, &hints, &servinfo);
    if (retval!= 0) {
        printf("Error: %s\n", gai_strerror(retval));
        return 1;
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            printf("Error: %s\n", strerror(errno));
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == 0) {
            printf("Connection successful!\n");
            num_successful_connections++;
        } else {
            printf("Connection failed: %s\n", strerror(errno));
            num_failed_connections++;
        }

        close(sockfd);
    }

    freeaddrinfo(servinfo);
    return 0;
}