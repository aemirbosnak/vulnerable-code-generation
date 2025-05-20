//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int ip;
    int mask;
    int gateway;
} network_t;

int main() {
    int num_networks, i;
    network_t *networks;

    printf("Welcome to the Subnet Calculator, post-apocalyptic edition!\n");
    printf("Please enter the number of networks you want to configure: ");
    scanf("%d", &num_networks);

    networks = (network_t *)malloc(num_networks * sizeof(network_t));

    for (i = 0; i < num_networks; i++) {
        networks[i].name = (char *)malloc(64 * sizeof(char));
        networks[i].ip = 0;
        networks[i].mask = 0;
        networks[i].gateway = 0;

        printf("Enter the name of network %d: ", i+1);
        scanf("%s", networks[i].name);

        printf("Enter the IP address of network %s: ", networks[i].name);
        scanf("%d.%d.%d.%d", &networks[i].ip, &networks[i].ip, &networks[i].ip, &networks[i].ip);

        printf("Enter the subnet mask of network %s: ", networks[i].name);
        scanf("%d.%d.%d.%d", &networks[i].mask, &networks[i].mask, &networks[i].mask, &networks[i].mask);

        printf("Enter the default gateway of network %s: ", networks[i].name);
        scanf("%d.%d.%d.%d", &networks[i].gateway, &networks[i].gateway, &networks[i].gateway, &networks[i].gateway);
    }

    for (i = 0; i < num_networks; i++) {
        printf("\nNetwork %s:\n", networks[i].name);
        printf("IP address: %d.%d.%d.%d\n", networks[i].ip, networks[i].ip, networks[i].ip, networks[i].ip);
        printf("Subnet mask: %d.%d.%d.%d\n", networks[i].mask, networks[i].mask, networks[i].mask, networks[i].mask);
        printf("Default gateway: %d.%d.%d.%d\n\n", networks[i].gateway, networks[i].gateway, networks[i].gateway, networks[i].gateway);
    }

    free(networks);
    return 0;
}