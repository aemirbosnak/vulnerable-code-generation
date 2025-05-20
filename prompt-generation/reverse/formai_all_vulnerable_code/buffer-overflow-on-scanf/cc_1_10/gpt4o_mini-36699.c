//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define TOTAL_LIGHTS 16 // Total number of lights (represented by bits)

// Function to toggle a light
void toggleLight(int *lights, int lightNumber) {
    if (lightNumber < 0 || lightNumber >= TOTAL_LIGHTS) {
        printf("Invalid light number! Must be between 0 and %d.\n", TOTAL_LIGHTS - 1);
        return;
    }
    *lights ^= (1 << lightNumber);
    printf("Light %d toggled!\n", lightNumber);
}

// Function to check the status of a light
void checkLightStatus(int lights, int lightNumber) {
    if (lightNumber < 0 || lightNumber >= TOTAL_LIGHTS) {
        printf("Invalid light number! Must be between 0 and %d.\n", TOTAL_LIGHTS - 1);
        return;
    }
    printf("Light %d is %s.\n", lightNumber, (lights & (1 << lightNumber)) ? "ON" : "OFF");
}

// Function to count how many lights are on
int countLightsOn(int lights) {
    int count = 0;
    for (int i = 0; i < TOTAL_LIGHTS; i++) {
        count += (lights & (1 << i)) ? 1 : 0;
    }
    return count;
}

// Function to display the current status of all lights
void displayAllLights(int lights) {
    printf("Current status of all lights:\n");
    for (int i = 0; i < TOTAL_LIGHTS; i++) {
        printf("Light %d: %s\n", i, (lights & (1 << i)) ? "ON" : "OFF");
    }
}

int main() {
    int lights = 0; // All lights are initially OFF
    int choice, lightNumber;
    
    do {
        printf("\n--- Mystic Light Switch System ---\n");
        printf("1. Toggle Light\n");
        printf("2. Check Light Status\n");
        printf("3. Count Lights ON\n");
        printf("4. Display All Lights Status\n");
        printf("5. Exit\n");
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter light number to toggle (0-%d): ", TOTAL_LIGHTS - 1);
                scanf("%d", &lightNumber);
                toggleLight(&lights, lightNumber);
                break;
            case 2:
                printf("Enter light number to check (0-%d): ", TOTAL_LIGHTS - 1);
                scanf("%d", &lightNumber);
                checkLightStatus(lights, lightNumber);
                break;
            case 3:
                printf("Number of lights ON: %d\n", countLightsOn(lights));
                break;
            case 4:
                displayAllLights(lights);
                break;
            case 5:
                printf("Exiting the Mystic Light Switch System. Farewell!\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}