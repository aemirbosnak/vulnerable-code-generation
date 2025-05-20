//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LIGHTS 10
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    int is_on;
    int brightness; // 0 to 100
    char color[NAME_LENGTH];
} SmartLight;

SmartLight lights[MAX_LIGHTS];
int light_count = 0;

void initialize_lights() {
    // Initialize some lights with default values
    for(int i = 0; i < MAX_LIGHTS; i++) {
        snprintf(lights[i].name, NAME_LENGTH, "Light %d", i + 1);
        lights[i].is_on = 0; // All lights are off initially
        lights[i].brightness = 0; // Brightness starts at 0
        snprintf(lights[i].color, NAME_LENGTH, "White"); // Default color
    }
    light_count = MAX_LIGHTS; // Set the initial count
}

void turn_on_light(int index) {
    if (index >= 0 && index < light_count) {
        lights[index].is_on = 1;
        printf("%s turned ON\n", lights[index].name);
    } else {
        printf("Invalid light index!\n");
    }
}

void turn_off_light(int index) {
    if (index >= 0 && index < light_count) {
        lights[index].is_on = 0;
        printf("%s turned OFF\n", lights[index].name);
    } else {
        printf("Invalid light index!\n");
    }
}

void set_brightness(int index, int brightness) {
    if (index >= 0 && index < light_count) {
        if (brightness >= 0 && brightness <= 100) {
            lights[index].brightness = brightness;
            printf("Brightness of %s set to %d%%\n", lights[index].name, brightness);
        } else {
            printf("Brightness must be between 0 and 100!\n");
        }
    } else {
        printf("Invalid light index!\n");
    }
}

void change_color(int index, const char *color) {
    if (index >= 0 && index < light_count) {
        snprintf(lights[index].color, NAME_LENGTH, "%s", color);
        printf("Color of %s changed to %s\n", lights[index].name, lights[index].color);
    } else {
        printf("Invalid light index!\n");
    }
}

void status_report() {
    printf("\n--- Smart Light Status Report ---\n");
    for (int i = 0; i < light_count; i++) {
        char *status = lights[i].is_on ? "ON" : "OFF";
        printf("%s: %s, Brightness: %d%%, Color: %s\n",
               lights[i].name, status, lights[i].brightness, lights[i].color);
    }
    printf("----------------------------------\n");
}

void show_menu() {
    printf("\n=== Smart Home Light Control ===\n");
    printf("1. Turn ON Light\n");
    printf("2. Turn OFF Light\n");
    printf("3. Set Brightness\n");
    printf("4. Change Color\n");
    printf("5. Status Report\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    initialize_lights();

    while (1) {
        show_menu();
        int choice;
        scanf("%d", &choice);

        if (choice == 6) {
            printf("Exiting Smart Home Light Control...\n");
            break;
        }

        int index, brightness;
        char color[NAME_LENGTH];

        switch (choice) {
            case 1:
                printf("Enter light index to turn ON (1-%d): ", light_count);
                scanf("%d", &index);
                turn_on_light(index - 1);
                break;
            case 2:
                printf("Enter light index to turn OFF (1-%d): ", light_count);
                scanf("%d", &index);
                turn_off_light(index - 1);
                break;
            case 3:
                printf("Enter light index to set brightness (1-%d): ", light_count);
                scanf("%d", &index);
                printf("Enter brightness level (0-100): ");
                scanf("%d", &brightness);
                set_brightness(index - 1, brightness);
                break;
            case 4:
                printf("Enter light index to change color (1-%d): ", light_count);
                scanf("%d", &index);
                printf("Enter new color: ");
                scanf("%s", color);
                change_color(index - 1, color);
                break;
            case 5:
                status_report();
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}