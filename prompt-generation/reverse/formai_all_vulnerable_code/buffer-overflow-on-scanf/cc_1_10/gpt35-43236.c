//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NETWORKS 10
#define MAX_SSID_LENGTH 32

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int strength;
} Network;

void print_networks(Network networks[], int num_networks) {
    printf("Available Networks:\n");
    for (int i = 0; i < num_networks; i++) {
        printf("%s \t %d dBm\n", networks[i].ssid, networks[i].strength);
    }
}

int main() {
    Network networks[MAX_NETWORKS];
    int num_networks = 0;
    char ssid[MAX_SSID_LENGTH];
    int strength;

    printf("Wi-Fi Signal Strength Analyzer\n\n");

    while (true) {
        printf("Enter SSID (or 'exit' to quit): ");
        scanf("%s", ssid);
        
        if (strcmp(ssid, "exit") == 0) {
            break;
        }

        printf("Enter signal strength (in dBm): ");
        scanf("%d", &strength);

        bool existing_network = false;
        for (int i = 0; i < num_networks; i++) {
            if (strcmp(ssid, networks[i].ssid) == 0) {
                // update existing network strength
                networks[i].strength = strength;
                existing_network = true;
                break;
            }
        }

        if (!existing_network) {
            // add new network
            if (num_networks >= MAX_NETWORKS) {
                printf("Error: Maximum number of networks exceeded\n");
                continue;
            }
            strcpy(networks[num_networks].ssid, ssid);
            networks[num_networks].strength = strength;
            num_networks++;
        }

        print_networks(networks, num_networks);
    }

    printf("End of program\n");

    return 0;
}