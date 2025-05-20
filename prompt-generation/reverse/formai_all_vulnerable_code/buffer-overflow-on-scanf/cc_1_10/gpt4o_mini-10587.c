//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: real-life
#include <stdio.h>
#include <stdint.h>

// Define constants for different lights using bit shifting
#define LIGHT_LIVING_ROOM (1 << 0) // 0b00000001
#define LIGHT_BEDROOM     (1 << 1) // 0b00000010
#define LIGHT_KITCHEN     (1 << 2) // 0b00000100
#define LIGHT_BATHROOM    (1 << 3) // 0b00001000
#define LIGHT_GARAGE      (1 << 4) // 0b00010000

// Function to turn on a light
uint8_t turn_on_light(uint8_t lights, uint8_t light) {
    return lights | light;
}

// Function to turn off a light
uint8_t turn_off_light(uint8_t lights, uint8_t light) {
    return lights & ~light;
}

// Function to toggle a light
uint8_t toggle_light(uint8_t lights, uint8_t light) {
    return lights ^ light;
}

// Function to display the current status of the lights
void display_lights_status(uint8_t lights) {
    printf("Current Lights Status:\n");
    printf("Living Room: %s\n", (lights & LIGHT_LIVING_ROOM) ? "ON" : "OFF");
    printf("Bedroom: %s\n", (lights & LIGHT_BEDROOM) ? "ON" : "OFF");
    printf("Kitchen: %s\n", (lights & LIGHT_KITCHEN) ? "ON" : "OFF");
    printf("Bathroom: %s\n", (lights & LIGHT_BATHROOM) ? "ON" : "OFF");
    printf("Garage: %s\n", (lights & LIGHT_GARAGE) ? "ON" : "OFF");
}

int main() {
    uint8_t lights = 0; // Initial state of lights (all OFF)
    int choice;

    while (1) {
        printf("\nSmart Home Light Control\n");
        printf("1. Turn On Living Room Light\n");
        printf("2. Turn Off Living Room Light\n");
        printf("3. Toggle Living Room Light\n");
        printf("4. Turn On Bedroom Light\n");
        printf("5. Turn Off Bedroom Light\n");
        printf("6. Toggle Bedroom Light\n");
        printf("7. Turn On Kitchen Light\n");
        printf("8. Turn Off Kitchen Light\n");
        printf("9. Toggle Kitchen Light\n");
        printf("10. Display Current Lights Status\n");
        printf("11. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                lights = turn_on_light(lights, LIGHT_LIVING_ROOM);
                break;
            case 2:
                lights = turn_off_light(lights, LIGHT_LIVING_ROOM);
                break;
            case 3:
                lights = toggle_light(lights, LIGHT_LIVING_ROOM);
                break;
            case 4:
                lights = turn_on_light(lights, LIGHT_BEDROOM);
                break;
            case 5:
                lights = turn_off_light(lights, LIGHT_BEDROOM);
                break;
            case 6:
                lights = toggle_light(lights, LIGHT_BEDROOM);
                break;
            case 7:
                lights = turn_on_light(lights, LIGHT_KITCHEN);
                break;
            case 8:
                lights = turn_off_light(lights, LIGHT_KITCHEN);
                break;
            case 9:
                lights = toggle_light(lights, LIGHT_KITCHEN);
                break;
            case 10:
                display_lights_status(lights);
                break;
            case 11:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }

        display_lights_status(lights);
    }

    return 0;
}