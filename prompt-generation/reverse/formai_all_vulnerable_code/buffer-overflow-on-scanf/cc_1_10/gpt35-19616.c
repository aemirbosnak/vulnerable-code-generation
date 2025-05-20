//FormAI DATASET v1.0 Category: Smart home automation ; Style: protected
#include <stdio.h>
#include <stdbool.h>

// Define constants
#define ON 1
#define OFF 0

int main() {
    // Initialize smart home devices
    int thermostat = 70;
    bool lights_on = false;
    bool security_system_armed = false;
    
    // Display welcome message and instructions
    printf("Welcome to your smart home!\n");
    printf("Type 1 to turn on the lights.\n");
    printf("Type 2 to turn off the lights.\n");
    printf("Type 3 to adjust the thermostat.\n");
    printf("Type 4 to arm or disarm the security system.\n");
    
    // Loop until user decides to exit
    int command = 0;
    while (command != 5) {
        printf("Enter a command: ");
        scanf("%d", &command);
        
        if (command == 1) {
            // Turn on the lights
            lights_on = true;
            printf("Lights turned on.\n");
        }
        else if (command == 2) {
            // Turn off the lights
            lights_on = false;
            printf("Lights turned off.\n");
        }
        else if (command == 3) {
            // Adjust the thermostat
            printf("Enter a new temperature: ");
            scanf("%d", &thermostat);
            printf("Thermostat set to %d degrees.\n", thermostat);
        }
        else if (command == 4) {
            // Arm or disarm the security system
            printf("Enter 1 to arm or 0 to disarm: ");
            int arm_command;
            scanf("%d", &arm_command);
            switch (arm_command) {
                case ON:
                    security_system_armed = true;
                    printf("Security system armed.\n");
                    break;
                case OFF:
                    security_system_armed = false;
                    printf("Security system disarmed.\n");
                    break;
                default:
                    printf("Invalid command.\n");
                    break;
            }
        }
        else {
            printf("Invalid command.\n");
        }
    }
    
    printf("Thank you for using your smart home!\n");
    return 0;
}