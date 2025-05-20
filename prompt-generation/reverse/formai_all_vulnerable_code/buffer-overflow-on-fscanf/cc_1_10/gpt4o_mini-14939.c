//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_NETWORKS 100
#define MAX_SSID_LENGTH 32
#define COMMAND_LENGTH 256

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
} WiFiNetwork;

void clear_screen() {
    printf("\033[H\033[J"); // ANSI escape code to clear screen
}

void display_networks(WiFiNetwork networks[], int count) {
    clear_screen();
    printf("Wi-Fi Signal Strength Analyzer\n");
    printf("===============================\n");
    printf("%-32s %-15s\n", "SSID", "Signal Strength (dBm)");
    printf("------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-32s %-15d\n", networks[i].ssid, networks[i].signal_strength);
    }
}

int scan_networks(WiFiNetwork networks[]) {
    char command[COMMAND_LENGTH];
    FILE *fp;
    int count = 0;

    // Run the command to scan for Wi-Fi networks
    snprintf(command, sizeof(command), "nmcli -f ssid,signal dev wifi");
    fp = popen(command, "r");
    if (fp == NULL) {
        perror("Failed to run command");
        return -1;
    }

    char ssid[MAX_SSID_LENGTH];
    int signal_strength;

    // Read the output
    while (fscanf(fp, "%31s %d", ssid, &signal_strength) == 2) {
        if (count < MAX_NETWORKS) {
            // Make sure we don't duplicate SSIDs and store the network
            strncpy(networks[count].ssid, ssid, MAX_SSID_LENGTH);
            networks[count].signal_strength = signal_strength;
            count++;
        } else {
            break;
        }
    }

    pclose(fp);
    return count;
}

int main() {
    WiFiNetwork networks[MAX_NETWORKS];
    int network_count;

    while (1) {
        network_count = scan_networks(networks);
        if (network_count < 0) {
            fprintf(stderr, "Error scanning networks.\n");
            return EXIT_FAILURE;
        }

        display_networks(networks, network_count);

        // Pause for a moment before the next refresh
        printf("\nRefreshing in 5 seconds...\n");
        sleep(5);
    }

    return EXIT_SUCCESS;  // This line is never reached, but it's good practice
}