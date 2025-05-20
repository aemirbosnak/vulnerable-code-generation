//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to analyze Wi-Fi signal strength
void signalAnalyzer(int strength, bool isConnected) {
    if (isConnected) {
        printf("Connected to Wi-Fi network with signal strength %d\n", strength);
    } else {
        printf("Not connected to any Wi-Fi network\n");
    }
    
    if (strength <= 20) {
        printf("Signal strength is very weak. Consider moving closer to the Wi-Fi router or using a Wi-Fi range extender.\n");
    } else if (strength <= 50) {
        printf("Signal strength is weak. Try moving closer to the Wi-Fi router.\n");
    } else if (strength <= 80) {
        printf("Signal strength is average. You should be able to use the Wi-Fi network without issues.\n");
    } else {
        printf("Signal strength is strong. You should have no issues using the Wi-Fi network.\n");
    }
}

int main() {
    int signalStrength;
    bool connectedToWiFi;
    
    printf("Please enter the signal strength value (out of 100): ");
    scanf("%d", &signalStrength);

    // validate input
    if (signalStrength < 0 || signalStrength > 100) {
        printf("Error: Invalid signal strength entered. Please enter a value between 0 and 100.\n");
        return 1;
    }
    
    printf("Is the device connected to Wi-Fi network? (y/n): ");
    char response[10];
    scanf("%s", response);
    
    // validate input
    if (strcmp(response, "y") == 0) {
        connectedToWiFi = true;
    } else if (strcmp(response, "n") == 0) {
        connectedToWiFi = false;
    } else {
        printf("Error: Invalid response entered. Please enter 'y' or 'n' only.\n");
        return 1;
    }
    
    signalAnalyzer(signalStrength, connectedToWiFi);
    
    return 0;
}