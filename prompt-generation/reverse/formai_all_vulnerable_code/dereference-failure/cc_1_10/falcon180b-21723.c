//Falcon-180B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: modular
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_PACKET_SIZE 65535
#define SNAPLEN 65535
#define PCAP_ERRBUF_SIZE 256

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet captured:\n");
    printf("Length: %d\n", header->len);
    printf("Data:\n");
    for (int i = 0; i < header->len; i++) {
        printf("%02X ", packet[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    char dev[1024];
    struct bpf_program fp;
    int net = 0, mask = 0;
    int opt;
    char filter_exp[100];

    if (argc < 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        exit(1);
    }

    strcpy(dev, argv[1]);

    handle = pcap_open_live(dev, SNAPLEN, 1, 1000, errbuf);

    if (handle == NULL) {
        fprintf(stderr, "Error opening device %s: %s\n", dev, errbuf);
        exit(1);
    }

    pcap_compile(handle, &fp, filter_exp, 1, net);
    pcap_setfilter(handle, &fp);

    while (pcap_loop(handle, 0, process_packet, NULL) >= 0) {
    }

    pcap_freecode(&fp);
    pcap_close(handle);

    return 0;
}