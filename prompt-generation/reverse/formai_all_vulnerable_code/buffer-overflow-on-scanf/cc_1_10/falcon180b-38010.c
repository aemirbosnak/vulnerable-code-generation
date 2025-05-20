//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK 32

typedef struct {
    char name[10];
    char ipAddress[16];
    char subnetMask[16];
} subnet;

int main() {
    int numSubnets;
    subnet subnets[MAX_SUBNETS];
    char input[MAX_SUBNET_SIZE];
    char *token;
    int i, j;

    printf("Enter the number of subnets: ");
    scanf("%d", &numSubnets);

    for (i = 0; i < numSubnets; i++) {
        printf("Enter the subnet name: ");
        scanf("%s", subnets[i].name);

        printf("Enter the IP address: ");
        scanf("%s", input);
        strcpy(subnets[i].ipAddress, input);

        printf("Enter the subnet mask: ");
        scanf("%s", input);
        strcpy(subnets[i].subnetMask, input);
    }

    for (i = 0; i < numSubnets; i++) {
        token = strtok(subnets[i].ipAddress, ".");
        subnets[i].ipAddress[strlen(subnets[i].ipAddress) - 1] = '\0';

        for (j = 0; j < 4; j++) {
            printf("%d.%d.%d.%d\n", atoi(token), atoi(strtok(NULL, ". ")), atoi(strtok(NULL, ". ")), atoi(strtok(NULL, ". ")));
        }

        printf("\n");
    }

    return 0;
}