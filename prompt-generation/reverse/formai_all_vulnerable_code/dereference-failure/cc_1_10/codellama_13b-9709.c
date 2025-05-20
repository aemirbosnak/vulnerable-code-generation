//Code Llama-13B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: innovative
// Packet Capturer with pcap library
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>

// Structure to hold packet header and data
struct packet {
    struct pcap_pkthdr header;
    u_char *data;
};

int main(int argc, char *argv[]) {
    // Check arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return 1;
    }

    // Open interface
    char *interface = argv[1];
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live(interface, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open interface %s: %s\n", interface, errbuf);
        return 1;
    }

    // Set filter
    struct bpf_program filter;
    char filter_str[] = "tcp and port 80";
    if (pcap_compile(handle, &filter, filter_str, 0, 0) == -1) {
        fprintf(stderr, "Could not compile filter\n");
        return 1;
    }
    if (pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Could not set filter\n");
        return 1;
    }

    // Capture packets
    struct packet *packet;
    while ((packet = pcap_next(handle, NULL))) {
        // Print packet header
        printf("Packet header:\n");
        printf("    Timestamp: %lu\n", packet->header.ts.tv_sec);
        printf("    Capture length: %u\n", packet->header.len);
        printf("    Packet length: %u\n", packet->header.caplen);

        // Print packet data
        printf("Packet data:\n");
        for (int i = 0; i < packet->header.caplen; i++) {
            printf("    %02x ", packet->data[i]);
            if (i % 16 == 15) {
                printf("\n");
            }
        }
        printf("\n");
    }

    // Clean up
    pcap_close(handle);
    return 0;
}