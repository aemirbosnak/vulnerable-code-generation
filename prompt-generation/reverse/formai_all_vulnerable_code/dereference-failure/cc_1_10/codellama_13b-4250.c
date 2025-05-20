//Code Llama-13B DATASET v1.0 Category: Network Packet Monitoring ; Style: random
// C Network Packet Monitoring Example Program
// Author: [Your Name]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>

// Structure to store information about the packet
typedef struct {
    unsigned int source_ip;
    unsigned int destination_ip;
    unsigned short source_port;
    unsigned short destination_port;
    unsigned int protocol;
    unsigned int packet_length;
    unsigned char *payload;
} packet_info_t;

// Function to print the packet information
void print_packet_info(packet_info_t *info) {
    printf("Source IP: %d.%d.%d.%d\n", (info->source_ip >> 24) & 0xFF, (info->source_ip >> 16) & 0xFF, (info->source_ip >> 8) & 0xFF, info->source_ip & 0xFF);
    printf("Destination IP: %d.%d.%d.%d\n", (info->destination_ip >> 24) & 0xFF, (info->destination_ip >> 16) & 0xFF, (info->destination_ip >> 8) & 0xFF, info->destination_ip & 0xFF);
    printf("Source Port: %d\n", info->source_port);
    printf("Destination Port: %d\n", info->destination_port);
    printf("Protocol: %d\n", info->protocol);
    printf("Packet Length: %d\n", info->packet_length);
    printf("Payload: %s\n", info->payload);
}

// Main function
int main() {
    // Initialize the packet capture handle
    pcap_t *handle;
    char *dev;
    char errbuf[PCAP_ERRBUF_SIZE];

    // Get the default device name
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Error: %s\n", errbuf);
        return 1;
    }

    // Open the device
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error: %s\n", errbuf);
        return 1;
    }

    // Set the filter
    struct bpf_program filter;
    char filter_exp[] = "ip";
    if (pcap_compile(handle, &filter, filter_exp, 0, 0) == -1) {
        fprintf(stderr, "Error: %s\n", pcap_geterr(handle));
        return 1;
    }
    if (pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Error: %s\n", pcap_geterr(handle));
        return 1;
    }

    // Capture the packets
    int count = 0;
    while (1) {
        struct pcap_pkthdr header;
        const unsigned char *packet;
        packet = pcap_next(handle, &header);
        if (packet == NULL) {
            break;
        }

        // Print the packet information
        packet_info_t info;
        memset(&info, 0, sizeof(packet_info_t));
        info.source_ip = (unsigned int)ntohl(*((unsigned int *)(packet + 12)));
        info.destination_ip = (unsigned int)ntohl(*((unsigned int *)(packet + 16)));
        info.source_port = (unsigned short)ntohs(*((unsigned short *)(packet + 20)));
        info.destination_port = (unsigned short)ntohs(*((unsigned short *)(packet + 22)));
        info.protocol = (unsigned int)ntohl(*((unsigned int *)(packet + 24)));
        info.packet_length = header.len;
        info.payload = packet + 42;
        print_packet_info(&info);

        count++;
    }

    // Close the device
    pcap_close(handle);

    return 0;
}