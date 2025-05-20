//Code Llama-13B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: innovative
#include <pcap.h>
#include <stdio.h>

int main(int argc, char **argv) {
    char *dev, *filter;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct pcap_pkthdr hdr;
    const u_char *packet;
    int i, ret;

    if (argc != 3) {
        printf("Usage: %s <interface> <filter>\n", argv[0]);
        return 1;
    }

    dev = argv[1];
    filter = argv[2];

    handle = pcap_create(dev, errbuf);
    if (handle == NULL) {
        printf("pcap_create() failed: %s\n", errbuf);
        return 1;
    }

    ret = pcap_activate(handle);
    if (ret != 0) {
        printf("pcap_activate() failed: %s\n", pcap_statustostr(ret));
        return 1;
    }

    ret = pcap_setfilter(handle, filter);
    if (ret != 0) {
        printf("pcap_setfilter() failed: %s\n", pcap_statustostr(ret));
        return 1;
    }

    while (1) {
        packet = pcap_next(handle, &hdr);
        if (packet == NULL) {
            printf("pcap_next() failed: %s\n", pcap_statustostr(pcap_geterr(handle)));
            return 1;
        }

        printf("Packet length: %d bytes\n", hdr.len);

        for (i = 0; i < hdr.len; i++) {
            printf("%02X ", packet[i]);
            if (i % 16 == 15) {
                printf("\n");
            }
        }

        printf("\n");
    }

    return 0;
}