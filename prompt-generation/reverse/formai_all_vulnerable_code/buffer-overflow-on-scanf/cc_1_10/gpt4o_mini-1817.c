//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ROOMS 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    bool is_on;
    int brightness; // Range from 0 to 100
} Light;

Light lights[MAX_ROOMS];
int light_count = 0;

void add_light(const char *name) {
    if (light_count >= MAX_ROOMS) {
        printf("Cannot add more lights. Max limit reached.\n");
        return;
    }
    strncpy(lights[light_count].name, name, MAX_NAME_LENGTH);
    lights[light_count].is_on = false;
    lights[light_count].brightness = 0;
    light_count++;
    printf("Light '%s' added successfully!\n", name);
}

void toggle_light(const char *name) {
    for (int i = 0; i < light_count; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            lights[i].is_on = !lights[i].is_on;
            if (lights[i].is_on) {
                printf("Light '%s' is now ON.\n", name);
            } else {
                printf("Light '%s' is now OFF.\n", name);
            }
            return;
        }
    }
    printf("Light '%s' not found.\n", name);
}

void set_brightness(const char *name, int brightness) {
    if (brightness < 0 || brightness > 100) {
        printf("Invalid brightness level. Please select a value between 0 and 100.\n");
        return;
    }
    for (int i = 0; i < light_count; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            lights[i].brightness = brightness;
            printf("Brightness of light '%s' set to %d%%.\n", name, brightness);
            return;
        }
    }
    printf("Light '%s' not found.\n", name);
}

void display_lights() {
    printf("\nCurrent Light Status:\n");
    for (int i = 0; i < light_count; i++) {
        printf(" - Light: %s, Status: %s, Brightness: %d%%\n", 
                lights[i].name, 
                lights[i].is_on ? "ON" : "OFF", 
                lights[i].brightness);
    }
}

void display_menu() {
    printf("\n--- Smart Home Lights Control ---\n");
    printf("1. Add Light\n");
    printf("2. Toggle Light\n");
    printf("3. Set Brightness\n");
    printf("4. Display Lights\n");
    printf("5. Exit\n");
    printf("Choose an option (1-5): ");
}

int main() {
    char input_name[MAX_NAME_LENGTH];
    int choice, brightness;

    while (true) {
        display_menu();

        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the name of the light to add: ");
                scanf("%s", input_name);
                add_light(input_name);
                break;
            case 2:
                printf("Enter the name of the light to toggle: ");
                scanf("%s", input_name);
                toggle_light(input_name);
                break;
            case 3:
                printf("Enter the name of the light to set brightness: ");
                scanf("%s", input_name);
                printf("Enter brightness level (0-100): ");
                scanf("%d", &brightness);
                set_brightness(input_name, brightness);
                break;
            case 4:
                display_lights();
                break;
            case 5:
                printf("Exiting Smart Home Lights Control...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}