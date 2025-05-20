//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_ADDRESS_LENGTH 15
#define BINARY_LENGTH 8

typedef struct {
    int network_bits;
    int host_bits;
    int total_bits;
    char network_address[MAX_IP_ADDRESS_LENGTH + 1];
    char subnet_mask[MAX_IP_ADDRESS_LENGTH + 1];
    char first_host[MAX_IP_ADDRESS_LENGTH + 1];
    char last_host[MAX_IP_ADDRESS_LENGTH + 1];
    char broadcast_address[MAX_IP_ADDRESS_LENGTH + 1];
} Subnet;

int get_number_of_subnets(int bits) {
    if (bits == 0) {
        return 1;
    }
    return 2 * get_number_of_subnets(bits - 1);
}

void calculate_subnet(Subnet *subnet, char *ip_address, int mask_bits) {
    memset(subnet, 0, sizeof(Subnet)); // Clear the memory

    // Calculate the network bits, host bits, and total bits
    subnet->network_bits = mask_bits;
    subnet->host_bits = 32 - mask_bits;
    subnet->total_bits = 32;

    // Calculate the subnet mask
    unsigned long long mask = (unsigned long long)(-1LL) << subnet->host_bits;
    sprintf(subnet->subnet_mask, "%d.%d.%d.%d",
            (int)((mask >> 24) & 0xff),
            (int)((mask >> 16) & 0xff),
            (int)((mask >> 8) & 0xff),
            (int)(mask & 0xff));

    // Calculate the network address
    unsigned long ip = inet_addr(ip_address);
    unsigned long network = ip & mask;
    sprintf(subnet->network_address, "%d.%d.%d.%d",
            (int)((network >> 24) & 0xff),
            (int)((network >> 16) & 0xff),
            (int)((network >> 8) & 0xff),
            (int)(network & 0xff));

    // Calculate the broadcast address
    unsigned long broadcast = network | ~mask;
    sprintf(subnet->broadcast_address, "%d.%d.%d.%d",
            (int)((broadcast >> 24) & 0xff),
            (int)((broadcast >> 16) & 0xff),
            (int)((broadcast >> 8) & 0xff),
            (int)(broadcast & 0xff));

    // Calculate the first host
    unsigned long first_host = network + 1;
    sprintf(subnet->first_host, "%d.%d.%d.%d",
            (int)((first_host >> 24) & 0xff),
            (int)((first_host >> 16) & 0xff),
            (int)((first_host >> 8) & 0xff),
            (int)(first_host & 0xff));

    // Calculate the last host
    unsigned long last_host = broadcast - 1;
    sprintf(subnet->last_host, "%d.%d.%d.%d",
            (int)((last_host >> 24) & 0xff),
            (int)((last_host >> 16) & 0xff),
            (int)((last_host >> 8) & 0xff),
            (int)(last_host & 0xff));
}

int main() {
    char ip_address[MAX_IP_ADDRESS_LENGTH + 1];
    int mask_bits;
    Subnet subnet;

    printf("C Subnet Calculator\n");

    while (1) {
        printf("Please enter an IP address: ");
        scanf("%s", ip_address);

        printf("Please enter the subnet mask (in CIDR notation): ");
        scanf("%d", &mask_bits);

        calculate_subnet(&subnet, ip_address, mask_bits);

        printf("Network address:      %s/%d\n", subnet.network_address, subnet.network_bits);
        printf("Subnet mask:          %s\n", subnet.subnet_mask);
        printf("Broadcast address:    %s\n", subnet.broadcast_address);
        printf("First host:           %s\n", subnet.first_host);
        printf("Last host:            %s\n", subnet.last_host);
        printf("Number of subnets:    %d\n", get_number_of_subnets(subnet.host_bits));
        printf("Number of hosts/subnet: %d\n\n", (1 << subnet.host_bits) - 2);
    }

    return 0;
}