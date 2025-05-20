//Falcon-180B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <errno.h>

#define PCAP_ERRBUF_SIZE 256
#define SNAPLEN 65535
#define PROMISC 1

void got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Received packet: %d bytes\n", header->caplen);
}

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    char device[100];
    char filter_str[100];
    struct bpf_program filter;
    int optimize = 1;
    int net = 0;
    int promisc = 1;
    int timeout = 0;
    int ret;

    if (argc!= 2) {
        printf("Usage: %s <device>\n", argv[0]);
        exit(1);
    }

    strcpy(device, argv[1]);

    handle = pcap_open_live(device, SNAPLEN, promisc, timeout, errbuf);

    if (handle == NULL) {
        printf("Error opening adapter: %s\n", errbuf);
        exit(1);
    }

    pcap_compile(handle, &filter, filter_str, optimize, net);
    pcap_setfilter(handle, &filter);

    ret = pcap_loop(handle, -1, got_packet, NULL);

    if (ret == -1) {
        printf("Error in pcap loop: %s\n", pcap_geterr(handle));
    } else {
        printf("Captured %d packets\n", ret);
    }

    pcap_close(handle);

    return 0;
}