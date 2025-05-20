//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256
#define INTERFACE_NAME "wlan0" // Change according to your wireless interface

// Function to get the Wi-Fi signal strength
void get_wifi_signal_strength() {
    char command[BUFFER_SIZE];
    char buffer[BUFFER_SIZE];
    FILE *fp;

    // Construct the command to call iwconfig and read its output
    snprintf(command, sizeof(command), "iwconfig %s", INTERFACE_NAME);

    // Execute the command
    fp = popen(command, "r");
    if (fp == NULL) {
        perror("popen failed");
        exit(EXIT_FAILURE);
    }

    int signal_strength = -1; // Initialize to a default value
    // Read the output from iwconfig command
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        if (strstr(buffer, "Signal level=") != NULL) {
            char *level_start = strstr(buffer, "Signal level=") + strlen("Signal level=");
            sscanf(level_start, "%d", &signal_strength);
            break; // Exit after finding the signal level
        }
    }

    // Close the command stream
    pclose(fp);

    // Display signal strength
    if (signal_strength != -1) {
        printf("Current Wi-Fi Signal Strength on %s: %d dBm\n", INTERFACE_NAME, signal_strength);
    } else {
        printf("Could not retrieve the Wi-Fi signal strength. Please ensure you are connected to a network.\n");
    }
}

// Function to display available networks
void get_available_networks() {
    char command[BUFFER_SIZE];
    char buffer[BUFFER_SIZE];
    FILE *fp;

    snprintf(command, sizeof(command), "nmcli -f SSID,SIGNAL dev wifi");

    // Execute the command
    fp = popen(command, "r");
    if (fp == NULL) {
        perror("popen failed");
        exit(EXIT_FAILURE);
    }

    printf("\nAvailable Wi-Fi Networks:\n");
    printf("%-30s %s\n", "SSID", "Signal Strength (%)");
    printf("-----------------------------------------\n");

    // Read the output from the nmcli command
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        char ssid[BUFFER_SIZE];
        int signalStrength;
        sscanf(buffer, "%29s %d", ssid, &signalStrength);
        printf("%-30s %d\n", ssid, signalStrength);
    }

    // Close the command stream
    pclose(fp);
}

// Main function
int main() {
    int choice;

    printf("Welcome to the Wi-Fi Signal Strength Analyzer!\n");
    
    while (1) {
        printf("\n1. Get current Wi-Fi signal strength\n");
        printf("2. List available Wi-Fi networks\n");
        printf("3. Exit\n");
        printf("Select an option (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                get_wifi_signal_strength();
                break;
            case 2:
                get_available_networks();
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}