//Falcon-180B DATASET v1.0 Category: Network Packet Monitoring ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>

#define MAX_DATA_SIZE 1024
#define SNAPLEN 1024
#define MAX_PACKETS 100

typedef struct {
    u_char *data;
    int size;
} PacketData;

void callback(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    PacketData *packetData = (PacketData *) args;
    if (packetData->size + header->caplen > MAX_DATA_SIZE) {
        fprintf(stderr, "Packet truncated\n");
        return;
    }
    memcpy(packetData->data + packetData->size, packet, header->caplen);
    packetData->size += header->caplen;
}

int main() {
    char *device = "eth0";
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    PacketData packetData[MAX_PACKETS];
    int i, count = 0;

    handle = pcap_open_live(device, SNAPLEN, 1, 0, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device: %s\n", errbuf);
        exit(1);
    }

    for (i = 0; i < MAX_PACKETS; i++) {
        packetData[i].data = malloc(MAX_DATA_SIZE);
        if (packetData[i].data == NULL) {
            fprintf(stderr, "Memory error\n");
            exit(1);
        }
        packetData[i].size = 0;
    }

    pcap_loop(handle, -1, callback, (u_char *) packetData);

    for (i = 0; i < count; i++) {
        printf("Packet %d:\n", i);
        printf("Size: %d\n", packetData[i].size);
        printf("Data:\n");
        for (int j = 0; j < packetData[i].size; j++) {
            printf("%02X ", (int) packetData[i].data[j]);
        }
        printf("\n");
    }

    for (i = 0; i < MAX_PACKETS; i++) {
        free(packetData[i].data);
    }

    pcap_close(handle);
    return 0;
}