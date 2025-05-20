//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 5
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    int is_on;
    int brightness;  // Brightness as a percentage (0-100)
} Room;

void initialize_rooms(Room rooms[], int count) {
    for (int i = 0; i < count; i++) {
        snprintf(rooms[i].name, MAX_NAME_LENGTH, "Room %d", i + 1);
        rooms[i].is_on = 0; // Light is initially off
        rooms[i].brightness = 0; // Brightness is initially 0%
    }
}

void display_rooms(const Room rooms[], int count) {
    printf("\nCurrent Rooms Status:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %s, Brightness: %d%%\n", 
            rooms[i].name, 
            rooms[i].is_on ? "On" : "Off", 
            rooms[i].brightness);
    }
}

void toggle_light(Room *room) {
    room->is_on = !room->is_on; // Toggle the light state
    printf("%s light turned %s.\n", room->name, room->is_on ? "On" : "Off");
}

void set_brightness(Room *room, int brightness) {
    if (brightness >= 0 && brightness <= 100) {
        room->brightness = brightness;
        printf("%s brightness set to %d%%.\n", room->name, room->brightness);
    } else {
        printf("Invalid brightness level. Please enter a value between 0 and 100.\n");
    }
}

int main() {
    Room rooms[MAX_ROOMS];
    int num_rooms = MAX_ROOMS;
    int choice, room_number, brightness;

    initialize_rooms(rooms, num_rooms);

    do {
        printf("\nSmart Home Light Control Menu:\n");
        printf("1. Toggle Light\n");
        printf("2. Set Brightness\n");
        printf("3. Display Room Status\n");
        printf("4. Exit\n");
        printf("Select an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Select room number (1-%d): ", num_rooms);
                scanf("%d", &room_number);
                if (room_number >= 1 && room_number <= num_rooms) {
                    toggle_light(&rooms[room_number - 1]);
                } else {
                    printf("Invalid room number. Please try again.\n");
                }
                break;

            case 2:
                printf("Select room number (1-%d): ", num_rooms);
                scanf("%d", &room_number);
                if (room_number >= 1 && room_number <= num_rooms) {
                    printf("Enter brightness level (0-100): ");
                    scanf("%d", &brightness);
                    set_brightness(&rooms[room_number - 1], brightness);
                } else {
                    printf("Invalid room number. Please try again.\n");
                }
                break;

            case 3:
                display_rooms(rooms, num_rooms);
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}