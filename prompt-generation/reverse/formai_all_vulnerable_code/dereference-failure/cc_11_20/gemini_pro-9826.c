//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define MAX_PACKET_SIZE 65535

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <pcap file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the pcap file
    pcap_t *handle = pcap_open_offline(argv[1], NULL);
    if (handle == NULL) {
        perror("pcap_open_offline");
        return EXIT_FAILURE;
    }

    // Set the filter
    struct bpf_program filter;
    if (pcap_compile(handle, &filter, "tcp", 1, 0) == -1) {
        perror("pcap_compile");
        return EXIT_FAILURE;
    }
    if (pcap_setfilter(handle, &filter) == -1) {
        perror("pcap_setfilter");
        return EXIT_FAILURE;
    }

    // Loop through the packets
    struct pcap_pkthdr *header;
    const unsigned char *data;
    while (pcap_next_ex(handle, &header, &data) >= 0) {
        // Get the source and destination IP addresses
        struct in_addr src_ip;
        struct in_addr dst_ip;
        memcpy(&src_ip, &data[12], 4);
        memcpy(&dst_ip, &data[16], 4);

        // Get the source and destination ports
        uint16_t src_port = ntohs(*(uint16_t *)&data[20]);
        uint16_t dst_port = ntohs(*(uint16_t *)&data[22]);

        // Get the timestamp
        struct timeval timestamp = header->ts;

        // Print the packet information
        printf("%s:%d -> %s:%d at %ld.%06ld\n",
               inet_ntoa(src_ip), src_port,
               inet_ntoa(dst_ip), dst_port,
               timestamp.tv_sec, timestamp.tv_usec);

        // Check for suspicious activity
        if (src_port == 23 || dst_port == 23) {
            printf("Suspicious activity: Telnet traffic detected\n");
        }
        if (src_port == 25 || dst_port == 25) {
            printf("Suspicious activity: SMTP traffic detected\n");
        }
        if (src_port == 443 || dst_port == 443) {
            printf("Suspicious activity: HTTPS traffic detected\n");
        }
    }

    // Close the pcap file
    pcap_close(handle);

    return EXIT_SUCCESS;
}