//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHTS 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int brightness; // 0-100
    int is_on;      // 0: off, 1: on
} Light;

typedef struct {
    Light lights[MAX_LIGHTS];
    int total_lights;
} SmartHome;

void initialize_smart_home(SmartHome *home) {
    home->total_lights = 0;
}

void add_light(SmartHome *home, const char *name) {
    if (home->total_lights < MAX_LIGHTS) {
        strncpy(home->lights[home->total_lights].name, name, MAX_NAME_LENGTH);
        home->lights[home->total_lights].brightness = 0;
        home->lights[home->total_lights].is_on = 0;
        home->total_lights++;
        printf("Light '%s' added.\n", name);
    } else {
        printf("Maximum number of lights reached.\n");
    }
}

void remove_light(SmartHome *home, const char *name) {
    for (int i = 0; i < home->total_lights; i++) {
        if (strcmp(home->lights[i].name, name) == 0) {
            for (int j = i; j < home->total_lights - 1; j++) {
                home->lights[j] = home->lights[j + 1];
            }
            home->total_lights--;
            printf("Light '%s' removed.\n", name);
            return;
        }
    }
    printf("Light '%s' not found.\n", name);
}

void turn_on_light(SmartHome *home, const char *name) {
    for (int i = 0; i < home->total_lights; i++) {
        if (strcmp(home->lights[i].name, name) == 0) {
            home->lights[i].is_on = 1;
            printf("Light '%s' turned on.\n", name);
            return;
        }
    }
    printf("Light '%s' not found.\n", name);
}

void turn_off_light(SmartHome *home, const char *name) {
    for (int i = 0; i < home->total_lights; i++) {
        if (strcmp(home->lights[i].name, name) == 0) {
            home->lights[i].is_on = 0;
            printf("Light '%s' turned off.\n", name);
            return;
        }
    }
    printf("Light '%s' not found.\n", name);
}

void set_brightness(SmartHome *home, const char *name, int brightness) {
    if (brightness < 0 || brightness > 100) {
        printf("Brightness must be between 0 and 100.\n");
        return;
    }
    
    for (int i = 0; i < home->total_lights; i++) {
        if (strcmp(home->lights[i].name, name) == 0) {
            home->lights[i].brightness = brightness;
            printf("Brightness of light '%s' set to %d.\n", name, brightness);
            return;
        }
    }
    printf("Light '%s' not found.\n", name);
}

void list_lights(SmartHome *home) {
    if (home->total_lights == 0) {
        printf("No lights found.\n");
        return;
    }
    
    printf("Listing all lights:\n");
    for (int i = 0; i < home->total_lights; i++) {
        printf(" - %s | State: %s | Brightness: %d\n",
               home->lights[i].name,
               home->lights[i].is_on ? "On" : "Off",
               home->lights[i].brightness);
    }
}

void show_menu() {
    printf("\nSmart Home Light Control Menu:\n");
    printf("1. Add Light\n");
    printf("2. Remove Light\n");
    printf("3. Turn On Light\n");
    printf("4. Turn Off Light\n");
    printf("5. Set Brightness\n");
    printf("6. List Lights\n");
    printf("7. Exit\n");
    printf("Choose an option: ");
}

int main() {
    SmartHome myHome;
    int choice;
    char name[MAX_NAME_LENGTH];
    int brightness;

    initialize_smart_home(&myHome);

    while (1) {
        show_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter light name: ");
                scanf("%s", name);
                add_light(&myHome, name);
                break;
            case 2:
                printf("Enter light name to remove: ");
                scanf("%s", name);
                remove_light(&myHome, name);
                break;
            case 3:
                printf("Enter light name to turn on: ");
                scanf("%s", name);
                turn_on_light(&myHome, name);
                break;
            case 4:
                printf("Enter light name to turn off: ");
                scanf("%s", name);
                turn_off_light(&myHome, name);
                break;
            case 5:
                printf("Enter light name: ");
                scanf("%s", name);
                printf("Enter brightness (0-100): ");
                scanf("%d", &brightness);
                set_brightness(&myHome, name, brightness);
                break;
            case 6:
                list_lights(&myHome);
                break;
            case 7:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}