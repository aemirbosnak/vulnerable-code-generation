//Code Llama-13B DATASET v1.0 Category: Network Packet Monitoring ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <pcap.h>

#define SNAP_LEN 65535
#define NETWORK_INTERFACE "eth0"

int main(int argc, char *argv[]) {
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct pcap_pkthdr hdr;
    const u_char *packet;
    int i, j, k;

    // Open the network interface
    handle = pcap_open_live(NETWORK_INTERFACE, SNAP_LEN, 1, 1, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", NETWORK_INTERFACE, errbuf);
        return 2;
    }

    // Loop indefinitely, printing out packets
    while (1) {
        packet = pcap_next(handle, &hdr);
        if (packet == NULL) {
            fprintf(stderr, "Error reading packet: %s\n", pcap_geterr(handle));
            return 3;
        }

        // Print out the packet's source and destination IP addresses
        struct in_addr src, dst;
        src.s_addr = *(u_int32_t *)(packet + 12);
        dst.s_addr = *(u_int32_t *)(packet + 16);
        printf("Source IP: %s\n", inet_ntoa(src));
        printf("Destination IP: %s\n", inet_ntoa(dst));

        // Print out the packet's source and destination ports
        uint16_t src_port = *(uint16_t *)(packet + 20);
        uint16_t dst_port = *(uint16_t *)(packet + 22);
        printf("Source port: %d\n", ntohs(src_port));
        printf("Destination port: %d\n", ntohs(dst_port));

        // Print out the packet's payload
        int payload_len = hdr.len - 40;
        printf("Payload length: %d\n", payload_len);
        for (i = 0; i < payload_len; i++) {
            printf("%02x ", packet[40 + i]);
        }
        printf("\n");
    }

    pcap_close(handle);
    return 0;
}