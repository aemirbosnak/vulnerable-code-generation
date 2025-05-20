//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate Wi-Fi Signal Strength
int calculate_signal_strength(int signal) {
    int strength;

    if(signal < -90) {
        strength = 0;
    }
    else if(signal < -80) {
        strength = 1;
    }
    else if(signal < -70) {
        strength = 2;
    }
    else if(signal < -60) {
        strength = 3;
    }
    else if(signal < -50) {
        strength = 4;
    }
    else if(signal < -40) {
        strength = 5;
    }
    else {
        strength = 6;
    }

    return strength;
}

int main() {
    int signal_strength;
    char ssid[30];

    printf("Enter Wi-Fi signal strength: ");
    scanf("%d", &signal_strength);

    printf("Enter Wi-Fi network name (SSID): ");
    scanf("%s", ssid);

    // Print signal strength and corresponding bars
    printf("\nWi-Fi Signal Strength: %d\n", signal_strength);
    printf("Signal Bars: ");

    for(int i = 0; i < calculate_signal_strength(signal_strength); i++) {
        printf("|");
    }

    printf("\n");

    return 0;
}