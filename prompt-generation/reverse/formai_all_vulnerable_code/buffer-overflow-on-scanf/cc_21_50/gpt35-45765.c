//FormAI DATASET v1.0 Category: Smart home light control ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum {OFF, ON} light_state;

typedef struct Light {
    int id;
    char name[20];
    bool smart;
    light_state state;
} Light;

typedef struct Room {
    int id;
    char name[20];
    Light *lights;
    int num_lights;
} Room;

int main() {
    // Initialize lights
    Light living_room_lights[] = {{1, "Ceiling", true, OFF}, {2, "Lamp", true, OFF}};
    Light kitchen_lights[] = {{3, "Overhead", true, OFF}, {4, "Counter", true, OFF}, {5, "Pantry", false, OFF}};
    Light bathroom_lights[] = {{6, "vanity", true, OFF}, {7, "Shower", false, OFF}, {8, "Toilet", true, OFF}};
    
    // Initialize rooms
    Room living_room = {1, "Living Room", living_room_lights, 2};
    Room kitchen = {2, "Kitchen", kitchen_lights, 3};
    Room bathroom = {3, "Bathroom", bathroom_lights, 3};
    
    // Loop until user quits
    int choice;
    do {
        printf("Choose a room:\n");
        printf("1. Living Room\n");
        printf("2. Kitchen\n");
        printf("3. Bathroom\n");
        printf("0. Quit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Living Room lights:\n");
                for (int i = 0; i < living_room.num_lights; i++) {
                    printf("%d. %s ", living_room.lights[i].id, living_room.lights[i].name);
                    if (living_room.lights[i].smart) {
                        printf("(%s)\n", living_room.lights[i].state == OFF ? "off" : "on");
                    } else {
                        printf("(manual control)\n");
                    }
                }
                printf("Enter light number to toggle (0 to cancel): ");
                int living_room_choice;
                scanf("%d", &living_room_choice);
                if (living_room_choice > 0) {
                    Light *chosen_light = &living_room.lights[living_room_choice - 1];
                    if (chosen_light->smart) {
                        chosen_light->state = chosen_light->state == OFF ? ON : OFF;
                    } else {
                        printf("This light is not smart and cannot be controlled through the app.\n");
                    }
                }
                break;
            case 2:
                printf("Kitchen lights:\n");
                for (int i = 0; i < kitchen.num_lights; i++) {
                    printf("%d. %s ", kitchen.lights[i].id, kitchen.lights[i].name);
                    if (kitchen.lights[i].smart) {
                        printf("(%s)\n", kitchen.lights[i].state == OFF ? "off" : "on");
                    } else {
                        printf("(manual control)\n");
                    }
                }
                printf("Enter light number to toggle (0 to cancel): ");
                int kitchen_choice;
                scanf("%d", &kitchen_choice);
                if (kitchen_choice > 0) {
                    Light *chosen_light = &kitchen.lights[kitchen_choice - 1];
                    if (chosen_light->smart) {
                        chosen_light->state = chosen_light->state == OFF ? ON : OFF;
                    } else {
                        printf("This light is not smart and cannot be controlled through the app.\n");
                    }
                }
                break;
            case 3:
                printf("Bathroom lights:\n");
                for (int i = 0; i < bathroom.num_lights; i++) {
                    printf("%d. %s ", bathroom.lights[i].id, bathroom.lights[i].name);
                    if (bathroom.lights[i].smart) {
                        printf("(%s)\n", bathroom.lights[i].state == OFF ? "off" : "on");
                    } else {
                        printf("(manual control)\n");
                    }
                }
                printf("Enter light number to toggle (0 to cancel): ");
                int bathroom_choice;
                scanf("%d", &bathroom_choice);
                if (bathroom_choice > 0) {
                    Light *chosen_light = &bathroom.lights[bathroom_choice - 1];
                    if (chosen_light->smart) {
                        chosen_light->state = chosen_light->state == OFF ? ON : OFF;
                    } else {
                        printf("This light is not smart and cannot be controlled through the app.\n");
                    }
                }
                break;
            case 0:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 0);
    
    return 0;
}