//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 100
#define MAX_IP_LENGTH 16

typedef struct {
    char ip[MAX_IP_LENGTH];
    char mask[MAX_IP_LENGTH];
    int size;
} Subnet;

int main() {
    int num_subnets, i, j, k, l, size;
    Subnet subnets[MAX_SUBNETS];
    char input[MAX_IP_LENGTH];
    char *token;

    printf("Enter the IP address: ");
    scanf("%s", input);

    num_subnets = 0;
    size = 32;

    while (num_subnets < MAX_SUBNETS) {
        printf("Enter the subnet size (1-%d): ", size);
        scanf("%d", &size);

        if (size < 1 || size > size) {
            printf("Invalid subnet size.\n");
            continue;
        }

        for (i = 0; i < num_subnets; i++) {
            if (subnets[i].size == size) {
                printf("Subnet with size %d already exists.\n", size);
                break;
            }
        }

        if (i == num_subnets) {
            subnets[num_subnets].size = size;

            token = strtok(input, ".");
            strcpy(subnets[num_subnets].ip, token);

            for (j = 0; j < size; j++) {
                subnets[num_subnets].mask[j] = '1';
            }

            for (j = size; j < MAX_IP_LENGTH; j++) {
                subnets[num_subnets].mask[j] = '0';
            }

            num_subnets++;
        }
    }

    printf("Subnets:\n");
    for (i = 0; i < num_subnets; i++) {
        printf("Size: %d\nIP: %s\nMask: %s\n", subnets[i].size, subnets[i].ip, subnets[i].mask);
    }

    return 0;
}