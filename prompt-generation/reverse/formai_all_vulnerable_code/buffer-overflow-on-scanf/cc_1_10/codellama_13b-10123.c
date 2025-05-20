//Code Llama-13B DATASET v1.0 Category: Subnet Calculator ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 100

void calculate_subnet(char* subnet, char* netmask) {
    char subnet_binary[MAX_INPUT_SIZE];
    char netmask_binary[MAX_INPUT_SIZE];

    // Convert subnet and netmask to binary
    strncpy(subnet_binary, subnet, MAX_INPUT_SIZE);
    strncpy(netmask_binary, netmask, MAX_INPUT_SIZE);

    // Replace "." with "/"
    for (int i = 0; i < MAX_INPUT_SIZE; i++) {
        if (subnet_binary[i] == '.') {
            subnet_binary[i] = '/';
        }
        if (netmask_binary[i] == '.') {
            netmask_binary[i] = '/';
        }
    }

    // Calculate subnet
    char* subnet_ip = strtok(subnet_binary, "/");
    char* subnet_mask = strtok(NULL, "/");
    char* netmask_ip = strtok(netmask_binary, "/");
    char* netmask_mask = strtok(NULL, "/");

    // Convert subnet and netmask to binary
    int subnet_ip_decimal = strtol(subnet_ip, NULL, 10);
    int subnet_mask_decimal = strtol(subnet_mask, NULL, 10);
    int netmask_ip_decimal = strtol(netmask_ip, NULL, 10);
    int netmask_mask_decimal = strtol(netmask_mask, NULL, 10);

    // Calculate subnet
    int subnet_result = subnet_ip_decimal & subnet_mask_decimal;
    int netmask_result = netmask_ip_decimal & netmask_mask_decimal;

    // Print result
    printf("Subnet: %d\n", subnet_result);
    printf("Netmask: %d\n", netmask_result);
}

int main() {
    char subnet[MAX_INPUT_SIZE];
    char netmask[MAX_INPUT_SIZE];

    printf("Enter subnet: ");
    scanf("%s", subnet);
    printf("Enter netmask: ");
    scanf("%s", netmask);

    calculate_subnet(subnet, netmask);

    return 0;
}