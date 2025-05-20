//Code Llama-13B DATASET v1.0 Category: Subnet Calculator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100
#define MAX_HOSTS 255

typedef struct {
    int subnet_id;
    int subnet_mask;
    int number_of_hosts;
} Subnet;

void calculate_subnets(int number_of_subnets, int number_of_hosts, Subnet subnets[]) {
    int i, j;
    int subnet_mask;
    int total_number_of_hosts = 0;

    for (i = 0; i < number_of_subnets; i++) {
        subnets[i].subnet_id = i;
        subnets[i].subnet_mask = (int) pow(2, 32 - (i + 1));
        subnets[i].number_of_hosts = (int) pow(2, (i + 1));
        total_number_of_hosts += subnets[i].number_of_hosts;
    }

    for (i = 0; i < number_of_subnets; i++) {
        for (j = 0; j < number_of_subnets; j++) {
            if (i != j) {
                subnet_mask = subnets[i].subnet_mask & subnets[j].subnet_mask;
                if (subnet_mask == 0) {
                    subnets[i].number_of_hosts -= subnets[j].number_of_hosts;
                }
            }
        }
    }

    for (i = 0; i < number_of_subnets; i++) {
        printf("Subnet %d has %d hosts.\n", subnets[i].subnet_id, subnets[i].number_of_hosts);
    }

    printf("Total number of hosts: %d\n", total_number_of_hosts);
}

int main() {
    Subnet subnets[MAX_SUBNETS];
    int number_of_subnets;
    int number_of_hosts;

    printf("Enter number of subnets: ");
    scanf("%d", &number_of_subnets);
    printf("Enter number of hosts: ");
    scanf("%d", &number_of_hosts);

    calculate_subnets(number_of_subnets, number_of_hosts, subnets);

    return 0;
}