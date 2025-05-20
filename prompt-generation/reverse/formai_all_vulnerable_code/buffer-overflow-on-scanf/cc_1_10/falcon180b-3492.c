//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32

typedef struct {
    char name[20];
    int size;
    char *subnets[MAX_SUBNETS];
} network_t;

void add_subnet(network_t *net, char *subnet) {
    int i;
    for (i = 0; i < net->size; i++) {
        if (net->subnets[i] == NULL) {
            net->subnets[i] = strdup(subnet);
            return;
        }
    }
    printf("Error: No more subnets available.\n");
}

int main() {
    network_t net;
    char input[100];
    char *token;
    int i, j, size;

    printf("Enter network name: ");
    scanf("%s", net.name);

    printf("Enter network size (1-32): ");
    scanf("%d", &size);
    if (size < 1 || size > MAX_SUBNET_SIZE) {
        printf("Error: Invalid network size.\n");
        return 1;
    }

    net.size = size;

    printf("Enter subnets (up to %d):\n", MAX_SUBNETS);
    i = 0;
    while (i < MAX_SUBNETS && scanf("%s", input)!= EOF) {
        token = strtok(input, ".");
        if (token == NULL || strlen(token) < 1 || strlen(token) > 3) {
            printf("Error: Invalid subnet.\n");
            return 1;
        }
        for (j = 1; j < 4 - strlen(token); j++) {
            if (scanf("%s", input)!= 1) {
                printf("Error: Invalid subnet.\n");
                return 1;
            }
            token = strtok(input, ".");
            if (token == NULL || strlen(token) < 1 || strlen(token) > 3) {
                printf("Error: Invalid subnet.\n");
                return 1;
            }
        }
        add_subnet(&net, input);
        i++;
    }

    printf("Network name: %s\n", net.name);
    printf("Network size: %d\n", net.size);
    printf("Subnets:\n");
    for (i = 0; i < net.size; i++) {
        if (net.subnets[i]!= NULL) {
            printf("%s\n", net.subnets[i]);
        }
    }

    return 0;
}