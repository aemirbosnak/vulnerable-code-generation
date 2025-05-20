//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_IP_LEN 16
#define MAX_CIDR_LEN 3
#define MAX_SUBNETS 10

typedef struct {
    char network[MAX_IP_LEN];
    char broadcast[MAX_IP_LEN];
    char first_host[MAX_IP_LEN];
    char last_host[MAX_IP_LEN];
    int num_hosts;
} SubnetInfo;

void calculate_subnet(const char* ip, const char* cidr, SubnetInfo* subnet_info) {
    struct in_addr addr;
    inet_aton(ip, &addr);
    
    int network_bits = atoi(cidr);
    int mask_bits = 32 - network_bits;
    unsigned int mask = ~((1 << mask_bits) - 1);

    unsigned int network = ntohl(addr.s_addr) & mask;
    unsigned int broadcast = network | ~mask;
    
    snprintf(subnet_info->network, MAX_IP_LEN, "%s", inet_ntoa((struct in_addr){ htonl(network) }));
    snprintf(subnet_info->broadcast, MAX_IP_LEN, "%s", inet_ntoa((struct in_addr){ htonl(broadcast) }));

    unsigned int first_host = network + 1;
    unsigned int last_host = broadcast - 1;

    snprintf(subnet_info->first_host, MAX_IP_LEN, "%s", inet_ntoa((struct in_addr){ htonl(first_host) }));
    snprintf(subnet_info->last_host, MAX_IP_LEN, "%s", inet_ntoa((struct in_addr){ htonl(last_host) }));
    
    subnet_info->num_hosts = (1 << (32 - network_bits)) - 2;
}

int main() {
    char ip[MAX_IP_LEN];
    char cidr[MAX_CIDR_LEN];
    SubnetInfo subnet_info;
    
    printf("Brave Subnet Calculator\n");
    printf("-----------------------\n");

    while (1) {
        printf("Enter IP address (x.x.x.x format): ");
        fgets(ip, MAX_IP_LEN, stdin);
        ip[strcspn(ip, "\n")] = '\0';  // Remove trailing newline
        
        printf("Enter CIDR (like 24): ");
        fgets(cidr, MAX_CIDR_LEN, stdin);
        cidr[strcspn(cidr, "\n")] = '\0';  // Remove trailing newline
        
        if (strcmp(ip, "exit") == 0 || strcmp(cidr, "exit") == 0) {
            break;
        }

        calculate_subnet(ip, cidr, &subnet_info);

        printf("Network Address: %s\n", subnet_info.network);
        printf("Broadcast Address: %s\n", subnet_info.broadcast);
        printf("First Host: %s\n", subnet_info.first_host);
        printf("Last Host: %s\n", subnet_info.last_host);
        printf("Number of Usable Hosts: %d\n", subnet_info.num_hosts);
        printf("-----------------------\n");
    }

    printf("Exiting Brave Subnet Calculator.\n");
    return 0;
}