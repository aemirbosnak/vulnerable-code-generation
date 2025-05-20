//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LIGHTS 10
#define LIGHT_NAME_LENGTH 50

typedef enum { OFF, ON } LightState;

typedef struct {
    char name[LIGHT_NAME_LENGTH];
    LightState state;
    int brightness; // 0-100
} SmartLight;

SmartLight lights[MAX_LIGHTS];
int light_count = 0;

void init_lights() {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        snprintf(lights[i].name, LIGHT_NAME_LENGTH, "Light %d", i + 1);
        lights[i].state = OFF;
        lights[i].brightness = 0;
    }
    light_count = MAX_LIGHTS;
}

void print_light_status() {
    printf("\nCurrent Light Status:\n");
    for (int i = 0; i < light_count; i++) {
        printf("%s - %s (Brightness: %d)\n", 
            lights[i].name, 
            lights[i].state == ON ? "ON" : "OFF", 
            lights[i].brightness);
    }
    printf("---------------------------\n");
}

void toggle_light(int index) {
    if (index < 0 || index >= light_count) {
        printf("Invalid light index.\n");
        return;
    }
    lights[index].state = (lights[index].state == ON) ? OFF : ON;
    if (lights[index].state == ON) {
        lights[index].brightness = 100; // Default to full brightness if turned ON
        printf("%s turned ON.\n", lights[index].name);
    } else {
        lights[index].brightness = 0; // Turn off brightness
        printf("%s turned OFF.\n", lights[index].name);
    }
}

void set_brightness(int index, int brightness) {
    if (index < 0 || index >= light_count) {
        printf("Invalid light index.\n");
        return;
    }
    if (lights[index].state == OFF) {
        printf("Cannot set brightness. %s is OFF.\n", lights[index].name);
        return;
    }
    if (brightness < 0 || brightness > 100) {
        printf("Brightness must be between 0 and 100.\n");
        return;
    }
    lights[index].brightness = brightness;
    printf("Set brightness of %s to %d.\n", lights[index].name, brightness);
}

void show_menu() {
    printf("1. Toggle Light\n");
    printf("2. Set Brightness\n");
    printf("3. Show Status\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice, index, brightness;

    init_lights();

    while (1) {
        show_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter light index (0 to %d): ", light_count - 1);
                scanf("%d", &index);
                toggle_light(index);
                break;
            case 2:
                printf("Enter light index (0 to %d): ", light_count - 1);
                scanf("%d", &index);
                printf("Enter brightness (0-100): ");
                scanf("%d", &brightness);
                set_brightness(index, brightness);
                break;
            case 3:
                print_light_status();
                break;
            case 4:
                printf("Exiting... Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
        sleep(1); // Pause for clarity
    }

    return 0;
}