//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHTS 50
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    int is_on;
    int brightness; // 0 to 100
} SmartLight;

SmartLight lights[MAX_LIGHTS];
int light_count = 0;

void add_light(const char *name) {
    if (light_count < MAX_LIGHTS) {
        strncpy(lights[light_count].name, name, MAX_NAME_LENGTH);
        lights[light_count].is_on = 0;
        lights[light_count].brightness = 0;
        light_count++;
        printf("Light '%s' added.\n", name);
    } else {
        printf("Maximum light limit reached. Can't add more lights.\n");
    }
}

void toggle_light(const char *name) {
    for (int i = 0; i < light_count; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            lights[i].is_on = !lights[i].is_on;
            printf("Light '%s' is now %s.\n", lights[i].name, lights[i].is_on ? "ON" : "OFF");
            return;
        }
    }
    printf("Light '%s' not found.\n", name);
}

void set_brightness(const char *name, int brightness) {
    for (int i = 0; i < light_count; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            if (brightness < 0 || brightness > 100) {
                printf("Brightness must be between 0 and 100.\n");
            } else {
                lights[i].brightness = brightness;
                printf("Brightness of '%s' set to %d%%.\n", lights[i].name, brightness);
            }
            return;
        }
    }
    printf("Light '%s' not found.\n", name);
}

void list_lights() {
    printf("Lights in the system:\n");
    for (int i = 0; i < light_count; i++) {
        printf("%s - %s, Brightness: %d%%\n", 
               lights[i].name, 
               lights[i].is_on ? "ON" : "OFF", 
               lights[i].brightness);
    }
}

void show_menu() {
    printf("\nSmart Home Light Control Menu:\n");
    printf("1. Add Light\n");
    printf("2. Toggle Light\n");
    printf("3. Set Brightness\n");
    printf("4. List Lights\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];
    int brightness;

    while (1) {
        show_menu();
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
                printf("Enter brightness (0-100): ");
                scanf("%d", &brightness);
                set_brightness(name, brightness);
                break;
            case 4:
                list_lights();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}