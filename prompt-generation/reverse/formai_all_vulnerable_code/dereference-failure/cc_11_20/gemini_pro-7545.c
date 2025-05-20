//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pcap.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define PROMISCUOUS 1
#define SNAPLEN 65535
#define TIMEOUT 1000

int main() {
    char *interface;
    pcap_t *handle;
    struct bpf_program filter;
    char filter_exp[] = "tcp and port 80";
    struct pcap_pkthdr *header;
    const u_char *packet;
    char *src_ip, *dst_ip;
    int src_port, dst_port;

    // Get the network interface to listen on
    interface = pcap_lookupdev(NULL);
    if (interface == NULL) {
        printf("Could not find a suitable network interface\n");
        return 1;
    }

    // Open the network interface
    handle = pcap_open_live(interface, SNAPLEN, PROMISCUOUS, TIMEOUT, NULL);
    if (handle == NULL) {
        printf("Could not open the network interface %s\n", interface);
        return 1;
    }

    // Compile the filter expression
    if (pcap_compile(handle, &filter, filter_exp, 0, 0) != 0) {
        printf("Could not compile the filter expression\n");
        return 1;
    }

    // Set the filter
    if (pcap_setfilter(handle, &filter) != 0) {
        printf("Could not set the filter\n");
        return 1;
    }

    // Start the packet capture loop
    while (1) {
        // Wait for a packet to arrive
        int res = pcap_next_ex(handle, &header, &packet);
        if (res == 0) {
            continue;
        } else if (res == -1) {
            printf("Error reading packet\n");
            break;
        }

        // Parse the packet header
        src_ip = inet_ntoa(*(struct in_addr *) (packet + 12));
        dst_ip = inet_ntoa(*(struct in_addr *) (packet + 16));
        src_port = ntohs(*(unsigned short *) (packet + 34));
        dst_port = ntohs(*(unsigned short *) (packet + 36));

        // Print the packet information
        printf("Packet captured at %s\n", ctime(&header->ts.tv_sec));
        printf("Source IP: %s\n", src_ip);
        printf("Destination IP: %s\n", dst_ip);
        printf("Source port: %d\n", src_port);
        printf("Destination port: %d\n", dst_port);

        // Check if the packet is malicious
        if (src_port == 23 || dst_port == 23) {
            printf("Telnet traffic detected\n");
        } else if (src_port == 25 || dst_port == 25) {
            printf("SMTP traffic detected\n");
        } else if (src_port == 80 || dst_port == 80) {
            printf("HTTP traffic detected\n");
        } else {
            printf("Unknown traffic detected\n");
        }

        printf("\n");
    }

    // Close the network interface
    pcap_close(handle);

    return 0;
}