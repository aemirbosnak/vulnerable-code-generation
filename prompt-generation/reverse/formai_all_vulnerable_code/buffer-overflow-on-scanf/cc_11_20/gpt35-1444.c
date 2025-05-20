//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    int signalStrength, numPoints = 0, totalStrength = 0;
    char response[10];
    
    printf("Welcome to Wi-Fi Signal Strength Analyzer!\n");
    
    do {
        printf("Enter signal strength (0-100): ");
        scanf("%d", &signalStrength);
        while (signalStrength < 0 || signalStrength > 100) {
            printf("Invalid signal strength. Please enter again: ");
            scanf("%d", &signalStrength);
        }
        numPoints++;
        totalStrength += signalStrength;
        
        printf("Do you want to enter another signal strength? (y/n): ");
        scanf("%s", response);
        while (strcmp(response, "y") != 0 && strcmp(response, "n") != 0) {
            printf("Invalid response. Please enter again (y/n): ");
            scanf("%s", response);
        }
    } while (strcmp(response, "y") == 0);
    
    double avgStrength = (double)totalStrength / (double)numPoints;
    double variance = 0;
    double stdDeviation = 0;
    
    printf("\n*** Wi-Fi Signal Strength Analysis ***\n");
    printf("Number of data points: %d\n", numPoints);
    printf("Average signal strength: %.2lf\n", avgStrength);
    
    for (int i = 0; i < numPoints; i++) {
        printf("Enter signal strength #%d: ", i+1);
        scanf("%d", &signalStrength);
        while (signalStrength < 0 || signalStrength > 100) {
            printf("Invalid signal strength. Please enter again: ");
            scanf("%d", &signalStrength);
        }
        variance += pow(signalStrength - avgStrength, 2);
    }
    
    variance = variance / numPoints;
    stdDeviation = sqrt(variance);
    
    printf("Standard deviation: %.2lf\n", stdDeviation);
    
    if (avgStrength > 70) {
        printf("Signal strength is excellent.\n");
    } else if (avgStrength > 50) {
        printf("Signal strength is good.\n");
    } else if (avgStrength > 30) {
        printf("Signal strength is fair.\n");
    } else {
        printf("Signal strength is poor.\n");
    }
    
    return 0;
}