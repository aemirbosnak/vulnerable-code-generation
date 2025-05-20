//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LIGHTS 10
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int state; // 0 for OFF, 1 for ON
    int brightness; // 0 to 100
} SmartLight;

SmartLight lights[MAX_LIGHTS];
int light_count = 0;

void add_light(const char* name) {
    if (light_count < MAX_LIGHTS) {
        strncpy(lights[light_count].name, name, NAME_LENGTH);
        lights[light_count].state = 0; // Light is initially OFF
        lights[light_count].brightness = 0; // Brightness is initially 0
        light_count++;
        printf("Added light: %s\n", name);
    } else {
        printf("Max light limit reached. Cannot add more lights.\n");
    }
}

void toggle_light(int index) {
    if (index >= 0 && index < light_count) {
        lights[index].state = !lights[index].state; // Toggle the state
        printf("Light '%s' is now %s\n", lights[index].name, lights[index].state ? "ON" : "OFF");
    } else {
        printf("Invalid light index.\n");
    }
}

void set_brightness(int index, int brightness) {
    if (index >= 0 && index < light_count) {
        if (brightness >= 0 && brightness <= 100) {
            lights[index].brightness = brightness;
            printf("Brightness of light '%s' set to %d%%\n", lights[index].name, brightness);
        } else {
            printf("Brightness value must be between 0 and 100.\n");
        }
    } else {
        printf("Invalid light index.\n");
    }
}

void show_light_status() {
    printf("\nCurrent light settings:\n");
    for (int i = 0; i < light_count; i++) {
        printf("Light %d: %s, Status: %s, Brightness: %d%%\n", 
               i + 1, lights[i].name, 
               lights[i].state ? "ON" : "OFF", 
               lights[i].brightness);
    }
}

void command_line_interface() {
    int choice, index, brightness;
    char name[NAME_LENGTH];

    while(1) {
        printf("\n--- Smart Home Light Control ---\n");
        printf("1. Add Light\n");
        printf("2. Toggle Light\n");
        printf("3. Set Brightness\n");
        printf("4. Show Light Status\n");
        printf("0. Quit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter light name: ");
                scanf("%s", name);
                add_light(name);
                break;
            case 2:
                printf("Enter light index to toggle (1-%d): ", light_count);
                scanf("%d", &index);
                toggle_light(index - 1);
                break;
            case 3:
                printf("Enter light index to set brightness (1-%d): ", light_count);
                scanf("%d", &index);
                printf("Enter brightness (0-100): ");
                scanf("%d", &brightness);
                set_brightness(index - 1, brightness);
                break;
            case 4:
                show_light_status();
                break;
            case 0:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}

int main() {
    printf("Welcome to the Smart Home Light Control System!\n");
    command_line_interface();
    return 0;
}