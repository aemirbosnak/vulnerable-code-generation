//MISTRAL-7B DATASET v1.0 Category: Network Ping Test ; Style: safe
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define SERVER_PORT 80
#define BUFFER_SIZE 1024
#define PING_PACKET_SIZE 64
#define TIMEOUT 1000 // in milliseconds

int main(int argc, char **argv) {
    int sockfd, ret, i;
    struct sockaddr_in server_addr;
    char request[PING_PACKET_SIZE];
    char response[BUFFER_SIZE];
    struct timeval start, end;
    long long elapsed;

    if (argc != 2) {
        printf("Usage: %s <server_address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);
    server_addr.sin_port = htons(SERVER_PORT);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < 5; ++i) {
        memset(request, 0, PING_PACKET_SIZE);
        memset(response, 0, BUFFER_SIZE);

        gettimeofday(&start, NULL);
        sendto(sockfd, request, PING_PACKET_SIZE, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
        fd_set master_fds;
        FD_ZERO(&master_fds);
        FD_SET(sockfd, &master_fds);
        struct timeval timeout;
        timeout.tv_sec = 0;
        timeout.tv_usec = TIMEOUT;
        int select_ret = select(sockfd + 1, NULL, &master_fds, NULL, &timeout);

        if (select_ret > 0) {
            socklen_t len = sizeof(server_addr);
            ret = recvfrom(sockfd, response, BUFFER_SIZE, 0, (struct sockaddr *)&server_addr, &len);
            if (ret > 0) {
                gettimeofday(&end, NULL);
                elapsed = (long long)(end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;
                printf("Reply received in %lld ms\n", elapsed);
            } else {
                perror("recvfrom");
                exit(EXIT_FAILURE);
            }
        } else if (select_ret == 0) {
            printf("Timeout\n");
        } else {
            perror("select");
            exit(EXIT_FAILURE);
        }
    }

    close(sockfd);
    return EXIT_SUCCESS;
}