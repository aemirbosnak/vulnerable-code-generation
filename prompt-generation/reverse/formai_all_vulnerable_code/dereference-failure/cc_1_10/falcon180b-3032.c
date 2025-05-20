//Falcon-180B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <string.h>

#define PCAP_BUF_SIZE 65536
#define PCAP_PROMISC 1

// Function to print packet details
void print_packet(u_char* args, const struct pcap_pkthdr* header, const u_char* packet) {
    printf("Packet size: %d\n", header->caplen);
    printf("Packet data: ");
    for (int i = 0; i < header->caplen; i++) {
        if (i % 16 == 0) {
            printf("\n");
        }
        printf("%02X ", packet[i]);
    }
    printf("\n\n");
}

// Function to handle packets
void packet_handler(u_char* args, const struct pcap_pkthdr* header, const u_char* packet) {
    print_packet(args, header, packet);
}

int main() {
    char* dev = "eth0";
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* handle;
    struct bpf_program filter;

    // Open the device for capturing
    handle = pcap_open_live(dev, PCAP_BUF_SIZE, PCAP_PROMISC, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device: %s\n", errbuf);
        exit(1);
    }

    // Compile the filter program
    if (pcap_compile(handle, &filter, "tcp and dst port 80", 0, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "Error compiling filter program: %s\n", pcap_geterr(handle));
        exit(1);
    }

    // Set the filter program
    if (pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Error setting filter program: %s\n", pcap_geterr(handle));
        exit(1);
    }

    // Loop to capture packets
    while (1) {
        u_char* packet;
        struct pcap_pkthdr header;
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == 0) {
            // Handle the packet
            packet_handler(NULL, &header, packet);
        } else if (res == -1) {
            fprintf(stderr, "Error capturing packet: %s\n", pcap_geterr(handle));
            exit(1);
        }
    }

    // Close the device
    pcap_freecode(&filter);
    pcap_close(handle);
    return 0;
}