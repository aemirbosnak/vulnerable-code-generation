//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIGNAL_STRENGTH 100

int main() {
    char ssid[32]; // network name
    int signalStrength; // signal strength in dBm

    printf("Enter the network name (SSID): ");
    scanf("%s", ssid);
    printf("Enter the signal strength (dBm): ");
    scanf("%d", &signalStrength);

    // check if signal strength is valid
    if (signalStrength < -100 || signalStrength > 0) {
        printf("Invalid signal strength! Signal strength should be between -100 and 0 dBm.\n");
        return 1;
    }

    // calculate signal quality
    int signalQuality = 2 * (signalStrength + 100);

    // print signal quality and strength
    printf("SSID: %s\n", ssid);
    printf("Signal quality: %d%%\n", signalQuality);
    printf("Signal strength: %d dBm\n", signalStrength);

    // print signal bars based on signal quality
    printf("Signal Bars: ");
    int signalBars = round(signalQuality / 10.0);
    for (int i = 0; i < signalBars; i++) {
        printf("|");
    }
    printf("\n");

    // print recommended actions based on signal strength
    if (signalStrength >= -60) {
        printf("Signal strength is excellent. No action is required.\n");
    } else if (signalStrength >= -70) {
        printf("Signal strength is good. Consider optimizing your network for better performance.\n");
    } else if (signalStrength >= -80) {
        printf("Signal strength is fair. Consider moving your wireless router closer to your device.\n");
    } else {
        printf("Signal strength is poor. Consider moving your wireless router or getting a Wi-Fi extender.\n");
    }

    return 0;
}