//FormAI DATASET v1.0 Category: Smart home light control ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIGHTS 4 // The number of lights in the Smart home

bool lights[LIGHTS] = {false, false, false, false}; // The initial state of the lights

void turn_on_light(int light_number) {
    if (light_number < 1 || light_number > LIGHTS) {
        printf("Invalid light number\n");
        return;
    }
    lights[light_number - 1] = true;
    printf("Light %d turned ON\n", light_number);
}

void turn_off_light(int light_number) {
    if (light_number < 1 || light_number > LIGHTS) {
        printf("Invalid light number\n");
        return;
    }
    lights[light_number - 1] = false;
    printf("Light %d turned OFF\n", light_number);
}

int main() {
    int choice, light_number;

    while (1) {
        printf("Smart Home Light Control\n");
        printf("------------------------\n");
        printf("1. Turn ON a light\n");
        printf("2. Turn OFF a light\n");
        printf("3. Show the status of all lights\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the light number (1 to %d): ", LIGHTS);
                scanf("%d", &light_number);
                turn_on_light(light_number);
                break;

            case 2:
                printf("Enter the light number (1 to %d): ", LIGHTS);
                scanf("%d", &light_number);
                turn_off_light(light_number);
                break;

            case 3:
                printf("Light Status\n");
                printf("------------\n");
                for (int i = 0; i < LIGHTS; i++) {
                    printf("Light %d: %s\n", i + 1, lights[i] ? "ON" : "OFF");
                }
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);
        }
        printf("\n");
    }
    return 0;
}