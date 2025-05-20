//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100

typedef struct {
    char name[50];
    int num_subnets;
    int subnet_size;
    int start_ip;
    int end_ip;
} Subnet;

int main() {
    int num_subnets, i;
    Subnet subnets[MAX_SUBNETS];
    char input[100];

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    for (i = 0; i < num_subnets; i++) {
        printf("Enter the name of subnet %d: ", i+1);
        scanf("%s", subnets[i].name);

        printf("Enter the number of subnets for %s: ", subnets[i].name);
        scanf("%d", &subnets[i].num_subnets);

        printf("Enter the subnet size for %s: ", subnets[i].name);
        scanf("%d", &subnets[i].subnet_size);

        printf("Enter the starting IP address for %s: ", subnets[i].name);
        scanf("%d", &subnets[i].start_ip);

        printf("Enter the ending IP address for %s: ", subnets[i].name);
        scanf("%d", &subnets[i].end_ip);
    }

    printf("\nSubnet Information:\n");
    printf("===================\n");

    for (i = 0; i < num_subnets; i++) {
        printf("Name: %s\n", subnets[i].name);
        printf("Number of Subnets: %d\n", subnets[i].num_subnets);
        printf("Subnet Size: %d\n", subnets[i].subnet_size);
        printf("Starting IP: %d\n", subnets[i].start_ip);
        printf("Ending IP: %d\n", subnets[i].end_ip);
        printf("\n");
    }

    return 0;
}