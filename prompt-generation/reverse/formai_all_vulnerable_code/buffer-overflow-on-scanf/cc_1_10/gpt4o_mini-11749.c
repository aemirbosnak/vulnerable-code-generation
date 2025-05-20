//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_LIGHTS 5

typedef struct {
    int id;
    int brightness; // range from 0 to 100
    int is_on;      // 1 for on, 0 for off
} Light;

void initializeLights(Light lights[]) {
    for (int i = 0; i < NUM_LIGHTS; i++) {
        lights[i].id = i + 1;
        lights[i].brightness = 0;
        lights[i].is_on = 0;
    }
}

void displayLights(Light lights[]) {
    printf("\nCurrent state of Lights:\n");
    for (int i = 0; i < NUM_LIGHTS; i++) {
        printf("Light %d: %s, Brightness: %d%%\n", 
               lights[i].id, lights[i].is_on ? "ON" : "OFF", lights[i].brightness);
    }
}

void toggleLight(Light *light) {
    light->is_on = !light->is_on;
    if (light->is_on) {
        light->brightness = 50; // Default brightness when turned on
    } else {
        light->brightness = 0; // Reset brightness when turned off
    }
}

void setBrightness(Light *light, int brightness) {
    if (light->is_on && brightness >= 0 && brightness <= 100) {
        light->brightness = brightness;
    } else if (!light->is_on) {
        printf("Light is off. Turn it on to set brightness.\n");
    } else {
        printf("Invalid brightness level. Must be between 0 and 100.\n");
    }
}

void handleUserInput(Light lights[]) {
    int choice = 0, light_id = 0, brightness = 0;

    while (choice != 5) {
        printf("\nSmart Home Light Control Menu:\n");
        printf("1. Toggle Light\n");
        printf("2. Set Brightness\n");
        printf("3. Display Lights\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Light ID (1 - %d): ", NUM_LIGHTS);
                scanf("%d", &light_id);
                if (light_id >= 1 && light_id <= NUM_LIGHTS) {
                    toggleLight(&lights[light_id - 1]);
                } else {
                    printf("Invalid Light ID!\n");
                }
                break;

            case 2:
                printf("Enter Light ID (1 - %d): ", NUM_LIGHTS);
                scanf("%d", &light_id);
                if (light_id >= 1 && light_id <= NUM_LIGHTS) {
                    printf("Enter Brightness (0-100): ");
                    scanf("%d", &brightness);
                    setBrightness(&lights[light_id - 1], brightness);
                } else {
                    printf("Invalid Light ID!\n");
                }
                break;

            case 3:
                displayLights(lights);
                break;

            case 4:
                printf("Exiting the Smart Home Light Control!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please enter a number from 1 to 4.\n");
                break;
        }
    }
}

int main() {
    Light lights[NUM_LIGHTS];

    initializeLights(lights);
    handleUserInput(lights);

    return 0;
}