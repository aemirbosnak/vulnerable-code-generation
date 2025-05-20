//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char *name;
    char *mac;
} Device;

int main() {
    char *dev = pcap_lookupdev(NULL);
    if (dev == NULL) {
        fprintf(stderr, "Error: pcap_lookupdev() failed\n");
        return EXIT_FAILURE;
    }

    pcap_t *handle = pcap_open_live(dev, BUFSIZ, 1, 1000, NULL);
    if (handle == NULL) {
        fprintf(stderr, "Error: pcap_open_live() failed\n");
        return EXIT_FAILURE;
    }

    struct pcap_pkthdr *header;
    const u_char *packet;

    while (true) {
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == -1) {
            fprintf(stderr, "Error: pcap_next_ex() failed\n");
            return EXIT_FAILURE;
        }

        if (res == 0) {
            continue;
        }

        if (header->len < 42) {
            continue;
        }

        if (packet[12] != 0x08 || packet[13] != 0x00) {
            continue;
        }

        if (packet[21] != 0x00 || packet[22] != 0x00) {
            continue;
        }

        Device device;
        device.name = malloc(256);
        device.mac = malloc(18);

        sprintf(device.name, "%s", packet + 24);
        sprintf(device.mac, "%02x:%02x:%02x:%02x:%02x:%02x", packet[16], packet[17], packet[18], packet[19], packet[20], packet[21]);

        printf("%s (%s)\n", device.name, device.mac);

        free(device.name);
        free(device.mac);
    }

    pcap_close(handle);
    return EXIT_SUCCESS;
}