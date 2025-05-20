//FormAI DATASET v1.0 Category: Network Ping Test ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/ip_icmp.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <unistd.h>

#define IP_HDR_SIZE 20
#define ICMP_HDR_SIZE 8
#define PACKET_SIZE 64
#define PORT_NO 0

void print_usage(char *prog_name)
{
    printf("Usage: %s <destination-IP>\n", prog_name);
    exit(EXIT_FAILURE);
}

unsigned short checksum(unsigned short *buffer, int size)
{
    unsigned long cksum = 0;
    while (size > 1)
    {
        cksum += *buffer++;
        size -= sizeof(unsigned short);
    }

    if (size)
    {
        cksum += *(unsigned char *)buffer;
    }

    cksum = (cksum >> 16) + (cksum & 0xffff);
    cksum += (cksum >> 16);

    return (unsigned short)(~cksum);
}

double timediff(struct timeval t1, struct timeval t2)
{
    if (t2.tv_usec < t1.tv_usec)
    {
        t2.tv_sec--;
        t2.tv_usec += 1000000;
    }

    double elapsed = (t2.tv_sec - t1.tv_sec) * 1000.0;
    elapsed += (t2.tv_usec - t1.tv_usec) / 1000.0;

    return elapsed;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        print_usage(argv[0]);
    }

    char *destination = argv[1];

    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);

    if (sockfd < 0)
    {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(struct sockaddr_in));

    dest_addr.sin_family = AF_INET;
    if (inet_pton(AF_INET, destination, &dest_addr.sin_addr) <= 0)
    {
        printf("Invalid IP address: %s\n", destination);
        exit(EXIT_FAILURE);
    }

    char packet[PACKET_SIZE];
    memset(packet, 0, sizeof(packet));

    struct icmphdr *icmp_header = (struct icmphdr *)packet;
    icmp_header->type = ICMP_ECHO;
    icmp_header->code = 0;
    icmp_header->checksum = 0;
    icmp_header->un.echo.id = getpid();

    for (int i = 0; i < PACKET_SIZE - ICMP_HDR_SIZE; i++)
    {
        packet[ICMP_HDR_SIZE + i] = i % 8 + '0';
    }

    icmp_header->checksum = checksum((unsigned short *)icmp_header, PACKET_SIZE);

    struct timeval start_time, end_time;

    for (int i = 1; i <= 10; i++)
    {
        printf("PING %s (%s) %d bytes of data.\n", destination,
               inet_ntoa(dest_addr.sin_addr), PACKET_SIZE);

        gettimeofday(&start_time, NULL);
        if (sendto(sockfd, packet, PACKET_SIZE, 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) < 0)
        {
            perror("sendto() failed");
        }

        char recv_packet[PACKET_SIZE];
        memset(recv_packet, 0, sizeof(recv_packet));
        struct sockaddr_in recv_addr;
        socklen_t addr_len = sizeof(struct sockaddr_in);

        if (recvfrom(sockfd, recv_packet, sizeof(recv_packet), 0, (struct sockaddr *)&recv_addr, &addr_len) < 0)
        {
            perror("recvfrom() failed");
        }
        else
        {
            struct icmphdr *recv_icmp_header = (struct icmphdr *)(recv_packet + IP_HDR_SIZE);
            if (recv_icmp_header->type == ICMP_ECHOREPLY && recv_icmp_header->un.echo.id == getpid())
            {
                gettimeofday(&end_time, NULL);
                double elapsed_time = timediff(start_time, end_time);
                printf("%d bytes from %s: icmp_seq=%d ttl=%d time=%.3f ms\n", PACKET_SIZE,
                       inet_ntoa(recv_addr.sin_addr), i, 64, elapsed_time);
            }
            else
            {
                printf("Packet error: icmp_type=%d icmp_code=%d\n",
                       recv_icmp_header->type, recv_icmp_header->code);
            }
        }

        sleep(1);
    }

    close(sockfd);

    return EXIT_SUCCESS;
}