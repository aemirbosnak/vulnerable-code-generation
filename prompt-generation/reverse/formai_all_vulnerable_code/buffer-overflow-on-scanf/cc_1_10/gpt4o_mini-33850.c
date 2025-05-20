//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHTS 10

typedef struct {
    char name[20];
    int brightness; // Range from 0 to 100
    int is_on; // 1 if the light is on, 0 otherwise
} SmartLight;

SmartLight lights[MAX_LIGHTS];
int light_count = 0;

void add_light(const char *name) {
    if (light_count >= MAX_LIGHTS) {
        printf("Cannot add more lights. Max limit reached!\n");
        return;
    }
    strcpy(lights[light_count].name, name);
    lights[light_count].brightness = 0; // Light off by default
    lights[light_count].is_on = 0;
    light_count++;
    printf("Added light: %s\n", name);
}

void set_light_brightness(const char *name, int brightness) {
    for (int i = 0; i < light_count; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            if (brightness < 0 || brightness > 100) {
                printf("Brightness must be between 0 and 100.\n");
                return;
            }
            lights[i].brightness = brightness;
            printf("Set brightness of %s to %d%%.\n", name, brightness);
            return;
        }
    }
    printf("Light with name %s not found.\n", name);
}

void turn_on_light(const char *name) {
    for (int i = 0; i < light_count; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            lights[i].is_on = 1;
            printf("Turned on light: %s\n", name);
            return;
        }
    }
    printf("Light with name %s not found.\n", name);
}

void turn_off_light(const char *name) {
    for (int i = 0; i < light_count; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            lights[i].is_on = 0;
            printf("Turned off light: %s\n", name);
            return;
        }
    }
    printf("Light with name %s not found.\n", name);
}

void display_lights() {
    if (light_count == 0) {
        printf("No lights found in the system.\n");
        return;
    }
    printf("\nCurrent Lights:\n");
    for (int i = 0; i < light_count; i++) {
        printf("Name: %s, Brightness: %d%%, Status: %s\n",
               lights[i].name,
               lights[i].brightness,
               lights[i].is_on ? "On" : "Off");
    }
}

void control_lights() {
    char action[50];
    char name[20];
    int brightness;

    while (1) {
        printf("\nEnter your command ('add', 'set', 'on', 'off', 'display', 'exit'):\n");
        scanf("%s", action);

        if (strcmp(action, "add") == 0) {
            printf("Enter light name to add: ");
            scanf("%s", name);
            add_light(name);
        } else if (strcmp(action, "set") == 0) {
            printf("Enter light name and brightness (0-100): ");
            scanf("%s %d", name, &brightness);
            set_light_brightness(name, brightness);
        } else if (strcmp(action, "on") == 0) {
            printf("Enter light name to turn on: ");
            scanf("%s", name);
            turn_on_light(name);
        } else if (strcmp(action, "off") == 0) {
            printf("Enter light name to turn off: ");
            scanf("%s", name);
            turn_off_light(name);
        } else if (strcmp(action, "display") == 0) {
            display_lights();
        } else if (strcmp(action, "exit") == 0) {
            printf("Exiting the Smart Home Light Control System.\n");
            break;
        } else {
            printf("Unknown command!\n");
        }
    }
}

int main() {
    printf("Welcome to the Smart Home Light Control System!\n");
    control_lights();
    return 0;
}