//Falcon-180B DATASET v1.0 Category: Network Packet Monitoring ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>

#define SNAPLEN 65535
#define BUFSIZE 1024

char *dev = NULL;
pcap_t *pcap_handle;
pcap_dumper_t *pcap_dumper;

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet captured: %d bytes\n", header->len);
}

void save_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    pcap_dump((u_char *)pcap_dumper, header, packet);
}

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    char filter_str[100];
    pcap_t *handle;
    struct bpf_program filter;

    if (argc < 3) {
        printf("Usage: %s <device> <filter>\n", argv[0]);
        exit(1);
    }

    dev = argv[1];
    strcpy(filter_str, argv[2]);

    pcap_handle = pcap_open_live(dev, SNAPLEN, 1, 100, errbuf);
    if (pcap_handle == NULL) {
        printf("Error opening device: %s\n", errbuf);
        exit(1);
    }

    if (pcap_compile(pcap_handle, &filter, filter_str, 1, 0)!= 0) {
        printf("Error compiling filter: %s\n", pcap_geterr(pcap_handle));
        exit(1);
    }

    if (pcap_setfilter(pcap_handle, &filter)!= 0) {
        printf("Error setting filter: %s\n", pcap_geterr(pcap_handle));
        exit(1);
    }

    pcap_dumper = pcap_dump_open(pcap_handle, "output.pcap");
    if (pcap_dumper == NULL) {
        printf("Error opening output file: %s\n", pcap_geterr(pcap_handle));
        exit(1);
    }

    pcap_loop(pcap_handle, -1, process_packet, NULL);

    pcap_freecode(&filter);
    pcap_close(pcap_handle);
    pcap_dump_close(pcap_dumper);

    return 0;
}