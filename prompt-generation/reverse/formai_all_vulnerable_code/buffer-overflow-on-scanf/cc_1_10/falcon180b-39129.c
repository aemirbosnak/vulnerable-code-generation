//Falcon-180B DATASET v1.0 Category: Network Packet Monitoring ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <string.h>
#include <arpa/inet.h>

#define SNAPLEN 1514
#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    char filter_expression[100];
    struct bpf_program filter;
    int ret = 0;
    int count = 0;
    u_char *packet;
    struct pcap_pkthdr header;
    const u_char *pkt_data;
    int i;
    char *dev = "eth0"; // default network interface

    if (argc > 1) {
        dev = argv[1]; // use network interface specified by user
    }

    handle = pcap_open_live(dev, SNAPLEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error: %s\n", errbuf);
        exit(1);
    }

    printf("Enter filter expression (press enter to skip): ");
    scanf("%s", filter_expression);

    if (filter_expression[0]!= '\0') {
        ret = pcap_compile(handle, &filter, filter_expression, 0, 0);
        if (ret == -1) {
            fprintf(stderr, "Error: %s\n", pcap_geterr(handle));
            exit(1);
        }
        ret = pcap_setfilter(handle, &filter);
        if (ret == -1) {
            fprintf(stderr, "Error: %s\n", pcap_geterr(handle));
            exit(1);
        }
    }

    while (count < 10) {
        ret = pcap_next_ex(handle, &header, &packet);
        if (ret == 0) {
            pkt_data = packet;
            for (i = 0; i < header.len; i++) {
                printf("%02x ", pkt_data[i]);
            }
            printf("\n");
            count++;
        }
    }

    pcap_freecode(&filter);
    pcap_close(handle);

    return 0;
}