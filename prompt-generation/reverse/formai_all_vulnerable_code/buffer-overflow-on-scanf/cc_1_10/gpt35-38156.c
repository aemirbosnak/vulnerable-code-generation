//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIGNAL_STRENGTH 100
#define MIN_SIGNAL_STRENGTH 0

// function to calculate the signal quality based on its strength
int calculateSignalQuality(int signalStrength) {
    if(signalStrength <= MIN_SIGNAL_STRENGTH) {
        return 0;
    } else if(signalStrength >= MAX_SIGNAL_STRENGTH) {
        return 100;
    }

    return signalStrength;
}

int main() {
    char* ssid = malloc(sizeof(char) * 256);
    int signalStrength = 0;
    bool isConnected = false;

    printf("Wi-Fi Signal Strength Analyzer\n\n");

    while(true) {
        // ask for the SSID
        printf("Enter Wi-Fi SSID: ");
        fgets(ssid, 256, stdin);
        ssid = strtok(ssid, "\n");

        // check if the user wants to exit
        if(strcmp(ssid, "exit") == 0) {
            break;
        }

        // check if the user is currently connected to the SSID
        printf("Are you currently connected to \"%s\"? (y/n): ", ssid);
        char connected = getchar();

        // clear the input buffer
        while ((getchar()) != '\n');

        if(connected == 'y' || connected == 'Y') {
            printf("Enter the current signal strength (between 0-100): ");
            scanf("%d", &signalStrength);

            // clear the input buffer
            while ((getchar()) != '\n');

            isConnected = true;

            printf("\nSignal Quality for \"%s\": %d%%\n", ssid, calculateSignalQuality(signalStrength));
        } else if (connected == 'n' || connected == 'N') {
            isConnected = false;

            printf("\nSignal Quality for \"%s\": Disconnected\n", ssid);
        } else {
            printf("Invalid input. Please try again.\n");
        }

        printf("\n");
    }

    printf("Exiting Wi-Fi Signal Strength Analyzer...\n");

    return 0;
}