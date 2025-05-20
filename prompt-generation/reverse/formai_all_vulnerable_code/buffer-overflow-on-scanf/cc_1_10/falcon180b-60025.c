//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 1000
#define MAX_SUBNET_SIZE 32
#define MAX_IP_SIZE 16

typedef struct {
    char ip[MAX_IP_SIZE];
    char mask[MAX_IP_SIZE];
    int size;
} subnet;

void add_subnet(subnet *subnets, int count, char *ip, char *mask, int size) {
    if (count >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        exit(1);
    }
    strcpy(subnets[count].ip, ip);
    strcpy(subnets[count].mask, mask);
    subnets[count].size = size;
    count++;
}

int main() {
    char ip[MAX_IP_SIZE];
    char mask[MAX_IP_SIZE];
    int size;
    int count = 0;
    subnet subnets[MAX_SUBNETS];

    printf("Enter IP address: ");
    scanf("%s", ip);

    printf("Enter subnet mask: ");
    scanf("%s", mask);

    if (sscanf(mask, "%d.%d.%d.%d", &size, &size, &size, &size)!= 4) {
        printf("Error: Invalid subnet mask.\n");
        exit(1);
    }

    add_subnet(subnets, count, ip, mask, size);

    printf("Subnet IP address\tSubnet mask\tSubnet size\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t\t%s\t\t%d\n", subnets[i].ip, subnets[i].mask, subnets[i].size);
    }

    return 0;
}