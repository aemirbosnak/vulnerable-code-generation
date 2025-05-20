//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void controlLights();
void controlTemperature();
void controlSecurity();

int main() {
    int choice;
    
    while (1) {
        printf("\n================== Smart Home Automation System ==================\n");
        printf("1. Control Lights\n");
        printf("2. Control Temperature\n");
        printf("3. Control Security System\n");
        printf("4. Exit\n");
        printf("=================================================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                controlLights();
                break;
            case 2:
                controlTemperature();
                break;
            case 3:
                controlSecurity();
                break;
            case 4:
                printf("Exiting the Smart Home Automation System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}

void controlLights() {
    char action[10];
    printf("\nControl Lights:\n");
    printf("Enter 'on' to turn on the lights or 'off' to turn them off: ");
    scanf("%s", action);
    
    if (strcmp(action, "on") == 0) {
        printf("The lights have been turned on!\n");
    } else if (strcmp(action, "off") == 0) {
        printf("The lights have been turned off!\n");
    } else {
        printf("Invalid action! Please enter 'on' or 'off'.\n");
    }
}

void controlTemperature() {
    int temperature;
    printf("\nControl Temperature:\n");
    printf("Enter the desired temperature setting (e.g., 22 for 22 degrees): ");
    scanf("%d", &temperature);
    
    if (temperature >= 15 && temperature <= 30) {
        printf("The temperature has been set to %d degrees Celsius.\n", temperature);
    } else {
        printf("Invalid temperature setting! Please set a temperature between 15 and 30 degrees Celsius.\n");
    }
}

void controlSecurity() {
    char action[10];
    printf("\nControl Security System:\n");
    printf("Enter 'activate' to activate the security system or 'deactivate' to turn it off: ");
    scanf("%s", action);
    
    if (strcmp(action, "activate") == 0) {
        printf("The security system has been activated! Your home is now secure.\n");
    } else if (strcmp(action, "deactivate") == 0) {
        printf("The security system has been deactivated! You are now vulnerable.\n");
    } else {
        printf("Invalid action! Please enter 'activate' or 'deactivate'.\n");
    }
}