//FormAI DATASET v1.0 Category: Network Ping Test ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>

#define IP_ADDR_LEN 20
#define IP_HDR_SIZE 20
#define ICMP_HDR_SIZE 8
#define PACKET_SIZE 64
#define MAX_HOPS 30

int main(int argc, char *argv[])
{
    int sockfd, rc, ttl, count, max_hops, success = 0;
    char *dst_addr_str;
    struct sockaddr_in dst_addr, recv_addr;
    struct iphdr *ip_hdr;
    struct icmphdr *icmp_hdr;
    char send_packet[PACKET_SIZE], recv_packet[PACKET_SIZE];
    socklen_t addr_len = sizeof(recv_addr);
    
    if (argc != 2) {
        printf("Usage: %s <dst_ip>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    dst_addr_str = argv[1];
    max_hops = MAX_HOPS;
    memset(&dst_addr, 0, sizeof(dst_addr));
    dst_addr.sin_family = AF_INET;
    inet_aton(dst_addr_str, &dst_addr.sin_addr);
    
    if (dst_addr.sin_addr.s_addr == INADDR_NONE) {
        printf("Invalid address: %s\n", dst_addr_str);
        return EXIT_FAILURE;
    }
    
    printf("PING %s\n", dst_addr_str);
    
    for (ttl = 1; ttl <= max_hops && !success; ++ttl) {
        sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
        if (sockfd < 0) {
            perror("socket()");
            return EXIT_FAILURE;
        }

        if (setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) < 0) {
            perror("setsockopt()");
            return EXIT_FAILURE;
        }

        memset(&send_packet, 0, PACKET_SIZE);
        icmp_hdr = (struct icmphdr*)send_packet;
        icmp_hdr->type = ICMP_ECHO;
        icmp_hdr->code = 0;
        icmp_hdr->checksum = 0;
        icmp_hdr->un.echo.id = getpid();
        icmp_hdr->un.echo.sequence = count++;

        memset(&recv_packet, 0, PACKET_SIZE);
        struct timeval timeout;
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;
        if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
            perror("setsockopt()");
            return EXIT_FAILURE;
        }

        if (sendto(sockfd, &send_packet, ICMP_HDR_SIZE, 0, (struct sockaddr *)&dst_addr, sizeof(dst_addr)) < 0) {
            perror("sendto()");
            return EXIT_FAILURE;
        }

        rc = recvfrom(sockfd, recv_packet, PACKET_SIZE, 0, (struct sockaddr*)&recv_addr, &addr_len);

        if (rc <= 0) {
            printf("%2d   %15s   *\n", ttl, inet_ntoa(dst_addr.sin_addr));
            close(sockfd);
            continue;
        }

        ip_hdr = (struct iphdr*)recv_packet;
        icmp_hdr = (struct icmphdr*)(recv_packet + IP_HDR_SIZE);
        if (icmp_hdr->type == ICMP_ECHOREPLY) {
            success = 1;
            printf("%2d   %15s   %.3fms\n", ttl, inet_ntoa(recv_addr.sin_addr), (double)rc*1000/1000000);
        } else {
            printf("%2d   %15s   *\n", ttl, inet_ntoa(recv_addr.sin_addr));
        }

        close(sockfd);
    }
    
    return EXIT_SUCCESS;
}