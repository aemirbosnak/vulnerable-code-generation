//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* Define constants for signal strength */
#define EXCELLENT 80
#define GOOD 60
#define FAIR 40
#define POOR 20

/* Define function to calculate signal strength */
int getSignalStrength(int signalQuality) {
    if (signalQuality >= EXCELLENT) {
        return 4;
    } else if (signalQuality >= GOOD) {
        return 3;
    } else if (signalQuality >= FAIR) {
        return 2;
    } else if (signalQuality >= POOR) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int signalQuality; /* Signal quality in dBm */

    /* Prompt user for signal quality */
    printf("Enter Signal Quality (in dBm): ");
    scanf("%d", &signalQuality);

    /* Calculate signal strength */
    int signalStrength = getSignalStrength(signalQuality);

    /* Display signal strength */
    switch (signalStrength) {
        case 4:
            printf("Signal Strength: Excellent\n");
            break;
        case 3:
            printf("Signal Strength: Good\n");
            break;
        case 2:
            printf("Signal Strength: Fair\n");
            break;
        case 1:
            printf("Signal Strength: Poor\n");
            break;
        default:
            printf("Signal Strength: No Signal\n");
            break;
    }

    return 0;
}