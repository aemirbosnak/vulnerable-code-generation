//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

#define MAXBYTES2CAPTURE 2048

int main(int argc, char *argv[]) {
    int i;
    pcap_t *descr;
    char errbuf[PCAP_ERRBUF_SIZE];
    char *device = NULL;
    bpf_u_int32 netaddr = 0, mask = 0;
    struct bpf_program filter;
    char filter_string[] = "tcp";
    struct pcap_pkthdr hdr;
    const unsigned char *packet;

    // Get the name of network device
    if(argc == 2) {
        device = argv[1];
    }
    else if(argc > 2) {
        printf("Usage: %s [device]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    else {
        device = pcap_lookupdev(errbuf);
        if(device == NULL) {
            printf("pcap_lookupdev(): %s\n", errbuf);
            exit(EXIT_FAILURE);
        }
    }

    // Get the network address and mask
    if(pcap_lookupnet(device, &netaddr, &mask, errbuf) == -1) {
        printf("pcap_lookupnet(): %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    // Open the device for live capture
    descr = pcap_open_live(device, MAXBYTES2CAPTURE, 1, 0, errbuf);
    if(descr == NULL) {
        printf("pcap_open_live(): %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    // Compile the filter string
    if(pcap_compile(descr, &filter, filter_string, 0, netaddr) == -1) {
        printf("pcap_compile(): %s\n", pcap_geterr(descr));
        exit(EXIT_FAILURE);
    }

    // Set the filter
    if(pcap_setfilter(descr, &filter) == -1) {
        printf("pcap_setfilter(): %s\n", pcap_geterr(descr));
        exit(EXIT_FAILURE);
    }

    printf("Listening on %s...\n", device);

    // Start the capture loop
    while(1) {
        packet = pcap_next(descr, &hdr);
        if(packet == NULL) {
            continue;
        }

        printf("Packet captured: ");
        for(i = 0; i < hdr.caplen; i++) {
            printf("%02x ", *(packet + i));
        }
        printf("\n");
    }

    // Close the descriptor
    pcap_close(descr);

    return 0;
}