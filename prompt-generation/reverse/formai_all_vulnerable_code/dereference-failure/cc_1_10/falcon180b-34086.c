//Falcon-180B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>

// Callback function for packet capture
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet captured: %d bytes\n", header->len);
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    char dev[100];
    pcap_t *handle;
    struct bpf_program filter;

    // Get device name from user
    printf("Enter device name: ");
    scanf("%s", dev);

    // Open device for packet capture
    handle = pcap_open_live(dev, BUFSIZ, 1, 0, errbuf);
    if (handle == NULL) {
        printf("Error opening device: %s\n", errbuf);
        exit(1);
    }

    // Compile filter expression
    strcpy(filter.bf_insns, "ip");
    if (pcap_compile(handle, &filter, "ip", 0, 0)!= 0) {
        printf("Error compiling filter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    // Set filter for packet capture
    if (pcap_setfilter(handle, &filter)!= 0) {
        printf("Error setting filter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    // Start packet capture
    if (pcap_loop(handle, -1, packet_handler, NULL)!= 0) {
        printf("Error capturing packets: %s\n", pcap_geterr(handle));
        exit(1);
    }

    return 0;
}