//Falcon-180B DATASET v1.0 Category: Network Packet Monitoring ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <netinet/ip6.h>
#include <netinet/icmp6.h>
#include <netinet/if_ether.h>
#include <net/ethernet.h>
#include <net/if.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PACKET_SIZE 1024
#define MAX_SNAPLEN 65535

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    const u_char *packet;
    struct pcap_pkthdr *header;
    int res = -1;

    handle = pcap_create("eth0", errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error creating handle: %s\n", errbuf);
        exit(1);
    }

    if (pcap_set_snaplen(handle, MAX_SNAPLEN)!= 0) {
        fprintf(stderr, "Error setting snaplen: %s\n", pcap_geterr(handle));
        exit(1);
    }

    if (pcap_set_promisc(handle, 1)!= 0) {
        fprintf(stderr, "Error setting promiscuous mode: %s\n", pcap_geterr(handle));
        exit(1);
    }

    if (pcap_activate(handle)!= 0) {
        fprintf(stderr, "Error activating handle: %s\n", pcap_geterr(handle));
        exit(1);
    }

    while ((packet = pcap_next(handle, &header))!= NULL) {
        printf("Packet received: %d bytes\n", header->len);
        printf("Src IP: %s\n", inet_ntoa(*(struct in_addr *)&(((struct iphdr *)packet)->saddr)));
        printf("Dst IP: %s\n", inet_ntoa(*(struct in_addr *)&(((struct iphdr *)packet)->daddr)));
        printf("Src Port: %d\n", ntohs(((struct tcphdr *)packet)->source));
        printf("Dst Port: %d\n", ntohs(((struct tcphdr *)packet)->dest));
        printf("Protocol: TCP\n");
    }

    pcap_close(handle);
    return 0;
}