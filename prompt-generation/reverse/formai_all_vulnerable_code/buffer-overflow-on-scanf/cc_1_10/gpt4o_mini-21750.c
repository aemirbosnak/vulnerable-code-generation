//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHTS 10

typedef struct {
    int id;
    char name[30];
    int is_on; // States: 0 = off, 1 = on
    int brightness; // Brightness level (0-100)
} Light;

Light lights[MAX_LIGHTS];
int light_count = 0;

void turn_on(Light *light) {
    light->is_on = 1;
    printf("Light %s turned ON.\n", light->name);
}

void turn_off(Light *light) {
    light->is_on = 0;
    printf("Light %s turned OFF.\n", light->name);
}

void set_brightness(Light *light, int brightness) {
    if (brightness < 0 || brightness > 100) {
        printf("Invalid brightness value. It should be between 0 and 100.\n");
    } else {
        light->brightness = brightness;
        printf("Brightness of %s set to %d%%.\n", light->name, brightness);
    }
}

void add_light(const char *name) {
    if (light_count < MAX_LIGHTS) {
        lights[light_count].id = light_count;
        strncpy(lights[light_count].name, name, 30);
        lights[light_count].is_on = 0;
        lights[light_count].brightness = 0;
        light_count++;
        printf("Light %s added with ID %d.\n", name, light_count - 1);
    } else {
        printf("Cannot add more lights. Maximum limit reached.\n");
    }
}

void list_lights() {
    if (light_count == 0) {
        printf("No lights available.\n");
        return;
    }
    for (int i = 0; i < light_count; i++) {
        printf("ID: %d, Name: %s, Status: %s, Brightness: %d%%\n", 
               lights[i].id, lights[i].name, 
               lights[i].is_on ? "ON" : "OFF", 
               lights[i].brightness);
    }
}

int main() {
    char command[50];
    char light_name[30];
    int brightness, id;

    while (1) {
        printf("\nSmart Home Light Control System\n");
        printf("Commands: add, on, off, brightness, list, exit\n");
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter light name: ");
            scanf("%s", light_name);
            add_light(light_name);
        } else if (strcmp(command, "on") == 0) {
            printf("Enter light ID to turn ON: ");
            scanf("%d", &id);
            if (id >= 0 && id < light_count) {
                turn_on(&lights[id]);
            } else {
                printf("Invalid light ID.\n");
            }
        } else if (strcmp(command, "off") == 0) {
            printf("Enter light ID to turn OFF: ");
            scanf("%d", &id);
            if (id >= 0 && id < light_count) {
                turn_off(&lights[id]);
            } else {
                printf("Invalid light ID.\n");
            }
        } else if (strcmp(command, "brightness") == 0) {
            printf("Enter light ID to set brightness: ");
            scanf("%d", &id);
            if (id >= 0 && id < light_count) {
                printf("Enter brightness (0-100): ");
                scanf("%d", &brightness);
                set_brightness(&lights[id], brightness);
            } else {
                printf("Invalid light ID.\n");
            }
        } else if (strcmp(command, "list") == 0) {
            list_lights();
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the system.\n");
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}