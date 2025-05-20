//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_IP_LEN 16

typedef struct {
    char ip[MAX_IP_LEN];
    char mask[MAX_IP_LEN];
    char subnet[MAX_IP_LEN];
} subnet_t;

int main() {
    int num_subnets;
    subnet_t subnets[MAX_SUBNETS];
    char input_ip[MAX_IP_LEN] = "192.168.1.0";
    char input_mask[MAX_IP_LEN] = "255.255.255.0";

    // Get the number of subnets from the user
    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    // Initialize the first subnet with the input IP and mask
    strcpy(subnets[0].ip, input_ip);
    strcpy(subnets[0].mask, input_mask);

    // Calculate the remaining subnets
    for (int i = 1; i < num_subnets; i++) {
        strcpy(subnets[i].ip, input_ip);
        strcpy(subnets[i].mask, input_mask);

        // Increment the third octet of the IP address
        char *ip_octet = strchr(subnets[i].ip, '.') + 1;
        int octet_val = atoi(ip_octet);
        octet_val++;
        sprintf(ip_octet, "%d", octet_val);

        // Update the subnet IP address
        strcpy(subnets[i].subnet, subnets[i].ip);
        strcat(subnets[i].subnet, "/");
        strcat(subnets[i].subnet, input_mask);
    }

    // Print the subnets
    printf("\nSubnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("Subnet %d: %s\n", i+1, subnets[i].subnet);
    }

    return 0;
}