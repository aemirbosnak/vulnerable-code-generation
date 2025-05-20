//FormAI DATASET v1.0 Category: Network Ping Test ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>

#define PACKET_SIZE 64

struct packet
{
    struct icmphdr hdr;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
};

struct recv_packet
{
    struct iphdr iphdr;
    struct icmphdr icmphdr;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
};

unsigned short checksum(void *buffer, int len)
{
    unsigned short *ptr = (unsigned short *)buffer;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2)
        sum += *ptr++;

    if (len == 1)
        sum += *(unsigned char *)ptr;

    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    result = ~sum;

    return result;
}

double time_diff(struct timeval x , struct timeval y)
{
    double x_ms , y_ms , diff;

    x_ms = (double)x.tv_sec*1000000 + (double)x.tv_usec;
    y_ms = (double)y.tv_sec*1000000 + (double)y.tv_usec;

    diff = (double)y_ms - (double)x_ms;

    return diff;
}

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        printf("Error: Please specify a hostname or an IP address\n");
        exit(-1);
    }

    int sockfd;
    struct sockaddr_in target;
    socklen_t target_size = sizeof(target);

    target.sin_family = AF_INET;
    inet_aton(argv[1], &target.sin_addr.s_addr);

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);

    if (sockfd < 0)
    {
        printf("Error: Failed to create socket\n");
        exit(-1);
    }

    int TTL = 64;
    if (setsockopt(sockfd, IPPROTO_IP, IP_TTL, &TTL, sizeof(TTL)) < 0)
    {
        printf("Error: Failed to set TTL\n");
        exit(-1);
    }

    struct packet packet_send;
    memset(&packet_send, 0, sizeof(packet_send));
    packet_send.hdr.type = ICMP_ECHO;
    packet_send.hdr.un.echo.id = getpid();

    int i;
    for (i = 0; i < sizeof(packet_send.msg) - 1; i++)
        packet_send.msg[i] = i+'0';

    packet_send.msg[i] = 0;
    packet_send.hdr.un.echo.sequence = 0;
    packet_send.hdr.checksum = checksum(&packet_send, sizeof(packet_send));

    printf("Pinging %s [%s] with 64 bytes of data:\n", argv[1], inet_ntoa(target.sin_addr));

    int total = 0, sent = 0, lost = 0;
    double total_time = 0;

    while (total < 5)
    {
        struct timeval start_time, end_time;
        gettimeofday(&start_time, NULL);

        if (sendto(sockfd, &packet_send, sizeof(packet_send), 0, (struct sockaddr *)&target, sizeof(target)) <= 0)
        {
            printf("Error: Failed to send packet\n");
            lost++;
        }
        else
        {
            sent++;
        }

        char recv_buffer[PACKET_SIZE];
        int recv_size;

        if ((recv_size = recvfrom(sockfd, recv_buffer, PACKET_SIZE, 0, (struct sockaddr *)&target, &target_size)) <= 0)
        {
            printf("Error: Failed to receive packet\n");
            lost++;
        }
        else
        {
            struct recv_packet *packet_recv = (struct recv_packet *)recv_buffer;

            if (packet_recv->icmphdr.type == ICMP_ECHOREPLY)
            {
                printf("Reply from %s: bytes=%d time=%.2fms TTL=%d\n",
                       inet_ntoa(target.sin_addr), recv_size,
                       time_diff(start_time, end_time), packet_recv->iphdr.ttl);
            }
            else
            {
                printf("Error: Invalid packet received\n");
                lost++;
            }
        }

        gettimeofday(&end_time, NULL);
        total_time += time_diff(start_time, end_time);

        total++;
        sleep(1);
    }

    printf("\nPing statistics for %s [%s]:\n",
           argv[1], inet_ntoa(target.sin_addr));

    printf("    Packets: Sent = %d, Received = %d, Lost = %d (%.0f%% loss),\n",
           sent, sent-lost, lost, ((double)lost/(double)sent)*100);

    printf("Approximate round trip times in milli-seconds:\n");
    printf("    Minimum = %.2fms, Maximum = %.2fms, Average = %.2fms\n",
           total_time/sent, total_time/sent, total_time/sent);

    close(sockfd);
    return 0;
}