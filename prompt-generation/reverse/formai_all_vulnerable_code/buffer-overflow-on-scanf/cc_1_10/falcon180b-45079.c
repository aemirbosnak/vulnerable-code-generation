//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 256
#define MAX_SUBNET_SIZE 32

typedef struct {
    int size;
    char *subnet;
} Subnet;

void calculate_subnets(char *ip, int mask, Subnet *subnets) {
    int i, j, k;
    char *subnet_ip;
    for (i = 0; i < MAX_SUBNETS; i++) {
        subnets[i].size = 0;
        subnets[i].subnet = NULL;
    }
    for (i = 0; i < 32; i++) {
        if ((1 << i) & mask) {
            for (j = 0; j < MAX_SUBNETS; j++) {
                if (subnets[j].size == i) {
                    subnets[j].size++;
                    break;
                }
            }
            if (j == MAX_SUBNETS) {
                subnets[i].size = 1;
                subnets[i].subnet = malloc(MAX_SUBNET_SIZE);
                strcpy(subnets[i].subnet, ip);
            }
        }
    }
    for (i = 0; i < MAX_SUBNETS; i++) {
        if (subnets[i].size > 0) {
            printf("Subnet %d: ", i);
            for (j = 0; j < subnets[i].size; j++) {
                subnet_ip = malloc(MAX_SUBNET_SIZE);
                strcpy(subnet_ip, subnets[i].subnet);
                k = strlen(subnet_ip);
                subnet_ip[k - 1]++;
                printf("%s ", subnet_ip);
                free(subnet_ip);
            }
            printf("\n");
        }
    }
}

int main() {
    char ip[16], mask[16];
    printf("Enter IP address: ");
    scanf("%s", ip);
    printf("Enter subnet mask: ");
    scanf("%s", mask);
    Subnet subnets[MAX_SUBNETS];
    calculate_subnets(ip, atoi(mask), subnets);
    return 0;
}