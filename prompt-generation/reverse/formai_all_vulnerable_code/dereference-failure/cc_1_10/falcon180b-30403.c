//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK 32

typedef struct {
    char subnet[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_MASK];
    int size;
} subnet_t;

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Subnet Mask>\n", argv[0]);
        return 1;
    }

    char ip[16];
    strcpy(ip, argv[1]);

    char mask[16];
    strcpy(mask, argv[2]);

    int i, j;
    subnet_t subnets[MAX_SUBNETS];
    int num_subnets = 0;

    for (i = 0; i < 32; i++) {
        if (mask[i] == '1') {
            for (j = 0; j < num_subnets; j++) {
                if (subnets[j].size == i + 1) {
                    break;
                }
            }

            if (j == num_subnets) {
                strcpy(subnets[num_subnets].subnet, ip);
                strcpy(subnets[num_subnets].mask, mask);
                subnets[num_subnets].size = i + 1;
                num_subnets++;
            }
        }
    }

    printf("Subnets:\n");
    for (i = 0; i < num_subnets; i++) {
        printf("Subnet %d: %s/%d\n", i + 1, subnets[i].subnet, subnets[i].size);
    }

    return 0;
}