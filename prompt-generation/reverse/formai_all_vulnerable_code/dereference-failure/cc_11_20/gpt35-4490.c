//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <net/if.h>

#define BUFSIZE 65536
#define ETHERNET_HEADER_LENGTH 14
#define IP_HEADER_LENGTH 20
#define TCP_HEADER_LENGTH 20

int main(int argc, char *argv[]) {
    int sockfd, nread;
    struct sockaddr_in servaddr, localaddr;
    char buf[BUFSIZE];
    
    // Create socket
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // Set socket options
    int one = 1;
    if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &one, sizeof(one)) < 0) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }
    
    // Set timeout for recvfrom function
    struct timeval timeout;
    timeout.tv_sec = 5;
    timeout.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }
    
    // Bind to a local interface
    memset(&localaddr, 0, sizeof(localaddr));
    localaddr.sin_family = AF_INET;
    localaddr.sin_port = htons(0);
    localaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(sockfd, (struct sockaddr *)&localaddr, sizeof(localaddr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Send an ARP request to get the MAC address of the gateway
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("192.168.1.1");
    
    struct arpreq arp;
    memset(&arp, 0, sizeof(arp));
    arp.arp_flags = ATF_COM;
    ((struct sockaddr_in *)&arp.arp_pa)->sin_family = AF_INET;
    ((struct sockaddr_in *)&arp.arp_pa)->sin_addr.s_addr = servaddr.sin_addr.s_addr;
    
    if (ioctl(sockfd, SIOCGARP, (caddr_t)&arp) < 0) {
        perror("ioctl failed");
        exit(EXIT_FAILURE);
    }
    
    // Extract gateway MAC address from ARP response
    unsigned char gateway_mac[6];
    memcpy(gateway_mac, arp.arp_ha.sa_data, 6);
    
    // Print header
    printf("%-20s%-20s%-20s%-20s\n", "IP Address", "Hostname", "MAC Address", "Vendor");
    
    while (1) {
        // Receive packets
        nread = recvfrom(sockfd, buf, BUFSIZE, 0, NULL, NULL);
        if (nread < 0) {
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                break; // Timeout expired, stop scanning
            } else {
                perror("recvfrom failed");
                exit(EXIT_FAILURE);
            }
        }
        
        // Extract Ethernet header
        struct ether_header *eth_hdr = (struct ether_header *)buf;
        
        // Check if it's an IP packet
        if (ntohs(eth_hdr->ether_type) != ETHERTYPE_IP) {
            continue; // Not an IP packet, ignore it
        }
        
        // Extract IP header
        struct iphdr *ip_hdr = (struct iphdr *)(buf + ETHERNET_HEADER_LENGTH);
        
        // Check if it's a TCP packet
        if (ip_hdr->protocol != IPPROTO_TCP) {
            continue; // Not a TCP packet, ignore it
        }
        
        // Extract TCP header
        struct tcphdr *tcp_hdr = (struct tcphdr *)(buf + ETHERNET_HEADER_LENGTH + IP_HEADER_LENGTH);
        
        // Check if the ACK flag is set
        if (!(tcp_hdr->th_flags & TH_ACK)) {
            continue; // Not an ACK packet, ignore it
        }
        
        // Extract source IP address
        char src_addr[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(ip_hdr->saddr), src_addr, INET_ADDRSTRLEN);
        
        // Extract source port number
        unsigned short src_port = ntohs(tcp_hdr->th_sport);
        
        // Extract MAC address
        unsigned char *mac_addr = eth_hdr->ether_shost;
        
        // Print information
        printf("%-20s%-20s%02x:%02x:%02x:%02x:%02x:%02x\t%s\n", src_addr, "", mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5], "");
    }
    
    // Close socket
    close(sockfd);
    
    return 0;
}