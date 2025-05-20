//FormAI DATASET v1.0 Category: Smart home automation ; Style: mathematical
#include <stdio.h>
#include <stdbool.h>

int main() {

    bool isLightOn = false;
    bool isDoorOpen = false;

    // User input
    int temperature;
    printf("Enter the current temperature: ");
    scanf("%d", &temperature);
    getchar(); // Consume remaining newline

    // Mathematically determine house condition based on temperature
    bool isHouseWarm = temperature > 72;
    bool isHouseCold = temperature < 68;

    if (isHouseWarm && !isLightOn) {
        printf("Turning on lights...\n");
        isLightOn = true;
    }

    if (isHouseCold && !isDoorOpen) {
        printf("Opening front door...\n");
        isDoorOpen = true;
    }

    // User input
    int motionDetected;
    printf("Is there motion in the house? (0 = no, 1 = yes)");
    scanf("%d", &motionDetected);
    getchar(); // Consume remaining newline

    // Mathematically determine if house is occupied based on motion detected
    bool isHouseOccupied = motionDetected == 1;

    if (
        isHouseOccupied && 
        isHouseCold && 
        !isDoorOpen
    ) {
        printf("Opening front door...\n");
        isDoorOpen = true;
    }

    if (
        isHouseOccupied &&
        !isLightOn
    ) {
        printf("Turning on lights...\n");
        isLightOn = true;
    }

    return 0;
}