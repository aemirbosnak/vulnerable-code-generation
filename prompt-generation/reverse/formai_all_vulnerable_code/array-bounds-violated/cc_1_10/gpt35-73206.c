//FormAI DATASET v1.0 Category: Network Ping Test ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <unistd.h>
#include <time.h>

#define PACKET_SIZE 64
#define IP_SIZE 16
#define ICMP_ECHO 8
#define ICMP_ECHOREPLY 0

struct icmp_packet
{
    struct icmphdr header;
    char message[PACKET_SIZE - sizeof(struct icmphdr)];
};

unsigned short checksum(void *b, int len)
{
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2)
    {
        sum += *buf++;
    }

    if (len == 1)
    {
        sum += *(unsigned char *)buf;
    }

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;

    return result;
}

double time_subtract(struct timespec *start, struct timespec *end)
{
    unsigned long long delta = (end->tv_sec - start->tv_sec) * 1000000000 + (end->tv_nsec - start->tv_nsec);
    return (double)delta / 1000000;
}

int ping(char *ip_address)
{
    int sock, sent_packets, received_packets, i;
    struct sockaddr_in address;
    struct icmp_packet packet;
    struct timespec start, end;

    sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);

    if (sock < 0)
    {
        printf("Error: could not create socket\n");
        return -1;
    }

    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    inet_pton(AF_INET, ip_address, &address.sin_addr);

    memset(&packet, 0, sizeof(packet));
    packet.header.type = ICMP_ECHO;
    packet.header.un.echo.id = getpid();

    sent_packets = 0;
    received_packets = 0;

    printf("Pinging %s...\n\n", ip_address);

    for (i = 0; i < 10; i++)
    {
        sent_packets++;

        packet.header.un.echo.sequence = i;
        packet.header.checksum = 0;
        packet.header.checksum = checksum(&packet, sizeof(packet));

        clock_gettime(CLOCK_MONOTONIC_RAW, &start);
        sendto(sock, &packet, sizeof(packet), 0, (struct sockaddr *)&address, sizeof(address));

        char buffer[PACKET_SIZE];
        struct sockaddr_in response_address;
        socklen_t response_address_length = sizeof(response_address);
        int response_size = recvfrom(sock, buffer, PACKET_SIZE, 0, (struct sockaddr *)&response_address, &response_address_length);
        clock_gettime(CLOCK_MONOTONIC_RAW, &end);

        if (response_size >= sizeof(struct icmphdr))
        {
            struct icmphdr *response_header = (struct icmphdr *)buffer;

            if (response_header->type == ICMP_ECHOREPLY && response_header->un.echo.id == getpid())
            {
                received_packets++;

                double elapsed_time = time_subtract(&start, &end);

                printf("Reply from %s: time=%.2lfms\n", ip_address, elapsed_time);
            }
        }

        sleep(1);
    }

    close(sock);

    printf("\nPing statistics for %s:\n", ip_address);
    printf("\tPackets: Sent = %d, Received = %d, Lost = %d (%.2lf%% loss)\n",
           sent_packets, received_packets, sent_packets - received_packets, (double)(sent_packets - received_packets) / sent_packets * 100);

    return 0;
}

int main()
{
    char ip_address[IP_SIZE];

    printf("Enter the IP address you want to ping:\n");
    fgets(ip_address, IP_SIZE, stdin);
    ip_address[strlen(ip_address) - 1] = '\0';

    ping(ip_address);

    return 0;
}