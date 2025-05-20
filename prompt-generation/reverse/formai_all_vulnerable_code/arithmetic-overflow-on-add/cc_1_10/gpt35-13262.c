//FormAI DATASET v1.0 Category: Network Ping Test ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/ip_icmp.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>

#define MAX_PACKET_SIZE 65535
#define IP_MAXPACKET 65535

/* Structure to hold variables needed for ping test */
struct ping_test {
    int sockets;
    char *sendpacket;
    char *recvpacket;
    char *host_name;
    struct sockaddr_in dest_addr;
    int pack_size;
    int send_count;
    int recv_count;
    double min_time;
    double max_time;
    double total_time;
};

/* Function to calculate checksum */
unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum=0; len>1; len-=2)
        sum += *buf++;

    if (len==1)
        sum += *(unsigned char*)buf;

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;

    return result;
}

/* Function to initialize ping test variables */
void init_ping_test(struct ping_test *p, char *host, int pack_size) {
    struct hostent *host_entity;

    p->host_name = host;
    p->sockets = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    p->sendpacket = (char*)malloc(MAX_PACKET_SIZE);
    p->recvpacket = (char*)malloc(MAX_PACKET_SIZE);
    p->pack_size = pack_size;
    p->dest_addr.sin_family = AF_INET;

    if ((host_entity = gethostbyname(host)) == NULL) {
        printf("Unknown host %s\n", host);
        exit(EXIT_FAILURE);
    }

    memcpy((char *)&p->dest_addr.sin_addr, host_entity->h_addr, host_entity->h_length);
}

/* Function to send single ping packet */
void send_ping_packet(struct ping_test *p) {
    int pack_size = p->pack_size, send_count = p->send_count;
    struct icmp* ping_packet = (struct icmp*)p->sendpacket;

    ping_packet->icmp_type = ICMP_ECHO;
    ping_packet->icmp_code = 0;
    ping_packet->icmp_seq = send_count;
    ping_packet->icmp_id = getpid();
    memset(ping_packet->icmp_data, 0xa5, pack_size - 8);

    ping_packet->icmp_cksum = checksum(ping_packet, pack_size);
    sendto(p->sockets, p->sendpacket, pack_size, 0, (struct sockaddr *)&p->dest_addr, sizeof(p->dest_addr));
}

/* Function to receive single ping packet */
void recv_ping_packet(struct ping_test *p) {
    int sockets = p->sockets, recv_count = p->recv_count;
    struct sockaddr_in from;
    socklen_t from_len = sizeof(from);
    struct timeval recv_time;
    int len = 0;

    while (1) {
        fd_set read_fds;

        FD_ZERO(&read_fds);
        FD_SET(sockets, &read_fds);

        recv_time.tv_sec = 1;
        recv_time.tv_usec = 0;
        if (select(sockets+1, &read_fds, NULL, NULL, &recv_time) < 1)
            return;

        len = recvfrom(sockets, p->recvpacket, MAX_PACKET_SIZE, 0, (struct sockaddr *)&from, &from_len);

        if (len < 0)
            continue;
        struct iphdr *ip = (struct iphdr *)p->recvpacket;
        struct icmp *icmp = (struct icmp *)(p->recvpacket + (ip->ihl << 2));

        if ((icmp->icmp_type == ICMP_ECHOREPLY) && (icmp->icmp_id == getpid()) && (icmp->icmp_seq == recv_count)) {
            struct timeval tv_end;
            gettimeofday(&tv_end, NULL);

            double rtt_msec = (tv_end.tv_sec - icmp->icmp_data[(sizeof(struct timeval))]);
            rtt_msec = rtt_msec*1000 + (tv_end.tv_usec - icmp->icmp_data[(sizeof(struct timeval)+4)]) / 1000.0;

            printf("%d bytes from %s: icmp_seq=%u ttl=%d time=%.2f ms\n", len, p->host_name, recv_count, ip->ttl, rtt_msec);

            if (rtt_msec < p->min_time) p->min_time = rtt_msec;
            if (rtt_msec > p->max_time) p->max_time = rtt_msec;

            p->total_time += rtt_msec;
            return;
        }
    }
}

/* Main function to execute ping test */
int main(int argc, char **argv) {

    if (argc < 2) {
        printf("usage: %s <hostname> <packet_size>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int pack_size = 64;
    if(argv[2]) pack_size = atoi(argv[2]);

    struct ping_test p;
    init_ping_test(&p, argv[1], pack_size);

    memset(&p.dest_addr, 0, sizeof(p.dest_addr));

    printf("Start Pinging '%s' with %d bytes of data:\n", p.host_name, pack_size);

    int i;
    for (i = 0; i < 4; i++) {
        p.send_count++;
        send_ping_packet(&p);
        recv_ping_packet(&p);
        usleep(500000);
    }

    printf("-- PING Statistics for %s --\n", p.host_name);
    printf("%d packets transmitted, %d packets received, %.2f%% packet loss\n", p.send_count, p.recv_count, 100.0 * (p.send_count - p.recv_count) / p.send_count);

    if (p.recv_count > 0) {
        double avg_time = p.total_time / p.recv_count;

        printf("rtt min/avg/max %.2f %.2f %.2f ms\n", p.min_time, avg_time, p.max_time);
    }

    free(p.sendpacket);
    free(p.recvpacket);

    close(p.sockets);

    return 0;
}