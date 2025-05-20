//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80); // HTTP uses port 80
    if (inet_pton(AF_INET, argv[1], &addr.sin_addr) != 1) {
        perror("inet_pton");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        exit(1);
    }

    char request[BUFFER_SIZE];
    snprintf(request, BUFFER_SIZE, "GET / HTTP/1.0\r\nHost: %s\r\n\r\n", argv[1]);
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send");
        exit(1);
    }

    char response[BUFFER_SIZE];
    int total_bytes = 0;
    int num_bytes = 0;
    while ((num_bytes = recv(sockfd, response + total_bytes, BUFFER_SIZE - total_bytes - 1, 0)) > 0) {
        total_bytes += num_bytes;
    }
    response[total_bytes] = '\0';

    printf("%s", response);

    close(sockfd);

    return 0;
}