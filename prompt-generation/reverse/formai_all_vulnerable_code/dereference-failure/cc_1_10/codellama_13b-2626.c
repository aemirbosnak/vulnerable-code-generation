//Code Llama-13B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: curious
/*
 * A curious packet capturer with pcap library
 *
 * Usage: ./packet_capturer [interface]
 *
 * Example: ./packet_capturer eth0
 */

#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PCAP_SNAPLEN 65535
#define PCAP_PROMISC 1
#define PCAP_TIMEOUT 1000

int main(int argc, char **argv) {
    pcap_t *pcap;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct pcap_pkthdr *header;
    const u_char *packet;
    int interface_index;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return 1;
    }

    interface_index = if_nametoindex(argv[1]);
    if (interface_index == 0) {
        fprintf(stderr, "Error: Invalid interface name\n");
        return 1;
    }

    pcap = pcap_open_live(argv[1], PCAP_SNAPLEN, PCAP_PROMISC, PCAP_TIMEOUT, errbuf);
    if (pcap == NULL) {
        fprintf(stderr, "Error: Could not open interface: %s\n", errbuf);
        return 1;
    }

    printf("Starting packet capture on %s\n", argv[1]);

    while (1) {
        packet = pcap_next(pcap, &header);
        if (packet == NULL) {
            break;
        }

        printf("Packet received: %ld bytes\n", header->len);

        /* Do something with the packet here */
    }

    pcap_close(pcap);

    return 0;
}