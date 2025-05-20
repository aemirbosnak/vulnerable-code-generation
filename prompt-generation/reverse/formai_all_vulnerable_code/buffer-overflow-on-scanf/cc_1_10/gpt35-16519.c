//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct IP_Address {
    int ip[4];
} ip_address;

struct Subnet_Mask {
    int mask[4];
} subnet_mask;

void get_octets(char* str, int* octets) {
    char *pch;
    pch = strtok(str, ".");
    int i = 0;
    while (pch != NULL) {
        octets[i++] = atoi(pch);
        pch = strtok(NULL, ".");
    }
}

void to_binary(int octet, char* binary_octet) {
    binary_octet[8] = '\0';
    int i = 0;
    while (octet > 0 && i < 8) {
        binary_octet[7 - i++] = (octet % 2 == 0 ? '0' : '1');
        octet /= 2;
    }
    while (i < 8) {
        binary_octet[7 - i++] = '0';
    }
}

void get_binary_ip_address(struct IP_Address ip_address, char* binary_ip_address) {
    char binary_octet[9];
    binary_ip_address[0] = '\0';
    for (int i = 0; i < 4; i++) {
        to_binary(ip_address.ip[i], binary_octet);
        strcat(binary_ip_address, binary_octet);
        if (i < 3) {
            strcat(binary_ip_address, ".");
        }
    }
}

void get_binary_subnet_mask(struct Subnet_Mask subnet_mask, char* binary_subnet_mask) {
    char binary_octet[9];
    binary_subnet_mask[0] = '\0';
    for (int i = 0; i < 4; i++) {
        to_binary(subnet_mask.mask[i], binary_octet);
        strcat(binary_subnet_mask, binary_octet);
        if (i < 3) {
            strcat(binary_subnet_mask, ".");
        }
    }
}

int get_network_address(int host_octet, int mask_octet) {
    return (host_octet & mask_octet);
}

void get_network_id(struct IP_Address ip_address, struct Subnet_Mask subnet_mask, char* network_id) {
    int network_octet;
    char network_octet_string[4];
    network_id[0] = '\0';
    for (int i = 0; i < 4; i++) {
        network_octet = get_network_address(ip_address.ip[i], subnet_mask.mask[i]);
        sprintf(network_octet_string, "%d", network_octet);
        strcat(network_id, network_octet_string);
        if (i < 3) {
            strcat(network_id, ".");
        }
    }
}

int main() {
    char ip_address_string[16];
    char subnet_mask_string[16];
    char binary_ip_address[35];
    char binary_subnet_mask[35];
    char network_id[16];

    printf("Enter IP Address: ");
    scanf("%s", ip_address_string);

    printf("Enter Subnet Mask: ");
    scanf("%s", subnet_mask_string);

    get_octets(ip_address_string, ip_address.ip);
    get_octets(subnet_mask_string, subnet_mask.mask);
    get_binary_ip_address(ip_address, binary_ip_address);
    get_binary_subnet_mask(subnet_mask, binary_subnet_mask);
    get_network_id(ip_address, subnet_mask, network_id);

    printf("\nIP Address: %s/%d", ip_address_string, atoi(subnet_mask_string + strlen(subnet_mask_string) - 1));
    printf("\nBinary IP Address: %s", binary_ip_address);
    printf("\nSubnet Mask: %s", subnet_mask_string);
    printf("\nBinary Subnet Mask: %s", binary_subnet_mask);
    printf("\nNetwork ID: %s/%d", network_id, atoi(subnet_mask_string + strlen(subnet_mask_string) - 1));

    return 0;
}