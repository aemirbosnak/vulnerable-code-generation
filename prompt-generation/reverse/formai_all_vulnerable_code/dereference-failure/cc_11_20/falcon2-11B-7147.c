//Falcon2-11B DATASET v1.0 Category: Subnet Calculator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LEN 16
#define MAX_SUBNET_LEN 8

typedef struct {
    char ip[MAX_IP_LEN];
    char subnet[MAX_SUBNET_LEN];
} IPSubnet;

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <ip address>\n", argv[0]);
        return 1;
    }

    IPSubnet *subnet = (IPSubnet *)malloc(sizeof(IPSubnet));
    if (subnet == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    char *ip = argv[1];
    strncpy(subnet->ip, ip, MAX_IP_LEN - 1);
    subnet->ip[MAX_IP_LEN - 1] = '\0';

    int mask_bits = 0;
    int mask_len = 0;
    int octet = 0;
    for (int i = 0; i < 4; i++) {
        octet = subnet->ip[i] - '0';
        if (octet > 255) {
            printf("Invalid IP address: %s\n", subnet->ip);
            free(subnet);
            return 1;
        }
        if (i == 0 || i == 2) {
            mask_bits = (octet & 1) * 4;
            mask_len = mask_bits + 1;
            octet = 1;
            i += 1;
        } else if (i == 1 || i == 3) {
            mask_bits = (octet & 1) * 4;
            mask_len = mask_bits + 1;
            octet = 1;
            i += 1;
        } else {
            printf("Invalid IP address: %s\n", subnet->ip);
            free(subnet);
            return 1;
        }
    }

    int subnet_bits = mask_len * 8;
    int subnet_octet = 0;
    for (int i = 0; i < 4; i++) {
        if (i == 0) {
            subnet_octet = (subnet->ip[i] & mask_len) + 1;
        } else if (i == 1) {
            subnet_octet = (subnet->ip[i] & mask_len) + 1;
        } else if (i == 2) {
            subnet_octet = (subnet->ip[i] & mask_len) + 1;
        } else {
            subnet_octet = (subnet->ip[i] & mask_len) + 1;
        }

        int subnet_octet_str = subnet_octet + '0';
        strncpy(subnet->subnet, &subnet_octet_str, MAX_SUBNET_LEN - 1);
        subnet->subnet[MAX_SUBNET_LEN - 1] = '\0';
    }

    printf("Subnet: %s\n", subnet->subnet);
    free(subnet);

    return 0;
}