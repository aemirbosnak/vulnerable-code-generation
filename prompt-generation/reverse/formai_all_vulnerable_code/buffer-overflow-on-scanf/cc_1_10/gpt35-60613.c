//FormAI DATASET v1.0 Category: Smart home light control ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHTS 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int brightness;
    int is_on;
} Light;

void set_brightness(Light *light, int brightness) {
    if (brightness < 0 || brightness > 100) {
        printf("Invalid brightness level\n");
        return;
    }
    light->brightness = brightness;
    printf("%s's brightness set to %d\n", light->name, brightness);
}

void turn_on(Light *light) {
    if (light->is_on) {
        printf("%s is already on\n", light->name);
        return;
    }
    light->is_on = 1;
    printf("%s turned on\n", light->name);
}

void turn_off(Light *light) {
    if (!light->is_on) {
        printf("%s is already off\n", light->name);
        return;
    }
    light->is_on = 0;
    printf("%s turned off\n", light->name);
}

int main() {
    Light lights[MAX_LIGHTS];
    int num_lights = 0;
    int i, choice;

    while (1) {
        printf("Smart Home Light Control Menu\n");
        printf("1. Add Light\n");
        printf("2. Set Brightness\n");
        printf("3. Turn On\n");
        printf("4. Turn Off\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_lights == MAX_LIGHTS) {
                    printf("Sorry, you have reached the maximum number of lights\n");
                    break;
                }
                printf("Enter light name: ");
                scanf("%s", lights[num_lights].name);
                lights[num_lights].brightness = 50;
                lights[num_lights].is_on = 0;
                printf("%s added\n", lights[num_lights].name);
                num_lights++;
                break;
            case 2:
                printf("Enter light name: ");
                char name[MAX_NAME_LENGTH];
                scanf("%s", name);

                for (i = 0; i < num_lights; i++) {
                    if (strcmp(lights[i].name, name) == 0) {
                        printf("Enter brightness level (0-100): ");
                        int brightness;
                        scanf("%d", &brightness);
                        set_brightness(&lights[i], brightness);
                        break;
                    }
                }
                if (i == num_lights) {
                    printf("Light not found\n");
                }
                break;
            case 3:
                printf("Enter light name: ");
                scanf("%s", name);

                for (i = 0; i < num_lights; i++) {
                    if (strcmp(lights[i].name, name) == 0) {
                        turn_on(&lights[i]);
                        break;
                    }
                }
                if (i == num_lights) {
                    printf("Light not found\n");
                }
                break;
            case 4:
                printf("Enter light name: ");
                scanf("%s", name);

                for (i = 0; i < num_lights; i++) {
                    if (strcmp(lights[i].name, name) == 0) {
                        turn_off(&lights[i]);
                        break;
                    }
                }
                if (i == num_lights) {
                    printf("Light not found\n");
                }
                break;
            case 5:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}