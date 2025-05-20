//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>

#define MAX_DEVICES 100

struct device {
    char *name;
    char *mac;
    int channel;
    int signal;
};

struct device devices[MAX_DEVICES];
int num_devices = 0;

int main(int argc, char *argv[]) {
    char *interface = argv[1];
    if (interface == NULL) {
        printf("Usage: %s <interface>\n", argv[0]);
        return 1;
    }

    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live(interface, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Error opening interface: %s\n", errbuf);
        return 1;
    }

    struct pcap_pkthdr *header;
    const u_char *packet;
    while (1) {
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == -1) {
            printf("Error reading packet: %s\n", pcap_geterr(handle));
            break;
        } else if (res == 0) {
            continue;
        }

        if (header->len < 24) {
            continue;
        }

        if (packet[0] != 0x80 || packet[1] != 0x00) {
            continue;
        }

        struct device device;
        device.name = malloc(33);
        device.mac = malloc(18);
        device.channel = packet[9];
        device.signal = packet[16];
        memcpy(device.name, packet + 10, 32);
        memcpy(device.mac, packet + 18, 17);

        int found = 0;
        for (int i = 0; i < num_devices; i++) {
            if (strcmp(devices[i].mac, device.mac) == 0) {
                found = 1;
                break;
            }
        }

        if (!found) {
            devices[num_devices] = device;
            num_devices++;
        }
    }

    pcap_close(handle);

    printf("Found %d devices:\n", num_devices);
    for (int i = 0; i < num_devices; i++) {
        printf("%s (%s, channel %d, signal %d)\n", devices[i].name, devices[i].mac, devices[i].channel, devices[i].signal);
    }

    return 0;
}