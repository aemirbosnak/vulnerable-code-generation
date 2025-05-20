//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random signal strength
int generateSignalStrength() {
    return (rand() % 100) - 50;
}

// Function to print signal strength in graphical form
void printSignalGraph(int signalStrength) {
    printf("\nSignal Strength: %ddBm\n", signalStrength);
    if (signalStrength >= 80) {
        printf("[==========]\n");
    } else if (signalStrength >= 70) {
        printf("[========= ]\n");
    } else if (signalStrength >= 60) {
        printf("[========  ]\n");
    } else if (signalStrength >= 50) {
        printf("[=======   ]\n");
    } else if (signalStrength >= 40) {
        printf("[======    ]\n");
    } else if (signalStrength >= 30) {
        printf("[=====     ]\n");
    } else if (signalStrength >= 20) {
        printf("[====      ]\n");
    } else if (signalStrength >= 10) {
        printf("[===       ]\n");
    } else if (signalStrength >= 0) {
        printf("[==        ]\n");
    } else {
        printf("[          ]\n");
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator with current time
    
    int signalStrength = generateSignalStrength();
    printSignalGraph(signalStrength);
    
    char choice;
    do {
        printf("\nWould you like to refresh the signal strength? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'y') {
            signalStrength = generateSignalStrength();
            printSignalGraph(signalStrength);
        }
    } while (choice != 'n');
    
    printf("\nExiting Wi-Fi Signal Strength Analyzer...\n");
    return 0;
}