//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHTS 10
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int id;
    int is_on;
    int brightness; // 0 (off) to 100 (fully bright)
} Light;

Light lights[MAX_LIGHTS];
int light_count = 0;

// Function to add a new light
void add_light(const char *name) {
    if (light_count < MAX_LIGHTS) {
        strcpy(lights[light_count].name, name);
        lights[light_count].id = light_count + 1;
        lights[light_count].is_on = 0;
        lights[light_count].brightness = 0;
        light_count++;
        printf("Light '%s' added successfully!\n", name);
    } else {
        printf("Cannot add more lights. Maximum limit reached.\n");
    }
}

// Function to list all lights
void list_lights() {
    printf("Listing all lights:\n");
    for (int i = 0; i < light_count; i++) {
        printf("ID: %d, Name: %s, Status: %s, Brightness: %d%%\n",
               lights[i].id, lights[i].name,
               lights[i].is_on ? "On" : "Off",
               lights[i].brightness);
    }
}

// Function to turn a light on
void turn_on(int id) {
    if (id > 0 && id <= light_count) {
        lights[id - 1].is_on = 1;
        printf("Light '%s' turned on.\n", lights[id - 1].name);
    } else {
        printf("Invalid light ID.\n");
    }
}

// Function to turn a light off
void turn_off(int id) {
    if (id > 0 && id <= light_count) {
        lights[id - 1].is_on = 0;
        printf("Light '%s' turned off.\n", lights[id - 1].name);
    } else {
        printf("Invalid light ID.\n");
    }
}

// Function to set brightness
void set_brightness(int id, int brightness) {
    if (id > 0 && id <= light_count) {
        if (brightness >= 0 && brightness <= 100) {
            lights[id - 1].brightness = brightness;
            printf("Brightness of light '%s' set to %d%%.\n", lights[id - 1].name, brightness);
        } else {
            printf("Brightness must be between 0 and 100.\n");
        }
    } else {
        printf("Invalid light ID.\n");
    }
}

// Function to toggle light
void toggle_light(int id) {
    if (id > 0 && id <= light_count) {
        lights[id - 1].is_on = !lights[id - 1].is_on;
        printf("Light '%s' is now %s.\n", lights[id - 1].name,
               lights[id - 1].is_on ? "On" : "Off");
    } else {
        printf("Invalid light ID.\n");
    }
}

// Function to display main menu
void display_menu() {
    printf("\nSmart Home Light Control System\n");
    printf("1. Add Light\n");
    printf("2. List Lights\n");
    printf("3. Turn On Light\n");
    printf("4. Turn Off Light\n");
    printf("5. Set Brightness\n");
    printf("6. Toggle Light\n");
    printf("7. Exit\n");
    printf("Choose an option: ");
}

// Main function
int main() {
    int choice, id, brightness;
    char name[NAME_LENGTH];

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the light: ");
                scanf("%s", name);
                add_light(name);
                break;
            case 2:
                list_lights();
                break;
            case 3:
                printf("Enter light ID to turn on: ");
                scanf("%d", &id);
                turn_on(id);
                break;
            case 4:
                printf("Enter light ID to turn off: ");
                scanf("%d", &id);
                turn_off(id);
                break;
            case 5:
                printf("Enter light ID to set brightness: ");
                scanf("%d", &id);
                printf("Enter brightness (0-100): ");
                scanf("%d", &brightness);
                set_brightness(id, brightness);
                break;
            case 6:
                printf("Enter light ID to toggle: ");
                scanf("%d", &id);
                toggle_light(id);
                break;
            case 7:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}