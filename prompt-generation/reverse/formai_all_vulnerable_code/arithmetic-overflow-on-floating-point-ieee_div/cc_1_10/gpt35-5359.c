//FormAI DATASET v1.0 Category: Network Ping Test ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/times.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define IP_HDR_SIZE 20
#define ICMP_HDR_SIZE 8
#define BUFFER_SIZE 1024
#define MAX_HOPS 64
#define DEFAULT_PORT 33434    // Starting port for traceroute

struct icmp_packet
{
    uint8_t type;
    uint8_t code;
    uint16_t checksum;
    uint16_t id;
    uint16_t seq_num;
};

struct ip_packet
{
    uint8_t version_and_header_length;
    uint8_t type_of_service;
    uint16_t total_length;
    uint16_t identification;
    uint16_t flags_and_fragment_offset;
    uint8_t time_to_live;
    uint8_t protocol;
    uint16_t header_checksum;
    struct in_addr source_address;
    struct in_addr destination_address;
};

double get_time()
{
    struct tms t;
    times(&t);
    return (double)t.tms_utime / sysconf(_SC_CLK_TCK);
}

uint16_t checksum(uint16_t *data, int len)
{
    uint32_t sum = 0;
    while (len > 1)
    {
        sum += *data++;
        len -= 2;
    }
    if (len == 1)
        sum += *(unsigned char *)data;
    while (sum >> 16)
        sum = (sum & 0xffff) + (sum >> 16);
    return ~sum;
}

int create_raw_socket()
{
    int s = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (s < 0)
    {
        perror("Unable to create socket");
        exit(EXIT_FAILURE);
    }
    return s;
}

void set_socket_ttl(int s, int ttl)
{
    const int val = ttl;
    if (setsockopt(s, IPPROTO_IP, IP_TTL, &val, sizeof(val)) < 0)
    {
        perror("Unable to set TTL");
        exit(EXIT_FAILURE);
    }
}

void print_address(struct in_addr address)
{
    char buffer[INET_ADDRSTRLEN];
    if (inet_ntop(AF_INET, &address, buffer, INET_ADDRSTRLEN) == NULL)
    {
        perror("Unable to convert address");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);
}

void send_ping(int s, struct sockaddr_in *dest, int ttl, int seq_num)
{
    char packet[sizeof(struct icmp_packet) + sizeof(struct timeval)];
    memset(packet, 0, sizeof(packet));

    struct icmp_packet *icmp = (struct icmp_packet *)packet;
    icmp->type = 8;
    icmp->code = 0;
    icmp->checksum = 0;
    icmp->id = getpid() & 0xFFFF;
    icmp->seq_num = seq_num;

    struct timeval *tv = (struct timeval *)(packet + sizeof(struct icmp_packet));
    gettimeofday(tv, NULL);

    icmp->checksum = checksum((uint16_t *)icmp, sizeof(struct icmp_packet) + sizeof(struct timeval));

    set_socket_ttl(s, ttl);
    if (sendto(s, packet, sizeof(packet), 0, (struct sockaddr *)dest, sizeof(*dest)) < 0)
    {
        perror("Unable to send packet");
        exit(EXIT_FAILURE);
    }
}

double receive_ping(int s, int seq_num)
{
    char buffer[BUFFER_SIZE];
    struct sockaddr_in address;
    socklen_t len = sizeof(address);
    if (recvfrom(s, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&address, &len) < 0)
    {
        perror("Unable to receive packet");
        exit(EXIT_FAILURE);
    }

    struct ip_packet *ip = (struct ip_packet *)buffer;
    int ip_hdr_size = (ip->version_and_header_length & 0x0F) * 4;
    struct icmp_packet *icmp = (struct icmp_packet *)(buffer + ip_hdr_size);
    int icmp_size = ntohs(ip->total_length) - ip_hdr_size;

    if (icmp->type != 0 || icmp->id != (getpid() & 0xFFFF) || icmp->seq_num != seq_num)
        return -1;

    struct timeval *tv_sent = (struct timeval *)(icmp + 1);
    struct timeval tv_received;
    gettimeofday(&tv_received, NULL);

    double rtt = (tv_received.tv_sec - tv_sent->tv_sec) * 1000.0 + (tv_received.tv_usec - tv_sent->tv_usec) / 1000.0;
    printf("%.2f ms\t", rtt);

    print_address(ip->source_address);

    return rtt;
}

void ping(const char *dest_address)
{
    struct sockaddr_in dest;
    memset(&dest, 0, sizeof(dest));
    dest.sin_family = AF_INET;
    if (inet_pton(AF_INET, dest_address, &dest.sin_addr) != 1)
    {
        fprintf(stderr, "Invalid address: %s", dest_address);
        exit(EXIT_FAILURE);
    }

    int s = create_raw_socket();

    int seq_num;
    double rtt = 0;
    for (int ttl = 1; ttl <= MAX_HOPS && rtt < 10000; ttl++)
    {
        printf("%d\t", ttl);

        seq_num = ttl;
        for (int i = 0; i < 3; i++)
        {
            double start_time = get_time();
            send_ping(s, &dest, ttl, seq_num);
            rtt = receive_ping(s, seq_num);
            if (rtt >= 0)
                break;
            sleep(1);
        }
        if (rtt < 0)
            printf("*\n");
    }

    close(s);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <destination>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ping(argv[1]);

    return EXIT_SUCCESS;
}