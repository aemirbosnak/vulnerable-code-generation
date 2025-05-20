//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdint.h>

uint32_t ipaddress_to_decimal(char *ipaddress) {
    uint32_t output = 0;
    char *token = strtok(ipaddress, ".");
    while (token != NULL) {
        output = (output << 8) + atoi(token);
        token = strtok(NULL, ".");
    }
    return output;
}

void decimal_to_ipaddress(uint32_t decimal, char *ipaddress) {
    sprintf(ipaddress, "%d.%d.%d.%d", (decimal >> 24) & 0xFF, (decimal >> 16) & 0xFF, (decimal >> 8) & 0xFF, decimal & 0xFF);
}

void generate_subnet_mask(uint8_t mask_length, uint32_t *subnet_mask) {
    *subnet_mask = 0xFFFFFFFF << (32 - mask_length);
}

void split_ipaddress_network(uint32_t ipaddress, uint32_t subnet_mask, uint32_t *network, uint32_t *broadcast) {
    *network = ipaddress & subnet_mask;
    *broadcast = *network | (~subnet_mask & 0xFFFFFFFF);
}

void print_subnet_details(char *ipaddress, uint8_t mask_length) {
    uint32_t decimal_ip = ipaddress_to_decimal(ipaddress);
    uint32_t subnet_mask_decimal;
    generate_subnet_mask(mask_length, &subnet_mask_decimal);
    uint32_t network_decimal, broadcast_decimal;
    split_ipaddress_network(decimal_ip, subnet_mask_decimal, &network_decimal, &broadcast_decimal);
    char subnet_mask_ip[16];
    decimal_to_ipaddress(subnet_mask_decimal, subnet_mask_ip);
    char network_ip[16];
    decimal_to_ipaddress(network_decimal, network_ip);
    char broadcast_ip[16];
    decimal_to_ipaddress(broadcast_decimal, broadcast_ip);
    printf("IP Address: %s\n", ipaddress);
    printf("Subnet Mask: %s\n", subnet_mask_ip);
    printf("Network Address: %s\n", network_ip);
    printf("Broadcast Address: %s\n", broadcast_ip);
}

int main() {
    char ipaddress[16];
    uint8_t mask_length;
    printf("Enter IP Address: ");
    scanf("%s", ipaddress);
    printf("Enter Mask Length: ");
    scanf("%hhu", &mask_length);
    print_subnet_details(ipaddress, mask_length);
    return 0;
}