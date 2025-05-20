//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    char wifiName[100];
    int signalStrength;
    bool connectionStatus = false;

    printf("Welcome to Wi-Fi Signal Strength Analyzer!\n\n");

    // Prompt the user to enter the Wi-Fi name
    printf("Please enter the name of the Wi-Fi you want to check the signal strength for: ");
    fgets(wifiName, 100, stdin);
    wifiName[strcspn(wifiName, "\n")] = '\0';

    // Prompt the user to enter the signal strength
    printf("Enter the signal strength (out of 100): ");
    scanf("%d", &signalStrength);

    // Check if the signal strength is valid
    if (signalStrength < 0 || signalStrength > 100)
    {
        printf("Invalid signal strength. Please enter a number between 0 and 100.\n");
        return 0;
    }

    // Check if the connection status is valid
    printf("Is the connection status active? (Y/N)");
    char connectionStatusInput;
    scanf(" %c", &connectionStatusInput);
    if (connectionStatusInput == 'Y' || connectionStatusInput == 'y')
    {
        connectionStatus = true;
    }
    else if (connectionStatusInput == 'N' || connectionStatusInput == 'n')
    {
        connectionStatus = false;
    }
    else
    {
        printf("Invalid connection status. Please enter Y or N.\n");
        return 0;
    }

    // Print the results
    printf("\n------------\n");
    printf("Wi-Fi name: %s\n", wifiName);
    printf("Signal strength: %d/100\n", signalStrength);
    if (connectionStatus)
    {
        printf("Connection status: Active\n");
    }
    else
    {
        printf("Connection status: Inactive\n");
    }

    return 0;
}