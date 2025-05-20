//FormAI DATASET v1.0 Category: Smart home light control ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool living_room_lights_on = false;
bool bedroom_lights_on = false;
bool kitchen_lights_on = false;
bool bathroom_lights_on = false;


void turn_off_all_lights() {
    living_room_lights_on = false;
    bedroom_lights_on = false;
    kitchen_lights_on = false;
    bathroom_lights_on = false;
}


void show_current_light_status() {
    printf("\nLiving Room Lights: %s", living_room_lights_on ? "On" : "Off");
    printf("\nBedroom Lights: %s", bedroom_lights_on ? "On" : "Off");
    printf("\nKitchen Lights: %s", kitchen_lights_on ? "On" : "Off");
    printf("\nBathroom Lights: %s", bathroom_lights_on ? "On" : "Off");
}


void toggle_living_room_lights() {
    living_room_lights_on = !living_room_lights_on;
}


void toggle_bedroom_lights() {
    bedroom_lights_on = !bedroom_lights_on;
}


void toggle_kitchen_lights() {
    kitchen_lights_on = !kitchen_lights_on;
}


void toggle_bathroom_lights() {
    bathroom_lights_on = !bathroom_lights_on;
}


int main() {
    printf("Welcome to Smart Home Light Control");

    bool is_running = true;
    while (is_running) {
        printf("\n\nSelect an option below:");
        printf("\n1. Turn off all lights");
        printf("\n2. Show current light status");
        printf("\n3. Toggle Living Room Lights");
        printf("\n4. Toggle Bedroom Lights");
        printf("\n5. Toggle Kitchen Lights");
        printf("\n6. Toggle Bathroom Lights");
        printf("\n7. Exit");

        int option;
        scanf("%d", &option);

        switch (option) {
            case 1:
                turn_off_all_lights();
                break;
            case 2:
                show_current_light_status();
                break;
            case 3:
                toggle_living_room_lights();
                break;
            case 4:
                toggle_bedroom_lights();
                break;
            case 5:
                toggle_kitchen_lights();
                break;
            case 6:
                toggle_bathroom_lights();
                break;
            case 7:
                is_running = false;
                break;
            default:
                printf("\nInvalid option selected");
        }
    }

    printf("\nExiting Smart Home Light Control");

    return 0;
}