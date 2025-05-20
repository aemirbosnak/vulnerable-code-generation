//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    int opt = 1;
    char *server_ip = "speedtest.net";
    char *port = "80";
    char buffer[BUFFER_SIZE];
    int bytes_received = 0;
    int total_bytes_received = 0;
    struct timeval start_time, end_time;
    double elapsed_time;
    double speed;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));
    server_addr.sin_addr.s_addr = inet_addr(server_ip);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    gettimeofday(&start_time, NULL);

    while (1) {
        bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            break;
        }

        total_bytes_received += bytes_received;
    }

    gettimeofday(&end_time, NULL);

    elapsed_time = ((end_time.tv_sec - start_time.tv_sec) * 1000) + ((end_time.tv_usec - start_time.tv_usec) / 1000);
    speed = (double)total_bytes_received / elapsed_time;

    printf("Internet Speed: %.2f KB/s\n", speed);

    close(sockfd);

    return 0;
}