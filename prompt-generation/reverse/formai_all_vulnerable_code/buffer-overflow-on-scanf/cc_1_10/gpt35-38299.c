//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SSID_LEN 32

struct wifi_data {
    char ssid[MAX_SSID_LEN];
    int signal_strength;
};

int main() {
    int num_networks, i;
    printf("Enter number of networks to scan: ");
    scanf("%d", &num_networks);
    getchar(); // clear the input buffer

    struct wifi_data *networks = (struct wifi_data*) malloc(num_networks * sizeof(struct wifi_data));

    // scan for networks
    printf("Scanning for networks...\n");
    for (i = 0; i < num_networks; i++) {
        printf("Enter SSID for network %d: ", i+1);
        fgets(networks[i].ssid, MAX_SSID_LEN, stdin);
        networks[i].ssid[strcspn(networks[i].ssid, "\n")] = '\0'; // remove newline

        printf("Enter signal strength for network %d: ", i+1);
        scanf("%d", &networks[i].signal_strength);
        getchar(); // clear the input buffer
    }

    // print network information
    printf("\nNetworks found:\n");
    for (i = 0; i < num_networks; i++) {
        printf("%d. SSID: %s, Signal Strength: %d dBm\n", i+1, networks[i].ssid, networks[i].signal_strength);
    }

    // find strongest signal
    int max_strength = -9999;
    int max_index = -1;
    for (i = 0; i < num_networks; i++) {
        if (networks[i].signal_strength > max_strength) {
            max_strength = networks[i].signal_strength;
            max_index = i;
        }
    }

    // print strongest network
    printf("\nStrongest network:\n");
    printf("SSID: %s, Signal Strength: %d dBm\n", networks[max_index].ssid, networks[max_index].signal_strength);

    free(networks);
    return 0;
}