//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define SERVER_PORT "8080"
#define SERVER_ADDR "127.0.0.1"

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo server_addr;
    char buf[BUF_SIZE];
    int bytes_received;
    int total_bytes = 0;
    int packet_count = 0;
    double throughput = 0.0;
    struct timeval start_time, end_time;

    if (argc!= 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.ai_family = AF_INET;
    server_addr.ai_socktype = SOCK_STREAM;
    getaddrinfo(argv[1], SERVER_PORT, &server_addr, NULL);

    sockfd = socket(server_addr.ai_family, server_addr.ai_socktype, 0);
    if (sockfd == -1) {
        printf("Error: socket creation failed\n");
        exit(1);
    }

    printf("Socket created\n");

    if (connect(sockfd, server_addr.ai_addr, server_addr.ai_addrlen) == -1) {
        printf("Error: connection failed\n");
        exit(1);
    }

    printf("Connection established\n");

    gettimeofday(&start_time, NULL);

    while (1) {
        bytes_received = recv(sockfd, buf, BUF_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Error: data reception failed\n");
            exit(1);
        }

        total_bytes += bytes_received;
        packet_count++;

        if (packet_count == 10) {
            gettimeofday(&end_time, NULL);
            throughput = (double) total_bytes / ((end_time.tv_sec - start_time.tv_sec) +
                (end_time.tv_usec - start_time.tv_usec) / 1000000.0);

            printf("Throughput: %.2f bytes/second\n", throughput);
            packet_count = 0;
            total_bytes = 0;
            memset(buf, 0, BUF_SIZE);
        }
    }

    close(sockfd);
    return 0;
}