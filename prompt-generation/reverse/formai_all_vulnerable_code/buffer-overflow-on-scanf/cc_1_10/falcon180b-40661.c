//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK 32

typedef struct {
    char subnet[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_MASK];
    int num_hosts;
} Subnet;

void generate_subnets(char ip[MAX_SUBNET_SIZE], int num_subnets, Subnet subnets[MAX_SUBNETS]) {
    int i, j, k;
    int subnet_size;
    int num_hosts;

    // Calculate subnet size based on number of subnets
    for (i = 0; i < num_subnets; i++) {
        subnet_size = strlen(ip);
        subnets[i].num_hosts = pow(2, 8 - subnet_size) - 2;
    }

    // Calculate number of hosts per subnet
    for (i = 0; i < num_subnets; i++) {
        num_hosts = subnets[i].num_hosts;

        // Fill subnet with zeros
        for (j = strlen(ip) - 1; j >= 0; j--) {
            if (ip[j] == '.') {
                k = j + 1;
                while (k < strlen(ip)) {
                    subnets[i].subnet[j] = '0';
                    k++;
                }
                break;
            }
        }

        // Fill subnet with ones
        for (j = strlen(ip) - 1; j >= 0; j--) {
            if (ip[j] == '.') {
                k = j + 1;
                while (k < strlen(ip)) {
                    subnets[i].mask[k] = '1';
                    k++;
                }
                break;
            }
        }
    }
}

int main() {
    char ip[MAX_SUBNET_SIZE];
    int num_subnets;

    printf("Enter IP address: ");
    scanf("%s", ip);

    printf("Enter number of subnets: ");
    scanf("%d", &num_subnets);

    Subnet subnets[MAX_SUBNETS];
    generate_subnets(ip, num_subnets, subnets);

    printf("\nSubnet\t\tMask\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("%s\t\t%s\n", subnets[i].subnet, subnets[i].mask);
    }

    return 0;
}