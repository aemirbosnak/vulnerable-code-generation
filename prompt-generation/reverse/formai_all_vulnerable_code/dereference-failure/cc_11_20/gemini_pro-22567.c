//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BSSID_LEN 6
#define MAX_SSID_LEN 32

struct wireless_network {
    char bssid[MAX_BSSID_LEN];
    char ssid[MAX_SSID_LEN];
    int channel;
    int signal_strength;
};

int main(int argc, char **argv) {
    char *interface;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program filter;
    struct wireless_network wn;
    int res;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <interface>\n", argv[0]);
        return EXIT_FAILURE;
    }

    interface = argv[1];

    handle = pcap_open_live(interface, 65535, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live(): %s\n", errbuf);
        return EXIT_FAILURE;
    }

    res = pcap_compile(handle, &filter, "type mgt subtype beacon", 0, 0);
    if (res != 0) {
        fprintf(stderr, "pcap_compile(): %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    res = pcap_setfilter(handle, &filter);
    if (res != 0) {
        fprintf(stderr, "pcap_setfilter(): %s\n", pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    while (1) {
        struct pcap_pkthdr *header;
        const u_char *packet;

        res = pcap_next_ex(handle, &header, &packet);
        if (res == 0) {
            continue;
        } else if (res == -1) {
            fprintf(stderr, "pcap_next_ex(): %s\n", pcap_geterr(handle));
            return EXIT_FAILURE;
        }

        if (header->len < 24) {
            continue;
        }

        if (packet[0] != 0x80 || packet[1] != 0x00) {
            continue;
        }

        if (packet[12] != 0x08 || packet[13] != 0x06) {
            continue;
        }

        memcpy(wn.bssid, packet + 16, MAX_BSSID_LEN);
        wn.bssid[MAX_BSSID_LEN] = '\0';

        res = packet[36];
        if (res < 1 || res > 14) {
            continue;
        }
        wn.channel = res;

        res = packet[37];
        if (res < 0 || res > 100) {
            continue;
        }
        wn.signal_strength = res;

        res = packet[43];
        if (res < 0 || res > MAX_SSID_LEN) {
            continue;
        }
        memcpy(wn.ssid, packet + 44, res);
        wn.ssid[res] = '\0';

        printf("%s (%s, channel %d, signal strength %d)\n", wn.ssid, wn.bssid, wn.channel, wn.signal_strength);
    }

    pcap_close(handle);

    return EXIT_SUCCESS;
}