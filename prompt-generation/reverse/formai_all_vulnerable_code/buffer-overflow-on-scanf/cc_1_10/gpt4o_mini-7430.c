//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: introspective
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ip *ip_header = (struct ip *)(packet + 14); // Ethernet header is 14 bytes
    char src_ip[INET_ADDRSTRLEN];
    char dest_ip[INET_ADDRSTRLEN];

    // Convert the IP addresses from binary to text
    inet_ntop(AF_INET, &(ip_header->ip_src), src_ip, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &(ip_header->ip_dst), dest_ip, INET_ADDRSTRLEN);

    // Print packet details
    printf("Packet Length: %d bytes\n", header->len);
    printf("Source IP: %s\n", src_ip);
    printf("Destination IP: %s\n", dest_ip);
    printf("Protocol: ");
    switch (ip_header->ip_p) {
        case IPPROTO_TCP:
            printf("TCP\n");
            break;
        case IPPROTO_UDP:
            printf("UDP\n");
            break;
        case IPPROTO_ICMP:
            printf("ICMP\n");
            break;
        default:
            printf("Other\n");
            break;
    }
    printf("------------------------------\n");
}

void list_devices() {
    pcap_if_t *interfaces, *temp;
    char errbuf[PCAP_ERRBUF_SIZE];

    // Fetch the list of available devices
    if (pcap_findalldevs(&interfaces, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    printf("Available Devices:\n");
    for (temp = interfaces; temp != NULL; temp = temp->next) {
        printf(" - %s\n", temp->name);
    }
    pcap_freealldevs(interfaces);
}

int main() {
    char device[128];
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    // Ask user for the device to listen to
    list_devices();
    printf("Enter the device name to capture from: ");
    scanf("%s", device);
    
    // Open the device for packet capturing
    handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", device, errbuf);
        return EXIT_FAILURE;
    }

    // Start capturing packets
    printf("Listening on %s...\n", device);
    pcap_loop(handle, 0, packet_handler, NULL);

    // After capturing, close the pcap handle
    pcap_close(handle);
    return EXIT_SUCCESS;
}