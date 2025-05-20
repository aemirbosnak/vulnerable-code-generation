//Falcon-180B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

#define MAX_PACKET_SIZE 1024
#define SNAPLEN 65535
#define PROMISC 1

pcap_t *handle;
char errbuf[PCAP_ERRBUF_SIZE];

void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Packet received:\n");
    printf("Length: %d\n", header->len);
    printf("Data:\n");
    for (int i = 0; i < header->len; i++) {
        printf("%02X ", packet[i]);
    }
    printf("\n");
}

int main() {
    char *dev;
    char filter_str[100];
    int opt = 1;
    int ret;

    printf("Enter device name: ");
    scanf("%s", dev);

    handle = pcap_open_live(dev, SNAPLEN, PROMISC, 0, errbuf);
    if (handle == NULL) {
        printf("Error: %s\n", errbuf);
        exit(1);
    }

    printf("Enter filter: ");
    scanf("%s", filter_str);

    ret = pcap_compile(handle, &opt, filter_str, 1, 0);
    if (ret == -1) {
        printf("Error: %s\n", errbuf);
        exit(1);
    }

    ret = pcap_setfilter(handle, &opt);
    if (ret == -1) {
        printf("Error: %s\n", errbuf);
        exit(1);
    }

    printf("Press any key to start capturing...\n");
    getchar();

    pcap_loop(handle, -1, process_packet, NULL);

    pcap_freecode(&opt);
    pcap_close(handle);

    return 0;
}