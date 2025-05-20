//Code Llama-13B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: optimized
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    pcap_if_t *alldevs;
    pcap_if_t *dev;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct pcap_pkthdr *header;
    const u_char *packet;
    int i, j;

    // Find the first available device
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error in pcap_findalldevs: %s\n", errbuf);
        exit(1);
    }
    for (dev = alldevs; dev != NULL; dev = dev->next) {
        if ((dev->flags & PCAP_IF_LOOPBACK) == 0) {
            break;
        }
    }
    if (dev == NULL) {
        fprintf(stderr, "Error: No available devices\n");
        exit(1);
    }

    // Open the device
    handle = pcap_open_live(dev->name, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error in pcap_open_live: %s\n", errbuf);
        exit(1);
    }

    // Loop through the packets
    while (1) {
        packet = pcap_next(handle, &header);
        if (packet == NULL) {
            break;
        }
        printf("Packet number %d:\n", ++i);
        for (j = 0; j < header->len; j++) {
            printf("%02x ", packet[j]);
        }
        printf("\n");
    }

    // Close the device
    pcap_close(handle);

    return 0;
}