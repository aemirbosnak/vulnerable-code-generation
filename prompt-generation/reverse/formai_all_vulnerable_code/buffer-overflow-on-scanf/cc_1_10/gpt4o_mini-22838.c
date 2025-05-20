//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LIGHTS 10

typedef struct Light {
    int id;
    char name[50];
    int brightness; // 0 to 100
    int state; // 0 = off, 1 = on
} Light;

Light lights[MAX_LIGHTS];
int light_count = 0;

void add_light(const char *name) {
    if (light_count >= MAX_LIGHTS) {
        printf("Max light limit reached!\n");
        return;
    }
    lights[light_count].id = light_count + 1;
    strcpy(lights[light_count].name, name);
    lights[light_count].brightness = 0;
    lights[light_count].state = 0; // initially off
    light_count++;
    printf("Light %s added!\n", name);
}

void toggle_light(int id) {
    if (id < 1 || id > light_count) {
        printf("Invalid light ID!\n");
        return;
    }
    Light *light = &lights[id - 1];
    light->state = !light->state;
    printf("Light %s is now %s.\n", light->name, light->state ? "ON" : "OFF");
}

void set_brightness(int id, int brightness) {
    if (id < 1 || id > light_count) {
        printf("Invalid light ID!\n");
        return;
    }
    if (brightness < 0 || brightness > 100) {
        printf("Brightness must be between 0 and 100!\n");
        return;
    }
    Light *light = &lights[id - 1];
    light->brightness = brightness;
    printf("Light %s brightness set to %d%%.\n", light->name, brightness);
}

void show_lights() {
    printf("\nCurrent Lights State:\n");
    for (int i = 0; i < light_count; i++) {
        Light *light = &lights[i];
        printf("ID: %d, Name: %s, Brightness: %d%%, State: %s\n", 
               light->id, light->name, light->brightness, 
               light->state ? "ON" : "OFF");
    }
    printf("\n");
}

void menu() {
    printf("Smart Home Light Control\n");
    printf("1. Add a Light\n");
    printf("2. Toggle Light\n");
    printf("3. Set Brightness\n");
    printf("4. Show Lights\n");
    printf("5. Exit\n");
}

int main() {
    int choice, id, brightness;
    char name[50];

    while (1) {
        menu();
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter light name: ");
                scanf("%s", name);
                add_light(name);
                break;
            case 2:
                printf("Enter light ID to toggle: ");
                scanf("%d", &id);
                toggle_light(id);
                break;
            case 3:
                printf("Enter light ID to set brightness: ");
                scanf("%d", &id);
                printf("Enter brightness (0-100): ");
                scanf("%d", &brightness);
                set_brightness(id, brightness);
                break;
            case 4:
                show_lights();
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
        sleep(1); // minor delay for better user experience
    }

    return 0;
}