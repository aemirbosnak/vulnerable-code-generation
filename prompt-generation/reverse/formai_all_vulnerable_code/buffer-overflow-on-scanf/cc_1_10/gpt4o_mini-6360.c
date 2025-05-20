//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: inquisitive
#include <stdio.h>
#include <string.h>

#define MAX_ROOMS 5
#define ROOM_NAME_LENGTH 20

typedef struct {
    char name[ROOM_NAME_LENGTH];
    int is_on; // 1 for on, 0 for off
} Room;

Room rooms[MAX_ROOMS];
int room_count = 0;

void initialize_rooms() {
    strncpy(rooms[0].name, "Living Room", ROOM_NAME_LENGTH);
    strncpy(rooms[1].name, "Kitchen", ROOM_NAME_LENGTH);
    strncpy(rooms[2].name, "Bedroom", ROOM_NAME_LENGTH);
    strncpy(rooms[3].name, "Bathroom", ROOM_NAME_LENGTH);
    strncpy(rooms[4].name, "Garage", ROOM_NAME_LENGTH);
    room_count = 5;

    for(int i = 0; i < room_count; i++)
        rooms[i].is_on = 0; // Initialize all lights to off
}

void display_rooms() {
    printf("Available Rooms:\n");
    for(int i = 0; i < room_count; i++) {
        printf("%d. %s - Light is %s\n", i + 1, rooms[i].name, rooms[i].is_on ? "ON" : "OFF");
    }
}

void toggle_light(int room_index) {
    rooms[room_index].is_on = !rooms[room_index].is_on;
    printf("The light in the %s has been turned %s.\n", rooms[room_index].name, rooms[room_index].is_on ? "ON" : "OFF");
}

void control_lights() {
    int choice;
    
    while(1) {
        display_rooms();
        printf("Enter room number to toggle light (0 to exit): ");
        scanf("%d", &choice);
        
        if (choice == 0) {
            printf("Exiting the light control system.\n");
            break;
        } else if (choice < 1 || choice > room_count) {
            printf("Invalid room number! Please try again.\n");
        } else {
            toggle_light(choice - 1); // Adjust for 0-based index
        }
    }
}

int main() {
    printf("Welcome to the Smart Home Light Control System!\n");
    initialize_rooms();

    control_lights();

    return 0;
}