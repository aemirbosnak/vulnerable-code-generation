//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32
#define MAX_CIDR_SIZE 16

typedef struct {
    char name[MAX_SUBNET_SIZE];
    char cidr[MAX_CIDR_SIZE];
    int num_hosts;
} subnet_t;

int main() {
    int num_subnets = 0;
    subnet_t subnets[MAX_SUBNETS];
    char input[MAX_SUBNET_SIZE];
    char cidr_input[MAX_CIDR_SIZE];
    int i, j, cidr_len;

    printf("Welcome to the Cheerful Subnet Calculator!\n");
    printf("How many subnets do you want to calculate? (up to %d)\n", MAX_SUBNETS);
    scanf("%d", &num_subnets);

    for (i = 0; i < num_subnets; i++) {
        printf("Enter the name of subnet #%d: ", i+1);
        scanf("%s", subnets[i].name);
        printf("Enter the CIDR notation for subnet #%d: ", i+1);
        scanf("%s", cidr_input);

        // Check if CIDR notation is valid
        cidr_len = strlen(cidr_input);
        if (cidr_len < MAX_CIDR_SIZE || cidr_len > MAX_SUBNET_SIZE) {
            printf("Invalid CIDR notation for subnet #%d.\n", i+1);
            exit(1);
        }
        strcpy(subnets[i].cidr, cidr_input);

        // Calculate number of hosts in subnet
        if (cidr_input[cidr_len-1] == '/') {
            cidr_input[cidr_len-1] = '\0';
            subnets[i].num_hosts = pow(2, atoi(cidr_input+1)) - 2;
        } else {
            printf("Invalid CIDR notation for subnet #%d.\n", i+1);
            exit(1);
        }
    }

    // Print subnet information
    printf("\nCheerful Subnet Calculator Results:\n");
    printf("Subnet\tCIDR Notation\tNumber of Hosts\n");
    for (i = 0; i < num_subnets; i++) {
        printf("%s\t%s\t\t%d\n", subnets[i].name, subnets[i].cidr, subnets[i].num_hosts);
    }

    return 0;
}