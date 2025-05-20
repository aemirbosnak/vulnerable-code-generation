//Falcon-180B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <string.h>
#include <pthread.h>

#define TRUE 1
#define FALSE 0

// Global variables
pcap_t *descr;
char *dev;
char errbuf[PCAP_ERRBUF_SIZE];

void *process_packet(void *arg) {
    pcap_t *handle = (pcap_t *) arg;
    const u_char *packet;
    int len;

    while ((packet = pcap_next(handle, &len))!= NULL) {
        printf("Packet received: %d bytes\n", len);
        printf("Packet data: ");
        for (int i = 0; i < len; i++) {
            printf("%02X ", packet[i]);
        }
        printf("\n");
    }

    return NULL;
}

int main() {
    char device[100];

    // Get device name from user
    printf("Enter device name: ");
    scanf("%s", device);

    // Open device for capturing
    descr = pcap_open_live(device, 65535, 1, 0, errbuf);
    if (descr == NULL) {
        printf("Error opening device: %s\n", errbuf);
        exit(1);
    }

    dev = pcap_geterr(descr);
    printf("Device opened: %s\n", dev);

    // Start capturing packets
    pcap_loop(descr, -1, process_packet, NULL);

    pcap_close(descr);
    return 0;
}