//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define BUFFER_SIZE 1024

void print_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char hostname[NI_MAXHOST];
    if (getnameinfo(argv[1], strlen(argv[1]), hostname, sizeof(hostname), NULL, 0, 0)!= 0) {
        print_error("Invalid hostname");
    }

    struct addrinfo hints, *result;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(hostname, NULL, &hints, &result)!= 0) {
        print_error("Failed to resolve hostname");
    }

    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd == -1) {
        print_error("Failed to create socket");
    }

    if (connect(sockfd, result->ai_addr, result->ai_addrlen)!= 0) {
        print_error("Failed to connect to host");
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "PING %s\r\n", hostname);

    if (send(sockfd, buffer, strlen(buffer), 0)!= strlen(buffer)) {
        print_error("Failed to send PING request");
    }

    while (1) {
        int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }

        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    return EXIT_SUCCESS;
}