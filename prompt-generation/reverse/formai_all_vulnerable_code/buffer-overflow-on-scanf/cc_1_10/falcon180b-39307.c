//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <errno.h>

#define BUF_SIZE 65535
#define SNAP_LEN 1514

int main() {
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    char filter_str[100];
    char *dev;
    struct bpf_program filter;
    int ret;
    u_char *pkt_data;
    int pkt_len;
    int i;

    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        printf("Error: %s\n", errbuf);
        exit(1);
    }

    handle = pcap_open_live(dev, BUF_SIZE, 1, 0, errbuf);
    if (handle == NULL) {
        printf("Error: %s\n", errbuf);
        exit(1);
    }

    printf("Enter the filter string: ");
    scanf("%s", filter_str);

    ret = pcap_compile(handle, &filter, filter_str, 0, PCAP_NETMASK_UNKNOWN);
    if (ret == -1) {
        printf("Error: %s\n", pcap_geterr(handle));
        exit(1);
    }

    ret = pcap_setfilter(handle, &filter);
    if (ret == -1) {
        printf("Error: %s\n", pcap_geterr(handle));
        exit(1);
    }

    while (1) {
        pkt_data = pcap_next(handle, &pkt_len);
        if (pkt_data == NULL) {
            printf("Error: %s\n", pcap_geterr(handle));
            exit(1);
        }

        for (i = 0; i < pkt_len; i++) {
            if (pkt_data[i] == 0x00) {
                printf("Possible intrusion detected!\n");
                printf("Packet data: ");
                for (int j = 0; j < i; j++) {
                    printf("%02X ", pkt_data[j]);
                }
                printf("\n");
                break;
            }
        }
    }

    pcap_close(handle);
    return 0;
}