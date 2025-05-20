//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 16

typedef struct {
    char subnet[MAX_SUBNET_SIZE];
    int size;
    int num_hosts;
} Subnet;

void generate_subnets(int num_subnets, int num_hosts) {
    int i, j, k;
    Subnet subnets[MAX_SUBNETS];
    int num_subnets_generated = 0;

    for (i = 0; i < MAX_SUBNETS; i++) {
        subnets[i].size = 0;
        subnets[i].num_hosts = 0;
    }

    for (i = 0; i < num_subnets; i++) {
        for (j = 1; j <= num_hosts; j++) {
            if (j == num_hosts) {
                subnets[num_subnets_generated].size = 0;
            } else {
                subnets[num_subnets_generated].size = j;
            }

            for (k = 0; k < MAX_SUBNET_SIZE; k++) {
                subnets[num_subnets_generated].subnet[k] = '0';
            }

            subnets[num_subnets_generated].num_hosts = j;
            num_subnets_generated++;
        }
    }

    printf("Subnets generated:\n");
    for (i = 0; i < num_subnets_generated; i++) {
        printf("Subnet %d: %s\n", subnets[i].num_hosts, subnets[i].subnet);
    }
}

int main() {
    int num_subnets, num_hosts;

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    printf("Enter the number of hosts per subnet: ");
    scanf("%d", &num_hosts);

    generate_subnets(num_subnets, num_hosts);

    return 0;
}