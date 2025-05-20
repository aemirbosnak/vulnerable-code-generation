//Falcon-180B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <netinet/ip6.h>
#include <netinet/icmp6.h>
#include <netdb.h>

#define MAX_PACKET_SIZE 65535
#define SNAPLEN 65535

typedef struct {
    u_char *data;
    int len;
} PacketData;

void packet_handler(u_char *user, const struct pcap_pkthdr *header, const u_char *packet) {
    PacketData *data = (PacketData *)user;
    data->data = (u_char *)malloc(header->caplen);
    data->len = header->caplen;
    memcpy(data->data, packet, header->caplen);
}

void print_packet(PacketData *data) {
    char *payload = (char *)data->data;
    int i = 0;
    while (i < data->len) {
        printf("%02X ", payload[i]);
        i++;
        if (i % 16 == 0) {
            printf("\n");
        }
    }
}

int main(int argc, char *argv[]) {
    char *dev = "eth0";
    char *errbuf = NULL;
    pcap_t *handle;
    PacketData data;

    if (argc > 1) {
        dev = argv[1];
    }

    handle = pcap_open_live(dev, SNAPLEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device: %s\n", errbuf);
        exit(1);
    }

    if (pcap_setfilter(handle, "tcp or udp or icmp")!= 0) {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    if (pcap_loop(handle, -1, packet_handler, (u_char *)&data)!= 0) {
        fprintf(stderr, "Error in packet capture loop: %s\n", pcap_geterr(handle));
        exit(1);
    }

    pcap_close(handle);

    printf("Captured packet:\n");
    print_packet(&data);

    free(data.data);

    return 0;
}