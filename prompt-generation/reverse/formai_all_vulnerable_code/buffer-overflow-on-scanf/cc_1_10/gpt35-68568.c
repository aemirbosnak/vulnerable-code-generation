//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct wifi_data {
    char ssid[30];
    int strength;
} wifi_data_t;

int main() {
    int num_networks;
    printf("Enter the number of Wi-Fi networks to analyze: ");
    scanf("%d", &num_networks);
    printf("\n");

    wifi_data_t *networks = (wifi_data_t *) malloc(num_networks * sizeof(wifi_data_t));
    if (networks == NULL) {
        printf("Error: Memory allocation failed");
        return 1;
    }

    // Populate Wi-Fi network data
    for (int i = 0; i < num_networks; i++) {
        printf("Enter the SSID of network %d: ", i+1);
        scanf("%s", networks[i].ssid);
        printf("Enter the signal strength of network %d: ", i+1);
        scanf("%d", &networks[i].strength);
        printf("\n");
    }

    // Sort networks based on signal strength
    for (int i = 0; i < num_networks-1; i++) {
        for (int j = i+1; j < num_networks; j++) {
            if (networks[i].strength < networks[j].strength) {
                // Swap the two elements
                wifi_data_t temp = networks[i];
                networks[i] = networks[j];
                networks[j] = temp;
            }
        }
    }

    // Display Wi-Fi network data in descending order of signal strength
    printf("Wi-Fi Network\tSignal Strength (dBm)\n");
    for (int i = 0; i < num_networks; i++) {
        printf("%s\t\t%d\n", networks[i].ssid, networks[i].strength);
    }

    free(networks);
    return 0;
}