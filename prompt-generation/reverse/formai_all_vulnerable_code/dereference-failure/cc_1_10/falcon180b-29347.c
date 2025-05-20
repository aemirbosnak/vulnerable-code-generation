//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

#define BUFFER_SIZE 1024


int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    struct addrinfo *addrinfo;
    int sockfd, retval;

    retval = getaddrinfo(hostname, NULL, NULL, &addrinfo);
    if (retval!= 0) {
        fprintf(stderr, "Error: %s\n", gai_strerror(retval));
        exit(1);
    }

    sockfd = socket(addrinfo->ai_family, addrinfo->ai_socktype, addrinfo->ai_protocol);
    if (sockfd == -1) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    while (1) {
        retval = sendto(sockfd, "PING", strlen("PING"), 0, addrinfo->ai_addr, addrinfo->ai_addrlen);
        if (retval!= strlen("PING")) {
            fprintf(stderr, "Error: %s\n", strerror(errno));
            exit(1);
        }

        retval = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, NULL, NULL);
        if (retval < 0) {
            fprintf(stderr, "Error: %s\n", strerror(errno));
            exit(1);
        }

        buffer[retval] = '\0';
        printf("%s\n", buffer);

        usleep(1000000);
    }

    close(sockfd);
    freeaddrinfo(addrinfo);

    return 0;
}