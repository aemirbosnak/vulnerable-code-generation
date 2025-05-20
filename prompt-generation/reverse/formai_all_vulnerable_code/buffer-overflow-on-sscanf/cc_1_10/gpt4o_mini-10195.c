//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHTS 10
#define BUFFER_SIZE 100

typedef struct {
    char name[50];
    int is_on; // 1 for on, 0 for off
} SmartLight;

SmartLight lights[MAX_LIGHTS];
int light_count = 0;

void add_light(const char *name) {
    if (light_count < MAX_LIGHTS) {
        strncpy(lights[light_count].name, name, sizeof(lights[light_count].name) - 1);
        lights[light_count].is_on = 0;
        light_count++;
        printf("Light \"%s\" has been added to your smart home!\n", name);
    } else {
        printf("Maximum number of lights reached. Cannot add more!\n");
    }
}

void toggle_light(const char *name) {
    for (int i = 0; i < light_count; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            lights[i].is_on = !lights[i].is_on;
            printf("Light \"%s\" is now turned %s!\n", 
                lights[i].name, lights[i].is_on ? "ON" : "OFF");
            return;
        }
    }
    printf("Light \"%s\" not found in your smart home!\n", name);
}

void list_lights() {
    printf("\nCurrent Smart Lights:\n");
    for (int i = 0; i < light_count; i++) {
        printf("- %s: %s\n", lights[i].name, lights[i].is_on ? "ON" : "OFF");
    }
    printf("\n");
}

void display_menu() {
    printf("Welcome to your Smart Home Light Control Console!\n");
    printf("Follow the instructions, and let the magic happen:\n");
    printf("1. Add Light - 'add <light_name>'\n");
    printf("2. Toggle Light - 'toggle <light_name>'\n");
    printf("3. List Lights - 'list'\n");
    printf("4. Exit - 'exit'\n");
    printf("Please enter your command: ");
}

int main() {
    printf("Welcome to the realm of Smart Lights!\n");
    char command[BUFFER_SIZE];

    while (1) {
        display_menu();
        fgets(command, BUFFER_SIZE, stdin);
        command[strcspn(command, "\n")] = 0; // Remove trailing newline

        char action[10], light_name[50];
        if (sscanf(command, "%s %49[^\n]", action, light_name) == 2) {
            if (strcmp(action, "add") == 0) {
                add_light(light_name);
            } else if (strcmp(action, "toggle") == 0) {
                toggle_light(light_name);
            } else {
                printf("Unknown action! Please try again.\n");
            }
        } else if (strcmp(command, "list") == 0) {
            list_lights();
        } else if (strcmp(command, "exit") == 0) {
            printf("Goodbye! May your lights shine brightly!\n");
            break;
        } else {
            printf("Hmm, that doesn't seem right! Please follow the instructions accurately.\n");
        }
    }
    return 0;
}