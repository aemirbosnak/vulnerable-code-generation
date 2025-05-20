//FormAI DATASET v1.0 Category: Network Ping Test ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/ip_icmp.h> // for icmpheader struct
#include <netinet/in.h> // for in_addr struct
#include <arpa/inet.h> // for inet_pton function
#include <sys/socket.h> // for socket functions
#include <sys/time.h> // for gettimeofday function
#include <unistd.h> // for sleep function

#define PACKET_SIZE 64
#define PORT_NO 0

// checksum function for icmp header
unsigned short checksum(void *b, int len)
{
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2) {
        sum += *buf++;
    }
    if (len == 1) {
        sum += *(unsigned char *)buf;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

// ping function
void ping(struct sockaddr_in *remote, int count)
{
    struct icmp icmphdr;
    struct timeval t1, t2;
    int sockfd, seq = 1, packet_size = PACKET_SIZE;
    struct sockaddr_in from;
    socklen_t fromlen = sizeof(from);
    char packet[PACKET_SIZE];

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    memset(&icmphdr, 0, sizeof(icmphdr));
    icmphdr.icmp_type = ICMP_ECHO;
    icmphdr.icmp_id = getpid() & 0xFFFF;
    icmphdr.icmp_seq = seq++;
    memset(&packet, 0, sizeof(packet));
    memcpy(packet, &icmphdr, sizeof(icmphdr));
    gettimeofday(&t1, NULL);
    icmphdr.icmp_cksum = checksum(packet, packet_size);
    memcpy(packet, &icmphdr, sizeof(icmphdr));

    while (count--) {
        if (sendto(sockfd, packet, packet_size, 0, (struct sockaddr *)remote, sizeof(*remote)) <= 0) {
            perror("sendto");
        }
        if (recvfrom(sockfd, packet, packet_size, 0, (struct sockaddr *)&from, &fromlen) < 0) {
            perror("recvfrom");
        } else {
            gettimeofday(&t2, NULL);
            printf("Ping reply from %s, time = %ldms\n", inet_ntoa(remote->sin_addr), (t2.tv_sec-t1.tv_sec)*1000 + (t2.tv_usec-t1.tv_usec)/1000);
        }
        seq++;
        sleep(1);
    }

    close(sockfd);
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("Usage: %s <ip-address>\n", argv[0]);
        exit(1);
    }

    struct sockaddr_in remote;
    memset(&remote, 0, sizeof(remote));
    remote.sin_family = AF_INET;
    remote.sin_port = htons(PORT_NO);
    if (inet_pton(AF_INET, argv[1], &remote.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    printf("Pinging %s with 64 bytes of data:\n", argv[1]);
    ping(&remote, 3);

    return 0;
}