//Code Llama-13B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: standalone
/*
 * packet_capturer.c
 *
 * A simple C program that uses the pcap library to capture packets
 * and print them to the console.
 */

#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

int main(int argc, char *argv[]) {
    pcap_t *handle;
    char *dev;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct pcap_pkthdr *header;
    const u_char *packet;

    // Check the number of arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <device>\n", argv[0]);
        return 1;
    }

    // Open the device for capturing
    dev = argv[1];
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return 1;
    }

    // Loop forever, printing packets as they arrive
    while (1) {
        // Grab a packet from the device
        packet = pcap_next(handle, &header);
        if (packet == NULL) {
            fprintf(stderr, "Error while reading from device: %s\n", pcap_geterr(handle));
            return 1;
        }

        // Print the packet to the console
        printf("Packet %u: %u bytes\n", header->len, packet);
    }

    // Close the device when we're done
    pcap_close(handle);

    return 0;
}