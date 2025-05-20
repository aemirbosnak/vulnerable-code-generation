//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Define constants
#define MAX_LIGHTS 10
#define LIGHT_ON 1
#define LIGHT_OFF 0

// Structure to represent a smart light
typedef struct {
    int id;
    char name[50];
    int status; // 1 for ON, 0 for OFF
} SmartLight;

// Function prototypes
void initializeLights(SmartLight lights[], int count);
void displayLights(SmartLight lights[], int count);
void controlLight(SmartLight lights[], int count);
void toggleLight(SmartLight *light);
void turnOnAllLights(SmartLight lights[], int count);
void turnOffAllLights(SmartLight lights[], int count);
void showMenu();

int main() {
    SmartLight lights[MAX_LIGHTS];

    // Initialize the lights
    initializeLights(lights, MAX_LIGHTS);
    int choice;

    while (1) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                displayLights(lights, MAX_LIGHTS);
                break;
            case 2:
                controlLight(lights, MAX_LIGHTS);
                break;
            case 3:
                turnOnAllLights(lights, MAX_LIGHTS);
                break;
            case 4:
                turnOffAllLights(lights, MAX_LIGHTS);
                break;
            case 5:
                printf("Exiting the Smart Home Light Control System...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    }

    return 0;
}

void initializeLights(SmartLight lights[], int count) {
    for (int i = 0; i < count; i++) {
        lights[i].id = i + 1;
        sprintf(lights[i].name, "Light %d", i + 1);
        lights[i].status = LIGHT_OFF;
    }
}

void displayLights(SmartLight lights[], int count) {
    printf("Current Light Status:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Status: %s\n", 
            lights[i].id, 
            lights[i].name, 
            lights[i].status == LIGHT_ON ? "ON" : "OFF");
    }
}

void controlLight(SmartLight lights[], int count) {
    int id;
    printf("Enter light ID to toggle: ");
    scanf("%d", &id);
    
    if (id < 1 || id > count) {
        printf("Invalid Light ID!\n");
        return;
    }

    toggleLight(&lights[id - 1]);
    printf("Toggled %s\n", lights[id - 1].name);
}

void toggleLight(SmartLight *light) {
    light->status = (light->status == LIGHT_ON) ? LIGHT_OFF : LIGHT_ON;
}

void turnOnAllLights(SmartLight lights[], int count) {
    for (int i = 0; i < count; i++) {
        lights[i].status = LIGHT_ON;
    }
    printf("All lights are now ON.\n");
}

void turnOffAllLights(SmartLight lights[], int count) {
    for (int i = 0; i < count; i++) {
        lights[i].status = LIGHT_OFF;
    }
    printf("All lights are now OFF.\n");
}

void showMenu() {
    printf("=== Smart Home Light Control Menu ===\n");
    printf("1. Display all lights\n");
    printf("2. Toggle a light\n");
    printf("3. Turn ON all lights\n");
    printf("4. Turn OFF all lights\n");
    printf("5. Exit\n");
}