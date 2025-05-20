//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NETWORKS 50
#define BUFFER_SIZE 512

typedef struct {
    char ssid[32];
    int signal_strength;
} Network;

void displayNetworkInfo(Network networks[], int count) {
    printf("\nAvailable Wi-Fi Networks:\n");
    printf("%-30s %-15s\n", "SSID", "Signal Strength (dBm)");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-30s %-15d\n", networks[i].ssid, networks[i].signal_strength);
    }
}

int compareSignalStrength(const void *a, const void *b) {
    return ((Network *)b)->signal_strength - ((Network *)a)->signal_strength;
}

void analyzeSignalStrength() {
    FILE *fp;
    char buffer[BUFFER_SIZE];
    Network networks[MAX_NETWORKS];
    int count = 0;

    // Run the command to get Wi-Fi scan results
    fp = popen("iwlist wlan0 scan | grep 'ESSID\\|Quality'", "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to run command\n");
        exit(1);
    }

    // Read the output a line at a time
    while (fgets(buffer, sizeof(buffer) - 1, fp) != NULL) {
        char essid[32];
        int signal_quality;

        // Extract ESSID
        if (sscanf(buffer, " ESSID:\"%[^\"]\"", essid) == 1) {
            // Read the next line for signal quality
            fgets(buffer, sizeof(buffer) - 1, fp);
            if (sscanf(buffer, " Quality=%d", &signal_quality) == 1) {
                // Store in our network array
                if (count < MAX_NETWORKS) {
                    strncpy(networks[count].ssid, essid, sizeof(essid));
                    networks[count].signal_strength = signal_quality - 100; // Convert to dBm
                    count++;
                }
            }
        }
    }

    pclose(fp);

    if (count == 0) {
        printf("No Wi-Fi networks found!\n");
        return;
    }

    // Sort networks based on signal strength
    qsort(networks, count, sizeof(Network), compareSignalStrength);

    // Display the networks
    displayNetworkInfo(networks, count);
}

int main() {
    printf("🏄‍♂️ Welcome to the Wi-Fi Signal Strength Analyzer! 🏄‍♀️\n");
    printf("Scanning for available Wi-Fi networks...\n");

    analyzeSignalStrength();

    printf("\n🔎 Analyzing completed! Tune in again for more network fun! 🎉\n");
    return 0;
}