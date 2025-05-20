//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 32
#define IP_SIZE 32
#define SUBNET_SIZE 32

typedef struct {
    char ip[IP_SIZE];
    char subnet[SUBNET_SIZE];
} Subnet;

int main() {
    int num_subnets;
    Subnet subnets[MAX_SUBNETS];
    char input_ip[IP_SIZE];
    char input_subnet[SUBNET_SIZE];
    int i;

    // Get the number of subnets from user input
    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    // Get the input IP address from user input
    printf("Enter the IP address: ");
    scanf("%s", input_ip);

    // Loop through each subnet and calculate the IP address and subnet mask
    for (i = 0; i < num_subnets; i++) {
        // Get the subnet mask from user input
        printf("Enter the subnet mask for subnet %d: ", i + 1);
        scanf("%s", input_subnet);

        // Convert the subnet mask to binary
        int mask = 0;
        int j;
        for (j = 0; j < strlen(input_subnet); j++) {
            if (input_subnet[j] == '.') {
                continue;
            }
            mask = (mask << 8) | atoi(input_subnet + j);
        }

        // Calculate the subnet IP address and subnet mask
        int subnet_ip[IP_SIZE];
        memcpy(subnet_ip, input_ip, IP_SIZE);
        subnet_ip[strlen(input_subnet) - 1] = 0;
        int subnet_mask = mask | (0xFF << (32 - strlen(input_subnet) * 8));

        // Store the subnet information in the subnets array
        strcpy(subnets[i].ip, input_ip);
        sprintf(subnets[i].subnet, "%d.%d.%d.%d/%d.%d.%d.%d",
                subnet_ip[0], subnet_ip[1], subnet_ip[2], subnet_ip[3],
                subnet_mask >> 24 & 0xFF, subnet_mask >> 16 & 0xFF,
                subnet_mask >> 8 & 0xFF, subnet_mask & 0xFF);
    }

    // Print the subnet information
    printf("Subnet information:\n");
    for (i = 0; i < num_subnets; i++) {
        printf("Subnet %d: %s\n", i + 1, subnets[i].subnet);
    }

    return 0;
}