//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIGNAL_STRENGTH 100
#define MIN_SIGNAL_STRENGTH 0

/* Function to calculate signal strength in dBm based on RSSI */
double calculateSignalStrength(int rssi) {
    double signalStrength = 0.0;
    signalStrength = (double) ((27.55 * log10(abs(rssi))) - 20.0);
    return signalStrength;
}

/* Function to print WiFi signal strength bar */
void printSignalStrengthBar(int signalStrength) {
    int numBars = (int) round((double) signalStrength / 10);
    printf("|");
    for(int i = 0; i < numBars; i++) {
        printf("=");
    }
    for(int i = numBars; i < 10; i++) {
        printf(" ");
    }
    printf("|\n");
}

/* Function to analyze Wi-Fi signal strength */
void analyzeSignalStrength(int signalStrength) {
    double signalStrengthInDBm = calculateSignalStrength(signalStrength);
    printf("Signal Strength (dBm): %.2f\n", signalStrengthInDBm);
    printf("Signal Strength (Bar): ");
    printSignalStrengthBar(signalStrength);
    printf("\n");
}

/* Main function */
int main() {
    int signalStrength = 0;
    char input[10];

    printf("Welcome to Wi-Fi Signal Strength Analyzer!\n");

    do {
        printf("\nEnter Wi-Fi signal strength (0-100): ");
        fgets(input, 10, stdin);
        signalStrength = atoi(input);

        if(signalStrength < MIN_SIGNAL_STRENGTH || signalStrength > MAX_SIGNAL_STRENGTH) {
            printf("Invalid signal strength entered. Please enter a value between 0 and 100.\n");
        } else {
            analyzeSignalStrength(signalStrength);
        }

        printf("Do you want to analyze another signal strength? (yes/no): ");
        fgets(input, 10, stdin);
        input[strcspn(input, "\n")] = 0;

    } while(strcmp(input, "yes") == 0);

    printf("\nThank you for using Wi-Fi Signal Strength Analyzer!\n");

    return 0;
}