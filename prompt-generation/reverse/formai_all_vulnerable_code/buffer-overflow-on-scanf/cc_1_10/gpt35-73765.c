//FormAI DATASET v1.0 Category: Temperature monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define THRESHOLD_TEMP 30.0f
// Threshold temperature to turn on the cooling system

// Function declarations
bool is_temperature_above_threshold(float currentTemp);
void turn_cooling_system_on_or_off(bool turnOn);

int main() {
    float currentTemperature = 29.5f; // initial temperature
    char userChoice;

    printf("Temperature Monitor: Enter 'q' to quit.\n");

    while(true) {
        printf("Current Temperature: %.1fC\n", currentTemperature);
        if(is_temperature_above_threshold(currentTemperature)) {
            printf("ALERT: Temperature too high - cooling system will be turned on.\n");
            turn_cooling_system_on_or_off(true);
        } else {
            printf("Temperature is in the safe range.\n");
            turn_cooling_system_on_or_off(false);
        }

        printf("Enter a new temperature or 'q' to quit: ");
        scanf("%f", &currentTemperature);
        if(currentTemperature == 'q') {
            break;
        }
    }

    printf("Exiting Temperature Monitor...\n");

    return 0;
}

bool is_temperature_above_threshold(float currentTemp) {
    if(currentTemp > THRESHOLD_TEMP) {
        return true;
    } else {
        return false;
    }
}

void turn_cooling_system_on_or_off(bool turnOn) {
    if(turnOn) {
        printf("Cooling system turned on.\n");
    } else {
        printf("Cooling system turned off.\n");
    }
}