//FormAI DATASET v1.0 Category: Smart home automation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    bool isLightsOn = false;
    bool isDoorLocked = true;
    bool isACOn = false;

    printf("Welcome to Smart Home Automation System!\n");

    while (true) {
        int choice;
        printf("\nPlease select an option:\n"
                "1. Turn lights on/off\n"
                "2. Lock/Unlock door\n"
                "3. Turn AC on/off\n"
                "4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isLightsOn) {
                    printf("Turning lights off.\n");
                    isLightsOn = false;
                } else {
                    printf("Turning lights on.\n");
                    isLightsOn = true;
                }
                break;
            case 2:
                if (isDoorLocked) {
                    printf("Unlocking door.\n");
                    isDoorLocked = false;
                } else {
                    printf("Locking door.\n");
                    isDoorLocked = true;
                }
                break;
            case 3:
                if (isACOn) {
                    printf("Turning AC off.\n");
                    isACOn = false;
                } else {
                    printf("Turning AC on.\n");
                    isACOn = true;
                }
                break;
            case 4:
                printf("Exiting Smart Home Automation System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}