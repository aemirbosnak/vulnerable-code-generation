//Falcon-180B DATASET v1.0 Category: Network Packet Monitoring ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <sys/socket.h>

#define MAX_PACKET_SIZE 65535
#define MAX_PACKET_COUNT 1000
#define MAX_THREAD_COUNT 10

struct packet_info {
    u_char *packet;
    int size;
};

void *packet_handler(void *arg) {
    struct packet_info *packet_info = (struct packet_info *) arg;
    u_char *packet = packet_info->packet;
    int size = packet_info->size;

    printf("Packet size: %d\n", size);
    printf("Packet data:\n");

    if (packet[12] == 6 && packet[13] == 0x00) {
        struct iphdr *ip_header = (struct iphdr *) packet;
        struct tcphdr *tcp_header = (struct tcphdr *) (packet + ip_header->ihl * 4);

        printf("TCP\n");
        printf("Source IP: %s\n", inet_ntoa(*(struct in_addr *) &ip_header->saddr));
        printf("Destination IP: %s\n", inet_ntoa(*(struct in_addr *) &ip_header->daddr));
        printf("Source port: %d\n", ntohs(tcp_header->source));
        printf("Destination port: %d\n", ntohs(tcp_header->dest));
    } else if (packet[12] == 17 && packet[13] == 0x00) {
        struct iphdr *ip_header = (struct iphdr *) packet;
        struct udphdr *udp_header = (struct udphdr *) (packet + ip_header->ihl * 4);

        printf("UDP\n");
        printf("Source IP: %s\n", inet_ntoa(*(struct in_addr *) &ip_header->saddr));
        printf("Destination IP: %s\n", inet_ntoa(*(struct in_addr *) &ip_header->daddr));
        printf("Source port: %d\n", ntohs(udp_header->source));
        printf("Destination port: %d\n", ntohs(udp_header->dest));
    } else {
        printf("Unknown protocol\n");
    }

    free(packet_info);
    return NULL;
}

int main() {
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    int device;
    char filter_exp[50];

    printf("Enter the network device: ");
    scanf("%d", &device);

    sprintf(filter_exp, "tcp or udp");

    handle = pcap_open_live(device, MAX_PACKET_SIZE, 1, 0, errbuf);
    if (handle == NULL) {
        printf("Error opening capture device: %s\n", errbuf);
        return 1;
    }

    pcap_loop(handle, -1, packet_handler, NULL);

    pcap_close(handle);
    return 0;
}