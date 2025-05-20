//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32

typedef struct {
    char subnet[MAX_SUBNET_SIZE];
    int size;
} Subnet;

void generate_subnets(char *ip, int size) {
    int i, j, k;
    Subnet subnets[MAX_SUBNETS];
    int num_subnets = 0;

    // Convert IP address to integer
    int ip_int = inet_addr(ip);

    // Calculate subnet mask
    int subnet_mask = ~((1 << size) - 1);

    // Convert subnet mask to dotted decimal notation
    char subnet_str[MAX_SUBNET_SIZE];
    sprintf(subnet_str, "%d.%d.%d.%d", (subnet_mask >> 24) & 0xFF, (subnet_mask >> 16) & 0xFF, (subnet_mask >> 8) & 0xFF, subnet_mask & 0xFF);

    // Generate subnets
    for (i = 0; i < size; i++) {
        subnets[num_subnets].size = size;
        for (j = 0; j < size; j++) {
            if (j == i) {
                subnets[num_subnets].subnet[j] = '0';
            } else {
                subnets[num_subnets].subnet[j] = '1';
            }
        }
        subnets[num_subnets].subnet[size] = '\0';
        printf("%s\n", subnets[num_subnets].subnet);
        num_subnets++;
    }
}

int main() {
    char ip[MAX_SUBNET_SIZE];
    int size;

    printf("Enter IP address: ");
    scanf("%s", ip);

    printf("Enter subnet size: ");
    scanf("%d", &size);

    generate_subnets(ip, size);

    return 0;
}