//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <sys/socket.h>
#include <errno.h>
#include <time.h>

#define PACKET_SIZE     64
#define PING_REQUEST    8
#define PING_REPLY      0

typedef struct {
    struct icmphdr hdr;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
} ping_packet;

unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2)
        sum += *buf++;
    if (len == 1)
        sum += *(unsigned char *)buf;
    
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    
    result = ~sum;
    return result;
}

void ping(const char *ip_addr) {
    int sockfd;
    struct sockaddr_in addr_ping;
    ping_packet packet;
    struct timeval timeout;
    fd_set fdset;
    char recv_buf[PACKET_SIZE];
    int addr_len = sizeof(addr_ping);
    int nsent = 0, nreceived = 0;
    
    // Create raw socket
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("Socket Creation Failed");
        exit(EXIT_FAILURE);
    }
    
    // Time out for receiving
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    // Initialize packet
    memset(&packet, 0, sizeof(packet));
    packet.hdr.type = PING_REQUEST;
    packet.hdr.un.echo.id = getpid();
    strcpy(packet.msg, "Ping Test Message");
    packet.hdr.un.echo.sequence = 1;
    packet.hdr.checksum = checksum(&packet, sizeof(packet));

    addr_ping.sin_family = AF_INET;
    addr_ping.sin_addr.s_addr = inet_addr(ip_addr);

    // Send packets continuously
    while (1) {
        nsent++;
        if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&addr_ping, sizeof(addr_ping)) <= 0) {
            perror("Send Failed");
            break;
        }

        // Setting up fdset
        FD_ZERO(&fdset);
        FD_SET(sockfd, &fdset);
        
        if (select(sockfd + 1, &fdset, NULL, NULL, &timeout) > 0) {
            if (recvfrom(sockfd, recv_buf, sizeof(recv_buf), 0, (struct sockaddr *)&addr_ping, &addr_len) < 0) {
                perror("Receive Failed");
                break;
            }
            struct icmphdr *recv_hdr = (struct icmphdr *) (recv_buf + (sizeof(struct iphdr)));
            if (recv_hdr->type == PING_REPLY) {
                nreceived++;
                printf("Received reply from %s: icmp_seq=%d\n", ip_addr, recv_hdr->un.echo.sequence);
            }
        } else {
            printf("Request timed out for %d\n", nsent);
        }

        sleep(1); // Wait before sending the next ping
    }
    
    printf("\n--- %s ping statistics ---\n", ip_addr);
    printf("%d packets transmitted, %d received, %.1f%% packet loss\n", nsent, nreceived, ((nsent - nreceived) / (float)nsent) * 100);
    
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ping(argv[1]);
    return 0;
}