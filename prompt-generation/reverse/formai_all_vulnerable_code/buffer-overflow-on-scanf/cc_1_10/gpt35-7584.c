//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int signal_strength, i;
    char wifi_name[20], signal[5];
    
    printf("Welcome to the Wi-Fi Signal Strength Analyzer!\n\n");
    
    // Prompt user for Wi-Fi name and signal strength
    printf("Please enter the name of the Wi-Fi network: ");
    scanf("%s", wifi_name);
    printf("Please enter the Wi-Fi signal strength (out of 100): ");
    scanf("%d", &signal_strength);
    
    // Convert signal strength to bars
    int bars = signal_strength / 20;

    // Print out Wi-Fi network name and signal strength in bars
    printf("\nWi-Fi Network: %s\n", wifi_name);
    printf("Signal Strength: ");

    for (i = 0; i < bars; i++) {
        printf("|");
    }
    printf("\n\n");

    // Determine signal quality based on number of bars 
    if (bars >= 4) {
        strcpy(signal, "Excellent");
    } 
    else if (bars == 3) {
        strcpy(signal, "Good");
    }
    else if (bars == 2) {
        strcpy(signal, "Fair");
    }
    else if (bars == 1) {
        strcpy(signal, "Poor");
    }
    else if (bars == 0) {
        strcpy(signal, "No signal");
    }
    
    // Print out signal quality
    printf("Signal Quality: %s\n", signal);
    
    return 0;
}