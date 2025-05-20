//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIGHT_COUNT 5

typedef enum { OFF, ON } LightState;

typedef struct {
    int id;
    LightState state;
} SmartLight;

void initializeLights(SmartLight lights[], int count) {
    for (int i = 0; i < count; i++) {
        lights[i].id = i + 1;
        lights[i].state = OFF;
    }
}

void printLightStatus(SmartLight lights[], int count) {
    printf("Smart Home Light Status:\n");
    for (int i = 0; i < count; i++) {
        printf("Light %d: %s\n", lights[i].id, lights[i].state == ON ? "ON" : "OFF");
    }
    printf("\n");
}

void toggleLight(SmartLight *light) {
    if (light->state == OFF) {
        light->state = ON;
        printf("Light %d turned ON.\n", light->id);
    } else {
        light->state = OFF;
        printf("Light %d turned OFF.\n", light->id);
    }
}

void setLightState(SmartLight *light, LightState state) {
    light->state = state;
    printf("Light %d set to %s.\n", light->id, state == ON ? "ON" : "OFF");
}

void controlLights(SmartLight lights[], int count) {
    int choice;
    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Toggle Light\n");
        printf("2. Set Light ON\n");
        printf("3. Set Light OFF\n");
        printf("4. Show Light Status\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        
        if (choice == 5) {
            break;
        }

        int lightId;
        switch (choice) {
            case 1:
                printf("Enter light ID to toggle (1-%d): ", count);
                scanf("%d", &lightId);
                if (lightId >= 1 && lightId <= count) {
                    toggleLight(&lights[lightId - 1]);
                } else {
                    printf("Invalid light ID!\n");
                }
                break;
            case 2:
                printf("Enter light ID to turn ON (1-%d): ", count);
                scanf("%d", &lightId);
                if (lightId >= 1 && lightId <= count) {
                    setLightState(&lights[lightId - 1], ON);
                } else {
                    printf("Invalid light ID!\n");
                }
                break;
            case 3:
                printf("Enter light ID to turn OFF (1-%d): ", count);
                scanf("%d", &lightId);
                if (lightId >= 1 && lightId <= count) {
                    setLightState(&lights[lightId - 1], OFF);
                } else {
                    printf("Invalid light ID!\n");
                }
                break;
            case 4:
                printLightStatus(lights, count);
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
}

void simulateRandomLightControl(SmartLight lights[], int count) {
    srand(time(NULL)); // Seed random number generator
    for (int i = 0; i < 10; i++) { // Simulate 10 random controls
        int lightId = rand() % count; // Random light ID
        int action = rand() % 2; // Random action 0 or 1
        if (action == 0) {
            toggleLight(&lights[lightId]);
        } else {
            setLightState(&lights[lightId], ON);
        }
        sleep(1); // Simulate delay
    }
}

int main() {
    SmartLight lights[LIGHT_COUNT];
    initializeLights(lights, LIGHT_COUNT);

    printf("Welcome to Smart Home Light Control System!\n");
    printLightStatus(lights, LIGHT_COUNT);

    controlLights(lights, LIGHT_COUNT);
    printf("Exiting Smart Home Light Control System. Goodbye!\n");

    return 0;
}