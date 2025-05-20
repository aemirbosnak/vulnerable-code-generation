//FormAI DATASET v1.0 Category: Network Ping Test ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>

#define PACKET_SIZE 64

/* Function to calculate checksum */
unsigned short calculate_checksum(unsigned short *buffer, int length) {
    unsigned long sum = 0;
    while (length > 1) {
        sum += *buffer++;
        length -= 2;
    }
    if (length == 1) {
        sum += *(unsigned char *) buffer;
    }
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    return (unsigned short) ~sum;
}

/* Function to send ICMP echo request */
int send_ping_request(int sock_fd, struct sockaddr_in *dest_addr, int seq) {
    struct icmphdr icmp_header;
    icmp_header.type = ICMP_ECHO;
    icmp_header.code = 0;
    icmp_header.checksum = 0;
    icmp_header.un.echo.id = htons(getpid());
    icmp_header.un.echo.sequence = htons(seq);

    char packet[PACKET_SIZE];
    memset(packet, 0, PACKET_SIZE);
    memcpy(packet, &icmp_header, sizeof(struct icmphdr));
    icmp_header.checksum = calculate_checksum((unsigned short *) packet, sizeof(struct icmphdr));

    memcpy(packet, &icmp_header, sizeof(struct icmphdr));
    int sent_bytes = sendto(sock_fd, packet, sizeof(packet), 0, (struct sockaddr *) dest_addr, sizeof(struct sockaddr));
    return sent_bytes;
}

/* Function to receive ICMP echo reply */
int receive_ping_reply(int sock_fd, struct sockaddr_in *dest_addr, int seq, struct timeval *start_time) {
    char packet[PACKET_SIZE];
    struct sockaddr_in from_addr;
    socklen_t from_addrlen = sizeof(struct sockaddr_in);

    int received_bytes = recvfrom(sock_fd, packet, sizeof(packet), 0, (struct sockaddr *) &from_addr, &from_addrlen);
    if (received_bytes < 0) {
        return -1;
    }

    struct timeval end_time;
    gettimeofday(&end_time, NULL);
    long time_diff = (end_time.tv_sec - start_time->tv_sec) * 1000000 + (end_time.tv_usec - start_time->tv_usec);

    struct iphdr *ip_header = (struct iphdr *) packet;
    int ip_header_len = ip_header->ihl * 4;
    struct icmphdr *icmp_header = (struct icmphdr *) (packet + ip_header_len);

    if (icmp_header->type == ICMP_ECHOREPLY && icmp_header->un.echo.id == htons(getpid()) && icmp_header->un.echo.sequence == htons(seq)) {
        printf("%d bytes from %s: icmp_seq=%d ttl=%d time=%ld us\n", received_bytes, inet_ntoa(from_addr.sin_addr), seq, ip_header->ttl, time_diff);
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <ip_address>\n", argv[0]);
        return 1;
    }

    int sock_fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sock_fd < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(struct sockaddr_in));
    dest_addr.sin_family = AF_INET;
    if (inet_aton(argv[1], &dest_addr.sin_addr) == 0) {
        printf("Invalid IP address %s\n", argv[1]);
        return 1;
    }

    // Send and receive 4 ping packets
    for (int i = 0; i < 4; i++) {
        struct timeval start_time;
        gettimeofday(&start_time, NULL);
        send_ping_request(sock_fd, &dest_addr, i);
        receive_ping_reply(sock_fd, &dest_addr, i, &start_time);
        sleep(1);
    }

    close(sock_fd);
    return 0;
}