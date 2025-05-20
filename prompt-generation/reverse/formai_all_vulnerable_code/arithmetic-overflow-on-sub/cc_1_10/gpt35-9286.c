//FormAI DATASET v1.0 Category: Network Ping Test ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <arpa/inet.h>

#define PACKET_SIZE 4096
#define PING_TIMEOUT 1000
#define PING_INTERVAL 1000
#define MAX_PING_COUNT 5

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return -1;
    }

    struct sockaddr_in dest_addr;
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_addr.s_addr = inet_addr(argv[1]);

    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if(sockfd < 0) {
        perror("socket error");
        return -1;
    }

    char packet[PACKET_SIZE];
    memset(packet, 0, PACKET_SIZE);
    struct icmphdr *icmp = (struct icmphdr*) packet;
    icmp->type = ICMP_ECHO;
    icmp->code = 0;
    icmp->checksum = 0;
    icmp->un.echo.id = getpid();

    struct sockaddr_in from_addr;
    socklen_t from_addrlen = sizeof(from_addr);

    struct timeval start, end;
    int ping_count = 0;
    while(ping_count < MAX_PING_COUNT) {
        sleep(PING_INTERVAL / 1000);
        gettimeofday(&start, NULL);

        icmp->un.echo.sequence = ping_count++;
        icmp->checksum = 0;
        icmp->checksum = htons(~(htons(icmp->checksum + htons(sizeof(struct icmphdr))))); // checksum calculation

        int send_len = sendto(sockfd, packet, sizeof(struct icmphdr), 0, (struct sockaddr*) &dest_addr, sizeof(dest_addr));
        if(send_len < 0) {
            perror("sendto error");
            continue;
        }

        char recv_packet[PACKET_SIZE];
        memset(recv_packet, 0, PACKET_SIZE);
        fd_set fdset;
        FD_ZERO(&fdset);
        FD_SET(sockfd, &fdset);
        struct timeval timeout = {PING_TIMEOUT / 1000, (PING_TIMEOUT % 1000) * 1000}; // convert to timeval format
        int select_res = select(sockfd + 1, &fdset, NULL, NULL, &timeout);
        if(select_res <= 0) {
            printf("Request timed out.\n");
            continue;
        }

        int recv_len = recvfrom(sockfd, recv_packet, sizeof(recv_packet), 0, (struct sockaddr*) &from_addr, &from_addrlen);
        if(recv_len < 0) {
            perror("recvfrom error");
            continue;
        }

        gettimeofday(&end, NULL);
        double elapsed_time = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;
        printf("Reply from %s: bytes=%d time=%.3fms\n", inet_ntoa(from_addr.sin_addr), recv_len, elapsed_time);
    }

    close(sockfd);
    return 0;
}