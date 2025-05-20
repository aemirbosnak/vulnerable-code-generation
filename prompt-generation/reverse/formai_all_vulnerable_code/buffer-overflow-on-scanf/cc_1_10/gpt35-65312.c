//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CHANNELS 14
#define MAX_NETWORKS 10

struct wireless_network {
    char name[30];
    int channel;
    int signal_strength;
};

typedef struct wireless_network Network;

void scan_wireless_networks(Network* networks) {
    int num_networks = 0;
    bool found_network;
    printf("Scanning for wireless networks...\n");

    for (int channel = 1; channel <= MAX_CHANNELS; channel++) {
        found_network = false;
        for (int i = 0; i < num_networks; i++) {
            if (networks[i].channel == channel) {
                found_network = true;
                break;
            }
        }

        if (!found_network) {
            Network network;
            network.channel = channel;
            printf("Scanning channel %d...\n", channel);
            printf("Enter network name: ");
            scanf("%s", network.name);
            printf("Enter signal strength: ");
            scanf("%d", &network.signal_strength);
            networks[num_networks++] = network;
        }

        if (num_networks >= MAX_NETWORKS) {
            break;
        }
    }
}

void print_networks(Network* networks, int num_networks) {
    printf("%-30s%-10s%-15s\n", "Network Name", "Channel", "Signal Strength");
    for (int i = 0; i < num_networks; i++) {
        printf("%-30s%-10d%-15d\n", networks[i].name, networks[i].channel, networks[i].signal_strength);
    }
}

int main() {
    Network networks[MAX_NETWORKS] = {0};
    scan_wireless_networks(networks);
    print_networks(networks, MAX_NETWORKS);
    return 0;
}