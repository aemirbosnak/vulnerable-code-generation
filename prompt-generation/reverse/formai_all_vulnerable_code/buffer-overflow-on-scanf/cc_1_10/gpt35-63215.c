//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define SSID_LENGTH 32

/* This structure holds information about a wireless network */
struct wifi_network {
    char ssid[SSID_LENGTH];
    int signal_strength;
};

/* This function prints the data of a wifi network */
void print_wifi_network(struct wifi_network network) {
    printf("SSID: %s\nSignal Strength: %d dBm\n", network.ssid, network.signal_strength);
}

int main() {
    int num_networks;
    printf("Enter the number of available WiFi networks: ");
    scanf("%d", &num_networks);

    struct wifi_network networks[num_networks];

    /* Fill in the information for each network */
    for (int i = 0; i < num_networks; i++) {
        printf("\nEnter information for WiFi network %d\n", i+1);
        printf("SSID: ");
        scanf("%s", networks[i].ssid);
        printf("Signal Strength (dBm): ");
        scanf("%d", &networks[i].signal_strength);
    }

    /* Print out the information for each network */
    printf("\n\nAvailable WiFi Networks:\n");
    for (int i = 0; i < num_networks; i++) {
        print_wifi_network(networks[i]);
    }

    /* Find the strongest wifi network */
    struct wifi_network strongest_network = networks[0];
    for (int i = 1; i < num_networks; i++) {
        if (networks[i].signal_strength > strongest_network.signal_strength) {
            strongest_network = networks[i];
        }
    }

    /* Print out the information for the strongest network */
    printf("\n\nStrongest WiFi Network:\n");
    print_wifi_network(strongest_network);

    return 0;
}