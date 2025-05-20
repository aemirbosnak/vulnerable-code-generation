//Falcon-180B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: random
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0
#define SNAPLEN 65535
#define PCAP_ERROR_BUF_SIZE 256

pcap_t *pcap_handle;
char errbuf[PCAP_ERROR_BUF_SIZE];

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet received: %d bytes\n", header->len);
}

int main() {
    char dev[100];
    char filter_str[100];
    int opt;
    int ret;
    char *net;
    char *mask;
    char *host;

    printf("Enter the network interface: ");
    scanf("%s", dev);

    printf("Enter the filter string: ");
    scanf("%s", filter_str);

    pcap_handle = pcap_open_live(dev, SNAPLEN, 1, 0, errbuf);

    if (pcap_handle == NULL) {
        printf("Error opening the network interface: %s\n", errbuf);
        exit(1);
    }

    ret = pcap_setfilter(pcap_handle, filter_str);

    if (ret!= 0) {
        printf("Error setting the filter: %s\n", errbuf);
        exit(1);
    }

    printf("Press Ctrl+C to stop capturing...\n");

    while (TRUE) {
        ret = pcap_loop(pcap_handle, -1, packet_handler, NULL);

        if (ret!= 0) {
            printf("Error capturing packets: %s\n", errbuf);
            exit(1);
        }
    }

    pcap_close(pcap_handle);
    return 0;
}