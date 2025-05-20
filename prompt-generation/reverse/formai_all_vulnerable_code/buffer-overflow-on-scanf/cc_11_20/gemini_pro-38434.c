//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

#define SNAP_LEN 1518

int main() {
    char *dev;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct pcap_pkthdr *header;
    const u_char *packet;

    printf("Yo, what's up? I'm your network packet sniffing buddy!\n");
    printf("Let's grab some packets, shall we?\n");
    printf("What interface should we listen on? ");
    scanf("%s", dev);

    handle = pcap_open_live(dev, SNAP_LEN, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Oops, something went wrong: %s\n", errbuf);
        return 1;
    }

    while (1) {
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == 0) continue;
        if (res == -1) {
            printf("Error: %s\n", pcap_geterr(handle));
            break;
        }

        printf("\nPacket received!\n");
        printf("Capture length: %d\n", header->caplen);
        printf("Actual length: %d\n", header->len);
        printf("Source MAC: ");
        for (int i = 0; i < 6; i++) {
            printf("%02x", packet[i]);
            if (i < 5) printf(":");
        }
        printf("\n");
        printf("Destination MAC: ");
        for (int i = 6; i < 12; i++) {
            printf("%02x", packet[i]);
            if (i < 11) printf(":");
        }
        printf("\n");
        printf("Protocol: ");
        switch (packet[12]) {
            case 0x08: printf("IP\n"); break;
            case 0x06: printf("ARP\n"); break;
            default: printf("Unknown\n"); break;
        }

        if (packet[12] == 0x08) {
            printf("Source IP: %d.%d.%d.%d\n", packet[26], packet[27], packet[28], packet[29]);
            printf("Destination IP: %d.%d.%d.%d\n", packet[30], packet[31], packet[32], packet[33]);
        }

        printf("\n");
    }

    pcap_close(handle);
    return 0;
}