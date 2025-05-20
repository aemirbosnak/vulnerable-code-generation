//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100
#define IP_LENGTH 15
#define SUBNET_LENGTH 4

typedef struct {
    char ip[IP_LENGTH];
    char subnet[SUBNET_LENGTH];
} Subnet;

int main() {
    int numSubnets;
    Subnet subnets[MAX_SUBNETS];
    char input[IP_LENGTH];
    int i, j, k;

    // Get number of subnets
    printf("Enter the number of subnets: ");
    scanf("%d", &numSubnets);

    // Get subnet information
    for (i = 0; i < numSubnets; i++) {
        printf("Enter subnet %d IP address: ", i+1);
        scanf("%s", input);
        strcpy(subnets[i].ip, input);

        printf("Enter subnet %d subnet mask: ", i+1);
        scanf("%d.%d.%d.%d", &subnets[i].subnet[0], &subnets[i].subnet[1], &subnets[i].subnet[2], &subnets[i].subnet[3]);
    }

    // Calculate subnets
    for (i = 0; i < numSubnets; i++) {
        for (j = 0; j < IP_LENGTH; j++) {
            if (subnets[i].ip[j] == '.') {
                k = j;
                break;
            }
        }

        for (j = k+1; j < IP_LENGTH; j++) {
            if (subnets[i].ip[j] == '.') {
                break;
            }

            if (subnets[i].subnet[j-k-1] == '0' && subnets[i].ip[j]!= '0') {
                for (int l = j; l < IP_LENGTH; l++) {
                    subnets[i].ip[l] = '0';
                }
                break;
            } else if (subnets[i].subnet[j-k-1] == '1' && subnets[i].ip[j] == '0') {
                for (int l = j; l < IP_LENGTH; l++) {
                    subnets[i].ip[l] = '1';
                }
                break;
            }
        }
    }

    // Print subnets
    for (i = 0; i < numSubnets; i++) {
        printf("Subnet %d: %s\n", i+1, subnets[i].ip);
    }

    return 0;
}