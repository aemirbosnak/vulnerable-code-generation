//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 256
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK_SIZE 4

typedef struct {
    char *name;
    char *ip_address;
    char *subnet_mask;
    int num_hosts;
} Subnet;

int main(int argc, char *argv[]) {
    int num_subnets = 0;
    Subnet subnets[MAX_SUBNETS];

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    for (int i = 0; i < num_subnets; i++) {
        printf("Enter the name of subnet %d: ", i+1);
        scanf("%s", subnets[i].name);

        printf("Enter the IP address of subnet %d: ", i+1);
        scanf("%s", subnets[i].ip_address);

        printf("Enter the subnet mask of subnet %d: ", i+1);
        scanf("%s", subnets[i].subnet_mask);

        printf("Enter the number of hosts in subnet %d: ", i+1);
        scanf("%d", &subnets[i].num_hosts);
    }

    printf("\nSubnet Information:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("Name: %s\n", subnets[i].name);
        printf("IP Address: %s\n", subnets[i].ip_address);
        printf("Subnet Mask: %s\n", subnets[i].subnet_mask);
        printf("Number of Hosts: %d\n\n", subnets[i].num_hosts);

        char *ip_address_parts[4];
        char *subnet_mask_parts[4];
        strtok(subnets[i].ip_address, ".");
        strtok(subnets[i].subnet_mask, ".");
        for (int j = 0; j < 4; j++) {
            ip_address_parts[j] = strtok(NULL, ".");
            subnet_mask_parts[j] = strtok(NULL, ".");
        }

        int num_bits = 0;
        for (int j = 3; j >= 0; j--) {
            int ip_part = atoi(ip_address_parts[j]);
            int mask_part = atoi(subnet_mask_parts[j]);

            if (mask_part == 0) {
                num_bits += 8;
            } else if (mask_part == 255) {
                num_bits += 0;
            } else {
                num_bits += (8 - (int)log2(mask_part + 1));
            }
        }

        printf("Subnet Size: %d hosts\n", (int)pow(2, num_bits) - 2);
        printf("Subnet Mask (dotted decimal): %s\n", subnets[i].subnet_mask);
        printf("Subnet Mask (binary): ");
        for (int j = 0; j < strlen(subnets[i].subnet_mask); j++) {
            printf("%d", subnets[i].subnet_mask[j] - '0');
        }
        printf("\n\n");
    }

    return 0;
}