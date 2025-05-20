//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 1000
#define MAX_SUBNET_SIZE 32
#define MAX_IP_STR_LEN 16

typedef struct {
    char ip[MAX_IP_STR_LEN];
    char mask[MAX_IP_STR_LEN];
    int num_hosts;
} Subnet;

int main() {
    int num_subnets, i;
    Subnet subnets[MAX_SUBNETS];

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    for (i = 0; i < num_subnets; i++) {
        printf("Enter the IP address and mask for subnet %d: ", i + 1);
        scanf("%s %s", subnets[i].ip, subnets[i].mask);

        int j;
        for (j = 0; j < strlen(subnets[i].ip); j++) {
            if (subnets[i].ip[j] == '.') {
                subnets[i].ip[j] = '\0';
            }
        }

        for (j = 0; j < strlen(subnets[i].mask); j++) {
            if (subnets[i].mask[j] == '.') {
                subnets[i].mask[j] = '\0';
            }
        }

        int num_ones = 0;
        for (j = 0; j < strlen(subnets[i].mask); j++) {
            if (subnets[i].mask[j] == '1') {
                num_ones++;
            }
        }

        subnets[i].num_hosts = (int) pow(2, (MAX_SUBNET_SIZE - num_ones)) - 2;
    }

    printf("\nSubnet IP address\tSubnet mask\tNumber of hosts\n");
    for (i = 0; i < num_subnets; i++) {
        printf("%s\t\t%s\t\t%d\n", subnets[i].ip, subnets[i].mask, subnets[i].num_hosts);
    }

    return 0;
}