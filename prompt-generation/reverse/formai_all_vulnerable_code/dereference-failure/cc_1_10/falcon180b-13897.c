//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void print_error(const char* message) {
    perror(message);
    exit(1);
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    struct addrinfo hints, *result = NULL;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(argv[1], NULL, &hints, &result)!= 0) {
        print_error("getaddrinfo");
    }

    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd == -1) {
        print_error("socket");
    }

    if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) {
        print_error("connect");
    }

    char buffer[BUFFER_SIZE];
    int bytes_received = 0;

    while (bytes_received < BUFFER_SIZE) {
        int bytes_read = recv(sockfd, buffer + bytes_received, BUFFER_SIZE - bytes_received, 0);
        if (bytes_read <= 0) {
            print_error("recv");
            break;
        }
        bytes_received += bytes_read;
    }

    buffer[bytes_received] = '\0';
    printf("Response from %s:\n%s", argv[1], buffer);

    close(sockfd);
    freeaddrinfo(result);

    return 0;
}