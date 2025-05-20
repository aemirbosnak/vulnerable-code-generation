//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100
#define MAX_IP_LENGTH 16

struct subnet {
    char ip[MAX_IP_LENGTH];
    char mask[MAX_IP_LENGTH];
    int num_hosts;
};

void print_subnet(struct subnet *subnet) {
    printf("IP Address: %s\n", subnet->ip);
    printf("Subnet Mask: %s\n", subnet->mask);
    printf("Number of Hosts: %d\n", subnet->num_hosts);
}

int main() {
    int num_subnets, i;
    struct subnet subnets[MAX_SUBNETS];

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    if (num_subnets > MAX_SUBNETS) {
        printf("Error: Maximum number of subnets is %d\n", MAX_SUBNETS);
        return 1;
    }

    for (i = 0; i < num_subnets; i++) {
        printf("Enter the IP address and subnet mask for subnet %d:\n", i + 1);
        printf("IP Address: ");
        scanf("%s", subnets[i].ip);
        printf("Subnet Mask: ");
        scanf("%s", subnets[i].mask);

        int j;
        for (j = 0; j < strlen(subnets[i].mask); j++) {
            if (subnets[i].mask[j] == '.') {
                subnets[i].mask[j] = '\0';
            }
        }

        int num_ones = 0;
        int num_zeros = 0;
        int total_bits = 0;

        char *token = strtok(subnets[i].mask, ".");
        while (token!= NULL) {
            int value = atoi(token);
            if (value == 255) {
                num_ones++;
            } else if (value == 0) {
                num_zeros++;
            } else {
                printf("Error: Invalid subnet mask\n");
                return 1;
            }

            total_bits += 8;
            token = strtok(NULL, ".");
        }

        if (total_bits!= 32) {
            printf("Error: Invalid subnet mask\n");
            return 1;
        }

        subnets[i].num_hosts = (int) pow(2, num_ones) - (int) pow(2, num_zeros + 1) - 2;
    }

    printf("Subnet Information:\n");
    for (i = 0; i < num_subnets; i++) {
        print_subnet(&subnets[i]);
    }

    return 0;
}