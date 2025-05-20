//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server address> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        perror("inet_pton");
        return EXIT_FAILURE;
    }

    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    int flags = fcntl(sockfd, F_GETFL, 0);
    if (flags < 0) {
        perror("fcntl");
        return EXIT_FAILURE;
    }

    if (fcntl(sockfd, F_SETFL, flags | O_NONBLOCK) < 0) {
        perror("fcntl");
        return EXIT_FAILURE;
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    struct timeval start, end;
    gettimeofday(&start, NULL);

    int bytes_sent = 0;
    int bytes_received = 0;

    while (1) {
        int bytes = send(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes < 0) {
            if (errno == EAGAIN) {
                continue;
            } else {
                perror("send");
                return EXIT_FAILURE;
            }
        }

        bytes_sent += bytes;

        bytes = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes < 0) {
            if (errno == EAGAIN) {
                continue;
            } else {
                perror("recv");
                return EXIT_FAILURE;
            }
        }

        bytes_received += bytes;

        gettimeofday(&end, NULL);

        double elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

        if (elapsed_time >= 1.0) {
            double download_speed = bytes_received / elapsed_time;
            double upload_speed = bytes_sent / elapsed_time;

            printf("Download speed: %.2f MB/s\n", download_speed / 1024.0 / 1024.0);
            printf("Upload speed: %.2f MB/s\n", upload_speed / 1024.0 / 1024.0);

            bytes_sent = 0;
            bytes_received = 0;

            gettimeofday(&start, NULL);
        }
    }

    close(sockfd);

    return EXIT_SUCCESS;
}