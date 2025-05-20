//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct subnet_info {
    int subnet_mask;
    int num_hosts;
    int total_hosts;
    int addr_per_host;
};

void display_menu() {
    printf("\n--- Subnet Calculator Menu ---\n");
    printf("1. Calculate Subnet Mask\n");
    printf("2. Calculate Number of Hosts\n");
    printf("3. Calculate Total Number of Hosts\n");
    printf("4. Calculate Addresses per Host\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

void calc_subnet_mask(int num_subnets) {
    int mask_bits = 0;
    int hosts = num_subnets + 2;
    while (hosts > (1 << mask_bits)) {
        mask_bits++;
    }
    int mask_octets[] = {255, 255, 255, 0};
    mask_octets[mask_bits/8] = 256 - (1 << (mask_bits%8));
    printf("\nThe subnet mask is %d.%d.%d.%d\n", mask_octets[0], mask_octets[1], mask_octets[2], mask_octets[3]);
}

void calc_num_hosts(int num_hosts, int addr_per_host) {
    int mask_bits = 0;
    while (num_hosts * addr_per_host > (1 << (32 - mask_bits))) {
        mask_bits++;
    }
    printf("\nThe subnet mask is /%d\n", 32 - mask_bits);
}

void calc_total_hosts(int subnet_mask) {
    int host_bits = 32 - subnet_mask;
    printf("\nThe total number of hosts is %d\n", (1 << host_bits) - 2);
}

void calc_addr_per_host(int subnet_mask) {
    int host_bits = 32 - subnet_mask;
    printf("\nThe number of addresses per host is %d\n", (1 << host_bits));
}

int main() {
    int option;
    do {
        display_menu();
        scanf("%d", &option);
        switch (option) {
            case 1: {
                int num_subnets;
                printf("\nEnter the number of subnets: ");
                scanf("%d", &num_subnets);
                calc_subnet_mask(num_subnets);
                break;
            }
            case 2: {
                int num_hosts, addr_per_host;
                printf("\nEnter the number of hosts: ");
                scanf("%d", &num_hosts);
                printf("Enter the addresses per host: ");
                scanf("%d", &addr_per_host);
                calc_num_hosts(num_hosts, addr_per_host);
                break;
            }
            case 3: {
                int subnet_mask;
                printf("\nEnter the subnet mask: ");
                scanf("%d", &subnet_mask);
                calc_total_hosts(subnet_mask);
                break;
            }
            case 4: {
                int subnet_mask;
                printf("\nEnter the subnet mask: ");
                scanf("%d", &subnet_mask);
                calc_addr_per_host(subnet_mask);
                break;
            }
            case 5: {
                printf("\nExiting...\n");
                break;
            }
            default:
                printf("\nInvalid option, please try again...\n");
        }
    } while (option != 5);
    return 0;
}