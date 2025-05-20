//Falcon-180B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE]; // Error buffer for pcap
    pcap_t *handle; // Session handle
    char filter_exp[] = "tcp and host 192.168.1.1"; // Filter expression
    struct bpf_program fp; // BPF program
    int net = 0; // Network type
    int ret = 0; // Return value
    int i = 0; // Loop counter
    u_char *packet = NULL; // Packet buffer
    int len = 0; // Packet length
    struct pcap_pkthdr *header; // Packet header
    const u_char *pkt_data; // Packet data

    // Open capture device
    handle = pcap_open_live("eth0", 65535, 1, 0, errbuf);
    if (handle == NULL) {
        printf("Error opening capture device: %s\n", errbuf);
        exit(1);
    }

    // Set filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net)!= 0) {
        printf("Error compiling filter expression: %s\n", pcap_geterr(handle));
        exit(1);
    }

    // Set filter
    if (pcap_setfilter(handle, &fp)!= 0) {
        printf("Error setting filter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    // Loop to capture packets
    while ((packet = pcap_next(handle, &header))!= NULL) {
        // Get packet length
        len = header->caplen;

        // Get packet data
        pkt_data = packet;

        // Loop to print packet data
        for (i = 0; i < len; i++) {
            printf("%02X ", *(pkt_data + i));
        }

        // Print new line
        printf("\n");
    }

    // Close capture device
    pcap_close(handle);

    return 0;
}