//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

#define MAX_LIGHTS 10

typedef struct {
    char name[20];
    int isOn;
} SmartLight;

typedef struct {
    int temperature;
} Thermostat;

void initializeLights(SmartLight lights[], int count) {
    for (int i = 0; i < count; i++) {
        snprintf(lights[i].name, sizeof(lights[i].name), "Light %d", i + 1);
        lights[i].isOn = 0; // Initially off
    }
}

void turnLightOn(SmartLight *light) {
    light->isOn = 1;
    printf("%s is turned ON.\n", light->name);
}

void turnLightOff(SmartLight *light) {
    light->isOn = 0;
    printf("%s is turned OFF.\n", light->name);
}

void toggleLight(SmartLight *light) {
    if (light->isOn) {
        turnLightOff(light);
    } else {
        turnLightOn(light);
    }
}

void displayLights(SmartLight lights[], int count) {
    printf("\nSmart Lights Status:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %s\n", lights[i].name, lights[i].isOn ? "ON" : "OFF");
    }
}

void setThermostat(Thermostat *thermostat, int temp) {
    thermostat->temperature = temp;
    printf("Thermostat set to %d degrees.\n", temp);
}

void displayThermostatStatus(Thermostat *thermostat) {
    printf("Current Thermostat Temperature: %d degrees.\n", thermostat->temperature);
}

int main() {
    SmartLight lights[MAX_LIGHTS];
    Thermostat thermostat;
    int choice, lightNumber, temp;

    initializeLights(lights, MAX_LIGHTS);
    thermostat.temperature = 22; // Default temperature

    while (1) {
        printf("\nSmart Home Automation System\n");
        printf("1. Toggle Light\n");
        printf("2. View Lights Status\n");
        printf("3. Set Thermostat\n");
        printf("4. View Thermostat Status\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Light Number (1 to %d): ", MAX_LIGHTS);
                scanf("%d", &lightNumber);
                if (lightNumber >= 1 && lightNumber <= MAX_LIGHTS) {
                    toggleLight(&lights[lightNumber - 1]);
                } else {
                    printf("Invalid light number.\n");
                }
                break;
                
            case 2:
                displayLights(lights, MAX_LIGHTS);
                break;

            case 3:
                printf("Enter desired temperature: ");
                scanf("%d", &temp);
                setThermostat(&thermostat, temp);
                break;

            case 4:
                displayThermostatStatus(&thermostat);
                break;

            case 5:
                printf("Exiting the system. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}