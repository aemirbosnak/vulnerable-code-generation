//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LIGHTS 10

typedef enum {
    OFF,
    ON
} LightState;

typedef struct {
    char name[50];
    LightState state;
    int brightness; // 0 to 100
} SmartLight;

SmartLight lights[MAX_LIGHTS];
int light_count = 0;

// Function to initialize the lights
void init_lights() {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        snprintf(lights[i].name, sizeof(lights[i].name), "Light %d", i+1);
        lights[i].state = OFF;
        lights[i].brightness = 0;
    }
    light_count = MAX_LIGHTS;
}

// Function to toggle the state of a light
void toggle_light(int index) {
    if (index < 0 || index >= light_count) {
        printf("Invalid light index: %d\n", index);
        return;
    }
    
    lights[index].state = (lights[index].state == OFF) ? ON : OFF;
    printf("%s is now %s\n", lights[index].name, lights[index].state == ON ? "ON" : "OFF");
}

// Function to set the brightness of a light
void set_brightness(int index, int brightness) {
    if (index < 0 || index >= light_count) {
        printf("Invalid light index: %d\n", index);
        return;
    }
    
    if (brightness < 0 || brightness > 100) {
        printf("Brightness must be between 0 and 100\n");
        return;
    }

    lights[index].brightness = brightness;
    printf("Set brightness of %s to %d%%\n", lights[index].name, brightness);
}

// Function to get the state of a light
void get_light_status(int index) {
    if (index < 0 || index >= light_count) {
        printf("Invalid light index: %d\n", index);
        return;
    }

    printf("%s is %s with brightness %d%%\n", 
        lights[index].name, 
        lights[index].state == ON ? "ON" : "OFF", 
        lights[index].brightness);
}

// Function to list all lights
void list_lights() {
    printf("Listing all lights:\n");
    for (int i = 0; i < light_count; i++) {
        printf("%d: %s - %s at %d%%\n", 
            i, 
            lights[i].name, 
            lights[i].state == ON ? "ON" : "OFF", 
            lights[i].brightness);
    }
}

// Function to display the menu
void display_menu() {
    printf("\nSmart Home Light Control Menu:\n");
    printf("1. Toggle Light\n");
    printf("2. Set Brightness\n");
    printf("3. Get Light Status\n");
    printf("4. List All Lights\n");
    printf("5. Exit\n");
}

int main() {
    int choice, light_index, brightness;

    init_lights();

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter light index to toggle (0 to %d): ", light_count - 1);
                scanf("%d", &light_index);
                toggle_light(light_index);
                break;

            case 2:
                printf("Enter light index to set brightness (0 to %d): ", light_count - 1);
                scanf("%d", &light_index);
                printf("Enter brightness (0 to 100): ");
                scanf("%d", &brightness);
                set_brightness(light_index, brightness);
                break;

            case 3:
                printf("Enter light index to get status (0 to %d): ", light_count - 1);
                scanf("%d", &light_index);
                get_light_status(light_index);
                break;

            case 4:
                list_lights();
                break;

            case 5:
                printf("Exiting program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
        
        sleep(1); // Pausing for a second for better usability
    }

    return 0;
}