//Code Llama-13B DATASET v1.0 Category: Network Packet Monitoring ; Style: beginner-friendly
/* C Network Packet Monitoring Example Program */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>

#define MAX_PACKET_SIZE 1500
#define SNAP_LEN 1518

int main() {
    pcap_if_t *alldevs, *dev;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct pcap_pkthdr hdr;
    u_char *packet;
    int i, ret;

    // Find all available devices
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error in pcap_findalldevs: %s\n", errbuf);
        exit(1);
    }

    // Print the list of available devices
    for (dev = alldevs; dev != NULL; dev = dev->next) {
        printf("%d. %s\n", i++, dev->name);
    }

    // Select the device and open it for packet capture
    printf("Enter the interface number: ");
    scanf("%d", &i);
    handle = pcap_open_live(alldevs[i].name, SNAP_LEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", alldevs[i].name, errbuf);
        exit(1);
    }

    // Loop until we've got 10 packets
    for (i = 0; i < 10; i++) {
        // Grab a packet from the network
        packet = (u_char *)malloc(MAX_PACKET_SIZE);
        ret = pcap_next_ex(handle, &hdr, &packet);
        if (ret == 1) {
            // Print the packet data
            printf("Packet %d\n", i);
            printf("  Timestamp: %d.%d\n", hdr.ts.tv_sec, hdr.ts.tv_usec);
            printf("  Length: %d bytes\n", hdr.len);
            printf("  Data: ");
            for (int j = 0; j < hdr.len; j++) {
                printf("%02x ", packet[j]);
            }
            printf("\n");
        } else {
            fprintf(stderr, "Error getting packet: %s\n", pcap_geterr(handle));
            exit(1);
        }
        free(packet);
    }

    pcap_close(handle);
    return 0;
}