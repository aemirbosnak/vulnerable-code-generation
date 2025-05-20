//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define MAX_BUF 2048

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip address> <port>\n", argv[0]);
        exit(1);
    }

    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) == -1) {
        perror("inet_pton");
        exit(1);
    }

    char buf[MAX_BUF];
    memset(buf, 0, sizeof(buf));
    struct timeval start_time;
    struct timeval end_time;
    int num_sent = 0;
    int num_recv = 0;
    int total_delay = 0;
    while (1) {
        // Send a packet
        gettimeofday(&start_time, NULL);
        if (sendto(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
            perror("sendto");
            exit(1);
        }
        num_sent++;

        // Receive a packet
        gettimeofday(&end_time, NULL);
        socklen_t addrlen = sizeof(servaddr);
        if (recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&servaddr, &addrlen) == -1) {
            perror("recvfrom");
            exit(1);
        }
        num_recv++;

        // Calculate the delay
        long delay = (end_time.tv_sec - start_time.tv_sec) * 1000000 + (end_time.tv_usec - start_time.tv_usec);
        total_delay += delay;

        // Print the results
        printf("%d packets sent, %d packets received, average delay %d us\n", num_sent, num_recv, total_delay / num_recv);
    }

    return 0;
}