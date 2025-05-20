//Code Llama-13B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Dennis Ritchie
// Packet Capturer with pcap library
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <net/ethernet.h>

int main(int argc, char *argv[]) {
    // Setup pcap interface
    char *dev;
    char *filter;
    char *errbuf;
    pcap_t *handle;

    if (argc != 3) {
        printf("Usage: %s <dev> <filter>\n", argv[0]);
        return 1;
    }

    dev = argv[1];
    filter = argv[2];

    // Setup pcap handle
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Failed to open pcap handle: %s\n", errbuf);
        return 1;
    }

    // Setup pcap filter
    struct bpf_program fp;
    if (pcap_compile(handle, &fp, filter, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        printf("Failed to compile pcap filter: %s\n", pcap_geterr(handle));
        return 1;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Failed to set pcap filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Setup pcap callback
    struct pcap_pkthdr *hdr;
    const u_char *pkt;
    int ret;

    while (1) {
        ret = pcap_next_ex(handle, &hdr, &pkt);
        if (ret == 0) {
            break;
        } else if (ret == -1) {
            printf("Failed to read pcap packet: %s\n", pcap_geterr(handle));
            return 1;
        }

        // Print packet information
        printf("Packet #%d, %d bytes\n", hdr->ts.tv_sec, hdr->len);

        // Print ethernet header
        struct ether_header *eth = (struct ether_header *)pkt;
        printf("  Ethernet: dst=%02x:%02x:%02x:%02x:%02x:%02x, src=%02x:%02x:%02x:%02x:%02x:%02x, type=%04x\n",
            eth->ether_dhost[0], eth->ether_dhost[1], eth->ether_dhost[2],
            eth->ether_dhost[3], eth->ether_dhost[4], eth->ether_dhost[5],
            eth->ether_shost[0], eth->ether_shost[1], eth->ether_shost[2],
            eth->ether_shost[3], eth->ether_shost[4], eth->ether_shost[5],
            eth->ether_type);

        // Print IP header
        struct ip *ip = (struct ip *)(pkt + sizeof(struct ether_header));
        printf("  IP: %s -> %s, protocol=%d, length=%d\n",
            inet_ntoa(ip->ip_src), inet_ntoa(ip->ip_dst),
            ip->ip_p, hdr->len - sizeof(struct ether_header));

        // Print UDP or TCP header
        if (ip->ip_p == IPPROTO_UDP) {
            struct udphdr *udp = (struct udphdr *)(pkt + sizeof(struct ether_header) + sizeof(struct ip));
            printf("  UDP: src_port=%d, dst_port=%d, length=%d\n",
                ntohs(udp->uh_sport), ntohs(udp->uh_dport),
                hdr->len - sizeof(struct ether_header) - sizeof(struct ip));
        } else if (ip->ip_p == IPPROTO_TCP) {
            struct tcphdr *tcp = (struct tcphdr *)(pkt + sizeof(struct ether_header) + sizeof(struct ip));
            printf("  TCP: src_port=%d, dst_port=%d, seq=%d, ack=%d, length=%d\n",
                ntohs(tcp->th_sport), ntohs(tcp->th_dport),
                ntohl(tcp->th_seq), ntohl(tcp->th_ack),
                hdr->len - sizeof(struct ether_header) - sizeof(struct ip));
        }
    }

    // Cleanup
    pcap_close(handle);

    return 0;
}