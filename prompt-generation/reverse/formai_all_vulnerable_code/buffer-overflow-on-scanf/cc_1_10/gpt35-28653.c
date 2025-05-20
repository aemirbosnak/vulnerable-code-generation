//FormAI DATASET v1.0 Category: Smart home automation ; Style: scientific
#include <stdio.h>

// Function to control the lights
void controlLights(int brightness){
    printf("The lights are at a brightness level of %d.\n", brightness);
}

// Function to control the thermostat
void controlThermostat(int temperature){
    printf("The thermostat has been set to %d degrees Celsius.\n", temperature);
}

// Function to control the security system
void controlSecurity(int status){
    if(status == 1){
        printf("The security system is now armed.\n");
    } else {
        printf("The security system is now disarmed.\n");
    }
}

// Main program
int main(){
    int brightness = 50; // default brightness level
    int temperature = 22; // default temperature
    int status = 0; // 0 for disarmed, 1 for armed

    printf("Welcome to the Smart Home Automation system!\n");

    // User menu
    while(1){
        int choice;
        printf("Please choose an option:\n");
        printf("1 - Control lights\n");
        printf("2 - Control thermostat\n");
        printf("3 - Control security system\n");
        printf("4 - Quit\n");

        scanf("%d", &choice); // Get user choice

        if(choice == 1){
            printf("Please enter a brightness level (0-100): ");
            scanf("%d", &brightness);
            controlLights(brightness);
        } else if(choice == 2) {
            printf("Please enter a temperature level (in degrees Celsius): ");
            scanf("%d", &temperature);
            controlThermostat(temperature);
        } else if(choice == 3) {
            printf("Please enter 1 to arm or 0 to disarm security system: ");
            scanf("%d", &status);
            controlSecurity(status);
        } else if(choice == 4) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}