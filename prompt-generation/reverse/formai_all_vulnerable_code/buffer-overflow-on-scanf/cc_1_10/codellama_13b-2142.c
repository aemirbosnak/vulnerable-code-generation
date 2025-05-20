//Code Llama-13B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: statistical
/*
 * wifi_signal_strength.c
 *
 * This program analyzes Wi-Fi signal strength and provides statistics
 * on the signal strength of the Wi-Fi network.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SSID_LENGTH 32
#define MAX_BSSID_LENGTH 18
#define MAX_SIGNAL_STRENGTH 100

typedef struct {
    char ssid[MAX_SSID_LENGTH + 1];
    char bssid[MAX_BSSID_LENGTH + 1];
    int signal_strength;
} wifi_network;

int main() {
    wifi_network networks[10];
    int num_networks = 0;
    int i;

    // Initialize all networks
    for (i = 0; i < 10; i++) {
        networks[i].signal_strength = 0;
    }

    // Read in Wi-Fi network information from stdin
    while (scanf("%s %s %d", networks[num_networks].ssid, networks[num_networks].bssid, &networks[num_networks].signal_strength) == 3) {
        num_networks++;
    }

    // Calculate the average signal strength
    int total_signal_strength = 0;
    for (i = 0; i < num_networks; i++) {
        total_signal_strength += networks[i].signal_strength;
    }
    double average_signal_strength = (double) total_signal_strength / num_networks;

    // Calculate the standard deviation of the signal strength
    double std_dev = 0;
    for (i = 0; i < num_networks; i++) {
        std_dev += pow(networks[i].signal_strength - average_signal_strength, 2);
    }
    std_dev /= num_networks - 1;
    std_dev = sqrt(std_dev);

    // Print the results
    printf("Number of networks: %d\n", num_networks);
    printf("Average signal strength: %f\n", average_signal_strength);
    printf("Standard deviation: %f\n", std_dev);

    return 0;
}