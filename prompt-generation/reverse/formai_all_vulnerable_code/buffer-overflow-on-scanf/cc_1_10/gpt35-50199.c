//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <arpa/inet.h>

// This function is called every time pcap receives a packet
void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data) {
    int pkt_len = header->len;
    char *src_ip = NULL;
    char *dst_ip = NULL;
    char *protocol_name = NULL;
    struct sockaddr_in src_addr, dst_addr;

    // Get source and destination IP addresses
    memcpy(&src_addr, &pkt_data[26], sizeof(src_addr));
    memcpy(&dst_addr, &pkt_data[30], sizeof(dst_addr));
    src_ip = inet_ntoa(src_addr.sin_addr);
    dst_ip = inet_ntoa(dst_addr.sin_addr);

    // Get protocol ID and protocol name
    int proto_id = pkt_data[23];
    switch(proto_id) {
        case IPPROTO_TCP:
            protocol_name = "TCP";
            break;
        case IPPROTO_UDP:
            protocol_name = "UDP";
            break;
        case IPPROTO_ICMP:
            protocol_name = "ICMP";
            break;
        default:
            protocol_name = "Unknown";
    }

    // Print packet information
    printf("Packet captured: length=%d bytes, protocol=%s\n", pkt_len, protocol_name);
    printf("Source IP: %s\n", src_ip);
    printf("Destination IP: %s\n", dst_ip);
    printf("----------------------------------\n");
}

int main(int argc, char **argv) {
    char *dev;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    struct bpf_program fp;
    bpf_u_int32 mask;
    bpf_u_int32 net;

    // Prompt user for device to monitor
    printf("Enter the device to monitor (e.g. eth0): ");
    scanf("%s", dev);

    // Get network mask and IP address of the device
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        printf("Error getting information for device: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    // Open device for packet capture
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        printf("Error opening device for packet capture: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    // Compile the filter expression
    if (pcap_compile(handle, &fp, "ip", 0, net) == -1) {
        printf("Error compiling filter expression: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    // Apply the filter expression
    if(pcap_setfilter(handle, &fp) == -1 ){
        printf("Error setting filter expression: %s\n", pcap_geterr(handle));
        exit(EXIT_FAILURE);
    }

    // Start packet capture loop
    printf("Packet monitoring started...\n");
    pcap_loop(handle, -1, packet_handler, NULL);

    // Close the device handle
    pcap_close(handle);

    return 0;
}