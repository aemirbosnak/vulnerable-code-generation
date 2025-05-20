//Falcon-180B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Ada Lovelace
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);
void print_packet(const u_char *packet, int size);

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    char dev[100];
    struct bpf_program fp;
    int optimize = 1;
    int netmask = 0xffffff00;

    // Get the name of the network interface
    printf("Enter the name of the network interface: ");
    scanf("%s", dev);

    // Open the network interface
    handle = pcap_open_live(dev, 65535, 0, 1000, errbuf);
    if (handle == NULL) {
        printf("Error opening the network interface: %s\n", errbuf);
        exit(1);
    }

    // Compile the filter expression
    char filter_exp[] = "tcp or udp";
    if (pcap_compile(handle, &fp, filter_exp, 0, netmask) == -1) {
        printf("Error compiling the filter expression: %s\n", pcap_geterr(handle));
        exit(1);
    }

    // Set the filter
    if (pcap_setfilter(handle, &fp) == -1) {
        printf("Error setting the filter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    // Start capturing packets
    pcap_loop(handle, -1, process_packet, NULL);

    return 0;
}

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Received a packet with size %d\n", header->caplen);
    print_packet(packet, header->caplen);
}

void print_packet(const u_char *packet, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%02X ", packet[i]);
    }
    printf("\n");
}