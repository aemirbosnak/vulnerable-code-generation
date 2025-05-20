//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IP_LEN 16
#define MAX_MASK_LEN 32
#define MAX_SUBNETS 256

typedef struct {
    char ip[MAX_IP_LEN];
    char mask[MAX_MASK_LEN];
    int prefix;
    int num_subnets;
    char subnets[MAX_SUBNETS][MAX_IP_LEN];
} subnet_calc_t;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <ip address> <subnet mask>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Parse the IP address and subnet mask
    subnet_calc_t subnet_calc;
    memset(&subnet_calc, 0, sizeof(subnet_calc));
    strcpy(subnet_calc.ip, argv[1]);
    strcpy(subnet_calc.mask, argv[2]);

    // Calculate the prefix length
    int i;
    for (i = 0; i < MAX_MASK_LEN; i++) {
        if (subnet_calc.mask[i] == '\0') {
            break;
        }
        if (subnet_calc.mask[i] != '1' && subnet_calc.mask[i] != '0') {
            printf("Invalid subnet mask: %s\n", argv[2]);
            return EXIT_FAILURE;
        }
        if (subnet_calc.mask[i] == '1') {
            subnet_calc.prefix++;
        }
    }

    // Calculate the number of subnets
    subnet_calc.num_subnets = pow(2, MAX_MASK_LEN - subnet_calc.prefix);

    // Calculate the subnets
    char subnet[MAX_IP_LEN];
    for (i = 0; i < subnet_calc.num_subnets; i++) {
        strcpy(subnet, subnet_calc.ip);
        int subnet_num = i + 1;
        int subnet_bits = MAX_MASK_LEN - subnet_calc.prefix;
        for (int j = 0; j < subnet_bits; j++) {
            if (subnet_num & 1) {
                subnet[MAX_IP_LEN - j - 1] = '1';
            } else {
                subnet[MAX_IP_LEN - j - 1] = '0';
            }
            subnet_num >>= 1;
        }
        strcpy(subnet_calc.subnets[i], subnet);
    }

    // Print the results
    printf("IP Address: %s\n", subnet_calc.ip);
    printf("Subnet Mask: %s\n", subnet_calc.mask);
    printf("Prefix Length: %d\n", subnet_calc.prefix);
    printf("Number of Subnets: %d\n", subnet_calc.num_subnets);
    printf("Subnets:\n");
    for (i = 0; i < subnet_calc.num_subnets; i++) {
        printf("  %s\n", subnet_calc.subnets[i]);
    }

    return EXIT_SUCCESS;
}