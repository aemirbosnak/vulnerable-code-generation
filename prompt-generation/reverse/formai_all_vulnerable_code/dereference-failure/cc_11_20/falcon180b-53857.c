//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 32
#define MAX_SUBNET_SIZE 32
#define MAX_IP_SIZE 16

typedef struct {
    char ip[MAX_IP_SIZE];
    int mask;
} Subnet;

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP address> <subnet mask>\n", argv[0]);
        return 1;
    }

    char ip[MAX_IP_SIZE];
    strncpy(ip, argv[1], MAX_IP_SIZE);

    int mask;
    if (sscanf(argv[2], "%d", &mask)!= 1) {
        printf("Invalid subnet mask\n");
        return 1;
    }

    int num_subnets = 0;
    Subnet *subnets = malloc(MAX_SUBNETS * sizeof(Subnet));
    if (subnets == NULL) {
        printf("Memory error\n");
        return 1;
    }

    char *token = strtok(ip, ".");
    int i = 0;
    while (token!= NULL) {
        int value = atoi(token);
        if (value < 0 || value > 255) {
            printf("Invalid IP address\n");
            free(subnets);
            return 1;
        }
        subnets[num_subnets].ip[i++] = value;
        token = strtok(NULL, ".");
    }

    subnets[num_subnets].ip[i] = '\0';
    num_subnets++;

    for (i = 0; i < num_subnets; i++) {
        int j;
        for (j = 0; j < MAX_IP_SIZE; j++) {
            if (subnets[i].ip[j] == '*') {
                subnets[i].ip[j] = '\0';
                break;
            }
        }
        subnets[i].mask = mask;
    }

    printf("Subnet IP addresses:\n");
    for (i = 0; i < num_subnets; i++) {
        printf("%s\n", subnets[i].ip);
    }

    free(subnets);
    return 0;
}