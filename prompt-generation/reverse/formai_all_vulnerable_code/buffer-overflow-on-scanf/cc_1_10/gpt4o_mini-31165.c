//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>

#define PACKET_SNIFFING_HACK 0xCAFE
#define MAX_INTS 256
#define ETHER_HEADER_SIZE 14

// Enigma: Structure for packets and describes their mystery.
typedef struct packet_info {
    struct pcap_pkthdr header; // Packet header
    const u_char *data;        // Packet data
    int length;                // Length of packet
} packet_info_t;

// A spectral function to decode each captured packet.
void packet_decoder(const u_char *data, int length) {
    printf("Packet Length: %d bytes\n", length);
    printf("Packet Data (hex): ");
    for(int i = 0; i < length; i++) {
        printf("%02X ", data[i]);
    }
    printf("\n");
}

// A twist in the tale: An event to handle captured packets.
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    packet_info_t *pkt_info = (packet_info_t *)args;
    pkt_info->header = *header;
    pkt_info->data = packet;
    pkt_info->length = header->len;

    // Discovering the packet
    printf("\nMystic Packet Detected:\n");
    packet_decoder(pkt_info->data + ETHER_HEADER_SIZE, pkt_info->length - ETHER_HEADER_SIZE);
}

// A labyrinth of network devices.
void start_sniffing(const char *device) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    // The portal of capture is opened.
    handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device, errbuf);
        return;
    }

    // The spell of capturing begins!
    packet_info_t pkt_info;
    pcap_loop(handle, 10, packet_handler, (u_char *)&pkt_info); // Sniff 10 packets
    
    // All good things must return.
    pcap_close(handle);
}

// A clue hidden in the folds of the ether.
void list_devices() {
    pcap_if_t *alldevs;
    pcap_if_t *device;
    char errbuf[PCAP_ERRBUF_SIZE];

    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        return;
    }

    printf("Available Devices:\n");
    for (device = alldevs; device != NULL; device = device->next) {
        printf(" - %s\n", device->name);
    }
    
    pcap_freealldevs(alldevs);
}

// The main function, where it all converges.
int main() {
    printf("Network Packet Monitoring - The Great Unraveling!\n");

    // Hinting the user...
    list_devices();

    char device[100];
    printf("Enter the device name to sniff (from above): ");
    scanf("%s", device);
    
    // The fragile string of choices...
    start_sniffing(device);
    
    printf("Sniffing Complete - Secrets were revealed!\n");
    return 0;
}