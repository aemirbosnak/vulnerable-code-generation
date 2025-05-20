//Falcon-180B DATASET v1.0 Category: Network Packet Monitoring ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <arpa/inet.h>

#define MAX_PKT_SIZE 65535 // Maximum packet size
#define SNAPLEN 65535 // Snapshot length for capturing packets

struct packet_info {
    u_char *packet; // Packet data
    int len; // Length of packet
    struct timeval ts; // Timestamp of packet
};

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct packet_info *info = (struct packet_info *)args;
    memcpy(info->packet, packet, header->caplen);
    info->len = header->caplen;
    gettimeofday(&info->ts, NULL);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        exit(1);
    }

    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live(argv[1], SNAPLEN, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Error opening interface: %s\n", errbuf);
        exit(2);
    }

    pcap_dumper_t *dumper = pcap_dump_open(handle, "output.pcap");
    if (dumper == NULL) {
        printf("Error opening dumper: %s\n", pcap_geterr(handle));
        exit(3);
    }

    struct packet_info info;
    info.packet = malloc(MAX_PKT_SIZE);
    info.len = 0;

    pcap_loop(handle, -1, packet_handler, (u_char *)&info);

    pcap_dump_close(dumper);
    pcap_close(handle);

    return 0;
}