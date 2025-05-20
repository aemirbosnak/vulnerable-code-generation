//Falcon-180B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>

// Function prototypes
void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);
void print_packet(const u_char *packet, int size);

// Global variables
pcap_t *handle;
char *dev;
char errbuf[PCAP_ERRBUF_SIZE];

int main() {
    // Initialize variables
    dev = NULL;
    handle = NULL;

    // Get device name from user
    printf("Enter device name: ");
    scanf("%s", dev);

    // Open pcap session
    handle = pcap_open_live(dev, 65535, 1, 0, errbuf);

    if (handle == NULL) {
        printf("Error opening pcap session: %s\n", errbuf);
        exit(1);
    }

    // Set callback function
    pcap_loop(handle, 0, process_packet, NULL);

    return 0;
}

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    // Print packet details
    printf("Captured packet:\n");
    print_packet(packet, header->len);
}

void print_packet(const u_char *packet, int size) {
    // Print hex and ASCII representation of packet
    int i;
    for (i = 0; i < size; i++) {
        printf("%02x ", packet[i]);
        if (i % 16 == 15) {
            printf("\n");
        }
    }
    printf("\n");
}