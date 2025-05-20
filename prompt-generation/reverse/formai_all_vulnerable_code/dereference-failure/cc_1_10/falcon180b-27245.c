//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pcap.h>

#define MAX_PKT_SIZE 65535
#define SNAPLEN 65535

typedef struct {
    u_int32_t ip_src;
    u_int32_t ip_dst;
    u_int16_t tcp_src;
    u_int16_t tcp_dst;
    u_int32_t seq_num;
    u_int32_t ack_num;
    u_int16_t tcp_flags;
    char payload[MAX_PKT_SIZE];
} Packet;

int packet_handler(u_char* args, const struct pcap_pkthdr* pkthdr, const u_char* packet) {
    Packet* pkt = (Packet*) args;
    memcpy(pkt->payload, packet, pkthdr->caplen);
    pkt->ip_src = *(u_int32_t*) (packet + 12);
    pkt->ip_dst = *(u_int32_t*) (packet + 16);
    pkt->tcp_src = *(u_int16_t*) (packet + 28);
    pkt->tcp_dst = *(u_int16_t*) (packet + 30);
    pkt->seq_num = *(u_int32_t*) (packet + 34);
    pkt->ack_num = *(u_int32_t*) (packet + 38);
    pkt->tcp_flags = *(u_int16_t*) (packet + 42);
    return pkthdr->caplen;
}

void process_packet(Packet* pkt) {
    if (pkt->tcp_flags & 0x02) {
        printf("SYN packet detected.\n");
    } else if (pkt->tcp_flags & 0x10) {
        printf("ACK packet detected.\n");
    } else if (pkt->tcp_flags & 0x01) {
        printf("FIN packet detected.\n");
    } else if (pkt->tcp_flags & 0x04) {
        printf("RST packet detected.\n");
    } else {
        printf("Unknown TCP flag.\n");
    }
}

int main() {
    char* dev = "eth0";
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* handle;
    Packet* pkt;
    handle = pcap_open_live(dev, SNAPLEN, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Error opening network device: %s\n", errbuf);
        exit(1);
    }
    pkt = (Packet*) malloc(sizeof(Packet));
    pcap_loop(handle, -1, packet_handler, pkt);
    pcap_close(handle);
    return 0;
}