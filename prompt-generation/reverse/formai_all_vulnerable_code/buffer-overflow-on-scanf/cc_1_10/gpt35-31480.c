//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_SIZE 16

int convertIPtoBinary(char* ip, unsigned int* binary_ip);
void calculateSubnetMask(unsigned int mask_bits, unsigned int* subnet_mask, int* cidr);
void calculateNetworkAddress(unsigned int binary_ip, unsigned int subnet_mask, unsigned int* network_address);
void calculateBroadcastAddress(unsigned int network_address, unsigned int subnet_mask, unsigned int* broadcast_address);
void calculateRange(unsigned int network_address, unsigned int broadcast_address, unsigned int* from, unsigned int* to);

int main() {
    char ip[MAX_IP_SIZE];
    unsigned int binary_ip = 0, subnet_mask = 0, network_address = 0, broadcast_address = 0, from = 0, to = 0;
    int cidr = 0;

    printf("Enter IP address (e.g. 192.168.1.1): ");
    fgets(ip, MAX_IP_SIZE, stdin);
    ip[strlen(ip)-1] = '\0';

    if (!convertIPtoBinary(ip, &binary_ip)) {
        printf("Invalid IP address.\n");
        return -1;
    }

    printf("Enter subnet mask bits: ");
    scanf("%d", &cidr);

    calculateSubnetMask(cidr, &subnet_mask, &cidr);
    calculateNetworkAddress(binary_ip, subnet_mask, &network_address);
    calculateBroadcastAddress(network_address, subnet_mask, &broadcast_address);
    calculateRange(network_address, broadcast_address, &from, &to);

    printf("\n------------------------------------\n");
    printf("IP Address: %s\n", ip);
    printf("Subnet Mask: %u.%u.%u.%u\n", (subnet_mask >> 24) & 0xff, (subnet_mask >> 16) & 0xff, (subnet_mask >> 8) & 0xff, subnet_mask & 0xff);
    printf("CIDR Notation: /%d\n", cidr);
    printf("Network Address: %u.%u.%u.%u\n", (network_address >> 24) & 0xff, (network_address >> 16) & 0xff, (network_address >> 8) & 0xff, network_address & 0xff);
    printf("Broadcast Address: %u.%u.%u.%u\n", (broadcast_address >> 24) & 0xff, (broadcast_address >> 16) & 0xff, (broadcast_address >> 8) & 0xff, broadcast_address & 0xff);
    printf("Range: %u.%u.%u.%u - %u.%u.%u.%u\n", (from >> 24) & 0xff, (from >> 16) & 0xff, (from >> 8) & 0xff, from & 0xff,
                                                (to >> 24) & 0xff, (to >> 16) & 0xff, (to >> 8) & 0xff, to & 0xff);
    printf("------------------------------------\n");

    return 0;
}

int convertIPtoBinary(char* ip, unsigned int* binary_ip) {
    char* token;
    int i = 3;

    token = strtok(ip, ".");

    while (token) {
        if (atoi(token) < 0 || atoi(token) > 255) {
            return 0;
        }

        *binary_ip |= atoi(token) << (i * 8);
        i--;
        token = strtok(NULL, ".");
    }

    return 1;
}

void calculateSubnetMask(unsigned int mask_bits, unsigned int* subnet_mask, int* cidr) {
    *subnet_mask = 0xffffffff << (32 - mask_bits);
    *cidr = mask_bits;
}

void calculateNetworkAddress(unsigned int binary_ip, unsigned int subnet_mask, unsigned int* network_address) {
    *network_address = binary_ip & subnet_mask;
}

void calculateBroadcastAddress(unsigned int network_address, unsigned int subnet_mask, unsigned int* broadcast_address) {
    *broadcast_address = network_address | (~subnet_mask);
}

void calculateRange(unsigned int network_address, unsigned int broadcast_address, unsigned int* from, unsigned int* to) {
    *from = network_address + 1;
    *to = broadcast_address - 1;
}