//Code Llama-13B DATASET v1.0 Category: Network Packet Monitoring ; Style: excited
/*
 * Excited C Network Packet Monitoring Program
 *
 * This program uses the libpcap library to monitor network packets
 * and print out information about each packet.
 */

#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

#define NETWORK_INTERFACE "eth0"
#define SNAPLEN 1500
#define PROMISC 1

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    printf("Packet captured on interface %s.\n", NETWORK_INTERFACE);
    printf("Packet length: %d bytes\n", header->len);
    printf("Packet timestamp: %u.%u\n", header->ts.tv_sec, header->ts.tv_usec);

    // Print out the Ethernet header
    printf("Ethernet header:\n");
    printf("  Destination MAC: %02x:%02x:%02x:%02x:%02x:%02x\n", packet[0], packet[1], packet[2], packet[3], packet[4], packet[5]);
    printf("  Source MAC: %02x:%02x:%02x:%02x:%02x:%02x\n", packet[6], packet[7], packet[8], packet[9], packet[10], packet[11]);
    printf("  Ethertype: %04x\n", *(u_short *)(packet + 12));

    // Print out the IP header
    printf("IP header:\n");
    printf("  Version: %d\n", packet[14] >> 4);
    printf("  IHL: %d\n", packet[14] & 0x0f);
    printf("  TOS: %02x\n", packet[15]);
    printf("  Total Length: %d\n", ntohs(*(u_short *)(packet + 16)));
    printf("  Identification: %d\n", ntohs(*(u_short *)(packet + 18)));
    printf("  Flags: %04x\n", ntohs(*(u_short *)(packet + 20)));
    printf("  Fragment Offset: %d\n", ntohs(*(u_short *)(packet + 20)) & 0x1fff);
    printf("  Time to Live: %d\n", packet[22]);
    printf("  Protocol: %d\n", packet[23]);
    printf("  Header Checksum: %04x\n", ntohs(*(u_short *)(packet + 24)));
    printf("  Source IP: %d.%d.%d.%d\n", packet[26], packet[27], packet[28], packet[29]);
    printf("  Destination IP: %d.%d.%d.%d\n", packet[30], packet[31], packet[32], packet[33]);

    // Print out the TCP header
    printf("TCP header:\n");
    printf("  Source Port: %d\n", ntohs(*(u_short *)(packet + 34)));
    printf("  Destination Port: %d\n", ntohs(*(u_short *)(packet + 36)));
    printf("  Sequence Number: %d\n", ntohl(*(u_long *)(packet + 38)));
    printf("  Acknowledgement Number: %d\n", ntohl(*(u_long *)(packet + 42)));
    printf("  Data Offset: %d\n", (packet[40] >> 4) * 4);
    printf("  Flags: %04x\n", packet[41]);
    printf("  Window: %d\n", ntohs(*(u_short *)(packet + 42)));
    printf("  Checksum: %04x\n", ntohs(*(u_short *)(packet + 44)));
    printf("  Urgent Pointer: %d\n", ntohs(*(u_short *)(packet + 46)));

    // Print out the payload
    printf("Payload: %s\n", packet + 46 + (packet[40] >> 4) * 4);
}

int main(int argc, char *argv[])
{
    pcap_t *handle;
    char *dev;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct pcap_pkthdr header;
    const u_char *packet;

    // Open the device for reading
    dev = pcap_lookupdev(errbuf);
    handle = pcap_open_live(dev, SNAPLEN, PROMISC, 1000, errbuf);

    // Check for errors
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device for reading: %s\n", errbuf);
        return 1;
    }

    // Loop through the packets
    while (1) {
        // Get the next packet
        packet = pcap_next(handle, &header);

        // Print out the packet information
        packet_handler(NULL, &header, packet);
    }

    // Close the device
    pcap_close(handle);

    return 0;
}