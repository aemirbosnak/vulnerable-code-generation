//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SSID_LENGTH 32
#define MAX_NETWORKS 10

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
} wifi_network;

int main() {
    wifi_network networks[MAX_NETWORKS];

    int num_networks;
    printf("Enter the number of networks to analyze (up to %d): ", MAX_NETWORKS);
    scanf("%d", &num_networks);

    if (num_networks > MAX_NETWORKS) {
        printf("Error: too many networks specified. Maximum is %d.", MAX_NETWORKS);
        return 1;
    }

    // Randomize signal strengths for the networks
    srand(time(NULL));
    for (int i = 0; i < num_networks; i++) {
        networks[i].signal_strength = rand() % 100;
    }

    // Prompt user to enter SSIDs for the networks
    printf("Enter SSIDs for the networks:\n");
    for (int i = 0; i < num_networks; i++) {
        printf("SSID %d: ", i + 1);
        scanf("%s", networks[i].ssid);
    }

    // Display the signal strengths for each network
    printf("Network signal strengths:\n");
    for (int i = 0; i < num_networks; i++) {
        printf("%s: %d%%\n", networks[i].ssid, networks[i].signal_strength);
    }

    // Determine the strongest network
    int max_signal_strength = -1;
    int max_index = -1;
    for (int i = 0; i < num_networks; i++) {
        if (networks[i].signal_strength > max_signal_strength) {
            max_signal_strength = networks[i].signal_strength;
            max_index = i;
        }
    }

    printf("The strongest network is: %s", networks[max_index].ssid);

    return 0;
}