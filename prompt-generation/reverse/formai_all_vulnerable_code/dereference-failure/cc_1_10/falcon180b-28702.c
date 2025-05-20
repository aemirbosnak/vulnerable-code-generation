//Falcon-180B DATASET v1.0 Category: Packet Capturer with pcap library ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>
#include <time.h>

#define MAX_SNAPLEN 65535
#define MAX_PKTSIZE 2000

// Function to be executed for each incoming packet
void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    printf("Received packet with length %d\n", header->len);
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    char dev[] = "eth0"; // Device to capture packets on
    char filter_exp[] = "tcp"; // Filter expression to capture only TCP packets
    struct bpf_program fp; // BPF program for filtering

    handle = pcap_open_live(dev, MAX_SNAPLEN, 1, 0, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live() failed: %s\n", errbuf);
        exit(1);
    }

    if (pcap_compile(handle, &fp, filter_exp, 0, 0)!= 0) {
        fprintf(stderr, "pcap_compile() failed\n");
        exit(1);
    }

    if (pcap_setfilter(handle, &fp)!= 0) {
        fprintf(stderr, "pcap_setfilter() failed\n");
        exit(1);
    }

    printf("Packet capture started...\n");

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, (void *)packet_handler, (void *)NULL);

    pcap_loop(handle, -1, packet_handler, NULL);

    pcap_freecode(&fp);
    pcap_close(handle);

    return 0;
}