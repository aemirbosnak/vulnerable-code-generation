//Falcon-180B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <string.h>

#define MAX_PKT_SIZE 65536
#define SNAPLEN 65535
#define BUFSIZ 1024
#define TRUE 1
#define FALSE 0

// Function prototypes
void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);
void got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);
void print_stats(pcap_t *handle);

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    char *dev, *filter_str;
    bpf_u_int32 mask, net;
    bpf_u_int32 *mask_ptr;
    struct bpf_program filter;
    int i, j, k;

    // Ask the user for the network interface to capture packets on
    printf("Enter the name of the network interface: ");
    scanf("%s", dev);

    // Set the filter to capture all packets
    filter_str = "ip";

    // Compile the filter
    if (pcap_compile(handle, &filter, filter_str, 1, mask)!= 0) {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    // Set the filter
    if (pcap_setfilter(handle, &filter)!= 0) {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    // Start capturing packets
    if (pcap_loop(handle, -1, got_packet, NULL) < 0) {
        fprintf(stderr, "Error capturing packets: %s\n", pcap_geterr(handle));
        exit(1);
    }

    // Close the capture session
    pcap_freecode(&filter);
    pcap_close(handle);

    return 0;
}

// Function to process each captured packet
void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Received packet:\n");
    printf("  Size: %d bytes\n", header->caplen);
    printf("  Data:\n");

    // Print the packet data in hexadecimal format
    for (int i = 0; i < header->caplen; i++) {
        printf("%02X ", packet[i]);
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

// Function to handle each captured packet
void got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    process_packet(args, header, packet);
}

// Function to print capture statistics
void print_stats(pcap_t *handle) {
    struct pcap_stat stat;

    if (pcap_stats(handle, &stat) == -1) {
        fprintf(stderr, "Error getting capture statistics: %s\n", pcap_geterr(handle));
        exit(1);
    }

    printf("Packets captured: %d\n", stat.ps_recv);
    printf("Packets dropped: %d\n", stat.ps_drop);
}