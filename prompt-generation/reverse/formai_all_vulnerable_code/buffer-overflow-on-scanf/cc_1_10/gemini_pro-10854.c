//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: automated
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>

// Function to capture packets
void capture_packets(char *device) {
    // Open the device for capturing
    pcap_t *handle = pcap_open_live(device, BUFSIZ, 1, 1000, NULL);
    if (handle == NULL) {
        perror("pcap_open_live");
        exit(1);
    }

    // Define the filter expression
    struct bpf_program filter;
    char filter_exp[] = "tcp";
    if (pcap_compile(handle, &filter, filter_exp, 0, 0) == -1) {
        perror("pcap_compile");
        exit(1);
    }
    if (pcap_setfilter(handle, &filter) == -1) {
        perror("pcap_setfilter");
        exit(1);
    }

    // Capture packets in a loop
    while (1) {
        // Wait for packets
        struct pcap_pkthdr *header;
        const u_char *packet;
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == -1) {
            perror("pcap_next_ex");
            exit(1);
        }
        if (res == 0) {
            continue;
        }

        // Process the packet
        printf("Packet captured: %d bytes\n", header->len);
        for (int i = 0; i < header->len; i++) {
            printf("%02x ", packet[i]);
        }
        printf("\n\n");
    }

    // Close the device
    pcap_close(handle);
}

int main() {
    // List the devices
    char *devices = pcap_lookupdev(NULL);
    if (devices == NULL) {
        perror("pcap_lookupdev");
        exit(1);
    }

    // Print the list of devices
    printf("Available devices:\n");
    char *device = strtok(devices, ",");
    while (device != NULL) {
        printf("  * %s\n", device);
        device = strtok(NULL, ",");
    }

    // Select a device
    printf("Select a device: ");
    scanf("%s", device);

    // Capture packets
    capture_packets(device);

    return 0;
}