//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants
#define LIGHT_ON 1
#define LIGHT_OFF 0
#define TEMP_THRESHOLD 22
#define SECURITY_ARMED 1
#define SECURITY_DISARMED 0

// Smart Home Structure
typedef struct {
    int light_status;
    int temperature;
    int security_status;
} SmartHome;

// Function Prototypes
void toggleLight(SmartHome *home);
void setTemperature(SmartHome *home, int temp);
void armSecurity(SmartHome *home);
void disarmSecurity(SmartHome *home);
void displayStatus(SmartHome home);

int main() {
    SmartHome myHome = {LIGHT_OFF, 20, SECURITY_DISARMED};
    time_t t;
    
    srand((unsigned) time(&t));  // Seed for random temperature

    while (1) {
        int choice;

        printf("\n--- Smart Home Control Panel ---\n");
        printf("1. Toggle Light\n");
        printf("2. Set Temperature\n");
        printf("3. Arm Security\n");
        printf("4. Disarm Security\n");
        printf("5. Display Status\n");
        printf("6. Exit\n");
        printf("Choose an option (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                toggleLight(&myHome);
                break;
            case 2:
                {
                    int newTemp = (rand() % 10) + 15; // Simulate random temperature between 15 to 24
                    setTemperature(&myHome, newTemp);
                    printf("Temperature set to %d °C.\n", newTemp);
                    break;
                }
            case 3:
                armSecurity(&myHome);
                break;
            case 4:
                disarmSecurity(&myHome);
                break;
            case 5:
                displayStatus(myHome);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void toggleLight(SmartHome *home) {
    home->light_status = (home->light_status == LIGHT_ON) ? LIGHT_OFF : LIGHT_ON;
    printf("Light is now %s.\n", (home->light_status == LIGHT_ON) ? "ON" : "OFF");
}

void setTemperature(SmartHome *home, int temp) {
    home->temperature = temp;
    if (temp > TEMP_THRESHOLD) {
        printf("It's warm! Consider cooling down your home.\n");
    } else {
        printf("Temperature is comfortable.\n");
    }
}

void armSecurity(SmartHome *home) {
    home->security_status = SECURITY_ARMED;
    printf("Security system is ARMED.\n");
}

void disarmSecurity(SmartHome *home) {
    home->security_status = SECURITY_DISARMED;
    printf("Security system is DISARMED.\n");
}

void displayStatus(SmartHome home) {
    printf("\n--- Current Status ---\n");
    printf("Light: %s\n", (home.light_status == LIGHT_ON) ? "ON" : "OFF");
    printf("Temperature: %d °C\n", home.temperature);
    printf("Security Status: %s\n", (home.security_status == SECURITY_ARMED) ? "ARMED" : "DISARMED");
    printf("----------------------\n");
}