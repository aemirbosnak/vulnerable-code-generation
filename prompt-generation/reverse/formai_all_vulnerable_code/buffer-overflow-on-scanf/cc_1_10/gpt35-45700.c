//FormAI DATASET v1.0 Category: Smart home automation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    // Initialize smart devices
    bool lights = false;
    bool thermostat = false;
    
    printf("Welcome to Smart Home Automation!\n");
    
    while (true) {
        printf("\nSelect an option:\n");
        printf("1. Turn on/off lights\n");
        printf("2. Adjust thermostat temperature\n");
        printf("3. Exit\n");
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                // Toggle lights
                lights = !lights;
                if (lights) {
                    printf("Lights turned on!\n");
                } else {
                    printf("Lights turned off!\n");
                }
                break;
            case 2:
                // Adjust thermostat temperature
                printf("Enter desired temperature: ");
                int temperature;
                scanf("%d", &temperature);
                
                if (temperature < 60) {
                    printf("Temperature too low. Adjusting to minimum value (60)...\n");
                    temperature = 60;
                } else if (temperature > 80) {
                    printf("Temperature too high. Adjusting to maximum value (80)...\n");
                    temperature = 80;
                }
                
                thermostat = true;
                printf("Thermostat set to %d degrees Fahrenheit.\n", temperature);
                break;
            case 3:
                // Exit program
                printf("Exiting Smart Home Automation...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}