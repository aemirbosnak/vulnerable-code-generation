//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void print_error(const char* error_message) {
    perror(error_message);
    exit(1);
}

void print_usage(const char* program_name) {
    fprintf(stderr, "Usage: %s <hostname>\n", program_name);
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        print_usage(argv[0]);
        return 1;
    }

    char hostname[1024];
    strcpy(hostname, argv[1]);

    struct addrinfo hints, *result = NULL;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(hostname, NULL, &hints, &result)!= 0) {
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
    memset(buffer, 0, BUFFER_SIZE);

    if (send(sockfd, "PING", strlen("PING"), 0) == -1) {
        print_error("send");
    }

    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        print_error("recv");
    }

    if (strcmp(buffer, "PONG")!= 0) {
        fprintf(stderr, "Error: Received unexpected response\n");
        return 1;
    }

    close(sockfd);
    return 0;
}