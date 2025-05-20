//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char *hostname;
    int port;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    hostname = argv[1];
    port = atoi(argv[2]);

    struct addrinfo *result, *ptr;
    int rc;

    rc = getaddrinfo(hostname, NULL, NULL, &result);
    if (rc!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rc));
        return 1;
    }

    for (ptr = result; ptr!= NULL; ptr = ptr->ai_next) {
        int sockfd = socket(ptr->ai_family, SOCK_STREAM, 0);
        if (sockfd == -1) {
            fprintf(stderr, "socket: %s\n", strerror(errno));
            continue;
        }

        rc = connect(sockfd, ptr->ai_addr, ptr->ai_addrlen);
        if (rc == -1) {
            fprintf(stderr, "connect: %s\n", strerror(errno));
            close(sockfd);
            continue;
        }

        char buffer[BUFFER_SIZE];
        snprintf(buffer, BUFFER_SIZE, "GET / HTTP/1.0\r\nHost: %s\r\n\r\n", hostname);

        send(sockfd, buffer, strlen(buffer), 0);

        char response[BUFFER_SIZE];
        int bytes_received = recv(sockfd, response, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            fprintf(stderr, "recv: %s\n", strerror(errno));
            close(sockfd);
            continue;
        }

        response[bytes_received] = '\0';
        printf("Response:\n%s\n", response);

        close(sockfd);
    }

    freeaddrinfo(result);

    return 0;
}