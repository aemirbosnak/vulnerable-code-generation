//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>

#define MAX_DATA_LEN 1024
#define SNAPLEN 1514
#define TRUE 1
#define FALSE 0

typedef struct {
    char *data;
    int len;
} PacketData;

PacketData *packet_data = NULL;
int num_packets = 0;

void init_packet_data() {
    packet_data = (PacketData *) malloc(sizeof(PacketData) * 1000);
    if (packet_data == NULL) {
        printf("Error allocating memory for packet data\n");
        exit(1);
    }
    num_packets = 0;
}

void add_packet_data(char *data, int len) {
    if (num_packets >= 1000) {
        printf("Packet buffer full\n");
        return;
    }
    packet_data[num_packets].data = (char *) malloc(len + 1);
    if (packet_data[num_packets].data == NULL) {
        printf("Error allocating memory for packet data\n");
        exit(1);
    }
    memcpy(packet_data[num_packets].data, data, len);
    packet_data[num_packets].len = len;
    num_packets++;
}

void print_packet_data() {
    for (int i = 0; i < num_packets; i++) {
        printf("Packet %d: %s\n", i, packet_data[i].data);
    }
}

void pcap_callback(u_char *user, const struct pcap_pkthdr *h, const u_char *sp) {
    add_packet_data((char *) sp, h->caplen);
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    char filter_str[100] = "tcp port 80";
    pcap_t *handle;
    bpf_u_int32 netp, maskp;
    int i = 0;

    init_packet_data();

    handle = pcap_open_live("eth0", SNAPLEN, TRUE, 0, errbuf);
    if (handle == NULL) {
        printf("Error opening capture device: %s\n", errbuf);
        exit(1);
    }

    if (pcap_compile(handle, &netp, filter_str, 1, maskp)!= 0) {
        printf("Error compiling filter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    if (pcap_setfilter(handle, &netp)!= 0) {
        printf("Error setting filter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    pcap_loop(handle, -1, pcap_callback, NULL);

    pcap_freecode(&netp);
    pcap_close(handle);

    print_packet_data();

    return 0;
}