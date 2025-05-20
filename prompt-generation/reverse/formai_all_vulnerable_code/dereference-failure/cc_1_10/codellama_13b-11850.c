//Code Llama-13B DATASET v1.0 Category: Network Packet Monitoring ; Style: rigorous
// packet_monitor.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <pcap.h>

#define INTERFACE "eth0"
#define SNAPLEN 65535
#define PROMISC 1
#define TIMEOUT 1000

int main(int argc, char *argv[]) {
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program fp;
    bpf_u_int32 mask;
    bpf_u_int32 net;
    int i;

    // Open the network interface
    handle = pcap_open_live(INTERFACE, SNAPLEN, PROMISC, TIMEOUT, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", INTERFACE, errbuf);
        return 1;
    }

    // Compile and apply the filter
    if (pcap_compile(handle, &fp, "ip proto \\icmp", 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", "ip proto \\icmp", pcap_geterr(handle));
        return 1;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", "ip proto \\icmp", pcap_geterr(handle));
        return 1;
    }

    // Loop forever, processing packets
    while (1) {
        struct pcap_pkthdr *header;
        const u_char *packet;

        // Read the next packet from the buffer
        packet = pcap_next(handle, &header);
        if (packet == NULL) {
            break;
        }

        // Print the packet information
        printf("Packet received from %s, length %d bytes\n", INTERFACE, header->len);

        // Print the packet data
        for (i = 0; i < header->len; i++) {
            printf("%02x ", packet[i]);
        }
        printf("\n");
    }

    // Clean up
    pcap_close(handle);

    return 0;
}