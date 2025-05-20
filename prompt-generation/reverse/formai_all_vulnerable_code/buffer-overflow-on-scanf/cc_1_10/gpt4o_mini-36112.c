//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHTS 10
#define LIGHT_NAME_LENGTH 30

typedef struct {
    char name[LIGHT_NAME_LENGTH];
    int brightness; // 0 to 100
    int status; // 0: off, 1: on
} Light;

Light lights[MAX_LIGHTS];
int light_count = 0;

void add_light(const char *name) {
    if (light_count >= MAX_LIGHTS) {
        printf("Maximum number of lights reached.\n");
        return;
    }
    strncpy(lights[light_count].name, name, LIGHT_NAME_LENGTH - 1);
    lights[light_count].name[LIGHT_NAME_LENGTH - 1] = '\0'; // Ensuring null termination
    lights[light_count].brightness = 0;
    lights[light_count].status = 0; // Initially off
    light_count++;
    printf("Light '%s' added successfully!\n", name);
}

void set_brightness(int index, int brightness) {
    if (index < 0 || index >= light_count) {
        printf("Invalid light index.\n");
        return;
    }
    if (brightness < 0 || brightness > 100) {
        printf("Brightness must be between 0 and 100.\n");
        return;
    }
    lights[index].brightness = brightness;
    printf("Brightness of light '%s' set to %d%%.\n", lights[index].name, brightness);
}

void toggle_light(int index) {
    if (index < 0 || index >= light_count) {
        printf("Invalid light index.\n");
        return;
    }
    lights[index].status = !lights[index].status;
    const char *status_text = lights[index].status ? "on" : "off";
    printf("Light '%s' turned %s.\n", lights[index].name, status_text);
}

void show_lights() {
    if (light_count == 0) {
        printf("No lights added yet.\n");
        return;
    }
    printf("Current lights:\n");
    for (int i = 0; i < light_count; i++) {
        printf("Index: %d, Name: %s, Brightness: %d%%, Status: %s\n",
               i, lights[i].name, lights[i].brightness,
               lights[i].status ? "On" : "Off");
    }
}

void command_interface() {
    int choice, index, brightness;
    char light_name[LIGHT_NAME_LENGTH];

    while (1) {
        printf("\nSmart Home Light Control\n");
        printf("1. Add Light\n");
        printf("2. Set Brightness\n");
        printf("3. Toggle Light\n");
        printf("4. Show Lights\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter light name: ");
                scanf("%s", light_name);
                add_light(light_name);
                break;
            case 2:
                printf("Enter light index to set brightness: ");
                scanf("%d", &index);
                printf("Enter brightness (0-100): ");
                scanf("%d", &brightness);
                set_brightness(index, brightness);
                break;
            case 3:
                printf("Enter light index to toggle: ");
                scanf("%d", &index);
                toggle_light(index);
                break;
            case 4:
                show_lights();
                break;
            case 5:
                printf("Exiting the program.\n");
                return;
            default:
                printf("Invalid option, please try again.\n");
        }
    }
}

int main() {
    command_interface();
    return 0;
}