//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to calculate signal strength */
int signal_strength(int signal) {
    if (signal >= -50) {
        return 4;
    } else if (signal < -50 && signal >= -60) {
        return 3;
    } else if (signal < -60 && signal >= -70) {
        return 2;
    } else if (signal < -70 && signal >= -80) {
        return 1;
    } else {
        return 0;
    }
}

/* Main function */
int main() {
    char ssid[20], bssid[20], mac[20], channel[5];
    int signal;

    /* Get data from user */
    printf("Enter the SSID: ");
    scanf("%s", ssid);
    printf("Enter the BSSID: ");
    scanf("%s", bssid);
    printf("Enter the MAC address: ");
    scanf("%s", mac);
    printf("Enter the channel: ");
    scanf("%s", channel);
    printf("Enter the signal strength (in dBm): ");
    scanf("%d", &signal);

    /* Calculate signal strength */
    int strength = signal_strength(signal);

    /* Print the result */
    printf("Details of the Wi-Fi network:\n");
    printf("SSID: %s\n", ssid);
    printf("BSSID: %s\n", bssid);
    printf("MAC address: %s\n", mac);
    printf("Channel: %s\n", channel);
    printf("Signal Strength (in dBm): %d\n", signal);
    printf("Signal Strength (in bars): %d\n", strength);

    return 0;
}