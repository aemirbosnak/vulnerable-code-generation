//Falcon-180B DATASET v1.0 Category: Network Packet Monitoring ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <pcap.h>

#define BUF_SIZE 2048
#define SNAP_LEN 65535

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet received:\n");
    printf("Size: %d bytes\n", header->caplen);
    printf("Data:\n");
    for (int i = 0; i < header->caplen; i++) {
        printf("%02X ", *(packet + i));
    }
    printf("\n");
}

int main() {
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    char dev[BUF_SIZE];
    struct bpf_program filter;
    char filter_exp[BUF_SIZE];

    printf("Enter network interface: ");
    scanf("%s", dev);

    handle = pcap_open_live(dev, SNAP_LEN, 0, 1000, errbuf);
    if (handle == NULL) {
        printf("Error opening device: %s\n", errbuf);
        exit(1);
    }

    printf("Enter filter expression: ");
    scanf("%s", filter_exp);

    if (pcap_compile(handle, &filter, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        printf("Error compiling filter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    if (pcap_setfilter(handle, &filter) == -1) {
        printf("Error setting filter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    pcap_loop(handle, -1, packet_handler, NULL);

    pcap_freecode(&filter);
    pcap_close(handle);

    return 0;
}