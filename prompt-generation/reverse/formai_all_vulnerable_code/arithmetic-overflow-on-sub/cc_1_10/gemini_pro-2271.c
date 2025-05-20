//GEMINI-pro DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_SSID_LEN    32
#define MAX_RSSI_VALUE  -100

// Retro-style ASCII art of a Wi-Fi signal
const char *wifi_signal_ascii =
"         _____   _____ \n"
"        |  ___| |  ___|\n"
"        | |___  | |___  |\n"
"        |  ___| |  ___| |\n"
"        | |___  | |___  |\n"
"        |_____| |_____| |\n"
"        |=   |=|=   |=|\n"
"        | --- | | --- | |\n"
"        |     | |     | |\n"
"        |_____| |_____| |\n"
"        |_____| |_____| |\n"
"        |_____| |_____| |\n"
"        |_____| |_____| |\n"
"        |_____| |_____| |";

// Function to get the current Wi-Fi signal strength
int get_wifi_signal_strength() {
    // Open the file containing the Wi-Fi signal strength information
    FILE *fp = fopen("/proc/net/wireless", "r");
    if (fp == NULL) {
        perror("Error opening /proc/net/wireless");
        return -1;
    }

    // Read the first line of the file, which contains the header information
    char line[1024];
    if (fgets(line, sizeof(line), fp) == NULL) {
        perror("Error reading from /proc/net/wireless");
        fclose(fp);
        return -1;
    }

    // Find the line containing the signal strength information for the first interface
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strncmp(line, "wlan0", 5) == 0) {
            break;
        }
    }

    // Extract the signal strength value from the line
    int rssi_value;
    if (sscanf(line, "%*s %*s %d", &rssi_value) != 1) {
        perror("Error parsing /proc/net/wireless");
        fclose(fp);
        return -1;
    }

    // Close the file
    fclose(fp);

    // Return the signal strength value
    return rssi_value;
}

// Function to print the Wi-Fi signal strength in a retro-style ASCII art
void print_wifi_signal_strength(int rssi_value) {
    // Calculate the number of bars to display
    int num_bars = (rssi_value - MAX_RSSI_VALUE) / 5;
    if (num_bars < 0) {
        num_bars = 0;
    } else if (num_bars > 5) {
        num_bars = 5;
    }

    // Print the ASCII art
    printf("%s", wifi_signal_ascii);

    // Print the signal strength value
    printf("\nSignal Strength: %d dBm\n", rssi_value);

    // Print the signal strength bars
    printf("Signal Strength Bars:");
    for (int i = 0; i < num_bars; i++) {
        printf("█");
    }
    printf("\n");
}

int main() {
    // Get the current Wi-Fi signal strength
    int rssi_value = get_wifi_signal_strength();
    if (rssi_value == -1) {
        return 1;
    }

    // Print the Wi-Fi signal strength in a retro-style ASCII art
    print_wifi_signal_strength(rssi_value);

    return 0;
}