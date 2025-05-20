//Falcon-180B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <string.h>

#define SNAPLEN 65535
#define PCAP_ERRBUF_SIZE 256

void print_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet received: %d bytes\n", header->len);
    printf("Data: ");
    for (int i = 0; i < header->len; i++) {
        printf("%02X ", packet[i]);
    }
    printf("\n");
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    char dev[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    const u_char *packet;
    struct pcap_pkthdr header;

    printf("Enter interface name: ");
    scanf("%s", dev);

    // Open the session
    handle = pcap_open_live(dev, SNAPLEN, 1, 0, errbuf);

    if (handle == NULL) {
        printf("Error opening session: %s\n", errbuf);
        return 1;
    }

    printf("Session opened successfully\n");

    while (1) {
        // Capture a packet
        packet = pcap_next(handle, &header);

        if (packet == NULL) {
            printf("Error capturing packet\n");
            break;
        }

        // Print the packet
        print_packet(NULL, &header, packet);
    }

    pcap_close(handle);
    printf("Session closed\n");

    return 0;
}