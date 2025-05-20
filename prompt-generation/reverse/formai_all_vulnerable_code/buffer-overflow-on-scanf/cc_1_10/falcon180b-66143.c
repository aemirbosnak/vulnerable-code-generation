//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SUBNETS 256

typedef struct {
    char name[20];
    int subnet_id;
    int mask;
    int first_ip;
    int last_ip;
    int count;
} subnet_t;

int main() {
    int num_subnets;
    subnet_t subnets[MAX_SUBNETS];
    int i, j, k;
    char input[100];
    char delimiter;
    int ip_start, ip_end, subnet_mask;
    int num_ips;

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    for (i = 0; i < num_subnets; i++) {
        printf("Enter subnet %d name: ", i+1);
        scanf("%s", subnets[i].name);

        printf("Enter subnet %d IP address range (start-end): ", i+1);
        scanf("%s", input);
        delimiter = input[0];
        ip_start = atoi(strtok(input, delimiter));
        ip_end = atoi(strtok(NULL, delimiter));

        printf("Enter subnet %d subnet mask: ", i+1);
        scanf("%d", &subnets[i].mask);

        subnets[i].subnet_id = i+1;
        subnets[i].first_ip = ip_start;
        subnets[i].last_ip = ip_end;
        subnets[i].count = 0;
    }

    for (i = 0; i < num_subnets; i++) {
        printf("Subnet %d: %s\n", i+1, subnets[i].name);
        printf("IP range: %d.%d.%d.%d - %d.%d.%d.%d\n", (ip_start >> 24) & 0xFF, (ip_start >> 16) & 0xFF, (ip_start >> 8) & 0xFF, ip_start & 0xFF, (ip_end >> 24) & 0xFF, (ip_end >> 16) & 0xFF, (ip_end >> 8) & 0xFF, ip_end & 0xFF);
        printf("Subnet mask: %d.%d.%d.%d\n", (subnets[i].mask >> 24) & 0xFF, (subnets[i].mask >> 16) & 0xFF, (subnets[i].mask >> 8) & 0xFF, subnets[i].mask & 0xFF);
        printf("Number of IPs: %d\n\n", subnets[i].count);
    }

    return 0;
}