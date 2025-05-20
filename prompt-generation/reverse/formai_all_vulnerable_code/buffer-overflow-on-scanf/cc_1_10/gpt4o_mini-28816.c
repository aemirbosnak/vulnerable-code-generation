//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ROOMS 10
#define NAME_LEN 20

typedef struct {
    char name[NAME_LEN];
    int is_on;
} Room;

void printWelcomeMessage();
void listRooms(Room rooms[], int room_count);
void toggleLight(Room* room);
void statusUpdate(Room room);

int main() {
    Room rooms[MAX_ROOMS] = {
        {"Living Room", 0},
        {"Kitchen", 0},
        {"Bedroom", 0},
        {"Bathroom", 0},
        {"Dining Room", 0},
        {"Garage", 0},
        {"Hallway", 0},
        {"Office", 0},
        {"Patio", 0},
        {"Guest Room", 0}
    };

    int room_count = 10;
    char command[50];
    
    printWelcomeMessage();

    while (1) {
        printf("\nEnter a command (list, toggle [room name], exit): ");
        scanf(" %[^\n]", command);

        if (strcmp(command, "exit") == 0) {
            printf("Thank you for using the smart home light control system. Goodbye!\n");
            break;
        } else if (strcmp(command, "list") == 0) {
            listRooms(rooms, room_count);
        } else {
            char room_name[NAME_LEN];
            sscanf(command, "toggle %s", room_name);
            int found = 0;
            
            for (int i = 0; i < room_count; i++) {
                if (strcmp(rooms[i].name, room_name) == 0) {
                    toggleLight(&rooms[i]);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Room '%s' not found. Please try again.\n", room_name);
            }
        }
    }

    return 0;
}

void printWelcomeMessage() {
    printf("Welcome to the Smart Home Light Control System!\n");
    printf("We are grateful for your interest in making your home smarter and more efficient.\n");
    printf("Get started by typing 'list' to see available rooms.\n");
}

void listRooms(Room rooms[], int room_count) {
    printf("Available Rooms:\n");
    for (int i = 0; i < room_count; i++) {
        printf(" - %s (Currently: %s)\n", rooms[i].name, rooms[i].is_on ? "ON" : "OFF");
    }
    printf("Feel free to toggle the lights on or off!\n");
}

void toggleLight(Room* room) {
    room->is_on = !room->is_on;
    statusUpdate(*room);
}

void statusUpdate(Room room) {
    if (room.is_on) {
        printf("The light in the %s is now ON. Thank you for brightening up your space!\n", room.name);
    } else {
        printf("The light in the %s is now OFF. Thank you for conserving energy!\n", room.name);
    }
}