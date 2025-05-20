//Falcon-180B DATASET v1.0 Category: Network Packet Monitoring ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>

#define MAX_SNAPLEN 65535
#define MAX_PKTS 100

typedef struct {
    u_char *data;
    int len;
} packet_t;

void got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    packet_t *pkt = (packet_t *) args;
    pkt->data = (u_char *) malloc(header->caplen);
    pkt->len = header->caplen;
    memcpy(pkt->data, packet, header->caplen);
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    char filter_str[100];
    pcap_t *handle;
    bpf_u_int32 net, mask;
    char *dev = "eth0";
    int snapshot_len = MAX_SNAPLEN;
    int count = 0;
    packet_t *packets = (packet_t *) malloc(MAX_PKTS * sizeof(packet_t));

    printf("Enter the filter expression: ");
    scanf("%s", filter_str);

    handle = pcap_open_live(dev, snapshot_len, 1, 0, errbuf);
    if (handle == NULL) {
        printf("Error: %s\n", errbuf);
        exit(1);
    }

    pcap_compile(handle, &net, filter_str, 0, mask);
    pcap_setfilter(handle, &net);

    pcap_loop(handle, -1, got_packet, (u_char *) packets);

    for (int i = 0; i < count; i++) {
        printf("Packet %d:\n", i);
        printf("Data: %s\n", packets[i].data);
        printf("Length: %d\n", packets[i].len);
        printf("\n");
    }

    pcap_close(handle);
    free(packets);

    return 0;
}