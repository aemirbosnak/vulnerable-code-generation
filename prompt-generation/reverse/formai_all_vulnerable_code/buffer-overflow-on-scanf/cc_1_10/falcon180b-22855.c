//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 1024
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_NAME 64

typedef struct {
    char name[MAX_SUBNET_NAME];
    int num_hosts;
    int subnet_size;
    int first_host;
    int last_host;
} subnet_t;

int main() {
    int num_subnets, i;
    subnet_t subnets[MAX_SUBNETS];

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    for (i = 0; i < num_subnets; i++) {
        printf("Enter subnet %d name: ", i+1);
        scanf("%s", subnets[i].name);

        printf("Enter the number of hosts in subnet %s: ", subnets[i].name);
        scanf("%d", &subnets[i].num_hosts);

        printf("Enter the subnet size for %s: ", subnets[i].name);
        scanf("%d", &subnets[i].subnet_size);

        subnets[i].first_host = 1;
        subnets[i].last_host = subnets[i].num_hosts;
    }

    printf("Subnet\t\tIP Range\n");
    for (i = 0; i < num_subnets; i++) {
        int j;
        for (j = subnets[i].first_host; j <= subnets[i].last_host; j++) {
            int host_num = (j - subnets[i].first_host) + 1;
            int octet1 = (subnets[i].subnet_size >> 24) & 0xFF;
            int octet2 = (subnets[i].subnet_size >> 16) & 0xFF;
            int octet3 = (subnets[i].subnet_size >> 8) & 0xFF;
            int octet4 = subnets[i].subnet_size & 0xFF;

            printf("%s\t\t%d.%d.%d.%d - %d.%d.%d.%d\n",
                   subnets[i].name, octet1, octet2, octet3, octet4,
                   octet1, octet2, octet3, octet4 + (subnets[i].subnet_size - 1));
        }
    }

    return 0;
}