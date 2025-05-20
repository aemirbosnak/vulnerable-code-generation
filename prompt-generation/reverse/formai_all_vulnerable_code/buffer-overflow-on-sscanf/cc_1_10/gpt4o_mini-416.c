//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHTS 10
#define NAME_SIZE 30

typedef struct {
    char name[NAME_SIZE];
    int is_on;
    int brightness; // 0 - 100
} Light;

Light lights[MAX_LIGHTS];
int light_count = 0;

void add_light(const char *name) {
    if (light_count < MAX_LIGHTS) {
        strncpy(lights[light_count].name, name, NAME_SIZE);
        lights[light_count].is_on = 0;
        lights[light_count].brightness = 0;
        light_count++;
        printf("Added light: %s\n", name);
    } else {
        printf("Max lights reached. Can't add more.\n");
    }
}

void toggle_light(const char *name) {
    for (int i = 0; i < light_count; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            lights[i].is_on = !lights[i].is_on;
            printf("Light %s is %s\n", name, lights[i].is_on ? "ON" : "OFF");
            return;
        }
    }
    printf("Light not found: %s\n", name);
}

void set_brightness(const char *name, int brightness) {
    for (int i = 0; i < light_count; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            if (brightness < 0 || brightness > 100) {
                printf("Brightness must be between 0 and 100!\n");
            } else {
                lights[i].brightness = brightness;
                printf("Set brightness of %s to %d%%\n", name, brightness);
            }
            return;
        }
    }
    printf("Light not found: %s\n", name);
}

void status(const char *name) {
    for (int i = 0; i < light_count; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            printf("Light: %s, Status: %s, Brightness: %d%%\n", 
                   lights[i].name, 
                   lights[i].is_on ? "ON" : "OFF", 
                   lights[i].brightness);
            return;
        }
    }
    printf("Light not found: %s\n", name);
}

void list_lights() {
    printf("Listing all lights:\n");
    for (int i = 0; i < light_count; i++) {
        printf("%s: %s, Brightness: %d%%\n", 
               lights[i].name, 
               lights[i].is_on ? "ON" : "OFF", 
               lights[i].brightness);
    }
}

void command_parser(const char *command) {
    char action[20], light_name[NAME_SIZE];
    int brightness;

    if (sscanf(command, "ADD %s", light_name) == 1) {
        add_light(light_name);
    } else if (sscanf(command, "TOGGLE %s", light_name) == 1) {
        toggle_light(light_name);
    } else if (sscanf(command, "SET %s %d", light_name, &brightness) == 2) {
        set_brightness(light_name, brightness);
    } else if (sscanf(command, "STATUS %s", light_name) == 1) {
        status(light_name);
    } else if (strcmp(command, "LIST") == 0) {
        list_lights();
    } else {
        printf("Unknown command: %s\n", command);
    }
}

int main() {
    char command[100];

    printf("Welcome to the Smart Home Light Control System!\n");
    printf("Available commands: ADD <name>, TOGGLE <name>, SET <name> <brightness>, STATUS <name>, LIST, EXIT\n");

    while (1) {
        printf("> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Strip newline character

        if (strcmp(command, "EXIT") == 0) {
            break;
        }

        command_parser(command);
    }

    printf("Exiting Smart Home Light Control System. Goodbye!\n");
    return 0;
}