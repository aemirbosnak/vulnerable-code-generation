//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_PACKETS 1000
#define MAX_BSSID_LEN 6
#define MAX_SSID_LEN 32

struct wireless_network {
    unsigned char bssid[MAX_BSSID_LEN];
    char ssid[MAX_SSID_LEN];
    int channel;
    int signal_strength;
};

int main(int argc, char **argv) {
    char *interface = argv[1];
    char *filter = "type mgt subtype probe-req";

    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live(interface, 65535, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening interface: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    struct bpf_program fp;
    if (pcap_compile(handle, &fp, filter, 1, 0) == -1) {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        pcap_close(handle);
        return EXIT_FAILURE;
    }

    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        pcap_close(handle);
        return EXIT_FAILURE;
    }

    struct wireless_network networks[MAX_PACKETS];
    int num_networks = 0;

    while (1) {
        struct pcap_pkthdr *header;
        const unsigned char *packet;
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == -1) {
            fprintf(stderr, "Error reading packet: %s\n", pcap_geterr(handle));
            break;
        } else if (res == 0) {
            continue;
        }

        if (header->len < 24) {
            continue;
        }

        unsigned char *ptr = packet;
        ptr += 4; // skip preamble
        ptr += 10; // skip fixed part of header
        unsigned char frame_control = *ptr++;
        unsigned char frame_type = frame_control >> 2;
        unsigned char frame_subtype = frame_control & 0x03;

        if (frame_type != 0x00 || frame_subtype != 0x04) {
            continue;
        }

        ptr += 2; // skip duration
        ptr += 6; // skip source address
        ptr += 6; // skip destination address
        ptr += 6; // skip BSSID

        unsigned short ssid_len = *ptr++;
        if (ssid_len > 32) {
            continue;
        }

        memcpy(networks[num_networks].ssid, ptr, ssid_len);
        networks[num_networks].ssid[ssid_len] = '\0';
        ptr += ssid_len;

        memcpy(networks[num_networks].bssid, packet + 16, 6);

        unsigned char *ie = ptr;
        while (ie < packet + header->len) {
            unsigned char ie_len = ie[1];
            if (ie[0] == 0xdd && ie_len >= 2) {
                networks[num_networks].channel = ie[2];
            } else if (ie[0] == 0xdb && ie_len >= 4) {
                networks[num_networks].signal_strength = -ie[3];
            }
            ie += ie_len + 2;
        }

        num_networks++;
    }

    pcap_close(handle);

    for (int i = 0; i < num_networks; i++) {
        printf("SSID: %s\n", networks[i].ssid);
        printf("BSSID: %02x:%02x:%02x:%02x:%02x:%02x\n", networks[i].bssid[0], networks[i].bssid[1], networks[i].bssid[2], networks[i].bssid[3], networks[i].bssid[4], networks[i].bssid[5]);
        printf("Channel: %d\n", networks[i].channel);
        printf("Signal strength: %d dBm\n", networks[i].signal_strength);
        printf("\n");
    }

    return EXIT_SUCCESS;
}