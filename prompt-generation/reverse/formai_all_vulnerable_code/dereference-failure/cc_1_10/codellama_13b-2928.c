//Code Llama-13B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: complete
/*
 * packet_capturer.c
 *
 *  Created on: Oct 14, 2022
 *      Author: John Doe
 */

#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>

#define NETWORK_INTERFACE "eth0"

int main(int argc, char *argv[]) {
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct pcap_pkthdr *header;
    const u_char *packet;

    // Open the network interface for capturing packets
    handle = pcap_open_live(NETWORK_INTERFACE, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", NETWORK_INTERFACE, errbuf);
        return 1;
    }

    // Set the filter to capture only TCP packets
    struct bpf_program filter;
    pcap_compile(handle, &filter, "tcp", 0, PCAP_NETMASK_UNKNOWN);
    pcap_setfilter(handle, &filter);

    // Loop through all the packets
    while (1) {
        packet = pcap_next(handle, &header);
        if (packet == NULL) {
            break;
        }

        // Print the packet contents
        printf("Packet number: %d\n", header->len);
        printf("Packet length: %d\n", header->caplen);
        printf("Packet timestamp: %lld\n", header->ts.tv_sec);
        printf("Packet contents: %s\n", packet);
    }

    // Close the handle
    pcap_close(handle);

    return 0;
}