//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

#define BUFFER_SIZE 256

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <ip> <port> <check_interval>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *ip = argv[1];
    int port = atoi(argv[2]);
    int check_interval = atoi(argv[3]);

    int fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (fd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip);
    server_addr.sin_port = htons(port);

    char request[BUFFER_SIZE];
    memset(request, 0, BUFFER_SIZE);
    sprintf(request, "%s", "PING");

    char response[BUFFER_SIZE];
    memset(response, 0, BUFFER_SIZE);

    int flags = fcntl(fd, F_GETFL, 0);
    if (flags == -1) {
        perror("fcntl");
        return EXIT_FAILURE;
    }

    if (fcntl(fd, F_SETFL, flags | O_NONBLOCK) == -1) {
        perror("fcntl");
        return EXIT_FAILURE;
    }

    fd_set read_fds;
    FD_ZERO(&read_fds);

    struct timeval tv;
    tv.tv_sec = check_interval;
    tv.tv_usec = 0;

    while (1) {
        if (sendto(fd, request, BUFFER_SIZE, 0, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
            perror("sendto");
            return EXIT_FAILURE;
        }

        FD_SET(fd, &read_fds);

        int activity = select(fd + 1, &read_fds, NULL, NULL, &tv);
        if (activity == -1) {
            perror("select");
            return EXIT_FAILURE;
        }

        if (activity == 0) {
            printf("No response from server after %d second(s)\n", check_interval);
        } else {
            socklen_t server_len = sizeof(server_addr);
            if (recvfrom(fd, response, BUFFER_SIZE, 0, (struct sockaddr *)&server_addr, &server_len) == -1) {
                perror("recvfrom");
                return EXIT_FAILURE;
            }

            if (strcmp(response, "PONG") == 0) {
                printf("[%s] Network quality is good!\n", asctime(localtime(&tv.tv_sec)));
            } else {
                printf("[%s] Network quality is poor. Invalid response received: %s\n", asctime(localtime(&tv.tv_sec)), response);
            }

            memset(response, 0, BUFFER_SIZE);
        }

        tv.tv_sec = check_interval;
        tv.tv_usec = 0;
        FD_ZERO(&read_fds);
        usleep(500000);
    }

    return EXIT_SUCCESS;
}