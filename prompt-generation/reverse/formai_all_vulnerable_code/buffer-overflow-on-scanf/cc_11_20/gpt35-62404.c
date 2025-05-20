//FormAI DATASET v1.0 Category: Smart home automation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    // Initialize smart home appliances
    bool lightsOn = false;
    bool tvOn = false;
    bool airConditionerOn = false;
    int temperature = 25;
    bool windowOpen = false;
    bool doorLocked = true;

    printf("Welcome to your smart home automation system.\n");

    // Loop through the program until the user decides to quit
    while (true) {
        printf("\nPlease select an option:\n");
        printf("1. Turn lights on/off\n");
        printf("2. Turn TV on/off\n");
        printf("3. Turn air conditioner on/off\n");
        printf("4. Control temperature\n");
        printf("5. Open/close window\n");
        printf("6. Lock/unlock door\n");
        printf("7. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (lightsOn) {
                    printf("Turning lights off.\n");
                    lightsOn = false;
                } else {
                    printf("Turning lights on.\n");
                    lightsOn = true;
                }
                break;
            case 2:
                if (tvOn) {
                    printf("Turning TV off.\n");
                    tvOn = false;
                } else {
                    printf("Turning TV on.\n");
                    tvOn = true;
                }
                break;
            case 3:
                if (airConditionerOn) {
                    printf("Turning air conditioner off.\n");
                    airConditionerOn = false;
                } else {
                    printf("Turning air conditioner on.\n");
                    airConditionerOn = true;
                }
                break;
            case 4:
                printf("Enter temperature (16-30): ");
                scanf("%d", &temperature);
                if (temperature < 16 || temperature > 30) {
                    printf("Invalid temperature selected.\n");
                } else {
                    printf("Setting temperature to %d. \n", temperature);
                }
                break;
            case 5:
                if (windowOpen) {
                    printf("Closing window.\n");
                    windowOpen = false;
                } else {
                    printf("Opening window.\n");
                    windowOpen = true;
                }
                break;
            case 6:
                if (doorLocked) {
                    printf("Unlocking door.\n");
                    doorLocked = false;
                } else {
                    printf("Locking door.\n");
                    doorLocked = true;
                }
                break;
            case 7:
                printf("Exiting program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}