//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 32

typedef struct {
    char name[32];
    int num_hosts;
    int first_host;
    int last_host;
} Subnet;

void print_subnet(Subnet *subnet) {
    printf("%s: %d hosts, %d-%d\n", subnet->name, subnet->num_hosts, subnet->first_host, subnet->last_host);
}

int main() {
    int num_subnets;
    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    if (num_subnets > MAX_SUBNETS || num_subnets <= 0) {
        printf("Invalid number of subnets.\n");
        return 1;
    }

    Subnet subnets[MAX_SUBNETS];
    int i;
    for (i = 0; i < num_subnets; i++) {
        printf("Enter subnet %d name: ", i+1);
        scanf("%s", subnets[i].name);

        printf("Enter the number of hosts in subnet %s: ", subnets[i].name);
        scanf("%d", &subnets[i].num_hosts);

        printf("Enter the first host IP address in subnet %s: ", subnets[i].name);
        scanf("%d", &subnets[i].first_host);

        printf("Enter the last host IP address in subnet %s: ", subnets[i].name);
        scanf("%d", &subnets[i].last_host);
    }

    printf("Subnet information:\n");
    for (i = 0; i < num_subnets; i++) {
        print_subnet(&subnets[i]);
    }

    return 0;
}