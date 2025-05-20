//FormAI DATASET v1.0 Category: Network Ping Test ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <unistd.h>

#define PACKET_SIZE 64
#define MAX_WAIT_TIME 5
#define MAX_NO_PACKETS 3

typedef struct {
    struct timeval tv_begin; //time when the ping is sent
    struct timeval tv_end; //time when the ping is received
    short num_send; //number of packets sent
    short num_recv; //number of packets received
}ping_packet;

char *target_addr = "127.0.0.1";

unsigned short cal_chksum(unsigned short *addr, int len)
{
    int sum = 0;
    unsigned short cksum = 0;

    while(len > 1)
    {
        sum += *addr++;
        len -= 2;
    }

    if(len == 1)
    {
        *((unsigned char *)&cksum) = *((unsigned char *)addr);
        sum += cksum;
    }

    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    cksum = ~sum;

    return cksum;
}

int pack_icmp_packet(char *send_buf, int seq)
{
    struct icmp *icmp;
    icmp = (struct icmp *)send_buf;
    icmp->icmp_type = ICMP_ECHO;
    icmp->icmp_code = 0;
    icmp->icmp_cksum = 0;
    icmp->icmp_id = getpid();
    icmp->icmp_seq = seq;
    memset(icmp->icmp_data, 'a', PACKET_SIZE - sizeof(struct icmp));
    gettimeofday((struct timeval *)icmp->icmp_data, NULL);
    icmp->icmp_cksum = cal_chksum((unsigned short *)icmp, PACKET_SIZE);

    return PACKET_SIZE;
}

int unpack_icmp_packet(char *recv_buf, int len, struct sockaddr_in *from)
{
    struct ip *ip;
    struct icmp *icmp;
    struct timeval *tv_send;
    double rtt;

    ip = (struct ip *)recv_buf;
    int ip_hdr_len = ip->ip_hl << 2;
    icmp = (struct icmp *)(recv_buf + ip_hdr_len);
    len -= ip_hdr_len;

    if(len < 8)
    {
        printf("ICMP packet received with invalid length.\n");
        return -1;
    }

    if((icmp->icmp_type == ICMP_ECHOREPLY) && (icmp->icmp_id == getpid()))
    {
        tv_send = (struct timeval *)icmp->icmp_data;
        gettimeofday(&(((ping_packet *)icmp->icmp_data)->tv_end), NULL);
        return (int)((icmp->icmp_seq << 16) | (unsigned short)(rtt * 1000));
    }

    return -1;
}

void ping()
{
    int sockfd, size;
    char send_buf[PACKET_SIZE], recv_buf[PACKET_SIZE];
    struct sockaddr_in target_addr_in;
    target_addr_in.sin_family = AF_INET;
    target_addr_in.sin_addr.s_addr = inet_addr(target_addr);
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);

    if(sockfd < 0)
    {
        printf("Can not create socket.\n");
        exit(1);
    }

    ping_packet packet_data[MAX_NO_PACKETS];
    int over = 0;

    for(int i = 0; i < MAX_NO_PACKETS; i++)
    {
        packet_data[i].num_send = i;
        packet_data[i].num_recv = 0;
        gettimeofday(&packet_data[i].tv_begin, NULL);
        size = pack_icmp_packet(send_buf, i);

        if(sendto(sockfd, send_buf, size, 0, (struct sockaddr *)&target_addr_in, sizeof(target_addr_in)) < 0)
        {
            printf("Can not send to %s.\n", target_addr);
            packet_data[i].num_send = -1;
            over = 1;
        }

        sleep(1);
    }

    int recv_count = 0;

    while(recv_count < MAX_NO_PACKETS && !over)
    {
        fd_set fds;
        struct timeval tv;

        memset(&tv, 0, sizeof(tv));
        tv.tv_sec = MAX_WAIT_TIME;
        tv.tv_usec = 0;

        FD_ZERO(&fds);
        FD_SET(sockfd, &fds);

        int ret = select(sockfd + 1, &fds, NULL, NULL, &tv);

        switch(ret)
        {
            case -1:
            {
                printf("Select failed!\n");
                break;
            }
            case 0:
            {
                printf("Time out!\n");
                over = 1;
                break;
            }
            default:
            {
                int size = sizeof(target_addr_in);
                int times = recvfrom(sockfd, recv_buf, PACKET_SIZE, 0, (struct sockaddr *)&target_addr_in, (socklen_t *)&size);

                if(unpack_icmp_packet(recv_buf, times, &target_addr_in) == -1)
                {
                    continue;
                }

                recv_count++;
                break;
            }
        }
    }

    double total_time = 0;
    int lost_count = 0;

    for(int i = 0; i < MAX_NO_PACKETS; i++)
    {
        if(packet_data[i].num_send != -1)
        {
            if(packet_data[i].num_recv == 0)
            {
                printf("Lost packet %d\n", i);
                lost_count++;
            }
            else
            {
                double time_ms = (packet_data[i].tv_end.tv_sec - packet_data[i].tv_begin.tv_sec) * 1000.0 + (packet_data[i].tv_end.tv_usec - packet_data[i].tv_begin.tv_usec) / 1000.0;
                total_time += time_ms;
                printf("Received packet %d, rtt=%f ms\n", i, time_ms);
            }
        }
    }

    printf("%d packets sent, %d received, %.2f%% lost, rtt_avg=%f ms\n", MAX_NO_PACKETS, MAX_NO_PACKETS-lost_count, (lost_count * 100.0) / MAX_NO_PACKETS, total_time / (MAX_NO_PACKETS-lost_count));
    close(sockfd);
}

int main()
{
    ping();
    return 0;
}