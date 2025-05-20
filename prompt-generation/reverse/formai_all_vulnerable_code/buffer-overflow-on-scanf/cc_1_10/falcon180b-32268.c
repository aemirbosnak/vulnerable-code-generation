//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_SUBNET_SIZE 32

int main() {
    int num_subnets;
    int subnet_size;
    int host_count;
    int i;

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    printf("Enter the subnet size (1-32): ");
    scanf("%d", &subnet_size);

    if (subnet_size < 1 || subnet_size > MAX_SUBNET_SIZE) {
        printf("Invalid subnet size. Please enter a value between 1 and %d.\n", MAX_SUBNET_SIZE);
        return 1;
    }

    printf("Enter the number of hosts per subnet: ");
    scanf("%d", &host_count);

    if (host_count < 2 || host_count > (32 - subnet_size)) {
        printf("Invalid host count. Please enter a value between 2 and %d.\n", 32 - subnet_size);
        return 1;
    }

    printf("Subnet ID\tSubnet Mask\tHost Range\n");

    for (i = 0; i < num_subnets; i++) {
        int j;
        int start_ip;
        int end_ip;
        char subnet_mask[16];
        char subnet_id[16];
        char host_range[64];

        start_ip = (i * host_count) + 1;
        end_ip = start_ip + host_count - 1;

        sprintf(subnet_id, "192.168.%d.%d", (i / 256), (i % 256));
        sprintf(subnet_mask, "255.255.255.%d", subnet_size);

        printf("%s\t%s\t%d-%d\n", subnet_id, subnet_mask, start_ip, end_ip);

        for (j = start_ip; j <= end_ip; j++) {
            sprintf(host_range, "%s (%d-%d)\n", subnet_id, start_ip, end_ip);
            printf("%s", host_range);
        }
    }

    return 0;
}