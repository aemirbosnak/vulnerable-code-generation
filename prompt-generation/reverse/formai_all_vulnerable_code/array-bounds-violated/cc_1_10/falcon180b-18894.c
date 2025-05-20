//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_COUNT 32

typedef struct {
    char name[MAX_SUBNET_SIZE];
    char ip[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_SIZE];
    char gateway[MAX_SUBNET_SIZE];
    int count;
} subnet_t;

int main() {
    int i, j, k, n, m, count = 0;
    char input[MAX_SUBNET_SIZE];
    subnet_t subnets[MAX_SUBNETS];

    printf("Enter the IP address and subnet mask (in CIDR notation):\n");
    scanf("%s", input);

    n = strlen(input);
    m = input[n - 1] - '0';

    if (m > 32) {
        printf("Invalid subnet mask\n");
        return 1;
    }

    for (i = 0; i < MAX_SUBNETS; i++) {
        subnets[i].count = 0;
    }

    for (i = 0; i < MAX_SUBNET_COUNT; i++) {
        if (subnets[i].count == 0) {
            strcpy(subnets[i].name, "Subnet");
            strcpy(subnets[i].ip, input);
            strcpy(subnets[i].mask, input);
            strcpy(subnets[i].gateway, input);
            subnets[i].count = 1;
            count++;
        }
    }

    printf("Subnet ID\tSubnet IP\tSubnet Mask\tSubnet Gateway\n");

    for (i = 0; i < count; i++) {
        printf("%d\t%s\t%s\t%s\n", i, subnets[i].name, subnets[i].ip, subnets[i].gateway);
    }

    return 0;
}