//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK_SIZE 16

typedef struct {
    char *name;
    int size;
    char mask[MAX_SUBNET_MASK_SIZE];
} Subnet;

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    int parts[4] = {0};
    int num_parts = 0;

    char *token = strtok(ip, ".");
    while (token!= NULL) {
        int value = atoi(token);
        if (value < 0 || value > 255) {
            printf("Invalid IP address\n");
            return 1;
        }
        parts[num_parts++] = value;
        token = strtok(NULL, ".");
    }

    if (num_parts!= 4) {
        printf("Invalid IP address\n");
        return 1;
    }

    int num_subnets = 0;
    Subnet subnets[MAX_SUBNETS];

    for (int i = 0; i < num_parts; i++) {
        for (int j = 0; j < MAX_SUBNET_SIZE; j++) {
            if (i == 0 && j == 0)
                continue;

            char mask[MAX_SUBNET_MASK_SIZE];
            sprintf(mask, "%d.%d.%d.%d", 0xff, 0xff, 0xff, 0xff << j);

            if (i == 0 && j == 0) {
                subnets[num_subnets].name = strdup("default");
            } else {
                char subnet_ip[16];
                sprintf(subnet_ip, "%d.%d.%d.%d", parts[0], parts[1], parts[2], ((parts[3] >> (8 - j)) & 0xff));
                subnets[num_subnets].name = strdup(subnet_ip);
            }

            subnets[num_subnets].size = 32 - j;
            strncpy(subnets[num_subnets].mask, mask, MAX_SUBNET_MASK_SIZE);
            num_subnets++;
        }
    }

    printf("IP address: %s\n", ip);
    printf("Subnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("\t%s (%d hosts)\n", subnets[i].name, 1 << subnets[i].size);
    }

    return 0;
}