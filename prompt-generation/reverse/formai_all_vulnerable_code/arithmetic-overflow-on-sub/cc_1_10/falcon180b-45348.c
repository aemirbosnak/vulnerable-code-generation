//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100

typedef struct {
    char name[50];
    int num_subnets;
    int subnet_size;
    int first_ip;
    int last_ip;
} Subnet;

void calc_subnets(int num_subnets, int subnet_size, int first_ip, int last_ip, Subnet *subnets) {
    int i, j;
    for (i = 0; i < num_subnets; i++) {
        subnets[i].num_subnets = num_subnets;
        subnets[i].subnet_size = subnet_size;
        subnets[i].first_ip = first_ip + i * subnet_size;
        subnets[i].last_ip = subnets[i].first_ip + subnet_size - 1;
    }
}

int main() {
    int num_subnets, subnet_size, first_ip, last_ip;
    Subnet subnets[MAX_SUBNETS];

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    printf("Enter the subnet size: ");
    scanf("%d", &subnet_size);

    printf("Enter the first IP address: ");
    scanf("%d", &first_ip);

    printf("Enter the last IP address: ");
    scanf("%d", &last_ip);

    if (num_subnets > MAX_SUBNETS) {
        printf("Error: maximum number of subnets exceeded\n");
        return 1;
    }

    calc_subnets(num_subnets, subnet_size, first_ip, last_ip, subnets);

    printf("Subnet\t\tIP Range\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("%d\t\t%d.%d.%d.%d - %d.%d.%d.%d\n", i+1, first_ip/256, first_ip%256, subnets[i].first_ip/256, subnets[i].first_ip%256, subnets[i].last_ip/256, subnets[i].last_ip%256);
    }

    return 0;
}