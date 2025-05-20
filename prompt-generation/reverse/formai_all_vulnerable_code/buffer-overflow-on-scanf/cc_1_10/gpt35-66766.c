//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ether.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <net/ethernet.h>

#define BUFLEN 65535

int main(int argc, char *argv[]) {

    int sockfd;
    char buffer[BUFLEN];
    struct sockaddr_in saddr;
    struct ifreq interface;
    char if_name[IFNAMSIZ];

    printf("Wireless Network Scanner\n");
    printf("========================\n");

    // Get the interface name
    printf("Enter Interface Name: ");
    scanf("%s", if_name);

    // Open the socket
    if ((sockfd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL))) < 0) {
        perror("Socket Error");
        return -1;
    }

    // Bind the socket to the interface
    memset(&interface, 0, sizeof(struct ifreq));
    strncpy(interface.ifr_name, if_name, IFNAMSIZ-1);
    if (ioctl(sockfd, SIOCGIFINDEX, &interface) < 0) {
        perror("ioctl error");
        close(sockfd);
        return -1;
    }

    memset(&saddr, 0, sizeof(struct sockaddr_in));
    saddr.sin_family = AF_PACKET;
    saddr.sin_port = htons(ETH_P_ALL);
    saddr.sin_addr.s_addr = htons(INADDR_ANY);
    saddr.sin_addr.s_addr = htonl(interface.ifr_ifindex);

    if (bind(sockfd, (struct sockaddr*) &saddr, sizeof(struct sockaddr_in)) < 0) {
        perror("Bind Error");
        close(sockfd);
        return -1;
    }

    printf("========================\n");
    printf("Listening on Interface: %s\n", if_name);
    printf("========================\n");

    while (1) {
        memset(&buffer, 0, BUFLEN * sizeof(char));

        int n = recvfrom(sockfd, buffer, BUFLEN, 0, NULL, NULL);
        if (n < 0) {
            perror("recvfrom error");
        }

        printf("Received %d bytes\n", n);

        // Parse the packet
        struct ether_header *eth_header = (struct ether_header *) buffer;

        printf("Ethernet Source Address: %s\n", ether_ntoa((const struct ether_addr *)eth_header->ether_shost));
        printf("Ethernet Destination Address: %s\n", ether_ntoa((const struct ether_addr *)eth_header->ether_dhost));

        if (ntohs(eth_header->ether_type) == ETH_P_IP) {
            printf("IP Packet\n");

            struct iphdr *ip_header = (struct iphdr *) (buffer + sizeof(struct ether_header));

            char source_ip[INET_ADDRSTRLEN];
            char dest_ip[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &ip_header->saddr, source_ip, INET_ADDRSTRLEN);
            inet_ntop(AF_INET, &ip_header->daddr, dest_ip, INET_ADDRSTRLEN);

            printf("Source IP Address: %s\n", source_ip);
            printf("Destination IP Address: %s\n", dest_ip);

            if (ip_header->protocol == IPPROTO_TCP) {
                printf("TCP Packet\n");

                struct tcphdr *tcp_header = (struct tcphdr *) (buffer + sizeof(struct ether_header) + sizeof(struct iphdr));

                printf("Source Port: %d\n", ntohs(tcp_header->source));
                printf("Destination Port: %d\n", ntohs(tcp_header->dest));
            }
            else if (ip_header->protocol == IPPROTO_UDP) {
                printf("UDP Packet\n");

                struct udphdr *udp_header = (struct udphdr *) (buffer + sizeof(struct ether_header) + sizeof(struct iphdr));

                printf("Source Port: %d\n", ntohs(udp_header->source));
                printf("Destination Port: %d\n", ntohs(udp_header->dest));
            }
            printf("========================\n");
        }
    }

    // Close the socket
    close(sockfd);
    return 0;
}