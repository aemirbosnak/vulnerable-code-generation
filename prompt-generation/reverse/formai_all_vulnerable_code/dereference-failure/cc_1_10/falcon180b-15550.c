//Falcon-180B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet captured:\n");
    printf("Size: %d\n", header->len);
    printf("Data: ");
    for (int i = 0; i < header->len; i++) {
        printf("%02X ", packet[i]);
    }
    printf("\n");
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    char filter_str[BUF_SIZE];
    struct bpf_program filter;

    handle = pcap_open_live("eth0", BUF_SIZE, 0, 0, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening capture device: %s\n", errbuf);
        exit(1);
    }

    sprintf(filter_str, "tcp port 80");
    if (pcap_compile(handle, &filter, filter_str, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    if (pcap_setfilter(handle, &filter) == -1) {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    while (1) {
        const u_char *packet;
        struct pcap_pkthdr header;

        packet = pcap_next(handle, &header);
        if (packet == NULL) {
            fprintf(stderr, "Error reading packet: %s\n", pcap_geterr(handle));
            exit(1);
        }

        process_packet(NULL, &header, packet);
    }

    pcap_close(handle);
    return 0;
}