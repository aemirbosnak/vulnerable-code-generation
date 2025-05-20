//Code Llama-13B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: intelligent
// Packet Capturer with pcap library

#include <pcap.h>
#include <stdio.h>

int main() {
    pcap_t *handle;
    char *dev;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct pcap_pkthdr *header;
    const u_char *packet;
    int i, ret;

    // Find the default device
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        printf("Couldn't find default device: %s\n", errbuf);
        return 1;
    }

    // Open the device for capturing
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Couldn't open device for capturing: %s\n", errbuf);
        return 1;
    }

    // Loop through the packets
    while (1) {
        ret = pcap_next_ex(handle, &header, &packet);
        if (ret == 1) {
            // Print the packet header
            printf("Packet header:\n");
            printf("\tCaptured length: %d\n", header->len);
            printf("\tOriginal length: %d\n", header->len);
            printf("\tTimestamp: %d\n", header->ts.tv_sec);

            // Print the packet data
            printf("Packet data:\n");
            for (i = 0; i < header->len; i++) {
                printf("%02x ", packet[i]);
            }
            printf("\n");
        } else if (ret == -1) {
            printf("Error occurred: %s\n", pcap_geterr(handle));
        } else if (ret == -2) {
            printf("No more packets to capture\n");
            break;
        }
    }

    // Clean up
    pcap_close(handle);

    return 0;
}