//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK_LEN 32

struct subnet {
    char name[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_MASK_LEN];
    int num_hosts;
};

int main() {
    int num_subnets, i, j, k, num_hosts;
    char input_line[MAX_SUBNET_SIZE];
    char *token;
    struct subnet subnets[MAX_SUBNETS];

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    for (i = 0; i < num_subnets; i++) {
        printf("Enter subnet %d name: ", i+1);
        scanf("%s", subnets[i].name);

        printf("Enter subnet %d mask: ", i+1);
        scanf("%s", input_line);

        strcpy(subnets[i].mask, input_line);

        num_hosts = 0;
        for (j = 0; j < strlen(subnets[i].mask); j++) {
            if (subnets[i].mask[j] == '1') {
                num_hosts++;
            }
        }

        subnets[i].num_hosts = num_hosts;
    }

    printf("Subnet\tMask\t\tNumber of hosts\n");
    for (i = 0; i < num_subnets; i++) {
        printf("%s\t", subnets[i].name);
        for (j = 0; j < strlen(subnets[i].mask); j++) {
            if (subnets[i].mask[j] == '1') {
                printf("1");
            } else {
                printf("0");
            }
        }
        printf("\t\t%d\n", subnets[i].num_hosts);
    }

    return 0;
}