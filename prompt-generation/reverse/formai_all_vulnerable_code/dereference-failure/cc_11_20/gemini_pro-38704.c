//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PACKETS 1000
#define PROMISC 1

int main(int argc, char *argv[])
{
    pcap_t *handle;
    char *dev, errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program fp;
    bpf_u_int32 mask, net;
    struct pcap_pkthdr *header;
    const u_char *packet;
    int i, count = 0;

    // Get the device to listen on
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        exit(1);
    }
    dev = argv[1];

    // Open the device
    handle = pcap_open_live(dev, BUFSIZ, PROMISC, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live(): %s\n", errbuf);
        exit(1);
    }

    // Get the network mask
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "pcap_lookupnet(): %s\n", errbuf);
        exit(1);
    }

    // Compile the filter
    if (pcap_compile(handle, &fp, "arp", 1, net) == -1) {
        fprintf(stderr, "pcap_compile(): %s\n", pcap_geterr(handle));
        exit(1);
    }

    // Set the filter
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "pcap_setfilter(): %s\n", pcap_geterr(handle));
        exit(1);
    }

    // Loop and print the packets
    while (1) {
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == 0) {
            continue;
        } else if (res == -1) {
            fprintf(stderr, "pcap_next_ex(): %s\n", pcap_geterr(handle));
            break;
        }

        // Check if the packet is an ARP request
        if (header->len < 28) {
            continue;
        }
        if (ntohs(*(uint16_t *)(packet + 12)) != 0x0806) {
            continue;
        }

        // Print the packet
        printf("ARP request from: %s\n", inet_ntoa(*(struct in_addr *)(packet + 28)));
        printf("  MAC address: %02x:%02x:%02x:%02x:%02x:%02x\n",
            packet[6], packet[7], packet[8], packet[9], packet[10], packet[11]);
        printf("  IP address: %s\n", inet_ntoa(*(struct in_addr *)(packet + 14)));

        count++;
        if (count >= MAX_PACKETS) {
            break;
        }
    }

    // Clean up
    pcap_close(handle);
    pcap_freecode(&fp);

    return 0;
}