//Falcon-180B DATASET v1.0 Category: Network Packet Monitoring ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <errno.h>

// Function to print the details of each packet
void process_packet(u_char* args, const struct pcap_pkthdr* header, const u_char* packet) {
    printf("Packet captured:\n");
    printf("Timestamp: %lu.%06lu\n", header->ts.tv_sec, header->ts.tv_usec);
    printf("Packet length: %d\n", header->caplen);
    printf("Packet data:\n");
    for (int i = 0; i < header->caplen; i++) {
        printf("%02X ", packet[i]);
    }
    printf("\n\n");
}

// Function to handle errors
void handle_error(char* error_message) {
    fprintf(stderr, "%s\n", error_message);
    exit(1);
}

// Main function
int main(int argc, char** argv) {
    char* dev;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* handle;
    bpf_u_int32 mask;
    bpf_u_int32 net;
    char filter_exp[100];

    // Check if the correct number of arguments are provided
    if (argc!= 3) {
        handle_error("Incorrect number of arguments. Please provide an interface and a filter expression.");
    }

    // Assign the device and filter expression
    dev = argv[1];
    strcpy(filter_exp, argv[2]);

    // Open the capture device
    handle = pcap_open_live(dev, 65535, 1, 0, errbuf);
    if (handle == NULL) {
        handle_error(errbuf);
    }

    // Compile the filter expression
    if (pcap_compile(handle, &mask, filter_exp, 1, 0)!= 0) {
        handle_error("Error compiling filter expression.");
    }

    // Set the filter
    if (pcap_setfilter(handle, &mask)!= 0) {
        handle_error("Error setting filter.");
    }

    // Get the netmask for the device
    if (pcap_lookupnet(dev, &net, &mask, errbuf)!= 0) {
        handle_error(errbuf);
    }

    // Loop to capture packets
    while (1) {
        const u_char* packet;
        struct pcap_pkthdr header;

        // Capture a packet
        packet = pcap_next(handle, &header);

        // Process the packet
        if (packet!= NULL) {
            process_packet(NULL, &header, packet);
        }
    }

    // Close the capture device
    pcap_close(handle);

    return 0;
}