//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>

#define SIZE_ETHERNET 14
#define ETHER_ADDR_LEN 6
#define ETHER_TYPE_IP 0x0800
#define ETHER_TYPE_ARP 0x0806

typedef struct ethernet_header {
    u_char dest_mac[ETHER_ADDR_LEN];
    u_char src_mac[ETHER_ADDR_LEN];
    u_short ether_type;
} ethernet_header_t;

void print_mac_address(u_char *mac) {
    for (int i = 0; i < ETHER_ADDR_LEN; i++) {
        printf("%02x", mac[i]);
        if (i < ETHER_ADDR_LEN - 1) {
            printf(":");
        }
    }
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    ethernet_header_t *eth_header = (ethernet_header_t*) packet;

    printf("Packet captured:\n");
    printf("Timestamp: %ld.%06ld\n", header->ts.tv_sec, header->ts.tv_usec);
    
    printf("Source MAC: ");
    print_mac_address(eth_header->src_mac);
    printf("\n");

    printf("Destination MAC: ");
    print_mac_address(eth_header->dest_mac);
    printf("\n");

    printf("Ether Type: 0x%04x\n", ntohs(eth_header->ether_type));

    if (ntohs(eth_header->ether_type) == ETHER_TYPE_IP) {
        printf("This is an IP packet.\n");
    } else if (ntohs(eth_header->ether_type) == ETHER_TYPE_ARP) {
        printf("This is an ARP packet.\n");
    } else {
        printf("This is an unknown protocol packet.\n");
    }
    printf("----------------------------------------\n");
}

int main(int argc, char **argv) {
    pcap_if_t *alldevs, *device;
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        return 1;
    }

    printf("Available devices:\n");
    int index = 0;
    for (device = alldevs; device != NULL; device = device->next) {
        printf("%d. %s - %s\n", index++, device->name, device->description ? device->description : "No description");
    }

    printf("Select device number (0-%d): ", index - 1);
    int device_number;
    scanf("%d", &device_number);
    
    if (device_number < 0 || device_number >= index) {
        fprintf(stderr, "Invalid device number.\n");
        pcap_freealldevs(alldevs);
        return 1;
    }
    
    device = alldevs;
    for (int i = 0; i < device_number; i++) {
        device = device->next;
    }

    handle = pcap_open_live(device->name, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device->name, errbuf);
        pcap_freealldevs(alldevs);
        return 1;
    }

    printf("Listening on %s...\n", device->name);
    
    pcap_loop(handle, 0, packet_handler, NULL);

    pcap_freealldevs(alldevs);
    pcap_close(handle);
    return 0;
}