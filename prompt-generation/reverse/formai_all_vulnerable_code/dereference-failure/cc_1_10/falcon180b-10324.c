//Falcon-180B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Linus Torvalds
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_PACKET_SIZE 65535
#define SNAPLEN 1514

typedef struct {
    u_char *data;
    size_t size;
} Packet;

void got_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    Packet *p = (Packet *) args;
    p->data = (u_char *) malloc(header->len);
    if (p->data == NULL) {
        fprintf(stderr, "Error: out of memory\n");
        exit(1);
    }
    p->size = header->len;
    memcpy(p->data, packet, header->len);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <interface> <output_file>\n", argv[0]);
        exit(1);
    }

    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live(argv[1], SNAPLEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error: %s\n", errbuf);
        exit(1);
    }

    FILE *fp = fopen(argv[2], "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(1);
    }

    Packet packet;
    packet.data = NULL;
    packet.size = 0;

    pcap_loop(handle, -1, got_packet, (u_char *) &packet);

    fclose(fp);
    pcap_close(handle);

    return 0;
}