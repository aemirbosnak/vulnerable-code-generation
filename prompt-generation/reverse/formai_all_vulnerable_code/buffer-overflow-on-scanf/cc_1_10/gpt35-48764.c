//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SSID_LENGTH 32

// Define a struct to store the SSID and signal strength
typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
} WifiNetwork;

// Global variable to store the list of Wifi networks
WifiNetwork wifi_networks[10];
int num_networks = 0;

int main() {
    // Populate some fake network data for testing
    strcpy(wifi_networks[0].ssid, "My Wifi Network");
    wifi_networks[0].signal_strength = -70;
    strcpy(wifi_networks[1].ssid, "Second Wifi Network");
    wifi_networks[1].signal_strength = -81;
    strcpy(wifi_networks[2].ssid, "Third Wifi Network");
    wifi_networks[2].signal_strength = -68;
    num_networks = 3;

    // Print out the list of Wifi networks
    printf("Found %d Wifi networks:\n", num_networks);
    for (int i = 0; i < num_networks; i++) {
        printf("%s: %ddb\n", wifi_networks[i].ssid, wifi_networks[i].signal_strength);
    }

    // Ask the user to enter the name of a Wifi network they want to find the signal strength for
    char search_ssid[MAX_SSID_LENGTH];
    printf("\nEnter the name of a Wifi network to find the signal strength for: ");
    scanf("%s", search_ssid);

    // Search through the list of Wifi networks for a match
    bool found = false;
    int signal_strength;
    for (int i = 0; i < num_networks; i++) {
        if (strcmp(wifi_networks[i].ssid, search_ssid) == 0) {
            found = true;
            signal_strength = wifi_networks[i].signal_strength;
            break;
        }
    }

    // Print out the signal strength if the network was found, or an error message if it wasn't
    if (found) {
        printf("Signal strength for %s: %ddb\n", search_ssid, signal_strength);
    } else {
        printf("Error: Wifi network '%s' not found\n", search_ssid);
    }

    return 0;
}