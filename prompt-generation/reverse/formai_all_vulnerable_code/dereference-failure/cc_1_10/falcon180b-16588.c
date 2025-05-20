//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_HOSTNAME_LEN 256
#define MAX_DATA_LEN 64

void print_error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        return EXIT_FAILURE;
    }

    char hostname[MAX_HOSTNAME_LEN];
    strncpy(hostname, argv[1], MAX_HOSTNAME_LEN - 1);
    hostname[MAX_HOSTNAME_LEN - 1] = '\0';

    struct addrinfo hints, *result = NULL;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;

    int gai_error = getaddrinfo(hostname, NULL, &hints, &result);
    if (gai_error!= 0) {
        print_error("getaddrinfo");
    }

    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd == -1) {
        print_error("socket");
    }

    char data[MAX_DATA_LEN];
    strncpy(data, "PING", MAX_DATA_LEN - 1);
    data[MAX_DATA_LEN - 1] = '\0';

    int sent = sendto(sockfd, data, strlen(data), 0, result->ai_addr, result->ai_addrlen);
    if (sent == -1) {
        print_error("sendto");
    }

    char recv_buffer[MAX_DATA_LEN];
    memset(recv_buffer, 0, MAX_DATA_LEN);

    int recv_len = recvfrom(sockfd, recv_buffer, MAX_DATA_LEN, 0, NULL, NULL);
    if (recv_len == -1) {
        print_error("recvfrom");
    }

    recv_buffer[recv_len] = '\0';
    printf("Received: %s\n", recv_buffer);

    close(sockfd);
    freeaddrinfo(result);

    return EXIT_SUCCESS;
}