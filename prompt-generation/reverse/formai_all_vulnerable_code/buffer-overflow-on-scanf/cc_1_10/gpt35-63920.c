//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int get_octets(char *ip_addr, int octets[]) {
    int i = 0;
    char *ptr = strtok(ip_addr, ".");
    while (ptr != NULL && i < 4) {
        if (!isdigit(*ptr)) {
            return 0;
        }
        int octet = atoi(ptr);
        if (octet < 0 || octet > 255) {
            return 0;
        }
        octets[i++] = octet;
        ptr = strtok(NULL, ".");
    }
    return (i == 4);
}

int get_prefix_length(char *subnet_mask) {
    int mask;
    if (sscanf(subnet_mask, "%d", &mask) == 1) {
        if (mask >= 0 && mask <= 32) {
            return mask;
        }
    }
    return -1;
}

int main() {
    char ip_addr[16];
    char subnet_mask[3];
    printf("Enter IP Address: ");
    scanf("%s", ip_addr);
    printf("Enter Subnet Mask: ");
    scanf("%s", subnet_mask);

    int octets[4];
    if (!get_octets(ip_addr, octets)) {
        printf("Invalid IP address!\n");
        return EXIT_FAILURE;
    }

    int prefix_length = get_prefix_length(subnet_mask);
    if (prefix_length == -1) {
        printf("Invalid subnet mask!\n");
        return EXIT_FAILURE;
    }

    unsigned int num_host_bits = 32 - prefix_length;
    unsigned int num_hosts = (num_host_bits == 32) ? 0 : (1 << num_host_bits) - 2;
    unsigned int network_addr = (octets[0] << 24) | (octets[1] << 16) | (octets[2] << 8) | octets[3];
    unsigned int mask = (prefix_length == 0) ? 0 : (0xFFFFFFFF << (32 - prefix_length));

    printf("\n");
    printf("IP Address: %s\n", ip_addr);
    printf("Subnet Mask: %s /%d\n", subnet_mask, prefix_length);
    printf("Network Address: %d.%d.%d.%d\n", octets[0] & ((mask >> 24) & 0xFF), octets[1] & ((mask >> 16) & 0xFF), octets[2] & ((mask >> 8) & 0xFF), octets[3] & (mask & 0xFF));
    printf("Broadcast Address: %d.%d.%d.%d\n", octets[0] | ((~mask >> 24) & 0xFF), octets[1] | ((~mask >> 16) & 0xFF), octets[2] | ((~mask >> 8) & 0xFF), octets[3] | (~mask & 0xFF));

    printf("\n");
    printf("Prefix Length: %d\n", prefix_length);
    printf("Subnet Mask: %d.%d.%d.%d\n", (mask >> 24) & 0xFF, (mask >> 16) & 0xFF, (mask >> 8) & 0xFF, mask & 0xFF);
    printf("Number of Hosts: %u\n", num_hosts);
    printf("Usable Host Range: %d.%d.%d.%d - %d.%d.%d.%d\n", octets[0] & ((mask >> 24) & 0xFF), octets[1] & ((mask >> 16) & 0xFF), octets[2] & ((mask >> 8) & 0xFF), (octets[3] & (mask & 0xFF)) + 1, octets[0] | ((~mask >> 24) & 0xFF), octets[1] | ((~mask >> 16) & 0xFF), octets[2] | ((~mask >> 8) & 0xFF), (octets[3] | (~mask & 0xFF)) - 1);

    return 0;
}