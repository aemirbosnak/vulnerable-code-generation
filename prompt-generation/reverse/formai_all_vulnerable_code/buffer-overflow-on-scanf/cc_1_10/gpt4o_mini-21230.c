//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 5
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int is_on;
    int brightness;  // Range from 0 to 100
} SmartLight;

SmartLight lights[MAX_ROOMS];
int light_count = 0;

void initialize_lights() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        printf("Enter name for room %d (or 'done' to finish): ", i + 1);
        fgets(lights[i].name, MAX_NAME_LEN, stdin);
        lights[i].name[strcspn(lights[i].name, "\n")] = 0; // Remove newline
        if (strcmp(lights[i].name, "done") == 0) {
            break;
        }
        lights[i].is_on = 0; // Initialize lights to off
        lights[i].brightness = 0; // Initialize brightness to 0
        light_count++;
    }
}

void toggle_light(int index) {
    lights[index].is_on = !lights[index].is_on;
    printf("The light in %s is now %s.\n", lights[index].name, lights[index].is_on ? "ON" : "OFF");
}

void set_brightness(int index, int level) {
    if (level < 0 || level > 100) {
        printf("Invalid brightness level. Please enter a value between 0 and 100.\n");
        return;
    }
    lights[index].brightness = level;
    printf("The brightness in %s is set to %d%%.\n", lights[index].name, lights[index].brightness);
}

void show_menu() {
    printf("\nSmart Home Light Control\n");
    printf("1. Toggle Light\n");
    printf("2. Set Brightness\n");
    printf("3. Show All Lights\n");
    printf("4. Exit\n");
}

void show_all_lights() {
    printf("\n--- Light Status ---\n");
    for (int i = 0; i < light_count; i++) {
        printf("Room: %s, Status: %s, Brightness: %d%%\n", lights[i].name,
               lights[i].is_on ? "ON" : "OFF", lights[i].brightness);
    }
}

int main() {
    int choice, room_number, brightness_level;

    initialize_lights();

    do {
        show_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline left by scanf

        switch (choice) {
            case 1: // Toggle Light
                printf("Enter room number (1 to %d): ", light_count);
                scanf("%d", &room_number);
                getchar(); // Clear newline
                if (room_number < 1 || room_number > light_count) {
                    printf("Invalid room number!\n");
                } else {
                    toggle_light(room_number - 1);
                }
                break;

            case 2: // Set Brightness
                printf("Enter room number (1 to %d): ", light_count);
                scanf("%d", &room_number);
                getchar(); // Clear newline
                if (room_number < 1 || room_number > light_count) {
                    printf("Invalid room number!\n");
                } else {
                    printf("Enter brightness level (0 to 100): ");
                    scanf("%d", &brightness_level);
                    getchar(); // Clear newline
                    set_brightness(room_number - 1, brightness_level);
                }
                break;

            case 3: // Show All Lights
                show_all_lights();
                break;

            case 4: // Exit
                printf("Exiting the smart home light control system.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}