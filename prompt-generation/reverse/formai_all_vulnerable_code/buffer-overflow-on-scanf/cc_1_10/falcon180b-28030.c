//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK_SIZE 32

struct subnet {
    char name[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_MASK_SIZE];
    int num_hosts;
};

int main() {
    int num_subnets, i, j;
    struct subnet subnets[MAX_SUBNETS];
    char input[MAX_SUBNET_SIZE];
    char mask_input[MAX_SUBNET_MASK_SIZE];
    char *token;

    // Get number of subnets
    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    // Get subnet information
    for (i = 0; i < num_subnets; i++) {
        printf("Enter subnet %d name: ", i+1);
        scanf("%s", subnets[i].name);

        printf("Enter subnet %d mask: ", i+1);
        scanf("%s", mask_input);

        // Convert mask from string to binary
        for (j = 0; j < strlen(mask_input); j++) {
            if (mask_input[j] == '.') {
                subnets[i].mask[j] = '0';
                subnets[i].mask[j+1] = '0';
                subnets[i].mask[j+2] = '0';
                subnets[i].mask[j+3] = '0';
            } else {
                subnets[i].mask[j] = mask_input[j];
            }
        }

        subnets[i].num_hosts = 0;
    }

    // Calculate number of hosts per subnet
    for (i = 0; i < num_subnets; i++) {
        token = strtok(subnets[i].mask, ".");
        while (token!= NULL) {
            if (strcmp(token, "0") == 0) {
                subnets[i].num_hosts += 1;
            }
            token = strtok(NULL, ".");
        }
    }

    // Print subnet information
    printf("\nSubnet Name\tSubnet Mask\tNumber of Hosts\n");
    for (i = 0; i < num_subnets; i++) {
        printf("%s\t", subnets[i].name);
        for (j = 0; j < strlen(subnets[i].mask); j++) {
            if (subnets[i].mask[j] == '.') {
                printf(".%d", subnets[i].num_hosts);
                subnets[i].num_hosts = 0;
            } else {
                printf("%c", subnets[i].mask[j]);
            }
        }
        printf("\t%d\n", subnets[i].num_hosts);
    }

    return 0;
}