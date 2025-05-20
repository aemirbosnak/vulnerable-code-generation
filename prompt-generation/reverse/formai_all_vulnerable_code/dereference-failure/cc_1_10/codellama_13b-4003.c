//Code Llama-13B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: thoughtful
/*
 * C Packet Capturer with pcap library example program
 */

#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SNAP_LEN 1518
#define TIMEOUT 1000

void print_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    int i, j;
    for (i = 0; i < header->len; i++) {
        printf("%02X ", packet[i]);
        if (i % 16 == 15)
            printf("\n");
    }
}

int main(int argc, char **argv) {
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct pcap_pkthdr header;
    const u_char *packet;
    int i, j;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return 1;
    }

    handle = pcap_open_live(argv[1], SNAP_LEN, 1, TIMEOUT, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", argv[1], errbuf);
        return 2;
    }

    printf("Listening on %s...\n", argv[1]);
    while (1) {
        packet = pcap_next(handle, &header);
        if (packet == NULL)
            continue;

        print_packet(NULL, &header, packet);
    }

    return 0;
}