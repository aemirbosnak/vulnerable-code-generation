//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 100
#define ON 1
#define OFF 0

typedef struct {
    int lightStatus;
    int thermostatTemperature;
    int securityStatus;
} SmartHome;

void displayMenu() {
    printf("\n=== Smart Home Automation System ===\n");
    printf("1. Toggle Lights\n");
    printf("2. Set Thermostat\n");
    printf("3. Toggle Security System\n");
    printf("4. Show Status\n");
    printf("5. Exit\n");
    printf("===================================\n");
    printf("Choose an option: ");
}

void toggleLights(SmartHome *home) {
    home->lightStatus = !home->lightStatus;
    printf("Lights are now %s.\n", home->lightStatus ? "ON" : "OFF");
}

void setThermostat(SmartHome *home) {
    int temp;
    printf("Enter desired temperature: ");
    scanf("%d", &temp);
    home->thermostatTemperature = temp;
    printf("Thermostat set to %d degrees.\n", temp);
}

void toggleSecurity(SmartHome *home) {
    home->securityStatus = !home->securityStatus;
    printf("Security system is now %s.\n", home->securityStatus ? "ARMED" : "DISARMED");
}

void showStatus(SmartHome *home) {
    printf("\n=== Current System Status ===\n");
    printf("Lights: %s\n", home->lightStatus ? "ON" : "OFF");
    printf("Thermostat: %d degrees\n", home->thermostatTemperature);
    printf("Security System: %s\n", home->securityStatus ? "ARMED" : "DISARMED");
    printf("==============================\n");
}

int main() {
    SmartHome myHome = {OFF, 72, OFF};
    char input[MAX_INPUT];
    
    while (1) {
        displayMenu();
        fgets(input, sizeof(input), stdin);
        
        int choice = atoi(input);
        
        switch (choice) {
            case 1:
                toggleLights(&myHome);
                break;
            case 2:
                setThermostat(&myHome);
                break;
            case 3:
                toggleSecurity(&myHome);
                break;
            case 4:
                showStatus(&myHome);
                break;
            case 5:
                printf("Exiting Smart Home Automation System. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}