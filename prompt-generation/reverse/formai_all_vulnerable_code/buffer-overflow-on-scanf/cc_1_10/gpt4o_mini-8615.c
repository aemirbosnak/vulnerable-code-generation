//GPT-4o-mini DATASET v1.0 Category: Packet Capturer with pcap library ; Style: satisfied
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_PACKETS 100
#define SNAP_LEN 1518

void packet_handler(u_char *user, const struct pcap_pkthdr *pkthdr, const u_char *packet) {
    struct timeval ts = pkthdr->ts;
    char time_string[16];
    
    // Convert the timestamp to a readable format
    snprintf(time_string, sizeof(time_string), "%ld.%06ld", ts.tv_sec, ts.tv_usec);
    printf("Packet captured at: %s\n", time_string);
    printf("Packet length: %d bytes\n", pkthdr->len);
    
    // Print Packet Data
    printf("Packet data:\n");
    for (int i = 0; i < pkthdr->len; i++) {
        printf("%02x ", packet[i]);
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

void start_capture(const char *dev) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    
    // Open the network device for packet capture
    handle = pcap_open_live(dev, SNAP_LEN, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", dev, errbuf);
        return;
    }

    printf("Capturing packets on %s...\n", dev);
    pcap_loop(handle, MAX_PACKETS, packet_handler, NULL);

    // Cleanup
    pcap_close(handle);
}

void print_device_list() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_if_t *alldevsp, *device;

    // Retrieve the device list
    if (pcap_findalldevs(&alldevsp, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        return;
    }

    printf("Available devices:\n");
    for (device = alldevsp; device != NULL; device = device->next) {
        printf(" - %s\n", device->name);
    }

    pcap_freealldevs(alldevsp);
}

int main() {
    print_device_list();

    char dev[100];
    printf("Enter device name to capture (e.g. eth0): ");
    scanf("%s", dev);
    
    start_capture(dev);
    
    return 0;
}