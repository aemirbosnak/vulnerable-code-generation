//Falcon-180B DATASET v1.0 Category: Network Packet Monitoring ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include <time.h>

#define MAX_PACKET_SIZE 65535
#define MAX_PACKET_COUNT 1000
#define PACKET_TIMEOUT 10 // in seconds

struct Packet {
    time_t timestamp;
    size_t size;
    char data[MAX_PACKET_SIZE];
};

pcap_t *pcap_handle;
char *pcap_dev;
char pcap_errbuf[PCAP_ERRBUF_SIZE];

int packet_count = 0;
struct Packet packets[MAX_PACKET_COUNT];

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct Packet *pkt = &packets[packet_count];
    pkt->timestamp = time(NULL);
    pkt->size = header->len;
    memcpy(pkt->data, packet, pkt->size);
    packet_count++;
}

int main() {
    printf("Enter the network interface to capture packets: ");
    scanf("%s", pcap_dev);

    pcap_handle = pcap_open_live(pcap_dev, MAX_PACKET_SIZE, 1, 0, pcap_errbuf);
    if (pcap_handle == NULL) {
        printf("Error opening network interface: %s\n", pcap_errbuf);
        return 1;
    }

    pcap_loop(pcap_handle, -1, process_packet, NULL);

    pcap_close(pcap_handle);
    return 0;
}