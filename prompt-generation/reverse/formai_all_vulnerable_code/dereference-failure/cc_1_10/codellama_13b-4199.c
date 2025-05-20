//Code Llama-13B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: careful
/*
 * packet_capturer.c
 *
 * Simple packet capturer using libpcap library
 *
 * Compile with: gcc -o packet_capturer packet_capturer.c -lpcap
 */

#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

#define MAX_PACKET_LEN 1514

int main(int argc, char **argv)
{
    char *dev;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct pcap_pkthdr header;
    const u_char *packet;
    int ret;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return 1;
    }

    dev = argv[1];

    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return 2;
    }

    while (1) {
        ret = pcap_next_ex(handle, &header, &packet);
        if (ret == 1) {
            printf("Packet length: %d\n", header.len);
            printf("Packet contents:\n");
            for (int i = 0; i < header.len; i++) {
                printf("%02x ", packet[i]);
            }
            printf("\n");
        } else if (ret == -1) {
            fprintf(stderr, "Error reading packet: %s\n", pcap_geterr(handle));
            break;
        } else if (ret == -2) {
            fprintf(stderr, "Packet too large\n");
            break;
        }
    }

    pcap_close(handle);

    return 0;
}