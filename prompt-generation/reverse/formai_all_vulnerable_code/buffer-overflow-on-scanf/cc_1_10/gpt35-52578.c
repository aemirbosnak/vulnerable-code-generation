//FormAI DATASET v1.0 Category: Smart home light control ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Defining constants for pin numbers
#define BEDROOM_LIGHT 2
#define KITCHEN_LIGHT 3
#define LIVINGROOM_LIGHT 4

// Function to turn on light for a given pin number
void turn_on_light(int pin_number) {
    printf("Turning on light for pin %d\n", pin_number);
    // Code to turn on light for pin_number
}

// Function to turn off light for a given pin number
void turn_off_light(int pin_number) {
    printf("Turning off light for pin %d\n", pin_number);
    // Code to turn off light for pin_number
}

int main() {
    int selected_room;
    bool is_light_on = false;
    bool valid_room_selected = false;
    
    // User interface for selecting a room to control light for
    printf("Select a room to control light for:\n");
    printf("1. Bedroom\n");
    printf("2. Kitchen\n");
    printf("3. Living Room\n");
    
    do {
        scanf("%d", &selected_room);
        switch(selected_room) {
            case 1: printf("You have selected the Bedroom\n");
                    valid_room_selected = true;
                    break;
            case 2: printf("You have selected the Kitchen\n");
                    valid_room_selected = true;
                    break;
            case 3: printf("You have selected the Living Room\n");
                    valid_room_selected = true;
                    break;
            default: printf("Invalid room number selected. Please select again:\n");
                     break;
        }
    } while(!valid_room_selected);
    
    // User interface for controlling the selected room's light
    printf("Enter 1 to turn on light and 0 to turn off light for the selected room:\n");
    scanf("%d", &is_light_on);
    
    switch(selected_room) {
        case 1: if(is_light_on) {
                    turn_on_light(BEDROOM_LIGHT);
                } else {
                    turn_off_light(BEDROOM_LIGHT);
                }
                break;
        case 2: if(is_light_on) {
                    turn_on_light(KITCHEN_LIGHT);
                } else {
                    turn_off_light(KITCHEN_LIGHT);
                }
                break;
        case 3: if(is_light_on) {
                    turn_on_light(LIVINGROOM_LIGHT);
                } else {
                    turn_off_light(LIVINGROOM_LIGHT);
                }
                break;        
    }
    
    return 0;
}