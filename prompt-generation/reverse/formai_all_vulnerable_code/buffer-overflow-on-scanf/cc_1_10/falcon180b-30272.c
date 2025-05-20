//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK_SIZE 16

struct subnet {
    char name[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_MASK_SIZE];
    int num_hosts;
};

int main() {
    int num_subnets, i, j, k, num_hosts, subnet_size, mask_size, num_bits, start_ip, end_ip;
    char input[MAX_SUBNET_SIZE], mask[MAX_SUBNET_MASK_SIZE];
    struct subnet subnets[MAX_SUBNETS];

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    for (i = 0; i < num_subnets; i++) {
        printf("Enter the name of subnet %d: ", i + 1);
        scanf("%s", subnets[i].name);

        printf("Enter the subnet mask for %s: ", subnets[i].name);
        scanf("%s", mask);

        subnet_size = strlen(mask);
        mask_size = 0;

        for (j = 0; j < subnet_size; j++) {
            if (mask[j] == '.') {
                mask_size++;
            }
        }

        num_hosts = (int)pow(2, (subnet_size - mask_size) * 8) - 2;
        subnets[i].num_hosts = num_hosts;

        printf("Enter the starting IP address for %s: ", subnets[i].name);
        scanf("%s", input);

        start_ip = atoi(input);
        end_ip = start_ip + num_hosts - 1;

        printf("The subnet %s has %d hosts and the IP address range is %s - %s.\n",
               subnets[i].name, num_hosts, input, input);
    }

    return 0;
}