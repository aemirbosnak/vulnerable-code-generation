//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHTS 10

typedef struct {
    char name[50];
    int brightness; // 0 to 100
    int state;      // 0 = off, 1 = on
} Light;

Light lights[MAX_LIGHTS];
int light_count = 0;

void add_light(const char *name) {
    if (light_count < MAX_LIGHTS) {
        strncpy(lights[light_count].name, name, sizeof(lights[light_count].name));
        lights[light_count].brightness = 0; // Start off
        lights[light_count].state = 0; // Off 
        light_count++;
        printf("Light %s added successfully!\n", name);
    } else {
        printf("Maximum number of lights reached. Can't add more.\n");
    }
}

void set_brightness(const char *name, int brightness) {
    for (int i = 0; i < light_count; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            if (brightness >= 0 && brightness <= 100) {
                lights[i].brightness = brightness;
                printf("Brightness of %s set to %d%%.\n", name, brightness);
            } else {
                printf("Invalid brightness value! Please set a value between 0 and 100.\n");
            }
            return;
        }
    }
    printf("Light %s not found!\n", name);
}

void toggle_light(const char *name) {
    for (int i = 0; i < light_count; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            lights[i].state = !lights[i].state; // Toggle state
            printf("Light %s is now %s.\n", name, lights[i].state ? "ON" : "OFF");
            return;
        }
    }
    printf("Light %s not found!\n", name);
}

void list_lights() {
    if (light_count == 0) {
        printf("No lights found!\n");
        return;
    }
    printf("Current lights:\n");
    for (int i = 0; i < light_count; i++) {
        printf(" - %s: %s, Brightness: %d%%\n",
               lights[i].name,
               lights[i].state ? "ON" : "OFF",
               lights[i].brightness);
    }
}

void help() {
    printf("Commands:\n");
    printf("1. add <light_name> - Add a new light.\n");
    printf("2. toggle <light_name> - Toggle light state.\n");
    printf("3. set <light_name> <brightness> - Set brightness (0-100).\n");
    printf("4. list - List all lights.\n");
    printf("5. exit - Exit the program.\n");
}

int main() {
    char command[255];
    char light_name[50];
    int brightness;

    printf("Welcome to the Smart Home Light Control System!\n");
    help();

    while (1) {
        printf("Enter command: ");
        fgets(command, sizeof(command), stdin);

        // Removing newline character from the input
        command[strcspn(command, "\n")] = 0;

        if (strncmp(command, "add ", 4) == 0) {
            sscanf(command + 4, "%s", light_name);
            add_light(light_name);
        } else if (strncmp(command, "toggle ", 7) == 0) {
            sscanf(command + 7, "%s", light_name);
            toggle_light(light_name);
        } else if (strncmp(command, "set ", 4) == 0) {
            sscanf(command + 4, "%s %d", light_name, &brightness);
            set_brightness(light_name, brightness);
        } else if (strcmp(command, "list") == 0) {
            list_lights();
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the Smart Home Light Control System. Goodbye!\n");
            break;
        } else {
            printf("Invalid command! Please try again.\n");
        }
    }

    return 0;
}