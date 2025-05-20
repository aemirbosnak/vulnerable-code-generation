//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 50
#define MAX_LIGHTS 10

typedef struct {
    char name[NAME_LEN];
    int is_on;       // 1 for on, 0 for off
    int brightness;  // 0 to 100
} Light;

Light lights[MAX_LIGHTS];
int num_lights = 0;

void add_light(const char* name) {
    if (num_lights < MAX_LIGHTS) {
        strcpy(lights[num_lights].name, name);
        lights[num_lights].is_on = 0; // Initially off
        lights[num_lights].brightness = 0; // Initially dimmed
        num_lights++;
        printf("Light '%s' added successfully!\n", name);
    } else {
        printf("Error: Cannot add more lights. Maximum limit reached.\n");
    }
}

void toggle_light(const char* name) {
    for (int i = 0; i < num_lights; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            lights[i].is_on = !lights[i].is_on;
            printf("Light '%s' is now %s.\n", name, lights[i].is_on ? "ON" : "OFF");
            return;
        }
    }
    printf("Error: Light '%s' not found.\n", name);
}

void set_brightness(const char* name, int level) {
    if (level < 0 || level > 100) {
        printf("Error: Brightness level must be between 0 and 100.\n");
        return;
    }
    for (int i = 0; i < num_lights; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            lights[i].brightness = level;
            printf("Brightness of light '%s' set to %d%%.\n", name, level);
            return;
        }
    }
    printf("Error: Light '%s' not found.\n", name);
}

void check_light_status(const char* name) {
    for (int i = 0; i < num_lights; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            printf("Light '%s': %s, Brightness: %d%%\n", 
                name, 
                lights[i].is_on ? "ON" : "OFF", 
                lights[i].brightness);
            return;
        }
    }
    printf("Error: Light '%s' not found.\n", name);
}

void list_lights() {
    if (num_lights == 0) {
        printf("No lights available.\n");
        return;
    }
    printf("Lights in the system:\n");
    for (int i = 0; i < num_lights; i++) {
        printf(" - %s: %s, Brightness: %d%%\n", 
            lights[i].name, 
            lights[i].is_on ? "ON" : "OFF", 
            lights[i].brightness);
    }
}

int main() {
    int choice;
    char name[NAME_LEN];
    int brightness;

    while (1) {
        printf("\nSmart Home Light Control\n");
        printf("1. Add Light\n");
        printf("2. Toggle Light\n");
        printf("3. Set Brightness\n");
        printf("4. Check Light Status\n");
        printf("5. List All Lights\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter light name: ");
                scanf("%s", name);
                add_light(name);
                break;
            case 2:
                printf("Enter light name to toggle: ");
                scanf("%s", name);
                toggle_light(name);
                break;
            case 3:
                printf("Enter light name to set brightness: ");
                scanf("%s", name);
                printf("Enter brightness level (0-100): ");
                scanf("%d", &brightness);
                set_brightness(name, brightness);
                break;
            case 4:
                printf("Enter light name to check status: ");
                scanf("%s", name);
                check_light_status(name);
                break;
            case 5:
                list_lights();
                break;
            case 6:
                printf("Exiting the program...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}