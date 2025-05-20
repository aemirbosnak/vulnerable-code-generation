//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Donald Knuth
#include <stdio.h>

/* Converts dotted-decimal IP address to binary */
unsigned int ipv4_to_bin(char ip_addr[]) {
    int a, b, c, d;
    sscanf(ip_addr, "%d.%d.%d.%d", &a, &b, &c, &d);
    return (a << 24) | (b << 16) | (c << 8) | d;
}

/* Converts binary IP address to dotted-decimal */
void bin_to_ipv4(unsigned int ip_addr, char str[]) {
    sprintf(str, "%d.%d.%d.%d", (ip_addr >> 24) & 0xFF, 
            (ip_addr >> 16) & 0xFF, (ip_addr >> 8) & 0xFF, ip_addr & 0xFF);
}

/* Calculates subnet mask from CIDR notation */
unsigned int cidr_to_mask(int cidr) {
    return (0xFFFFFFFF << (32 - cidr));
}

/* Calculates network address */
unsigned int calc_network_addr(unsigned int ip_addr, unsigned int net_mask) {
    return (ip_addr & net_mask);
}

/* Calculates broadcast address */
unsigned int calc_broadcast_addr(unsigned int network_addr, unsigned int net_mask) {
    return (network_addr | (~net_mask));
}

/* Calculates number of hosts */
unsigned int calc_num_hosts(int cidr) {
    return (1 << (32 - cidr)) - 2;
}

int main() {
    char ip_address[20];
    int cidr_notation;

    printf("Enter IP address in dotted-decimal format: ");
    scanf("%s", ip_address);
    printf("Enter subnet mask in CIDR notation: ");
    scanf("%d", &cidr_notation);

    unsigned int ip_addr = ipv4_to_bin(ip_address);
    unsigned int net_mask = cidr_to_mask(cidr_notation);
    unsigned int network_addr = calc_network_addr(ip_addr, net_mask);
    unsigned int broadcast_addr = calc_broadcast_addr(network_addr, net_mask);
    unsigned int num_hosts = calc_num_hosts(cidr_notation);

    char net_addr_str[20], broadcast_addr_str[20];
    bin_to_ipv4(network_addr, net_addr_str);
    bin_to_ipv4(broadcast_addr, broadcast_addr_str);

    printf("\nNetwork Address: %s\n", net_addr_str);
    printf("Broadcast Address: %s\n", broadcast_addr_str);
    printf("Number of Hosts: %u\n\n", num_hosts);

    return 0;
}