//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: scientific
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h>

#define PCAP_ERRBUF_SIZE 256

int main(int argc, char *argv[])
{
    char *device, *filter, errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    struct pcap_pkthdr *header;
    const u_char *packet;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <device> <filter>\n", argv[0]);
        return EXIT_FAILURE;
    }
    device = argv[1];
    filter = argv[2];

    handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live(): %s\n", errbuf);
        return EXIT_FAILURE;
    }

    if (pcap_compile(handle, &fp, filter, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "pcap_compile(): %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "pcap_setfilter(): %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    while (1) {
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == 0)
            continue;
        else if (res == -1) {
            fprintf(stderr, "pcap_next_ex(): %s\n", pcap_geterr(handle));
            break;
        }

        printf("Packet length: %d\n", header->len);
        printf("Number of bytes captured: %d\n", header->caplen);
        printf("Packet timestamp: %s\n", ctime((const time_t *)&header->ts.tv_sec));

        struct ether_header *eth_header = (struct ether_header *)packet;
        printf("Source MAC address: %02x:%02x:%02x:%02x:%02x:%02x\n",
            eth_header->ether_shost[0], eth_header->ether_shost[1],
            eth_header->ether_shost[2], eth_header->ether_shost[3],
            eth_header->ether_shost[4], eth_header->ether_shost[5]);
        printf("Destination MAC address: %02x:%02x:%02x:%02x:%02x:%02x\n",
            eth_header->ether_dhost[0], eth_header->ether_dhost[1],
            eth_header->ether_dhost[2], eth_header->ether_dhost[3],
            eth_header->ether_dhost[4], eth_header->ether_dhost[5]);

        switch (ntohs(eth_header->ether_type)) {
        case ETHERTYPE_IP:
            printf("Packet type: IPv4\n");
            break;
        case ETHERTYPE_IPV6:
            printf("Packet type: IPv6\n");
            break;
        case ETHERTYPE_ARP:
            printf("Packet type: ARP\n");
            break;
        default:
            printf("Packet type: Unknown\n");
            break;
        }

        printf("\n");
    }

    pcap_close(handle);

    return EXIT_SUCCESS;
}