//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_IP_LEN 16

typedef struct {
    char ip[MAX_IP_LEN];
    int mask;
} Subnet;

void print_subnet(Subnet subnet) {
    printf("IP Address: %s\n", subnet.ip);
    printf("Subnet Mask: %d.%d.%d.%d\n", (subnet.mask >> 24) & 0xFF, (subnet.mask >> 16) & 0xFF, (subnet.mask >> 8) & 0xFF, subnet.mask & 0xFF);
}

int main() {
    int num_subnets;
    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    if (num_subnets > MAX_SUBNETS) {
        printf("Error: Maximum number of subnets is %d.\n", MAX_SUBNETS);
        return 1;
    }

    Subnet subnets[num_subnets];

    int i;
    for (i = 0; i < num_subnets; i++) {
        char ip[MAX_IP_LEN];
        printf("Enter the IP address for subnet %d: ", i + 1);
        scanf("%s", ip);

        int mask_len;
        printf("Enter the subnet mask length for subnet %d: ", i + 1);
        scanf("%d", &mask_len);

        if (mask_len > 32 || mask_len < 1) {
            printf("Error: Subnet mask length must be between 1 and 32.\n");
            return 1;
        }

        subnets[i].mask = 0xFFFFFFFF << (32 - mask_len);
        strcpy(subnets[i].ip, ip);
    }

    printf("\nSubnet Information:\n");
    for (i = 0; i < num_subnets; i++) {
        print_subnet(subnets[i]);
    }

    return 0;
}