//Falcon-180B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <string.h>
#include <errno.h>

#define MAX_PACKET_SIZE 65536
#define SNAPLEN 65535
#define TRUE 1
#define FALSE 0

void print_packet_info(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet size: %d bytes\n", header->caplen);
    printf("Packet data:\n");
    for (int i = 0; i < header->caplen; i++) {
        printf("%02X ", packet[i]);
    }
    printf("\n");
}

void got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    print_packet_info(args, header, packet);
}

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    char dev[100];
    char filter_str[100];
    struct bpf_program filter;
    int optimize = 0;
    int net = 0;
    int mask = 0;
    int protocol = 0;
    int dst_port = 0;
    int src_port = 0;
    int ret = 0;
    int count = 0;

    if (argc < 3) {
        printf("Usage: %s <interface> <filter>\n", argv[0]);
        return 1;
    }

    strcpy(dev, argv[1]);
    strcpy(filter_str, argv[2]);

    handle = pcap_open_live(dev, SNAPLEN, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Error opening device: %s\n", errbuf);
        return 1;
    }

    if (pcap_compile(handle, &filter, filter_str, 1, net) == -1) {
        printf("Error compiling filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    if (pcap_setfilter(handle, &filter) == -1) {
        printf("Error setting filter: %s\n", pcap_geterr(handle));
        return 1;
    }

    while (count < 10) {
        ret = pcap_loop(handle, -1, got_packet, NULL);
        if (ret == -1) {
            printf("Error looping: %s\n", pcap_geterr(handle));
            return 1;
        }
        count++;
    }

    pcap_freecode(&filter);
    pcap_close(handle);

    return 0;
}