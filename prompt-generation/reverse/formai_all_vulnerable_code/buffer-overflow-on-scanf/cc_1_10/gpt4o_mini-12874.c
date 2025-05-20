//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHTS 10
#define MAX_ROOM_NAME 20

typedef enum {
    OFF = 0,
    ON = 1
} LightStatus;

typedef struct {
    char room_name[MAX_ROOM_NAME];
    LightStatus status;
    int brightness; // 0 to 100
} SmartLight;

SmartLight lights[MAX_LIGHTS];
int light_count = 0;

void add_light(const char* room_name) {
    if (light_count < MAX_LIGHTS) {
        strncpy(lights[light_count].room_name, room_name, MAX_ROOM_NAME - 1);
        lights[light_count].status = OFF;
        lights[light_count].brightness = 0;
        light_count++;
        printf("Light added in %s.\n", room_name);
    } else {
        printf("Maximum light limit reached.\n");
    }
}

void toggle_light(const char* room_name) {
    for (int i = 0; i < light_count; i++) {
        if (strcmp(lights[i].room_name, room_name) == 0) {
            lights[i].status = lights[i].status == ON ? OFF : ON;
            printf("Light in %s turned %s.\n", room_name, lights[i].status == ON ? "ON" : "OFF");
            return;
        }
    }
    printf("No light found in %s.\n", room_name);
}

void set_brightness(const char* room_name, int brightness) {
    if (brightness < 0 || brightness > 100) {
        printf("Brightness level must be between 0 and 100.\n");
        return;
    }
    for (int i = 0; i < light_count; i++) {
        if (strcmp(lights[i].room_name, room_name) == 0) {
            lights[i].brightness = brightness;
            printf("Brightness in %s set to %d%%.\n", room_name, brightness);
            return;
        }
    }
    printf("No light found in %s.\n", room_name);
}

void display_lights() {
    if (light_count == 0) {
        printf("No lights configured.\n");
        return;
    }
    for (int i = 0; i < light_count; i++) {
        printf("Room: %s, Status: %s, Brightness: %d%%\n", lights[i].room_name,
               lights[i].status == ON ? "ON" : "OFF", lights[i].brightness);
    }
}

int main() {
    int choice, brightness;
    char room_name[MAX_ROOM_NAME];

    while (1) {
        printf("\nSmart Home Light Control System:\n");
        printf("1. Add Light\n");
        printf("2. Toggle Light\n");
        printf("3. Set Brightness\n");
        printf("4. Display Lights\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter room name: ");
                scanf("%s", room_name);
                add_light(room_name);
                break;
            case 2:
                printf("Enter room name: ");
                scanf("%s", room_name);
                toggle_light(room_name);
                break;
            case 3:
                printf("Enter room name: ");
                scanf("%s", room_name);
                printf("Enter brightness (0-100): ");
                scanf("%d", &brightness);
                set_brightness(room_name, brightness);
                break;
            case 4:
                display_lights();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}