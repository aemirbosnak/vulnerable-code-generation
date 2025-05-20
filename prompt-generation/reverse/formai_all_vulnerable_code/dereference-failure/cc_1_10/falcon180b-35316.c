//Falcon-180B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_PACKET_SIZE 1024
#define SNAPLEN 65535
#define TRUE 1
#define FALSE 0

typedef struct {
    u_char *data;
    int size;
} Packet;

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    Packet *pkt = (Packet*)args;
    int offset = 0;

    // Copy the packet data into the buffer
    memcpy(pkt->data + offset, packet, header->caplen);
    offset += header->caplen;

    // Check if the packet is truncated
    if (header->caplen == SNAPLEN) {
        printf("Packet truncated\n");
    }

    // Update the size of the captured packet
    pkt->size += header->caplen;
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    char *dev = "eth0";
    pcap_t *handle;
    Packet packet;

    // Open the capture device
    handle = pcap_open_live(dev, SNAPLEN, 1, 1000, errbuf);

    if (handle == NULL) {
        printf("Error opening capture device: %s\n", errbuf);
        return 1;
    }

    // Allocate memory for the packet buffer
    packet.data = (u_char*)malloc(MAX_PACKET_SIZE);
    packet.size = 0;

    // Set the callback function for processing packets
    pcap_loop(handle, -1, process_packet, (u_char*)&packet);

    // Close the capture device
    pcap_close(handle);

    return 0;
}