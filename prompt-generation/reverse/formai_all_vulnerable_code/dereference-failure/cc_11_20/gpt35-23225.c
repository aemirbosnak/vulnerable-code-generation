//FormAI DATASET v1.0 Category: Network Ping Test ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netdb.h>

#define BUF_SIZE 64
#define MAX_HOPS 64
#define MAX_TRIES 5
#define PING_DELAY 1000000

int main(int argc, char *argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <host>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *hostname = argv[1];
    struct sockaddr_in target;

    // Get IP address
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Unable to resolve %s\n", hostname);
        exit(EXIT_FAILURE);
    }

    // Set target address
    target.sin_family = AF_INET;
    target.sin_port = htons(0);
    target.sin_addr = *((struct in_addr*)host->h_addr);

    // Create ICMP socket
    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sock < 0) {
        fprintf(stderr, "Failed to create socket\n");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int ttl = MAX_HOPS;
    if (setsockopt(sock, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) < 0) {
        fprintf(stderr, "Failed to set TTL\n");
        exit(EXIT_FAILURE);
    }

    struct timeval timeout = {1, 0};
    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout)) < 0) {
        fprintf(stderr, "Failed to set receive timeout\n");
        exit(EXIT_FAILURE);
    }

    // Initialize packet buffer
    char packet[BUF_SIZE] = {0};
    struct icmp *icmp = (struct icmp*)packet;
    icmp->icmp_type = ICMP_ECHO;
    icmp->icmp_code = 0;
    icmp->icmp_id = htons(getpid());
    icmp->icmp_seq = 0;
    char data[BUF_SIZE - sizeof(struct icmp)];
    memset(data, 'P', BUF_SIZE - sizeof(struct icmp));
    memcpy(packet + sizeof(struct icmp), data, BUF_SIZE - sizeof(struct icmp));
    icmp->icmp_cksum = 0;
    icmp->icmp_cksum = htons(~(ICMP_ECHO << 8));

    // Start ping loop
    printf("Pinging %s...\n", hostname);

    for (int hop = 1; hop <= MAX_HOPS; hop++) {

        printf("%2d. ", hop);

        for (int i = 0; i < MAX_TRIES; i++) {

            // Build packet
            icmp->icmp_seq++;
            icmp->icmp_cksum = 0;
            icmp->icmp_cksum = htons(~(ICMP_ECHO << 8));
            if (sendto(sock, packet, BUF_SIZE, 0, (struct sockaddr*)&target, sizeof(target)) <= 0) {
                fprintf(stderr, "Failed to send packet\n");
                exit(EXIT_FAILURE);
            }

            // Wait for reply
            char recvBuf[BUF_SIZE] = {0};
            struct sockaddr_in replyAddr;
            socklen_t replyAddrLen = sizeof(replyAddr);
            struct iphdr *ip = (struct iphdr*)recvBuf;
            struct icmp *icmpReply = (struct icmp*)(recvBuf + sizeof(struct iphdr));
            int replySize = sizeof(struct iphdr) + sizeof(struct icmp);

            usleep(PING_DELAY);

            int recvSize = recvfrom(sock, recvBuf, BUF_SIZE, 0, (struct sockaddr*)&replyAddr, &replyAddrLen);
            if (recvSize < 0) {
                printf(" ???\t");
            } else if (icmpReply->icmp_type == ICMP_ECHOREPLY) {
                char *addrStr = inet_ntoa(replyAddr.sin_addr);
                printf(" %-20s", addrStr);
            } else {
                printf(" Error: %d\t", icmpReply->icmp_type);
            }
        }

        printf("\n");

        // Check if we have reached the target
        if (icmp->icmp_seq >= 5) {
            printf("\nPing finished\n");
            break;
        }
    }

    // Clean up
    close(sock);

    return EXIT_SUCCESS;
}