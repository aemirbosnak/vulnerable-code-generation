//Code Llama-13B DATASET v1.0 Category: Network Packet Monitoring ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <pcap.h>

#define PACKET_BUFFER_SIZE 65536

int main(int argc, char *argv[]) {
    char *dev, *filter;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    bpf_u_int32 mask;
    bpf_u_int32 net;
    struct pcap_pkthdr header;
    const u_char *packet;
    int i, ret;

    // Parse command-line arguments
    if (argc != 3) {
        printf("Usage: %s <device> <filter>\n", argv[0]);
        exit(1);
    }
    dev = argv[1];
    filter = argv[2];

    // Open device for packet capture
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Couldn't open device %s: %s\n", dev, errbuf);
        exit(1);
    }

    // Compile filter expression
    if (pcap_compile(handle, &fp, filter, 0, net) == -1) {
        printf("Couldn't parse filter %s: %s\n", filter, pcap_geterr(handle));
        exit(1);
    }

    // Apply filter to device
    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Couldn't install filter %s: %s\n", filter, pcap_geterr(handle));
        exit(1);
    }

    // Loop through packets
    while (1) {
        packet = pcap_next(handle, &header);
        if (packet == NULL) {
            printf("End of file reached\n");
            break;
        }

        // Print packet data
        printf("Packet number %d, captured at %s\n", header.ts.tv_sec, asctime(localtime(&header.ts.tv_sec)));
        for (i = 0; i < header.len; i++) {
            printf("%02x ", packet[i]);
        }
        printf("\n");
    }

    // Clean up
    pcap_close(handle);
    return 0;
}