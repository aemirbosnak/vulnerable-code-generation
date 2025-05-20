//Code Llama-13B DATASET v1.0 Category: Network Packet Monitoring ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <pcap.h>

#define MAX_PACKET_SIZE 4096
#define NETWORK_INTERFACE "eth0"
#define SNAPLEN 1024
#define TIMEOUT 1000

void handle_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    int size = header->len;
    char ip_buffer[INET_ADDRSTRLEN];
    char udp_buffer[INET_ADDRSTRLEN];
    char tcp_buffer[INET_ADDRSTRLEN];
    char icmp_buffer[INET_ADDRSTRLEN];
    struct in_addr src_ip;
    struct in_addr dst_ip;
    struct sockaddr_in src_addr;
    struct sockaddr_in dst_addr;
    struct ip *ip_header;
    struct udphdr *udp_header;
    struct tcphdr *tcp_header;
    struct icmp *icmp_header;

    ip_header = (struct ip *) packet;
    udp_header = (struct udphdr *) (packet + sizeof(struct ip));
    tcp_header = (struct tcphdr *) (packet + sizeof(struct ip));
    icmp_header = (struct icmp *) (packet + sizeof(struct ip));

    src_ip = ip_header->ip_src;
    dst_ip = ip_header->ip_dst;
    src_addr.sin_family = AF_INET;
    src_addr.sin_port = htons(udp_header->uh_sport);
    src_addr.sin_addr.s_addr = src_ip.s_addr;
    dst_addr.sin_family = AF_INET;
    dst_addr.sin_port = htons(udp_header->uh_dport);
    dst_addr.sin_addr.s_addr = dst_ip.s_addr;

    if (ip_header->ip_p == IPPROTO_UDP) {
        printf("UDP Packet: %s -> %s\n", inet_ntop(AF_INET, &src_ip, udp_buffer, INET_ADDRSTRLEN), inet_ntop(AF_INET, &dst_ip, udp_buffer, INET_ADDRSTRLEN));
    } else if (ip_header->ip_p == IPPROTO_TCP) {
        printf("TCP Packet: %s -> %s\n", inet_ntop(AF_INET, &src_ip, tcp_buffer, INET_ADDRSTRLEN), inet_ntop(AF_INET, &dst_ip, tcp_buffer, INET_ADDRSTRLEN));
    } else if (ip_header->ip_p == IPPROTO_ICMP) {
        printf("ICMP Packet: %s -> %s\n", inet_ntop(AF_INET, &src_ip, icmp_buffer, INET_ADDRSTRLEN), inet_ntop(AF_INET, &dst_ip, icmp_buffer, INET_ADDRSTRLEN));
    }
}

int main(int argc, char **argv) {
    pcap_if_t *alldevs;
    pcap_if_t *dev;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    int i, inum;

    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error in pcap_findalldevs: %s\n", errbuf);
        exit(1);
    }

    for (dev = alldevs, i = 0; dev != NULL; dev = dev->next, i++) {
        printf("%d. %s", i, dev->name);
        if (dev->description)
            printf(" (%s)\n", dev->description);
        else
            printf(" (No description available)\n");
    }

    if (i == 0) {
        printf("\nNo interfaces found! Make sure WinPcap is installed.\n");
        return 1;
    }

    printf("Enter the interface number (0-%d):", i);
    scanf("%d", &inum);

    if (inum < 0 || inum >= i) {
        printf("\nInterface number out of range. Choose a number between 0 and %d.\n", i);
        return 1;
    }

    dev = alldevs;
    for (i = 0; i < inum; i++) {
        dev = dev->next;
    }

    handle = pcap_open_live(dev->name, SNAPLEN, 1, TIMEOUT, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev->name, errbuf);
        return 1;
    }

    pcap_loop(handle, 0, handle_packet, NULL);

    return 0;
}