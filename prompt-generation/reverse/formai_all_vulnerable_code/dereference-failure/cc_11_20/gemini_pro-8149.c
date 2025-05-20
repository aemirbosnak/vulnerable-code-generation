//GEMINI-pro DATASET v1.0 Category: Packet Capturer with pcap library ; Style: intelligent
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom packet header structure
typedef struct {
    // Ethernet header fields
    uint8_t dst_mac[6];
    uint8_t src_mac[6];
    uint16_t ethertype;

    // IP header fields
    uint8_t ip_version;
    uint8_t ip_hdrlen;
    uint8_t ip_tos;
    uint16_t ip_total_len;
    uint16_t ip_id;
    uint16_t ip_frag_offset;
    uint8_t ip_ttl;
    uint8_t ip_protocol;
    uint16_t ip_checksum;
    uint32_t ip_src_addr;
    uint32_t ip_dst_addr;

    // TCP header fields
    uint16_t tcp_src_port;
    uint16_t tcp_dst_port;
    uint32_t tcp_seq;
    uint32_t tcp_ack;
    uint8_t tcp_data_offset;
    uint8_t tcp_flags;
    uint16_t tcp_window;
    uint16_t tcp_checksum;
    uint16_t tcp_urgent_ptr;

    // Payload (max 1460 bytes)
    uint8_t payload[1460];
} CustomPacketHeader;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <interface> <bpf_filter>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *interface = argv[1];
    char *bpf_filter = argv[2];

    // Open the network interface
    pcap_t *handle = pcap_open_live(interface, BUFSIZ, 1, 1000, NULL);
    if (!handle) {
        fprintf(stderr, "Error opening %s: %s\n", interface, pcap_geterr(handle));
        return EXIT_FAILURE;
    }

    // Compile the BPF filter
    struct bpf_program fp;
    if (pcap_compile(handle, &fp, bpf_filter, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
        pcap_close(handle);
        return EXIT_FAILURE;
    }

    // Set the filter
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
        pcap_freecode(&fp);
        pcap_close(handle);
        return EXIT_FAILURE;
    }

    while (1) {
        // Retrieve a packet
        struct pcap_pkthdr *header;
        const uint8_t *packet;
        int res = pcap_next_ex(handle, &header, &packet);

        if (res == -1) {
            fprintf(stderr, "Error capturing packet: %s\n", pcap_geterr(handle));
            pcap_freecode(&fp);
            pcap_close(handle);
            return EXIT_FAILURE;
        } else if (res == 0) {
            continue;
        }

        // Parse the custom packet header
        CustomPacketHeader *custom_header = (CustomPacketHeader *) packet;

        // Print the packet information
        printf("Packet length: %d\n", header->caplen);
        printf("Ethernet: %02x:%02x:%02x:%02x:%02x:%02x -> %02x:%02x:%02x:%02x:%02x:%02x\n",
            custom_header->src_mac[0], custom_header->src_mac[1], custom_header->src_mac[2],
            custom_header->src_mac[3], custom_header->src_mac[4], custom_header->src_mac[5],
            custom_header->dst_mac[0], custom_header->dst_mac[1], custom_header->dst_mac[2],
            custom_header->dst_mac[3], custom_header->dst_mac[4], custom_header->dst_mac[5]);
        printf("IP: %d.%d.%d.%d -> %d.%d.%d.%d\n",
            (custom_header->ip_src_addr >> 24) & 0xFF, (custom_header->ip_src_addr >> 16) & 0xFF,
            (custom_header->ip_src_addr >> 8) & 0xFF, custom_header->ip_src_addr & 0xFF,
            (custom_header->ip_dst_addr >> 24) & 0xFF, (custom_header->ip_dst_addr >> 16) & 0xFF,
            (custom_header->ip_dst_addr >> 8) & 0xFF, custom_header->ip_dst_addr & 0xFF);
        printf("TCP: %d -> %d\n", ntohs(custom_header->tcp_src_port), ntohs(custom_header->tcp_dst_port));

        // Print the payload (if any)
        if (header->caplen > sizeof(CustomPacketHeader)) {
            printf("Payload:\n");
            for (int i = 0; i < header->caplen - sizeof(CustomPacketHeader); i++) {
                if (i % 16 == 0) {
                    printf("%04x: ", i);
                }
                printf("%02x ", packet[i + sizeof(CustomPacketHeader)]);
                if ((i + 1) % 16 == 0) {
                    printf("\n");
                }
            }
        }

        printf("\n\n");
    }

    // Free the BPF filter code
    pcap_freecode(&fp);

    // Close the network interface
    pcap_close(handle);

    return EXIT_SUCCESS;
}