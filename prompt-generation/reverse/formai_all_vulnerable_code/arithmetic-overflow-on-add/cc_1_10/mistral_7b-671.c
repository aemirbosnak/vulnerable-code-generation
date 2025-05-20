//MISTRAL-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/select.h>

#define MAX_PACKET_SIZE 1500
#define BUFFER_SIZE 4096

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sockfd, newsockfd, portno, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    int max_fd, new_fd;
    fd_set readfds;
    struct timeval tv;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(5000);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    listen(sockfd, 5);

    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);
    FD_SET(sockfd, &readfds);

    max_fd = sockfd;

    while (1) {
        tv.tv_sec = 1;
        tv.tv_usec = 0;

        int retval = select(max_fd + 1, &readfds, NULL, NULL, &tv);
        if (retval < 0) {
            error("ERROR on select");
        }

        if (FD_ISSET(STDIN_FILENO, &readfds)) {
            // Handle user input
        }

        if (FD_ISSET(sockfd, &readfds)) {
            clilen = sizeof(cli_addr);
            ssize_t n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&cli_addr, &clilen);
            if (n < 0) {
                error("ERROR on recvfrom");
            }

            if (n > MAX_PACKET_SIZE) {
                printf("ERROR: Packet size %ld bytes from %s:%d\n", n, inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
            }

            sendto(sockfd, buffer, n, 0, (struct sockaddr *)&cli_addr, clilen);
        }
    }

    return 0;
}