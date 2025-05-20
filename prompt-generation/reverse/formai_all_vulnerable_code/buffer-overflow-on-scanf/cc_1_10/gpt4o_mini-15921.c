//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LIGHTS 10
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    int is_on;
    int brightness;
} SmartLight;

SmartLight lights[MAX_LIGHTS];
int num_lights = 0;

void add_light(const char* name) {
    if (num_lights < MAX_LIGHTS) {
        strncpy(lights[num_lights].name, name, NAME_LENGTH);
        lights[num_lights].is_on = 0;  // light is off by default
        lights[num_lights].brightness = 0;  // brightness ranges from 0 to 100
        num_lights++;
        printf("Added light: %s\n", name);
    } else {
        printf("Maximum number of lights reached!\n");
    }
}

void toggle_light(const char* name) {
    for (int i = 0; i < num_lights; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            lights[i].is_on = !lights[i].is_on;
            printf("Light %s is now %s\n", lights[i].name, lights[i].is_on ? "ON" : "OFF");
            return;
        }
    }
    printf("No light found with name: %s\n", name);
}

void set_brightness(const char* name, int brightness) {
    if (brightness < 0 || brightness > 100) {
        printf("Brightness must be between 0 and 100!\n");
        return;
    }
    for (int i = 0; i < num_lights; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            lights[i].brightness = brightness;
            printf("Set brightness of %s to %d%%\n", lights[i].name, brightness);
            return;
        }
    }
    printf("No light found with name: %s\n", name);
}

void show_status() {
    printf("\n--- Smart Home Light Status ---\n");
    for (int i = 0; i < num_lights; i++) {
        printf("Light Name: %s | Status: %s | Brightness: %d%%\n", 
               lights[i].name, lights[i].is_on ? "ON" : "OFF", lights[i].brightness);
    }
    printf("-------------------------------\n\n");
}

int main() {
    int choice;
    char name[NAME_LENGTH];
    int brightness;

    while (1) {
        printf("Smart Home Light Control\n");
        printf("1. Add Light\n");
        printf("2. Toggle Light\n");
        printf("3. Set Brightness\n");
        printf("4. Show Status\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
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
                show_status();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
        sleep(1);
    }
    return 0;
}