//Code Llama-13B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: innovative
// pcap_capturer.c
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    pcap_if_t *alldevs, *d;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    int i = 0;
    u_int inum, in;

    // Get list of all devices
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error in pcap_findalldevs: %s\n", errbuf);
        exit(1);
    }

    // Print list of devices
    for (d = alldevs; d; d = d->next) {
        printf("%d. %s", ++i, d->name);
        if (d->description)
            printf(" (%s)\n", d->description);
        else
            printf(" (No description available)\n");
    }

    // Prompt user for device
    printf("Enter the number of the device to use: ");
    scanf("%d", &inum);

    // Check if device number is valid
    if (inum < 1 || inum > i) {
        fprintf(stderr, "Invalid device number\n");
        exit(1);
    }

    // Open device
    if ((handle = pcap_open_live(alldevs[inum].name, BUFSIZ, 1, 1000, errbuf)) == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", alldevs[inum].name, errbuf);
        exit(1);
    }

    // Loop through packets
    while (1) {
        struct pcap_pkthdr hdr;
        const u_char *pkt;

        // Get packet
        if (pcap_next_ex(handle, &hdr, &pkt) == 1) {
            // Print packet
            printf("Packet received:\n");
            for (in = 0; in < hdr.len; in++) {
                printf("%02X ", pkt[in]);
                if (in % 16 == 15)
                    printf("\n");
            }
            printf("\n");
        }
    }

    // Clean up
    pcap_close(handle);
    pcap_freealldevs(alldevs);

    return 0;
}