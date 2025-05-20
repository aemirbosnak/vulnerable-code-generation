//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <pcap/pcap.h>
#include <pcap/dlt.h>

#define MAX_INTERFACES 10

int main(int argc, char *argv[]) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_if_t *alldevs, *d;
    int i = 0;

    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error finding all devices: %s\n", errbuf);
        return 1;
    }

    printf("Available network interfaces:\n");
    for (d = alldevs; d; d = d->next) {
        printf("%d. %s (%s)\n", ++i, d->name, d->description);
    }

    pcap_freealldevs(alldevs);

    char *interface = NULL;
    if (argc > 1) {
        interface = argv[1];
    } else {
        printf("Enter the interface to scan: ");
        scanf("%s", interface);
    }

    pcap_t *handle = pcap_open_live(interface, 1500, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening interface %s: %s\n", interface, errbuf);
        return 1;
    }

    int snapshot_len = 65535;
    int promiscuous = 1;
    int to_ms = 1000;
    if (pcap_set_snaplen(handle, snapshot_len) == -1) {
        fprintf(stderr, "Error setting snapshot length: %s\n", pcap_geterr(handle));
        return 1;
    }

    if (pcap_set_promisc(handle, promiscuous) == -1) {
        fprintf(stderr, "Error setting promiscuous mode: %s\n", pcap_geterr(handle));
        return 1;
    }

    if (pcap_set_timeout(handle, to_ms) == -1) {
        fprintf(stderr, "Error setting timeout: %s\n", pcap_geterr(handle));
        return 1;
    }

    printf("Scanning for access points on interface %s...\n", interface);

    struct pcap_pkthdr *header;
    const u_char *data;
    while (1) {
        int res = pcap_next_ex(handle, &header, &data);
        if (res == -1) {
            fprintf(stderr, "Error capturing packet: %s\n", pcap_geterr(handle));
            break;
        } else if (res == 0) {
            continue;
        }

        if (header->len < 24) {
            continue;
        }

        if (data[0] != 0x80 || data[1] != 0x5e) {
            continue;
        }

        char ssid[33];
        memset(ssid, 0, sizeof(ssid));
        memcpy(ssid, data + 32, header->len - 54);

        if (strlen(ssid) > 0) {
            printf("SSID: %s\n", ssid);
            printf("BSSID: %02x:%02x:%02x:%02x:%02x:%02x\n", data[16], data[17], data[18], data[19], data[20], data[21]);
            printf("Channel: %d\n", data[26]);
            printf("Signal strength: %d dBm\n", (int)data[27] - 100);
            printf("-------------------------------------\n");
        }
    }

    pcap_close(handle);

    return 0;
}