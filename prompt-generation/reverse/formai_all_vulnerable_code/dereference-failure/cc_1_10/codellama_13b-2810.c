//Code Llama-13B DATASET v1.0 Category: Network Packet Monitoring ; Style: minimalist
/* Network Packet Monitoring Example Program */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pcap.h>
#include <err.h>

#define MAX_PACKET_SIZE 65535
#define SNAP_LEN 1024

int main(int argc, char **argv) {
    char *dev = argv[1];
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    struct pcap_pkthdr *header;
    const u_char *packet;
    int i, ret;

    handle = pcap_open_live(dev, SNAP_LEN, 1, 1000, errbuf);
    if (handle == NULL) {
        errx(1, "Couldn't open device %s: %s", dev, errbuf);
    }

    if (pcap_compile(handle, &fp, "tcp", 0, PCAP_NETMASK_UNKNOWN) == -1) {
        errx(1, "Couldn't parse filter");
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        errx(1, "Couldn't install filter");
    }

    while (1) {
        ret = pcap_next_ex(handle, &header, &packet);
        if (ret == 1) {
            printf("Packet length: %d\n", header->len);
            for (i = 0; i < header->len; i++) {
                printf("%02x ", packet[i]);
            }
            printf("\n");
        } else if (ret == -1) {
            errx(1, "Error reading packet");
        } else if (ret == -2) {
            break;
        }
    }

    pcap_close(handle);
    return 0;
}