//Code Llama-13B DATASET v1.0 Category: Network Ping Test ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <sys/time.h>
#include <time.h>

#define PACKET_SIZE 64
#define TIMEOUT 10000
#define PING_COUNT 5

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];

    struct addrinfo hints, *result, *rp;
    struct sockaddr_in addr;
    int sock, i, ret;
    char buf[PACKET_SIZE];
    struct timeval tv;
    struct timezone tz;
    struct ip *ip;
    struct icmp *icmp;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_RAW;
    hints.ai_protocol = IPPROTO_ICMP;

    if ((ret = getaddrinfo(hostname, NULL, &hints, &result)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ret));
        return 1;
    }

    for (rp = result; rp != NULL; rp = rp->ai_next) {
        if (rp->ai_family == AF_INET) {
            memcpy(&addr, rp->ai_addr, rp->ai_addrlen);
            break;
        }
    }

    if (rp == NULL) {
        fprintf(stderr, "getaddrinfo: unknown hostname\n");
        return 1;
    }

    freeaddrinfo(result);

    if ((sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("socket");
        return 1;
    }

    for (i = 0; i < PING_COUNT; i++) {
        ip = (struct ip *)buf;
        icmp = (struct icmp *)(buf + sizeof(struct ip));

        ip->ip_v = 4;
        ip->ip_hl = 5;
        ip->ip_tos = 0;
        ip->ip_len = htons(sizeof(struct ip) + sizeof(struct icmp));
        ip->ip_id = htons(i);
        ip->ip_off = htons(0);
        ip->ip_ttl = 64;
        ip->ip_p = IPPROTO_ICMP;
        ip->ip_src.s_addr = INADDR_ANY;
        ip->ip_dst.s_addr = addr.sin_addr.s_addr;

        icmp->icmp_type = ICMP_ECHO;
        icmp->icmp_code = 0;
        icmp->icmp_cksum = 0;
        icmp->icmp_seq = htons(i);
        icmp->icmp_id = getpid();

        sendto(sock, buf, sizeof(struct ip) + sizeof(struct icmp), 0,
               (struct sockaddr *)&addr, sizeof(struct sockaddr_in));

        tv.tv_sec = 0;
        tv.tv_usec = TIMEOUT;
        setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));

        if ((ret = recvfrom(sock, buf, sizeof(buf), 0, NULL, NULL)) < 0) {
            perror("recvfrom");
            continue;
        }

        printf("Reply from %s: bytes=%d time=%.3f ms\n",
               inet_ntoa(addr.sin_addr), ret,
               (double)tv.tv_usec / 1000);
    }

    close(sock);

    return 0;
}