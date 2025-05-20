//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LIGHT_LEVEL 100
#define MIN_TEMPERATURE 15
#define MAX_TEMPERATURE 30

typedef struct {
    int temperature;
    int lightLevel;
} SmartHomeState;

// Function prototypes
void initializeHomeState(SmartHomeState *home);
void displayHomeState(const SmartHomeState *home);
void updateTemperature(SmartHomeState *home);
void adjustLighting(SmartHomeState *home);
void simulateExternalConditions(SmartHomeState *home);

int main() {
    SmartHomeState myHome;
    initializeHomeState(&myHome);
    
    int choice;
    
    while (1) {
        printf("\nSmart Home Automation System\n");
        printf("1. Display Current Home State\n");
        printf("2. Update Temperature\n");
        printf("3. Adjust Lighting\n");
        printf("4. Simulate External Conditions\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                displayHomeState(&myHome);
                break;
            case 2:
                updateTemperature(&myHome);
                break;
            case 3:
                adjustLighting(&myHome);
                break;
            case 4:
                simulateExternalConditions(&myHome);
                break;
            case 5:
                printf("Exiting the Smart Home Automation System.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

/* This function initializes the smart home state */
void initializeHomeState(SmartHomeState *home) {
    home->temperature = 22; // Default room temperature
    home->lightLevel = 50; // Default light level 
    printf("Smart home initialized with default settings.\n");
}

/* Display the current state of the smart home */
void displayHomeState(const SmartHomeState *home) {
    printf("Current Temperature: %d°C\n", home->temperature);
    printf("Current Light Level: %d%%\n", home->lightLevel);
}

/* Update the temperature based on user input within a valid range */
void updateTemperature(SmartHomeState *home) {
    int newTemperature;
    printf("Enter new temperature (%d to %d): ", MIN_TEMPERATURE, MAX_TEMPERATURE);
    scanf("%d", &newTemperature);
    
    if (newTemperature >= MIN_TEMPERATURE && newTemperature <= MAX_TEMPERATURE) {
        home->temperature = newTemperature;
        printf("Temperature updated to %d°C\n", home->temperature);
    } else {
        printf("Error: Temperature must be between %d and %d.\n", MIN_TEMPERATURE, MAX_TEMPERATURE);
    }
}

/* Adjust the lighting based on user input within a valid range */
void adjustLighting(SmartHomeState *home) {
    int newLightLevel;
    printf("Enter new light level (0 to %d): ", MAX_LIGHT_LEVEL);
    scanf("%d", &newLightLevel);
    
    if (newLightLevel >= 0 && newLightLevel <= MAX_LIGHT_LEVEL) {
        home->lightLevel = newLightLevel;
        printf("Light level updated to %d%%\n", home->lightLevel);
    } else {
        printf("Error: Light level must be between 0 and %d.\n", MAX_LIGHT_LEVEL);
    }
}

/* Simulate external conditions affecting temperature and lighting */
void simulateExternalConditions(SmartHomeState *home) {
    srand(time(NULL));
    int externalTemperatureChange = (rand() % 5) - 2; // Random change between -2 to 2
    int externalLightChange = (rand() % 11) - 5; // Random change between -5 to 5
    
    home->temperature += externalTemperatureChange;
    home->lightLevel += externalLightChange;

    // Clamp values to stay within bounds
    if (home->temperature < MIN_TEMPERATURE) home->temperature = MIN_TEMPERATURE;
    if (home->temperature > MAX_TEMPERATURE) home->temperature = MAX_TEMPERATURE;
    if (home->lightLevel < 0) home->lightLevel = 0;
    if (home->lightLevel > MAX_LIGHT_LEVEL) home->lightLevel = MAX_LIGHT_LEVEL;

    printf("Simulation complete! New conditions: Temperature: %d°C, Light Level: %d%%\n", home->temperature, home->lightLevel);
}