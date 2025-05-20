//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define structures for devices
typedef struct {
    char name[50];
    int status; // 0: off, 1: on
} Light;

typedef struct {
    char name[50];
    int temperature; // in Celsius
} Thermostat;

typedef struct {
    char name[50];
    int armed; // 0: disarmed, 1: armed
} SecuritySystem;

// Function prototypes
void toggleLight(Light *light);
void setThermostat(Thermostat *thermostat, int newTemperature);
void toggleSecurity(SecuritySystem *system);
void printStatus(Light lights[], int lightCount, Thermostat thermostats[], int thermostatCount, SecuritySystem systems[], int systemCount);
void delay(int seconds);

int main() {
    // Initialize devices
    Light lights[3] = {{"Living Room", 0}, {"Bedroom", 0}, {"Kitchen", 0}};
    Thermostat thermostats[1] = {{"Main Thermostat", 22}};
    SecuritySystem systems[1] = {{"Main Entrance", 0}};

    int choice;
    do {
        printf("\n=== Smart Home Automation ===\n");
        printf("1. Toggle Light\n");
        printf("2. Set Thermostat\n");
        printf("3. Toggle Security System\n");
        printf("4. Print Status\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int lightNumber;
            printf("Select Light (0: Living Room, 1: Bedroom, 2: Kitchen): ");
            scanf("%d", &lightNumber);
            if (lightNumber >= 0 && lightNumber < 3) {
                toggleLight(&lights[lightNumber]);
            } else {
                printf("Invalid Light Selection.\n");
            }
        } else if (choice == 2) {
            int newTemperature;
            printf("Enter new temperature for %s: ", thermostats[0].name);
            scanf("%d", &newTemperature);
            setThermostat(&thermostats[0], newTemperature);
        } else if (choice == 3) {
            toggleSecurity(&systems[0]);
        } else if (choice == 4) {
            printStatus(lights, 3, thermostats, 1, systems, 1);
        } else if (choice == 5) {
            printf("Exiting...\n");
        } else {
            printf("Invalid Option. Try Again.\n");
        }

        delay(1);
    } while (choice != 5);

    return 0;
}

void toggleLight(Light *light) {
    light->status = !light->status; // Flip status
    printf("%s is now %s.\n", light->name, light->status ? "On" : "Off");
}

void setThermostat(Thermostat *thermostat, int newTemperature) {
    thermostat->temperature = newTemperature;
    printf("The temperature of %s is set to %d°C.\n", thermostat->name, thermostat->temperature);
}

void toggleSecurity(SecuritySystem *system) {
    system->armed = !system->armed; 
    printf("The %s is now %s.\n", system->name, system->armed ? "Armed" : "Disarmed");
}

void printStatus(Light lights[], int lightCount, Thermostat thermostats[], int thermostatCount, SecuritySystem systems[], int systemCount) {
    printf("\n=== System Status ===\n");
    for (int i = 0; i < lightCount; i++) {
        printf("%s: %s\n", lights[i].name, lights[i].status ? "On" : "Off");
    }
    for (int i = 0; i < thermostatCount; i++) {
        printf("%s: %d°C\n", thermostats[i].name, thermostats[i].temperature);
    }
    for (int i = 0; i < systemCount; i++) {
        printf("%s: %s\n", systems[i].name, systems[i].armed ? "Armed" : "Disarmed");
    }
}

void delay(int seconds) {
    time_t start = time(NULL);
    while (time(NULL) - start < seconds);
}