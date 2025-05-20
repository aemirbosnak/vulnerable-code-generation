//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SUBNETS 32
#define MAX_SUBNET_SIZE 32

typedef struct {
    int num_subnets;
    int subnet_size;
    int first_subnet;
    int last_subnet;
} SubnetInfo;

void calculate_subnets(int num_hosts, int num_subnets, int *subnet_size, int *first_subnet, int *last_subnet) {
    int i, j, k, n, m;

    /* Calculate the number of hosts per subnet */
    n = num_hosts / num_subnets;
    m = num_hosts % num_subnets;

    /* Calculate the subnet size */
    if (m == 0) {
        *subnet_size = n;
    } else {
        *subnet_size = n + 1;
    }

    /* Calculate the first and last subnet numbers */
    if (num_subnets == 1) {
        *first_subnet = 0;
        *last_subnet = 0;
    } else {
        *first_subnet = 0;
        for (i = 0, k = 0; i < num_subnets - 1; i++) {
            if (m > 0 && k == 0) {
                n++;
                m--;
            }
            k++;
            *last_subnet = (i * n) - 1;
        }
    }
}

void print_subnet_info(SubnetInfo *info) {
    printf("Number of subnets: %d\n", info->num_subnets);
    printf("Subnet size: %d\n", info->subnet_size);
    printf("First subnet: %d\n", info->first_subnet);
    printf("Last subnet: %d\n", info->last_subnet);
}

int main() {
    int num_hosts, num_subnets;
    SubnetInfo info;

    printf("Enter the number of hosts: ");
    scanf("%d", &num_hosts);

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    if (num_subnets > MAX_SUBNETS || num_subnets <= 0) {
        printf("Invalid number of subnets.\n");
        return 1;
    }

    calculate_subnets(num_hosts, num_subnets, &info.subnet_size, &info.first_subnet, &info.last_subnet);
    info.num_subnets = num_subnets;

    print_subnet_info(&info);

    return 0;
}