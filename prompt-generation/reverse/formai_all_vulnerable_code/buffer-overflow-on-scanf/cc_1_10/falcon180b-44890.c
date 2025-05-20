//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_MASK_LENGTH 32
#define MAX_SUBNET_SIZE 254

typedef struct {
    char name[20];
    int mask_length;
    int subnet_size;
} Subnet;

void generate_subnets(int mask_length, int subnet_size, Subnet *subnets) {
    int i, j;
    for (i = 0, j = 0; i < 32; i++) {
        if ((1 << i) & (subnet_size - 1)) {
            j++;
        }
        if (j == subnet_size) {
            subnets[i].name[0] = '\0';
            subnets[i].mask_length = mask_length;
            subnets[i].subnet_size = subnet_size;
            i--;
            j = 0;
        }
    }
}

int main() {
    int num_subnets, mask_length, subnet_size;
    char input_buffer[100];
    Subnet subnets[MAX_SUBNETS];

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    printf("Enter the subnet mask length (1-32): ");
    scanf("%d", &mask_length);

    printf("Enter the subnet size (1-%d): ", MAX_SUBNET_SIZE);
    scanf("%d", &subnet_size);

    if (num_subnets > MAX_SUBNETS || mask_length > MAX_MASK_LENGTH || subnet_size > MAX_SUBNET_SIZE) {
        printf("Invalid input.\n");
        return 1;
    }

    generate_subnets(mask_length, subnet_size, subnets);

    printf("Subnet\t\tMask Length\tSubnet Size\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("%s\t\t%d\t\t%d\n", subnets[i].name, subnets[i].mask_length, subnets[i].subnet_size);
    }

    return 0;
}