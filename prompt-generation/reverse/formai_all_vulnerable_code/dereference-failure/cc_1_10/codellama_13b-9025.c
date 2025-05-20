//Code Llama-13B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Ken Thompson
/*
 * pcap_capture.c
 *
 * A unique C packet capturer using the pcap library
 *
 * By Ken Thompson
 */

#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

#define SNAP_LEN 65535

int main(int argc, char *argv[]) {
    char *dev, errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct pcap_pkthdr hdr;
    const u_char *pkt;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        exit(1);
    }

    dev = argv[1];

    handle = pcap_open_live(dev, SNAP_LEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", dev, errbuf);
        exit(1);
    }

    while (1) {
        pkt = pcap_next(handle, &hdr);
        if (pkt == NULL) {
            fprintf(stderr, "Error while capturing packet\n");
            break;
        }

        printf("Packet length: %d bytes\n", hdr.len);
        printf("Packet data:\n");
        for (int i = 0; i < hdr.len; i++) {
            printf("%02x ", pkt[i]);
        }
        printf("\n");
    }

    pcap_close(handle);
    return 0;
}