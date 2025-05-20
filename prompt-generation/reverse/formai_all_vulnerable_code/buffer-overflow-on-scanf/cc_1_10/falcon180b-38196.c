//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100

// Struct to hold subnet information
typedef struct {
    char ip[16];
    char mask[16];
    int num_hosts;
} Subnet;

void calculate_subnets(char* ip, int num_subnets, Subnet* subnets) {
    int i, j;
    char mask[16];

    // Initialize first subnet
    strcpy(subnets[0].ip, ip);
    sprintf(mask, "255.255.255.0");
    strcpy(subnets[0].mask, mask);
    subnets[0].num_hosts = 254;

    // Calculate remaining subnets
    for (i = 1; i < num_subnets; i++) {
        for (j = 0; j < 3; j++) {
            if (subnets[i-1].ip[j] == '.' && subnets[i-1].ip[j+1] == '.') {
                subnets[i].ip[j] = (char) (atoi(subnets[i-1].ip) + 1);
                subnets[i].ip[j+1] = '.';
                break;
            }
        }
        sprintf(mask, "255.255.255.%d", (255 - atoi(subnets[i-1].mask) - 1) + i);
        strcpy(subnets[i].mask, mask);
        subnets[i].num_hosts = 254 - i;
    }
}

int main() {
    int num_subnets;
    Subnet subnets[MAX_SUBNETS];

    // Get number of subnets to calculate
    printf("Enter the number of subnets to calculate: ");
    scanf("%d", &num_subnets);

    // Get IP address
    printf("Enter the IP address: ");
    scanf("%s", subnets[0].ip);

    // Calculate subnets
    calculate_subnets(subnets[0].ip, num_subnets, subnets);

    // Print subnet information
    printf("\nSubnet IP\tSubnet Mask\tNumber of Hosts\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("%s\t\t%s\t\t%d\n", subnets[i].ip, subnets[i].mask, subnets[i].num_hosts);
    }

    return 0;
}