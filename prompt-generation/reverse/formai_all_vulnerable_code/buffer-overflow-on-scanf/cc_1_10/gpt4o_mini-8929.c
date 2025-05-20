//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define LIGHTS 8 // Number of lights, we can control 8 lights (0-7)

void displayLights(int lights) {
    printf("Current Light States: \n");
    for (int i = 0; i < LIGHTS; i++) {
        if (lights & (1 << i)) {
            printf("Light %d: ON\n", i);
        } else {
            printf("Light %d: OFF\n", i);
        }
    }
    printf("\n");
}

void toggleLight(int *lights, int lightNumber) {
    if (lightNumber < 0 || lightNumber >= LIGHTS) {
        printf("Invalid light number!\n");
        return;
    }
    *lights ^= (1 << lightNumber); // Toggle the specific light
    printf("Toggled Light %d\n", lightNumber);
}

void turnOnLight(int *lights, int lightNumber) {
    if (lightNumber < 0 || lightNumber >= LIGHTS) {
        printf("Invalid light number!\n");
        return;
    }
    *lights |= (1 << lightNumber); // Turn on the specific light
    printf("Turned ON Light %d\n", lightNumber);
}

void turnOffLight(int *lights, int lightNumber) {
    if (lightNumber < 0 || lightNumber >= LIGHTS) {
        printf("Invalid light number!\n");
        return;
    }
    *lights &= ~(1 << lightNumber); // Turn off the specific light
    printf("Turned OFF Light %d\n", lightNumber);
}

int main() {
    int lights = 0; // Initially, all lights are OFF
    int choice, lightNumber;

    printf("Welcome to the Light Control System!\n");
    printf("You can control %d lights.\n", LIGHTS);
    
    while (1) {
        printf("\nChoose an action:\n");
        printf("1. Display Light States\n");
        printf("2. Toggle a Light\n");
        printf("3. Turn On a Light\n");
        printf("4. Turn Off a Light\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayLights(lights); // Display current states of lights
                break;
            case 2:
                printf("Enter light number to toggle (0-%d): ", LIGHTS - 1);
                scanf("%d", &lightNumber);
                toggleLight(&lights, lightNumber);
                break;
            case 3:
                printf("Enter light number to turn ON (0-%d): ", LIGHTS - 1);
                scanf("%d", &lightNumber);
                turnOnLight(&lights, lightNumber);
                break;
            case 4:
                printf("Enter light number to turn OFF (0-%d): ", LIGHTS - 1);
                scanf("%d", &lightNumber);
                turnOffLight(&lights, lightNumber);
                break;
            case 5:
                printf("Exiting the Light Control System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}