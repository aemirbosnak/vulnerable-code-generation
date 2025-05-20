//FormAI DATASET v1.0 Category: Network Ping Test ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

#define TIMEOUT 3
#define MAX_ATTEMPTS 3

typedef struct icmp_hdr
{
    unsigned char type;
    unsigned char code;
    unsigned short checksum;
    unsigned short id;
    unsigned short seq_num;
} icmp_hdr;

unsigned short calculate_checksum(unsigned short *buf, int len)
{
    unsigned long sum = 0;
    while (len > 1)
    {
        sum += *buf++;
        len -= 2;
    }
    if (len == 1)
    {
        sum += *(unsigned char *)buf;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    return (unsigned short)(~sum);
}

int ping(const char *dest_ip)
{
    struct sockaddr_in dest_addr;
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = 0;
    inet_pton(AF_INET, dest_ip, &dest_addr.sin_addr);

    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0)
    {
        perror("socket() error");
        return -1;
    }

    // Set TTL value
    int ttl_val = 64;
    if (setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl_val, sizeof(ttl_val)) != 0)
    {
        perror("setsockopt() error");
        return -1;
    }

    // Set up the ICMP packet
    const int PACKET_SIZE = sizeof(icmp_hdr) + sizeof(struct timeval);
    char packet[PACKET_SIZE];
    memset(packet, 0, PACKET_SIZE);

    icmp_hdr *icmp = (icmp_hdr *)packet;
    icmp->type = 8;
    icmp->code = 0;
    icmp->checksum = 0;
    icmp->id = getpid() & 0xFFFF;
    icmp->seq_num = 0;

    struct timeval *timestamp = (struct timeval *)(packet + sizeof(icmp_hdr));
    gettimeofday(timestamp, NULL);

    icmp->checksum = calculate_checksum((unsigned short *)packet, PACKET_SIZE);

    // Send the ICMP packet
    int num_attempts = 0;
    while (num_attempts < MAX_ATTEMPTS)
    {
        if (sendto(sockfd, packet, PACKET_SIZE, 0, (struct sockaddr *)&dest_addr, sizeof(struct sockaddr_in)) < 0)
        {
            perror("sendto() error");
            return -1;
        }

        struct timeval timeout;
        timeout.tv_sec = TIMEOUT;
        timeout.tv_usec = 0;

        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(sockfd, &read_fds);

        int status = select(sockfd + 1, &read_fds, NULL, NULL, &timeout);
        if (status < 0)
        {
            perror("select() error");
            return -1;
        }
        else if (status == 0)
        {
            printf("No reply from %s\n", dest_ip);
            num_attempts++;
        }
        else
        {
            char recv_buf[PACKET_SIZE];

            struct sockaddr_in recv_addr;
            socklen_t addr_len = sizeof(struct sockaddr_in);

            if (recvfrom(sockfd, recv_buf, PACKET_SIZE, 0, (struct sockaddr *)&recv_addr, &addr_len) < 0)
            {
                perror("recvfrom() error");
                return -1;
            }

            icmp_hdr *recv_icmp = (icmp_hdr *)recv_buf;

            if ((recv_icmp->type == 0) && (recv_icmp->id == icmp->id))
            {
                struct timeval *recv_timestamp = (struct timeval *)(recv_buf + sizeof(icmp_hdr));
                struct timeval current_time;
                gettimeofday(&current_time, NULL);

                double rtt = (current_time.tv_sec - timestamp->tv_sec) * 1000.0;
                rtt += (current_time.tv_usec - timestamp->tv_usec) / 1000.0;

                printf("Reply from %s: bytes=%d time=%fms\n", dest_ip, PACKET_SIZE - sizeof(icmp_hdr) - sizeof(struct timeval), rtt);

                close(sockfd);
                return 0;
            }

            num_attempts++;
        }
    }
    printf("No reply from %s\n", dest_ip);
    close(sockfd);
    return -1;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <destination_ip>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    signal(SIGINT, SIG_IGN);

    int status = ping(argv[1]);
    if (status != 0)
    {
        printf("Ping test failed\n");
    }
    else
    {
        printf("Ping test successful\n");
    }
    return 0;
}