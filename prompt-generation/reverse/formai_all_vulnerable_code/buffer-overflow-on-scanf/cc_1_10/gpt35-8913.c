//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to the Wi-Fi signal analyzer program!\n");
    printf("Please enter the name of your Wi-Fi network: ");
    char networkName[20];
    scanf("%s", networkName);

    printf("\nAnalyzing signal strength...\n");
    int signalStrength = rand() % 100 - 20;

    printf("Signal strength for network %s: %d%\n", networkName, signalStrength);

    printf("\n************************ WARNING ************************\n");
    if (signalStrength < 50) {
        char warning[] = "Signal strength is weak! You may experience slow internet speeds or connection issues.";
        printf("%s\n", warning);
    }
    else {
        char caution[] = "Signal strength is strong! Enjoy fast internet speeds and a reliable connection.";
        printf("%s\n", caution);
    }
    printf("*********************************************************\n");

    printf("\nWould you like to view a historical analysis of this network's signal strength? (Y/N) ");
    char response[2];
    scanf("%s", &response);

    // Only proceed with historical analysis if user enters "Y"
    if (strcmp(response, "Y") == 0) {
        printf("\nRetrieving historical signal data for network %s...\n", networkName);

        // Generate random data for past 10 days
        int historicalData[10];
        for (int i = 0; i < 10; i++) {
            historicalData[i] = rand() % 100 - 20;
        }

        // Calculate average signal strength and display to user
        int sum = 0;
        for (int i = 0; i < 10; i++) {
            sum += historicalData[i];
        }
        int average = sum / 10;
        printf("\nAverage signal strength for the past 10 days: %d%\n", average);

        // Display a helpful message based on average signal strength
        if (average < 50) {
            char advice[] = "You may want to consider moving your Wi-Fi router closer to your devices or investing in a Wi-Fi extender.";
            printf("%s\n", advice);
        }
        else {
            char feedback[] = "Your Wi-Fi setup seems to be working well! Keep up the good work.";
            printf("%s\n", feedback);
        }
    }

    printf("\nThank you for using the Wi-Fi signal analyzer program. Have a great day!\n");
    return 0;
}