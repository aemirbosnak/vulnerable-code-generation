//FormAI DATASET v1.0 Category: Firewall ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_PACKET_SIZE 65535

// Structure for holding packet information
struct packet_info {
    struct sockaddr_in source_addr;
    struct sockaddr_in dest_addr;
    int source_port;
    int dest_port;
    unsigned char *payload;
    int payload_size;
};

// Function to parse an incoming packet
int parse_packet(unsigned char *buffer, int size, struct packet_info *packet) {
    struct iphdr *ip_header = (struct iphdr*)buffer;
    if (ip_header->version != 4) {
        return -1;
    }

    packet->source_addr.sin_addr.s_addr = ip_header->saddr;
    packet->dest_addr.sin_addr.s_addr = ip_header->daddr;

    struct tcphdr *tcp_header = (struct tcphdr*)(buffer + (ip_header->ihl * 4));
    packet->source_port = ntohs(tcp_header->source);
    packet->dest_port = ntohs(tcp_header->dest);

    packet->payload = buffer + (ip_header->ihl * 4) + (tcp_header->doff * 4);
    packet->payload_size = size - (ip_header->ihl * 4) - (tcp_header->doff * 4);

    return 0;
}

// Function to check if a packet should be blocked
int check_packet(struct packet_info packet) {
    if (packet.payload_size > 0) {
        // Check for malicious payload here
        // ...
        return 1; // Block the packet
    }

    return 0; // Don't block the packet
}

// Main program function
int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);
    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);

    if (bind(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        return 1;
    }

    while (1) {
        unsigned char buffer[MAX_PACKET_SIZE];
        struct packet_info packet;

        int recv_size = recv(sock, buffer, MAX_PACKET_SIZE, 0);
        if (recv_size == -1) {
            perror("recv");
            continue;
        }

        parse_packet(buffer, recv_size, &packet);

        if (check_packet(packet)) {
            printf("Blocked packet from %s:%d to %s:%d\n",
                   inet_ntoa(packet.source_addr.sin_addr), packet.source_port,
                   inet_ntoa(packet.dest_addr.sin_addr), packet.dest_port);
            continue;
        }

        // Forward packet to destination
        struct hostent *he = gethostbyname(inet_ntoa(packet.dest_addr.sin_addr));
        if (he == NULL) {
            printf("Unknown host: %s\n", inet_ntoa(packet.dest_addr.sin_addr));
            continue;
        }

        struct sockaddr_in dest_addr;
        memset(&dest_addr, 0, sizeof(dest_addr));
        dest_addr.sin_family = AF_INET;
        dest_addr.sin_port = htons(packet.dest_port);
        dest_addr.sin_addr = *((struct in_addr*)he->h_addr);

        if (sendto(sock, buffer, recv_size, 0, (struct sockaddr*)&dest_addr, sizeof(dest_addr)) == -1) {
            perror("sendto");
            continue;
        }

        printf("Forwarded packet from %s:%d to %s:%d\n",
               inet_ntoa(packet.source_addr.sin_addr), packet.source_port,
               inet_ntoa(dest_addr.sin_addr), packet.dest_port);
    }

    close(sock);

    return 0;
}