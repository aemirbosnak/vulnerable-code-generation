//Falcon-180B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

// Function to print the captured packet details
void print_packet_details(u_char *args, const struct pcap_pkthdr *header,
                          const u_char *packet) {
    printf("Captured Packet:\n");
    printf("-----------------\n");
    printf("Packet Length: %d\n", header->len);
    printf("Packet Data:\n");
    int i = 0;
    for (i = 0; i < header->len; i++) {
        printf("%02X ", packet[i]);
    }
    printf("\n");
}

// Callback function for capturing packets
void packet_handler(u_char *args, const struct pcap_pkthdr *header,
                    const u_char *packet) {
    print_packet_details(args, header, packet);
}

// Main function to start capturing packets
int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    char dev[100];
    struct bpf_program filter;

    // Get the name of the network interface to capture packets from
    printf("Enter the name of the network interface: ");
    scanf("%s", dev);

    // Open the network interface for capturing packets
    handle = pcap_open_live(dev, 65535, 0, 1000, errbuf);
    if (handle == NULL) {
        printf("Error: %s\n", errbuf);
        exit(1);
    }

    // Compile the filter expression to capture only TCP packets
    if (pcap_compile(handle, &filter, "tcp", 0, 0) == -1) {
        printf("Error: Unable to compile filter expression.\n");
        exit(1);
    }

    // Set the filter for capturing packets
    if (pcap_setfilter(handle, &filter) == -1) {
        printf("Error: Unable to set filter.\n");
        exit(1);
    }

    // Register the callback function for capturing packets
    pcap_loop(handle, -1, packet_handler, NULL);

    return 0;
}