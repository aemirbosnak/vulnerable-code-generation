//Falcon-180B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <string.h>
#include <pthread.h>

struct packet_data {
    u_char *packet;
    int packet_size;
};

void *packet_handler(void *arg) {
    struct packet_data *data = (struct packet_data *) arg;
    printf("Packet received: %d bytes\n", data->packet_size);
    printf("Packet contents:\n");
    for (int i = 0; i < data->packet_size; i++) {
        printf("%02X ", data->packet[i]);
    }
    printf("\n");
    free(data->packet);
    free(data);
}

void capture_packets() {
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    const u_char *packet;
    struct pcap_pkthdr header;
    handle = pcap_open_live("eth0", 65535, 1, 0, errbuf);
    if (handle == NULL) {
        printf("Error: %s\n", errbuf);
        return;
    }
    printf("Packet capture started.\n");
    while (1) {
        packet = pcap_next(handle, &header);
        if (packet == NULL) {
            printf("Error while capturing packets.\n");
            break;
        }
        struct packet_data *data = (struct packet_data *) malloc(sizeof(struct packet_data));
        data->packet = (u_char *) malloc(header.caplen);
        memcpy(data->packet, packet, header.caplen);
        data->packet_size = header.caplen;
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, packet_handler, data);
    }
    pcap_close(handle);
}

int main() {
    printf("Starting packet capture...\n");
    capture_packets();
    return 0;
}