//FormAI DATASET v1.0 Category: Smart home automation ; Style: detailed
#include<stdio.h>
#include<stdlib.h>

// Function to turn on/off the light
void toggleLight(int *state) {
    if (*state == 0) {
        printf("Turning on the light\n");
        *state = 1;
    } else {
        printf("Turning off the light\n");
        *state = 0;
    }
}

// Function to turn on/off the fan
void toggleFan(int *state) {
    if (*state == 0) {
        printf("Turning on the fan\n");
        *state = 1;
    } else {
        printf("Turning off the fan\n");
        *state = 0;
    }
}

// Function to adjust the temperature
void adjustTemperature(float *temperature, float adjustment) {
    printf("Current temperature is %.2f degrees Celsius\n", *temperature);
    *temperature += adjustment;
    printf("Adjusting temperature to %.2f degrees Celsius\n", *temperature);
}

int main() {
    int light_state = 0; // 0 for off, 1 for on
    int fan_state = 0; // 0 for off, 1 for on
    float temperature = 25.0; // Initial temperature set to 25 degrees Celsius
    
    printf("Welcome to Smart Home Automation System\n");
    
    while (1) { // Main loop of the program
        printf("\nPress 1 to toggle light\n");
        printf("Press 2 to toggle fan\n");
        printf("Press 3 to adjust temperature up by 1 degree\n");
        printf("Press 4 to adjust temperature down by 1 degree\n");
        printf("Press 0 to exit\n");
        
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 0:
                printf("Exiting Smart Home Automation System\n");
                exit(0);
            case 1:
                toggleLight(&light_state);
                break;
            case 2:
                toggleFan(&fan_state);
                break;
            case 3:
                adjustTemperature(&temperature, 1.0);
                break;
            case 4:
                adjustTemperature(&temperature, -1.0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    
    return 0;
}