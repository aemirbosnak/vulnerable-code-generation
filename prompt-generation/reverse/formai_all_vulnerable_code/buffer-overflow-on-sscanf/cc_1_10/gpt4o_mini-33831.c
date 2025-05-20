//GPT-4o-mini DATASET v1.0 Category: Wireless Network Scanner ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NETWORKS 100
#define MAX_SSID_LENGTH 32
#define MAX_SIGNAL_LEVEL 100

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int signal_level;
} Network;

// Function prototypes
void scanNetworks(Network networks[], int *count);
void displayNetworks(Network networks[], int count);
void sortNetworksBySignal(Network networks[], int count);

// Main function
int main() {
    Network networks[MAX_NETWORKS];
    int count = 0;

    printf("Welcome to C Wireless Network Scanner!\n");
    printf("Scanning for available wireless networks...\n");

    scanNetworks(networks, &count);
    
    if (count == 0) {
        printf("No wireless networks found.\n");
    } else {
        printf("Found %d wireless networks:\n", count);
        displayNetworks(networks, count);
        sortNetworksBySignal(networks, count);
        printf("\nSorted Networks by Signal Strength:\n");
        displayNetworks(networks, count);
    }

    return 0;
}

// Function to scan networks using system command
void scanNetworks(Network networks[], int *count) {
    FILE *fp;
    char buffer[128];
    fp = popen("nmcli -t -f SSID,SIGNAL dev wifi", "r"); // Command to list SSID and signal levels

    if (fp == NULL) {
        printf("Failed to run nmcli command.\n");
        exit(1);
    }
    
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        char ssid[MAX_SSID_LENGTH];
        int signal_level;
        sscanf(buffer, "%[^:]:%d", ssid, &signal_level);

        if (*count < MAX_NETWORKS) {
            strcpy(networks[*count].ssid, ssid);
            networks[*count].signal_level = signal_level;
            (*count)++;
        }
    }

    pclose(fp);
}

// Function to display the networks
void displayNetworks(Network networks[], int count) {
    printf("%-32s %s\n", "SSID", "Signal Level (%)");
    printf("%-32s %s\n", "----", "-------------");

    for (int i = 0; i < count; ++i) {
        printf("%-32s %d\n", networks[i].ssid, networks[i].signal_level);
    }
}

// Function to sort networks by signal strength in descending order
void sortNetworksBySignal(Network networks[], int count) {
    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (networks[j].signal_level < networks[j + 1].signal_level) {
                // Swapping networks
                Network temp = networks[j];
                networks[j] = networks[j + 1];
                networks[j + 1] = temp;
            }
        }
    }
}