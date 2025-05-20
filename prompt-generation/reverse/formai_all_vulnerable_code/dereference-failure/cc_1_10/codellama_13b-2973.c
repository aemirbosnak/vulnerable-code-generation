//Code Llama-13B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: sophisticated
/*
 * pcap_capture.c
 *
 * A simple pcap packet capturer program using the pcap library.
 *
 * Usage: ./pcap_capture <interface> <output_file>
 */

#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 65535

int main(int argc, char *argv[]) {
    char *interface;
    char *output_file;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct pcap_pkthdr header;
    const u_char *packet;
    FILE *fp;

    // Check command-line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <interface> <output_file>\n", argv[0]);
        exit(1);
    }

    // Get the interface and output file names
    interface = argv[1];
    output_file = argv[2];

    // Open the output file
    fp = fopen(output_file, "w");
    if (fp == NULL) {
        perror("Error opening output file");
        exit(1);
    }

    // Open the pcap handle
    handle = pcap_open_live(interface, BUFSIZE, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening pcap handle: %s\n", errbuf);
        exit(1);
    }

    // Set the pcap filter
    struct bpf_program filter;
    char filter_exp[] = "ip";
    if (pcap_compile(handle, &filter, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        exit(1);
    }
    if (pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    // Start the capture loop
    while (1) {
        packet = pcap_next(handle, &header);
        if (packet == NULL) {
            fprintf(stderr, "Error capturing packet: %s\n", pcap_geterr(handle));
            break;
        }
        fprintf(fp, "%d\n", header.caplen);
        fwrite(packet, 1, header.caplen, fp);
    }

    // Clean up
    pcap_close(handle);
    fclose(fp);

    return 0;
}