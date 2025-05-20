//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SUBNETS 32
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_COUNT 1000

typedef struct {
    int start;
    int end;
    int mask;
} Subnet;

void print_subnet(Subnet subnet) {
    printf("%d.%d.%d.%d/%d\n", (subnet.start >> 24) & 0xFF, (subnet.start >> 16) & 0xFF, (subnet.start >> 8) & 0xFF, subnet.start & 0xFF, subnet.mask);
}

int main() {
    int num_subnets;
    int max_subnet_size;
    int max_subnet_count;
    Subnet subnets[MAX_SUBNETS];
    int i, j, k;

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    printf("Enter the maximum subnet size (1-%d): ", MAX_SUBNET_SIZE);
    scanf("%d", &max_subnet_size);

    printf("Enter the maximum number of subnets to generate: ");
    scanf("%d", &max_subnet_count);

    for (i = 0; i < num_subnets; i++) {
        subnets[i].start = 0;
        subnets[i].end = 0;
        subnets[i].mask = 0;
    }

    for (i = 0; i < num_subnets; i++) {
        for (j = 0; j < max_subnet_size; j++) {
            if ((subnets[i].mask & (1 << j)) == 0) {
                subnets[i].mask |= (1 << j);
                break;
            }
        }

        if (j == max_subnet_size) {
            printf("No more subnets available.\n");
            return 1;
        }

        subnets[i].start = rand() % (1 << max_subnet_size);
        subnets[i].end = subnets[i].start + (1 << j) - 1;
    }

    printf("Generated %d subnets:\n", num_subnets);
    for (i = 0; i < num_subnets; i++) {
        print_subnet(subnets[i]);
    }

    return 0;
}