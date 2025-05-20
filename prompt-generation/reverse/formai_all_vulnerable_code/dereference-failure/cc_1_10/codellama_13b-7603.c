//Code Llama-13B DATASET v1.0 Category: Network Packet Monitoring ; Style: statistical
// PacketMonitor.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pcap.h>

#define BUFSIZE 1024
#define DEV "eth0"
#define SNAPLEN 65535
#define PROMISC 1
#define TIMEOUT 1000

int main(int argc, char **argv) {
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct pcap_pkthdr header;
    const u_char *packet;
    int i, j, k;

    // Initialize packet capture
    handle = pcap_open_live(DEV, SNAPLEN, PROMISC, TIMEOUT, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", DEV, errbuf);
        return 1;
    }

    // Loop forever, reading packets from the network and printing their contents
    while (1) {
        packet = pcap_next(handle, &header);
        if (packet == NULL) {
            fprintf(stderr, "Failed to read packet\n");
            continue;
        }

        // Print the packet's source and destination addresses
        printf("Source: ");
        for (i = 0; i < 6; i++) {
            printf("%02x:", packet[i]);
        }
        printf("\n");

        printf("Destination: ");
        for (i = 6; i < 12; i++) {
            printf("%02x:", packet[i]);
        }
        printf("\n");

        // Print the packet's EtherType
        printf("EtherType: 0x%04x\n", packet[12] * 256 + packet[13]);

        // Print the packet's data
        printf("Data: ");
        for (i = 14; i < header.len; i++) {
            printf("%02x ", packet[i]);
        }
        printf("\n\n");
    }

    // Close the handle and exit
    pcap_close(handle);
    return 0;
}