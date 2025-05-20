//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct {
    int id;
    char name[30];
    int is_on;
    int brightness; // 0 to 100
} SmartLight;

void initializeLights(SmartLight lights[], int number_of_lights) {
    for (int i = 0; i < number_of_lights; i++) {
        lights[i].id = i + 1;
        snprintf(lights[i].name, sizeof(lights[i].name), "Light %d", i + 1);
        lights[i].is_on = 0; // initially off
        lights[i].brightness = 0; // initially at 0%
    }
}

void displayLights(SmartLight lights[], int number_of_lights) {
    printf("\nAvailable Smart Lights:\n");
    for (int i = 0; i < number_of_lights; i++) {
        printf("ID: %d, Name: %s, Status: %s, Brightness: %d%%\n",
               lights[i].id, lights[i].name,
               lights[i].is_on ? "On" : "Off", lights[i].brightness);
    }
}

void turnOnLight(SmartLight *light) {
    light->is_on = 1;
    light->brightness = 100; // Defaults to 100% when turned on
    printf("%s is now ON with brightness %d%%.\n", light->name, light->brightness);
}

void turnOffLight(SmartLight *light) {
    light->is_on = 0;
    light->brightness = 0; // Reset brightness when turned off
    printf("%s is now OFF.\n", light->name);
}

void setBrightness(SmartLight *light, int brightness) {
    if (brightness < 0 || brightness > 100) {
        printf("Brightness must be between 0 and 100\n");
        return;
    }
    light->brightness = brightness;
    printf("The brightness of %s has been set to %d%%.\n", light->name, light->brightness);
}

int findLightById(SmartLight lights[], int number_of_lights, int id) {
    for (int i = 0; i < number_of_lights; i++) {
        if (lights[i].id == id) {
            return i; // Return the index of the light found
        }
    }
    return -1; // Light not found
}

void controlLight(SmartLight lights[], int number_of_lights) {
    int choice, light_id, brightness;
    while (1) {
        printf("\nSmart Light Control Menu:\n");
        printf("1. Turn ON a light\n");
        printf("2. Turn OFF a light\n");
        printf("3. Set brightness\n");
        printf("4. Display all lights\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter light ID to turn ON: ");
                scanf("%d", &light_id);
                int index_on = findLightById(lights, number_of_lights, light_id);
                if (index_on != -1) {
                    turnOnLight(&lights[index_on]);
                } else {
                    printf("Light ID %d not found!\n", light_id);
                }
                break;

            case 2:
                printf("Enter light ID to turn OFF: ");
                scanf("%d", &light_id);
                int index_off = findLightById(lights, number_of_lights, light_id);
                if (index_off != -1) {
                    turnOffLight(&lights[index_off]);
                } else {
                    printf("Light ID %d not found!\n", light_id);
                }
                break;

            case 3:
                printf("Enter light ID to set brightness: ");
                scanf("%d", &light_id);
                int index_brightness = findLightById(lights, number_of_lights, light_id);
                if (index_brightness != -1) {
                    printf("Enter brightness level (0-100): ");
                    scanf("%d", &brightness);
                    setBrightness(&lights[index_brightness], brightness);
                } else {
                    printf("Light ID %d not found!\n", light_id);
                }
                break;

            case 4:
                displayLights(lights, number_of_lights);
                break;

            case 5:
                printf("Exiting Smart Light Control. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
        sleep(1); // Pause for a second before the next action
    }
}

int main() {
    const int NUMBER_OF_LIGHTS = 5;
    SmartLight lights[NUMBER_OF_LIGHTS];
    
    initializeLights(lights, NUMBER_OF_LIGHTS);
    controlLight(lights, NUMBER_OF_LIGHTS);

    return 0;
}