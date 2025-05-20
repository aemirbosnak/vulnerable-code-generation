//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>

#define MAX_HOSTNAME 256
#define MAX_DATA_SIZE 1024
#define TIME_OUT 5000 // in milliseconds

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    char hostname[MAX_HOSTNAME];
    strcpy(hostname, argv[1]);

    int sockfd;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(7);
    inet_pton(AF_INET, hostname, &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    char send_data[MAX_DATA_SIZE] = "PING";
    int send_len = strlen(send_data);

    send(sockfd, send_data, send_len, 0);

    char recv_data[MAX_DATA_SIZE];
    int recv_len;

    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);

    while (1) {
        memset(recv_data, 0, sizeof(recv_data));
        recv_len = recv(sockfd, recv_data, sizeof(recv_data), 0);

        if (recv_len <= 0) {
            printf("No response from host\n");
            break;
        }

        if (strcmp(recv_data, "PONG") == 0) {
            printf("Host is alive\n");
            break;
        }
    }

    gettimeofday(&end_time, NULL);
    long time_diff = (end_time.tv_sec - start_time.tv_sec) * 1000 + (end_time.tv_usec - start_time.tv_usec) / 1000;

    if (time_diff > TIME_OUT) {
        printf("Host is unreachable or not responding\n");
    } else {
        printf("Round trip time: %ld milliseconds\n", time_diff);
    }

    close(sockfd);
    return 0;
}