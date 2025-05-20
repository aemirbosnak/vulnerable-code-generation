//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LEN 16
#define MAX_MASK_LEN 32

typedef struct {
    unsigned int addr;
    unsigned int mask;
    unsigned int net_addr;
    unsigned int broadcast_addr;
    unsigned int num_hosts;
} subnet_info;

int get_ip_address(char *ip_str, unsigned int *ip_addr);
int get_subnet_mask(char *mask_str, unsigned int *subnet_mask);
void calculate_subnet(subnet_info *subnet);
void print_subnet_info(subnet_info *subnet);

int main() {
    char ip_str[MAX_IP_LEN];
    char mask_str[MAX_MASK_LEN];
    subnet_info subnet;

    printf("Enter the IP address: ");
    scanf("%s", ip_str);

    printf("Enter the subnet mask: ");
    scanf("%s", mask_str);

    if (get_ip_address(ip_str, &subnet.addr) != 0) {
        printf("Invalid IP address\n");
        return 1;
    }

    if (get_subnet_mask(mask_str, &subnet.mask) != 0) {
        printf("Invalid subnet mask\n");
        return 1;
    }

    calculate_subnet(&subnet);
    print_subnet_info(&subnet);

    return 0;
}

int get_ip_address(char *ip_str, unsigned int *ip_addr) {
    int octets[4];
    char *ptr;

    ptr = strtok(ip_str, ".");
    if (ptr == NULL) {
        return -1;
    }

    for (int i = 0; i < 4; i++) {
        octets[i] = atoi(ptr);
        if (octets[i] < 0 || octets[i] > 255) {
            return -1;
        }
        ptr = strtok(NULL, ".");
        if (ptr == NULL) {
            return -1;
        }
    }

    *ip_addr = (octets[0] << 24) | (octets[1] << 16) | (octets[2] << 8) | octets[3];
    return 0;
}

int get_subnet_mask(char *mask_str, unsigned int *subnet_mask) {
    int bits;

    bits = atoi(mask_str);
    if (bits < 0 || bits > 32) {
        return -1;
    }

    *subnet_mask = (1 << bits) - 1;
    return 0;
}

void calculate_subnet(subnet_info *subnet) {
    subnet->net_addr = subnet->addr & subnet->mask;
    subnet->broadcast_addr = subnet->net_addr | ~subnet->mask;
    subnet->num_hosts = (1 << (32 - subnet->mask)) - 2;
}

void print_subnet_info(subnet_info *subnet) {
    printf("Network address: %u.%u.%u.%u\n",
        (subnet->net_addr >> 24) & 0xff,
        (subnet->net_addr >> 16) & 0xff,
        (subnet->net_addr >> 8) & 0xff,
        subnet->net_addr & 0xff);

    printf("Broadcast address: %u.%u.%u.%u\n",
        (subnet->broadcast_addr >> 24) & 0xff,
        (subnet->broadcast_addr >> 16) & 0xff,
        (subnet->broadcast_addr >> 8) & 0xff,
        subnet->broadcast_addr & 0xff);

    printf("Number of hosts: %u\n", subnet->num_hosts);
}