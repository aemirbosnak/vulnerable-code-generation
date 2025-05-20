//Falcon-180B DATASET v1.0 Category: Network Packet Monitoring ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <pcap.h>

#define MAX_PACKET_SIZE 1024
#define SNAPLEN 1024
#define TRUE 1
#define FALSE 0

typedef struct {
    u_char *data;
    int size;
} packet_t;

pcap_t *handle;
char *dev;
char *filter;
pcap_handler callback;
u_char *buffer;
int buffer_size;
int packet_count;

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    packet_t *packet_data = (packet_t *) args;
    packet_data->data = malloc(header->caplen + 1);
    memcpy(packet_data->data, packet, header->caplen);
    packet_data->size = header->caplen;
    packet_count++;
}

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    dev = argv[1];
    filter = argv[2];
    buffer = malloc(MAX_PACKET_SIZE);
    buffer_size = MAX_PACKET_SIZE;
    packet_count = 0;

    handle = pcap_open_live(dev, SNAPLEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device %s: %s\n", dev, errbuf);
        exit(1);
    }

    if (pcap_compile(handle, &callback, filter, 0, 0)!= 0) {
        fprintf(stderr, "Error compiling filter %s: %s\n", filter, pcap_geterr(handle));
        exit(1);
    }

    if (pcap_setfilter(handle, &callback)!= 0) {
        fprintf(stderr, "Error setting filter %s: %s\n", filter, pcap_geterr(handle));
        exit(1);
    }

    pcap_loop(handle, -1, process_packet, NULL);

    pcap_freecode(&callback);
    pcap_close(handle);

    return 0;
}