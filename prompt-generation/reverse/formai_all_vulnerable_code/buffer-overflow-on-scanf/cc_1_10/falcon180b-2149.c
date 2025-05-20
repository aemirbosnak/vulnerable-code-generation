//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10

typedef struct {
    char name[20];
    int subnet_id;
    int mask;
    int hosts;
    int available_hosts;
} Subnet;

int main() {
    int num_subnets, i, j, max_hosts;
    Subnet subnets[MAX_SUBNETS];
    char input[100];

    printf("Welcome to the Subnet Calculator!\n");
    printf("How many subnets do you want to create? ");
    scanf("%d", &num_subnets);

    if (num_subnets > MAX_SUBNETS) {
        printf("Error: Maximum number of subnets is %d.\n", MAX_SUBNETS);
        return 1;
    }

    printf("Enter the subnet name and IP address in CIDR notation (e.g. 192.168.1.0/24):\n");
    for (i = 0; i < num_subnets; i++) {
        scanf("%s", input);
        strcpy(subnets[i].name, input);

        // Parse the IP address and subnet mask from the input string
        char *ip_ptr = strchr(input, '/');
        if (ip_ptr == NULL) {
            printf("Error: Invalid subnet address.\n");
            return 1;
        }
        *ip_ptr = '\0';
        subnets[i].mask = atoi(ip_ptr + 1);
        strcpy(subnets[i].name, input);

        // Calculate the number of hosts in the subnet
        subnets[i].hosts = 0;
        for (j = 0; j < subnets[i].mask; j++) {
            if ((subnets[i].mask & (1 << j)) == 0) {
                subnets[i].hosts++;
            }
        }
        subnets[i].available_hosts = subnets[i].hosts;
    }

    printf("Subnets created:\n");
    for (i = 0; i < num_subnets; i++) {
        printf("%s (%d hosts)\n", subnets[i].name, subnets[i].hosts);
    }

    printf("Enter the number of hosts you want to reserve: ");
    scanf("%d", &max_hosts);

    for (i = 0; i < num_subnets; i++) {
        if (subnets[i].available_hosts >= max_hosts) {
            printf("Subnet %s has enough available hosts.\n", subnets[i].name);
        } else {
            printf("Subnet %s does not have enough available hosts.\n", subnets[i].name);
        }
    }

    return 0;
}