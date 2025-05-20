//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <netinet/if_ether.h> 
#include <net/ethernet.h> 
#include <netinet/ether.h> 
#include <errno.h>
#include <net/if.h> 
#include <sys/ioctl.h> 
#include <netpacket/packet.h> 

void print_mac(unsigned char *mac) {
    int i;
	printf("%02x:%02x:%02x:%02x:%02x:%02x\n", 
    mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
}

int main() { 
    int sockfd; 
    int n; 
    char interface[IFNAMSIZ]; 
    unsigned char buffer[2048];
    struct ifreq ifr; 
    struct sockaddr_ll sll; 
    unsigned char src_mac[6];
    int len = sizeof(sll); 

    printf("Enter interface name: ");
    scanf("%s", interface);
  
    sockfd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL)) ;
    if(sockfd < 0) {
        perror("socket creation error");
        exit(1);
    }
  
    memset(&ifr, 0, sizeof(ifr));
    strncpy(ifr.ifr_name, interface, IFNAMSIZ-1); 
  
    if((ioctl(sockfd, SIOCGIFHWADDR, &ifr))<0) {
        perror("ioctl error");
        exit(2);
    }
  
    memcpy(src_mac, ifr.ifr_hwaddr.sa_data, 6);

    memset(&sll, 0, len); 
    sll.sll_family = AF_PACKET; 
    sll.sll_ifindex = if_nametoindex(interface); 
    sll.sll_halen = 6; 
    memcpy(sll.sll_addr, src_mac, 6); 

    printf("Listening for wireless networks...\n");

    while(1) { 
        n = recvfrom(sockfd, buffer, 2048, 0, (struct sockaddr*)&sll, &len); 
        if(n < 0) {
            perror("recvfrom error");
            close(sockfd); 
            exit(3); 
        }
        else if(n == 0) {
            printf("No data received.\n"); 
        }
        else {
            struct ether_header *eth = (struct ether_header *)(buffer);
            if(ntohs(eth->ether_type) == ETHERTYPE_IP) {
                printf("IP packet\n"); 
            }
            else if(ntohs(eth->ether_type) == ETHERTYPE_ARP) {
                printf("ARP packet\n"); 
            }
            else if(ntohs(eth->ether_type) == ETHERTYPE_REVARP) {
                printf("RARP packet\n"); 
            }
            else {
                printf("Unknown packet\n"); 
            }
            printf("Source MAC: ");
            print_mac(eth->ether_shost);
            printf("Destination MAC: ");
            print_mac(eth->ether_dhost);
            printf("\n");
        }
    }
    close(sockfd); 
    return 0; 
}