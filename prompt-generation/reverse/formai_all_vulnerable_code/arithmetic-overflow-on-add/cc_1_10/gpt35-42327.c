//FormAI DATASET v1.0 Category: Network Ping Test ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/ip_icmp.h>
#include <netinet/ip.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/select.h>

#define BUF_SIZE 1024
#define PING_SLEEP_RATE 1000000
#define PING_TIMEOUT 2
#define PING_SEND_TIMES 3

/*
 * Checksum for ICMP request/reply packets.
 */
unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2)
        sum += *buf++;

    if (len == 1)
        sum += *(unsigned char*)buf;

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

/*
 * Send echo request/reply packets for network ping.
 */
void pingHost(char *host) {
    struct sockaddr_in addr;
    int sockfd, count = 0, len;
    long tsend[PING_SEND_TIMES], trecv[PING_SEND_TIMES];
    struct timeval tvsend, tvrecv, tvinterval;
    char buf[BUF_SIZE];
    struct iphdr *ipHdr = (struct iphdr *)buf;
    struct icmphdr *icmpHdr = (struct icmphdr *)(buf+sizeof(struct iphdr));
    int seq = 0;

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(host);

    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        printf("Can not create socket for ping.\n");
        return;
    }

    while (count < PING_SEND_TIMES) {
        count++;
        memset(buf, 0, sizeof(buf));
        icmpHdr->type = ICMP_ECHO;
        icmpHdr->code = 0;
        icmpHdr->checksum = 0;
        icmpHdr->un.echo.id = getpid();

        tsend[count-1] = tvsend.tv_sec*1000000+tvsend.tv_usec;
        icmpHdr->un.echo.sequence = ++seq;
        memset(buf+sizeof(struct icmphdr), seq-'0', sizeof(buf)-sizeof(struct icmphdr));

        icmpHdr->checksum = checksum(icmpHdr, sizeof(struct icmphdr)+sizeof(long));

        if (sendto(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
            printf("Send failed!\n");
            close(sockfd);
            return;
        }

        len = sizeof(addr);
        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(sockfd, &fds);
        tvinterval.tv_sec = PING_TIMEOUT;
        tvinterval.tv_usec = 0;

        int nready = select(sockfd+1, &fds, NULL, NULL, &tvinterval);
        if (nready <= 0) {
            printf("ping %s timeout.\n", host);
            continue;
        }

        if (recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr*)&addr, &len) < 0) {
            printf("Receive failed!\n");
            close(sockfd);
            return;
        }

        gettimeofday(&tvrecv, NULL);
        trecv[count-1] = tvrecv.tv_sec*1000000+tvrecv.tv_usec;

        printf("%d bytes from %s: icmp_seq=%d ttl=%d time=%ld ms\n", ntohs(ipHdr->tot_len), host, seq, ipHdr->ttl, (trecv[count-1]-tsend[count-1])/1000);
        sleep(1);
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <ip>\n", argv[0]);
        return 1;
    }

    pingHost(argv[1]);

    return 0;
}