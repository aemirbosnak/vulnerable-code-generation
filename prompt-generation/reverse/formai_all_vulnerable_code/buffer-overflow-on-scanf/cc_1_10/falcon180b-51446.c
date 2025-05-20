//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32

typedef struct {
    char name[32];
    int size;
} Subnet;

int num_subnets = 0;
Subnet subnets[MAX_SUBNETS];

void add_subnet(char* name, int size) {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: maximum number of subnets reached.\n");
        return;
    }

    strncpy(subnets[num_subnets].name, name, 32);
    subnets[num_subnets].size = size;
    num_subnets++;
}

int main() {
    int i, j, k;
    char ip[16];
    int num_ips, subnet_size;

    printf("Enter the IP address: ");
    scanf("%s", ip);

    printf("Enter the number of subnets: ");
    scanf("%d", &num_ips);

    printf("Enter the subnet size: ");
    scanf("%d", &subnet_size);

    if (subnet_size > 32) {
        printf("Error: subnet size must be less than or equal to 32.\n");
        return 1;
    }

    for (i = 0; i < num_ips; i++) {
        add_subnet(ip, subnet_size);
        for (j = 0; j < num_subnets - 1; j++) {
            for (k = j + 1; k < num_subnets; k++) {
                if (strcmp(subnets[j].name, subnets[k].name) == 0) {
                    printf("Error: duplicate subnet name.\n");
                    return 1;
                }
            }
        }
    }

    printf("Subnets:\n");
    for (i = 0; i < num_subnets; i++) {
        printf("%s (%d IPs)\n", subnets[i].name, (int)pow(2, subnets[i].size));
    }

    return 0;
}