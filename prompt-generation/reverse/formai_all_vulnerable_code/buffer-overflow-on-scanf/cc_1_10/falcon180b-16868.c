//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32
#define MAX_IP_ADDR_SIZE 16

typedef struct {
    char ip_addr[MAX_IP_ADDR_SIZE];
    char subnet_mask[MAX_SUBNET_SIZE];
    char subnet_addr[MAX_IP_ADDR_SIZE];
} subnet_t;

void print_subnet_info(subnet_t *subnet) {
    printf("IP Address: %s\n", subnet->ip_addr);
    printf("Subnet Mask: %s\n", subnet->subnet_mask);
    printf("Subnet Address: %s\n", subnet->subnet_addr);
    printf("\n");
}

int main() {
    int num_subnets;
    subnet_t subnets[MAX_SUBNETS];
    char input_buffer[1024];
    char *token;
    int i, j;

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    for (i = 0; i < num_subnets; i++) {
        printf("Enter subnet %d information:\n", i+1);
        printf("IP Address: ");
        fgets(input_buffer, 1024, stdin);
        strtok(input_buffer, "\n");
        strcpy(subnets[i].ip_addr, input_buffer);

        printf("Subnet Mask: ");
        fgets(input_buffer, 1024, stdin);
        strtok(input_buffer, "\n");
        strcpy(subnets[i].subnet_mask, input_buffer);

        sprintf(input_buffer, "255.255.255.%d", (int)strlen(subnets[i].subnet_mask) * 8);
        strcpy(subnets[i].subnet_addr, input_buffer);

        print_subnet_info(&subnets[i]);
    }

    return 0;
}