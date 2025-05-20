//Code Llama-13B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: optimized
/*
 * pcap_capture.c
 *
 *  Created on: Mar 2, 2023
 *      Author: 
 */

#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SNAP_LEN 65535
#define PROMISC 1
#define TO_MS 1000

void print_packet_info(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet length: %d\n", header->len);
    printf("Packet timestamp: %d\n", header->ts.tv_sec);
    printf("Packet data: %s\n", packet);
}

int main(int argc, char **argv) {
    pcap_if_t *alldevs;
    pcap_if_t *dev;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *fp;
    struct pcap_pkthdr header;
    const u_char *packet;
    int i;

    // Find the first device
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error in pcap_findalldevs: %s\n", errbuf);
        exit(1);
    }

    // Print the list of devices
    for (dev = alldevs; dev; dev = dev->next) {
        printf("%d. %s", i++, dev->name);
        if (dev->description) {
            printf(" (%s)\n", dev->description);
        } else {
            printf(" (No description available)\n");
        }
    }

    // Select the first device
    dev = alldevs;

    // Open the device
    if ((fp = pcap_open_live(dev->name, SNAP_LEN, PROMISC, TO_MS, errbuf)) == NULL) {
        fprintf(stderr, "Error in pcap_open_live: %s\n", errbuf);
        exit(1);
    }

    // Set the packet handler
    pcap_loop(fp, -1, print_packet_info, NULL);

    // Clean up
    pcap_close(fp);
    pcap_freealldevs(alldevs);

    return 0;
}