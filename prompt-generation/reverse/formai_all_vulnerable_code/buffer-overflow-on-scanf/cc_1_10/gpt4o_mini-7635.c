//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 5
#define ROOM_NAME_LENGTH 20

typedef struct {
    char name[ROOM_NAME_LENGTH];
    int is_on;
} Room;

void display_rooms(Room rooms[], int room_count) {
    printf("\nAvailable rooms:\n");
    for (int i = 0; i < room_count; i++) {
        printf("%d. %s - %s\n", i + 1, rooms[i].name, rooms[i].is_on ? "On" : "Off");
    }
}

void control_light(Room *room) {
    if (room->is_on) {
        room->is_on = 0;
        printf("Thank you for turning off the lights in the %s.\n", room->name);
    } else {
        room->is_on = 1;
        printf("Thank you for turning on the lights in the %s!\n", room->name);
    }
}

int main() {
    Room rooms[MAX_ROOMS] = {
        {"Living Room", 0},
        {"Kitchen", 0},
        {"Bedroom", 0},
        {"Bathroom", 0},
        {"Garage", 0}
    };
    int room_count = 5;
    int choice;
    char continue_choice;

    printf("Welcome to the Smart Home Light Control System!\n");
    
    do {
        display_rooms(rooms, room_count);
        printf("Please select a room to control the light (1-%d): ", room_count);
        scanf("%d", &choice);

        if (choice < 1 || choice > room_count) {
            printf("That's not a valid choice. Please try again.\n");
            continue;
        }

        control_light(&rooms[choice - 1]);

        printf("\nWould you like to control another room? (y/n): ");
        scanf(" %c", &continue_choice);

    } while (continue_choice == 'y' || continue_choice == 'Y');
    
    printf("Thank you for using the Smart Home Light Control System. Have a great day!\n");

    return 0;
}