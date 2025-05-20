//Falcon-180B DATASET v1.0 Category: Network Packet Monitoring ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <arpa/inet.h>

#define MAX_DATA_SIZE 65535
#define SNAPLEN 65535
#define TRUE 1
#define FALSE 0

typedef struct {
    u_char *data;
    int len;
} pkt_data_t;

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    pkt_data_t *data = (pkt_data_t *) args;
    data->data = (u_char *) malloc(header->caplen);
    data->len = header->caplen;
    memcpy(data->data, packet, header->caplen);
}

int main(int argc, char **argv) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    char filter_exp[100] = "tcp";
    struct bpf_program fp;
    int net = 1, opt = 1;
    int ret = 0;
    pkt_data_t data;

    /* Open device */
    handle = pcap_open_live("eth0", SNAPLEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error in pcap_open_live: %s\n", errbuf);
        exit(1);
    }

    /* Set filter */
    if (pcap_compile(handle, &fp, filter_exp, 1, 0) == -1) {
        fprintf(stderr, "Error in pcap_compile\n");
        exit(1);
    }

    /* Set callback function */
    pcap_setfilter(handle, &fp);

    /* Loop to capture packets */
    while (ret!= -1) {
        ret = pcap_loop(handle, -1, process_packet, &data);
        if (ret == 1) {
            printf("Received packet of length %d\n", data.len);
            printf("Packet data: ");
            for (int i = 0; i < data.len; i++) {
                printf("%02X ", data.data[i]);
            }
            printf("\n");
        }
    }

    /* Close device */
    pcap_freecode(&fp);
    pcap_close(handle);
    return 0;
}