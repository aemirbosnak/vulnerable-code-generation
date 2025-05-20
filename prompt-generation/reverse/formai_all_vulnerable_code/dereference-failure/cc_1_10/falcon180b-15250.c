//Falcon-180B DATASET v1.0 Category: Network Packet Monitoring ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <arpa/inet.h>

#define MAX_DATA_LEN 65535
#define SNAPLEN 65535
#define TRUE 1
#define FALSE 0

typedef struct {
    u_char *data;
    int len;
} packet_t;

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    packet_t *packet_data = (packet_t *) args;
    packet_data->data = (u_char *) malloc(header->len);
    packet_data->len = header->len;
    memcpy(packet_data->data, packet, header->len);
}

void print_packet(packet_t *packet) {
    printf("Packet length: %d\n", packet->len);
    printf("Packet data:\n");
    for (int i = 0; i < packet->len; i++) {
        printf("%02X ", packet->data[i]);
    }
    printf("\n");
}

int main() {
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    char *dev = "eth0";
    char filter_exp[] = "tcp or udp";
    bpf_u_int32 netp, maskp;
    struct bpf_program fp;
    pcap_handler callback = process_packet;
    packet_t packet_data;

    handle = pcap_open_live(dev, SNAPLEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening the device: %s\n", errbuf);
        exit(1);
    }

    if (pcap_compile(handle, &fp, filter_exp, 0, netp)!= 0) {
        fprintf(stderr, "Error compiling the filter expression: %s\n", pcap_geterr(handle));
        exit(1);
    }

    if (pcap_setfilter(handle, &fp)!= 0) {
        fprintf(stderr, "Error setting the filter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    while (TRUE) {
        if (pcap_dispatch(handle, 1, callback, &packet_data)!= 0) {
            fprintf(stderr, "Error dispatching the packet: %s\n", pcap_geterr(handle));
            exit(1);
        }
        print_packet(&packet_data);
        free(packet_data.data);
    }

    pcap_close(handle);
    return 0;
}