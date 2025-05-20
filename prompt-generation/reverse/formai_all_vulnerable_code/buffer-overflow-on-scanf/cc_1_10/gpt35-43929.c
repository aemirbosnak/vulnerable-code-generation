//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: multiplayer
#include <stdio.h>

#define MAX_DEVICES 10
#define MIN_SIGNAL -100
#define MAX_SIGNAL 0

int main() {
    int devices[MAX_DEVICES] = {0};
    int numDevices = 0;
    int signalStrength;
    int userChoice;
    int i;

    // Input number of devices
    printf("Enter the number of devices: ");
    scanf("%d", &numDevices);

    // Input signal strengths for each device
    for (i = 0; i < numDevices; i++) {
        printf("Enter signal strength for device %d (between -100 and 0): ", i+1);
        scanf("%d", &signalStrength);

        while (signalStrength < MIN_SIGNAL || signalStrength > MAX_SIGNAL) {
            printf("Invalid signal strength. Please enter a value between -100 and 0: ");
            scanf("%d", &signalStrength);
        }

        devices[i] = signalStrength;
    }

    // Menu for user to select options
    do {
        printf("\nMenu\n");
        printf("1 - View all signal strengths\n");
        printf("2 - View average signal strength\n");
        printf("3 - Quit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &userChoice);

        switch (userChoice) {
            case 1:
                printf("\nAll signal strengths:\n");
                for (i = 0; i < numDevices; i++) {
                    printf("Device %d: %d dBm\n", i+1, devices[i]);
                }
                break;

            case 2:
                printf("\nAverage signal strength: ");
                int sum = 0;
                for (i = 0; i < numDevices; i++) {
                    sum += devices[i];
                }
                float average = (float) sum / numDevices;
                printf("%.2f dBm\n", average);
                break;

            case 3:
                printf("\nGoodbye!\n");
                break;

            default:
                printf("\nInvalid choice. Try again.\n");
                break;
        }
    } while (userChoice != 3);

    return 0;
}