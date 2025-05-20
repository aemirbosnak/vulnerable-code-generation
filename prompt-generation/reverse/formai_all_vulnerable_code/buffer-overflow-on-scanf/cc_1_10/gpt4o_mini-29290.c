//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/ip.h>

void packetHandler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);
void printPacketInfo(const struct pcap_pkthdr *header, const u_char *packet);
void listNetworkInterfaces();
void startPacketCapture(const char *interface);

int main() {
    printf("Network Packet Monitoring Program\n");
    
    listNetworkInterfaces();

    char interface[20];
    printf("Enter the network interface to capture packets (e.g., eth0): ");
    scanf("%s", interface);

    startPacketCapture(interface);

    return 0;
}

void listNetworkInterfaces() {
    pcap_if_t *interfaces, *temp;
    char errbuf[PCAP_ERRBUF_SIZE];

    if (pcap_findalldevs(&interfaces, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        return;
    }

    printf("Available Network Interfaces:\n");
    for (temp = interfaces; temp != NULL; temp = temp->next) {
        printf(" - %s\n", temp->name);
    }

    pcap_freealldevs(interfaces);
}

void startPacketCapture(const char *interface) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    handle = pcap_open_live(interface, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", interface, errbuf);
        exit(EXIT_FAILURE);
    }

    printf("Capturing packets on %s...\n", interface);
    pcap_loop(handle, 10, packetHandler, NULL); // Capture 10 packets

    pcap_close(handle);
    printf("Packet capture finished.\n");
}

void packetHandler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printPacketInfo(header, packet);
}

void printPacketInfo(const struct pcap_pkthdr *header, const u_char *packet) {
    struct ip *ipHeader = (struct ip *)(packet + 14); // Skip Ethernet header (14 bytes)
    
    printf("Packet captured:\n");
    printf(" - Length: %d bytes\n", header->len);
    printf(" - Time: %ld.%06ld\n", header->ts.tv_sec, header->ts.tv_usec);
    printf(" - Source IP: %s\n", inet_ntoa(ipHeader->ip_src));
    printf(" - Destination IP: %s\n", inet_ntoa(ipHeader->ip_dst));
    printf("-----------------------------------\n");
}