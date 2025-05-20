//Code Llama-13B DATASET v1.0 Category: Network Packet Monitoring ; Style: curious
/*
 * Curious Network Packet Monitoring Example Program
 *
 * This program demonstrates how to use the libpcap library to capture and
 * display network packets on a Linux system.
 */

#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>

#define SNAP_LEN 1518

int main(int argc, char *argv[]) {
    char *dev, errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct pcap_pkthdr hdr;
    const u_char *pkt_data;
    int i, ret;

    // Check for the correct number of command-line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return 1;
    }

    // Get the name of the network interface to capture packets from
    dev = argv[1];

    // Open the capture device
    handle = pcap_open_live(dev, SNAP_LEN, 0, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", dev, errbuf);
        return 1;
    }

    // Capture packets and print their data
    while (1) {
        ret = pcap_next_ex(handle, &hdr, &pkt_data);
        if (ret == 1) {
            // Print the packet data
            printf("Packet %ld: ", hdr.len);
            for (i = 0; i < hdr.len; i++) {
                printf("%02x ", pkt_data[i]);
            }
            printf("\n");
        } else if (ret == -1) {
            fprintf(stderr, "Error reading packet: %s\n", pcap_geterr(handle));
        } else if (ret == -2) {
            break;
        }
    }

    // Close the capture device
    pcap_close(handle);

    return 0;
}