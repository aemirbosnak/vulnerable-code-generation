//Falcon-180B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: creative
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>

#define MAX_PACKET_SIZE 65535
#define SNAPLEN 65535

void packet_handler(u_char *user, const struct pcap_pkthdr *header, const u_char *packet) {
    int i;
    for (i = 0; i < header->caplen; i++) {
        printf("%02X ", (unsigned char)packet[i]);
    }
    printf("\n");
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    char dev[100];
    char filter_exp[100];
    int res;
    struct bpf_program fp;
    int netmask;

    // Get the name of the network interface
    printf("Enter the name of the network interface: ");
    scanf("%s", dev);

    // Open the network interface for packet capture
    handle = pcap_open_live(dev, SNAPLEN, 1, 100, errbuf);
    if (handle == NULL) {
        printf("Error opening network interface: %s\n", errbuf);
        exit(1);
    }

    // Compile the filter expression
    printf("Enter the filter expression: ");
    scanf("%s", filter_exp);

    // Compile the filter program
    res = pcap_compile(handle, &fp, filter_exp, 1, netmask);
    if (res == -1) {
        printf("Error compiling filter program: %s\n", pcap_geterr(handle));
        exit(1);
    }

    // Set the filter program for the network interface
    res = pcap_setfilter(handle, &fp);
    if (res == -1) {
        printf("Error setting filter program: %s\n", pcap_geterr(handle));
        exit(1);
    }

    // Loop to capture packets
    while (1) {
        res = pcap_loop(handle, 0, packet_handler, NULL);
        if (res == -1) {
            printf("Error looping: %s\n", pcap_geterr(handle));
            exit(1);
        }
    }

    return 0;
}