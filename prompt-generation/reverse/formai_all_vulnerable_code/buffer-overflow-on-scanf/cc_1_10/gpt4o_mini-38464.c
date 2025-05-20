//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Lighting control
typedef struct {
    int brightness; // 0 to 100
    char color[20]; // Light color
} Light;

// Thermostat control
typedef struct {
    int temperature; // in Fahrenheit
} Thermostat;

// Security system
typedef struct {
    int isArmed; // 0: disarmed, 1: armed
} Security;

// Smart Home structure
typedef struct {
    Light livingRoomLight;
    Thermostat homeThermostat;
    Security homeSecurity;
} SmartHome;

// Function to initialize the smart home
void initializeSmartHome(SmartHome *home) {
    home->livingRoomLight.brightness = 50; // Default brightness
    strcpy(home->livingRoomLight.color, "Warm White");
    home->homeThermostat.temperature = 72; // Default temperature
    home->homeSecurity.isArmed = 0; // Start disarmed
}

// Function to adjust brightness
void adjustBrightness(SmartHome *home, int brightness) {
    if (brightness >= 0 && brightness <= 100) {
        home->livingRoomLight.brightness = brightness;
        printf("Living Room Light Brightness set to: %d%%\n", brightness);
    } else {
        printf("Error: Brightness value must be between 0 and 100.\n");
    }
}

// Function to change light color
void changeLightColor(SmartHome *home, const char *color) {
    strcpy(home->livingRoomLight.color, color);
    printf("Living Room Light Color changed to: %s\n", color);
}

// Function to set thermostat temperature
void setTemperature(SmartHome *home, int temperature) {
    home->homeThermostat.temperature = temperature;
    printf("Thermostat Temperature set to: %d°F\n", temperature);
}

// Function to arm/disarm the security system
void toggleSecurity(SmartHome *home) {
    home->homeSecurity.isArmed = !home->homeSecurity.isArmed;
    if (home->homeSecurity.isArmed) {
        printf("Security system armed.\n");
    } else {
        printf("Security system disarmed.\n");
    }
}

// Function to display the current smart home status
void displayStatus(SmartHome *home) {
    printf("\n--- Smart Home Status ---\n");
    printf("Living Room Light - Brightness: %d%%, Color: %s\n", 
        home->livingRoomLight.brightness, home->livingRoomLight.color);
    printf("Thermostat - Temperature: %d°F\n", home->homeThermostat.temperature);
    printf("Security Status: %s\n", 
        home->homeSecurity.isArmed ? "Armed" : "Disarmed");
    printf("--------------------------\n\n");
}

// Main function
int main() {
    SmartHome myHome;
    initializeSmartHome(&myHome);
    displayStatus(&myHome);

    int choice, value;
    char color[20];
    
    while (1) {
        printf("Smart Home Control Menu:\n");
        printf("1. Adjust Brightness\n");
        printf("2. Change Light Color\n");
        printf("3. Set Thermostat Temperature\n");
        printf("4. Toggle Security\n");
        printf("5. Display Status\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter brightness (0-100): ");
                scanf("%d", &value);
                adjustBrightness(&myHome, value);
                break;
            case 2:
                printf("Enter light color: ");
                scanf("%s", color);
                changeLightColor(&myHome, color);
                break;
            case 3:
                printf("Enter thermostat temperature (F): ");
                scanf("%d", &value);
                setTemperature(&myHome, value);
                break;
            case 4:
                toggleSecurity(&myHome);
                break;
            case 5:
                displayStatus(&myHome);
                break;
            case 6:
                printf("Exiting Smart Home Control.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}