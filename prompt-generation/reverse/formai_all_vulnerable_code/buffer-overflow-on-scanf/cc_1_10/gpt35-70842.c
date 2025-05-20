//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SSID_LENGTH 32
#define MAX_SSID_COUNT 10

// Define a struct to hold the information for each network
typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
} Network;

// Function to get a random signal strength (-100 to 0)
int get_random_signal_strength() {
    return rand() % 101 - 100;
}

// Function to print the list of networks and their signal strengths
void print_networks(Network networks[], int count) {
    printf("Wi-Fi Networks:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %d dBm\n", networks[i].ssid, networks[i].signal_strength);
    }
}

int main() {
    // Initialize the list of networks
    Network networks[MAX_SSID_COUNT];

    // Ask the user for the number of networks to scan
    int num_networks;
    printf("How many networks would you like to scan? (max %d) ", MAX_SSID_COUNT);
    scanf("%d", &num_networks);
    if (num_networks > MAX_SSID_COUNT) {
        printf("Error: Number of networks exceeds maximum count of %d\n", MAX_SSID_COUNT);
        exit(1);
    }

    // Get the SSIDs for each network from the user
    printf("Enter the SSIDs for each network:\n");
    for (int i = 0; i < num_networks; i++) {
        printf("SSID #%d: ", i+1);
        scanf("%s", networks[i].ssid);
        networks[i].signal_strength = get_random_signal_strength();
    }

    // Print the list of networks and their signal strengths
    print_networks(networks, num_networks);

    return 0;
}