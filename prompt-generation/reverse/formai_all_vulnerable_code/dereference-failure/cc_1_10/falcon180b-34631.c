//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32

typedef struct {
    char subnet[MAX_SUBNET_SIZE];
    int size;
} Subnet;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    char ip[16];
    strcpy(ip, argv[1]);

    int num_subnets = 1;
    Subnet subnets[MAX_SUBNETS];
    subnets[0].subnet[0] = '\0';
    subnets[0].size = 32;

    char *token = strtok(ip, ".");
    while (token!= NULL) {
        int value = atoi(token);
        if (value == 0) {
            printf("Invalid IP address.\n");
            return 1;
        }
        if (value == 255) {
            num_subnets *= 2;
        }
        token = strtok(NULL, ".");
    }

    if (num_subnets > MAX_SUBNETS) {
        printf("Too many subnets.\n");
        return 1;
    }

    int mask = 32 - atoi(strtok(ip, "."));
    int size = 32 - mask;

    for (int i = 0; i < num_subnets; i++) {
        int start = i * size;
        int end = (i + 1) * size - 1;
        snprintf(subnets[i].subnet, MAX_SUBNET_SIZE, "%d.%d.%d.%d", atoi(strtok(ip, ".")), atoi(strtok(NULL, ".")), atoi(strtok(NULL, ".")), end);
        subnets[i].size = end - start + 1;
    }

    printf("Number of subnets: %d\n", num_subnets);
    for (int i = 0; i < num_subnets; i++) {
        printf("Subnet %d: %s (%d hosts)\n", i + 1, subnets[i].subnet, subnets[i].size);
    }

    return 0;
}