//FormAI DATASET v1.0 Category: Network Ping Test ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define PACKET_SIZE 64
#define TIMEOUT 1

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("USAGE: %s <ip address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;

    int status = getaddrinfo(argv[1], NULL, &hints, &res);
    if(status != 0) {
        printf("Could not resolve hostname: %s\n", gai_strerror(status));
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in addr = *(struct sockaddr_in *)res->ai_addr;
    freeaddrinfo(res);

    int sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(sockfd < 0) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }

    char data[PACKET_SIZE];
    memset(data, 'a', PACKET_SIZE);

    printf("PING %s (%s): %d data bytes\n", argv[1], inet_ntoa(addr.sin_addr), PACKET_SIZE);
    int sent = 0, received = 0;
    double min = 999.0, max = 0.0, avg = 0.0;
    for(int i = 1; i <= 10; i++) {
        struct timeval start_time, end_time;
        gettimeofday(&start_time, NULL);

        if(sendto(sockfd, data, PACKET_SIZE, 0, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
            perror("sendto() failed");
            continue;
        }

        sent++;
        struct sockaddr_in from_addr;
        socklen_t from_len = sizeof(from_addr);
        char recv_data[PACKET_SIZE];
        memset(recv_data, 0, PACKET_SIZE);

        fd_set rfds;
        struct timeval tv;
        FD_ZERO(&rfds);
        FD_SET(sockfd, &rfds);
        tv.tv_sec = TIMEOUT;
        tv.tv_usec = 0;

        if(select(sockfd + 1, &rfds, NULL, NULL, &tv) == 1) {
            if(recvfrom(sockfd, recv_data, PACKET_SIZE, 0, (struct sockaddr *)&from_addr, &from_len) < 0) {
                perror("recvfrom() failed");
                continue;
            }

            gettimeofday(&end_time, NULL);
            double elapsed_time = ((end_time.tv_sec - start_time.tv_sec) * 1000.0 + (end_time.tv_usec - start_time.tv_usec) / 1000.0);
            received++;
            printf("%d bytes from %s: icmp_seq=%d time=%.2f ms\n", PACKET_SIZE, inet_ntoa(from_addr.sin_addr), i, elapsed_time);

            if(elapsed_time < min) {
                min = elapsed_time;
            }

            if(elapsed_time > max) {
                max = elapsed_time;
            }

            avg += elapsed_time;
        } else {
            printf("Request timed out\n");
        }

        sleep(1);
    }

    if(sent > 0 && received > 0) {
        printf("\n--- %s ping statistics ---\n", argv[1]);
        printf("%d packets transmitted, %d packets received, %.0f%% packet loss\n", sent, received, (double)(sent - received) / sent * 100);
        printf("round-trip min/avg/max = %.2f/%.2f/%.2f ms\n", min, avg / received, max);
    }

    close(sockfd);
    return 0;
}