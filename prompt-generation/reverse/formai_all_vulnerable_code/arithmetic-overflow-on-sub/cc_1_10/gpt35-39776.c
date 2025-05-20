//FormAI DATASET v1.0 Category: Smart home light control ; Style: recursive
#include <stdio.h>
#include <stdbool.h>

int switchLamp(int bulbNum, bool isOn) {
    if (isOn) {
        printf("Bulb %d is now turned on.\n", bulbNum);
    } else {
        printf("Bulb %d is now turned off.\n", bulbNum);
    }
    return 0;
}

int turnOnAllLamps(int numLamps) {
    if (numLamps == 1) {
        switchLamp(numLamps, true);
    } else {
        turnOnAllLamps(numLamps-1);
        switchLamp(numLamps, true);
    }
    return 0;
}

int turnOffAllLamps(int numLamps) {
    if (numLamps == 1) {
        switchLamp(numLamps, false);
    } else {
        switchLamp(numLamps, false);
        turnOffAllLamps(numLamps-1);
    }
    return 0;
}

int main() {
    int numLamps, option;
    bool isOn;

    printf("Enter the number of lamps in the house: ");
    scanf("%d", &numLamps);

    printf("\n--- Menu ---");
    printf("\n1. Turn on all lamps");
    printf("\n2. Turn off all lamps");
    printf("\n3. Exit");

    do {
        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                turnOnAllLamps(numLamps);
                break;

            case 2:
                turnOffAllLamps(numLamps);
                break;

            case 3:
                printf("\nExiting program...");
                break;

            default:
                printf("\nInvalid option. Please try again.");
        }

    } while(option != 3);

    return 0;
}