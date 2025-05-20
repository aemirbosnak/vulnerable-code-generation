//FormAI DATASET v1.0 Category: Network Ping Test ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <time.h>

#define PACKET_LENGTH 16
#define PING_TIMEOUT 2
#define PING_DELAY 1000000

struct ping_packet
{
    struct icmphdr hdr;
    char msg[PACKET_LENGTH - sizeof(struct icmphdr)];
};

void shape_shift(char* message)
{
    int len = strlen(message);
    int i;

    for(i = 0; i < len; i++)
    {
        if(message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] -= 32;
        }
        else if(message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] += 32;
        }
    }
}

unsigned short calculate_checksum(void* buf, int len)
{
    unsigned short* p = (unsigned short*)buf;
    int nleft = len;
    unsigned int sum = 0;
    unsigned short ans = 0;

    while(nleft > 1)
    {
        sum += *p++;
        nleft -= 2;
    }

    if(nleft == 1)
    {
        *(unsigned char*)(&ans) = *(unsigned char*)p;
        sum += ans;
    }

    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    ans = ~sum;
    return ans;
}

void ping(char* ip_address)
{
    int sockfd;
    struct sockaddr_in addr;
    char sendbuf[PACKET_LENGTH];
    char recvbuf[PACKET_LENGTH];
    int send_size, recv_size;
    struct ping_packet* ping_pkt;
    struct icmphdr* icmp_hdr;
    struct timespec begin_time, end_time;
    double rtt;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);

    if(sockfd < 0)
    {
        printf("Error: socket creation failed.\n");
        exit(-1);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_address);

    ping_pkt = (struct ping_packet*)sendbuf;
    icmp_hdr = &(ping_pkt->hdr);
    icmp_hdr->type = ICMP_ECHO;
    icmp_hdr->code = 0;
    icmp_hdr->checksum = 0;
    icmp_hdr->un.echo.id = getpid();
    icmp_hdr->un.echo.sequence = 0;
    memset(&(ping_pkt->msg), 0, PACKET_LENGTH - sizeof(struct icmphdr));
    send_size = PACKET_LENGTH;

    clock_gettime(CLOCK_MONOTONIC, &begin_time);

    icmp_hdr->checksum = calculate_checksum(icmp_hdr, send_size);
    if(sendto(sockfd, sendbuf, send_size, 0, (struct sockaddr*)&addr, sizeof(addr)) < 0)
    {
        printf("Error: sending ping failed.\n");
        exit(-1);
    }

    memset(recvbuf, 0, PACKET_LENGTH);
    recv_size = recv(sockfd, recvbuf, PACKET_LENGTH, 0);

    clock_gettime(CLOCK_MONOTONIC, &end_time);

    if(recv_size <= 0)
    {
        printf("Error: no response received from the host.\n");
    }
    else
    {
        rtt = (end_time.tv_sec - begin_time.tv_sec) * 1000.0 + (end_time.tv_nsec - begin_time.tv_nsec) / 1000000.0;

        shape_shift(ping_pkt->msg);

        printf("Ping response from %s: message='%s', time=%.0fms\n", ip_address, ping_pkt->msg, rtt);
    }

    close(sockfd);
}

int main(void)
{
    char* ip_address = "8.8.8.8";

    while(1)
    {
        ping(ip_address);
        usleep(PING_DELAY);
    }

    return 0;
}