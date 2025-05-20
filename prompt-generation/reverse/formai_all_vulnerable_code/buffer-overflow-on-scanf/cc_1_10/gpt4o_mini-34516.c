//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int is_on;
    int brightness; // Brightness level from 0 to 100
} Room;

void initialize_rooms(Room rooms[], int room_count) {
    for (int i = 0; i < room_count; i++) {
        snprintf(rooms[i].name, sizeof(rooms[i].name), "Room %d", i + 1);
        rooms[i].is_on = 0;
        rooms[i].brightness = 0;
    }
}

void display_rooms(Room rooms[], int room_count) {
    printf("\nCurrent Light Status:\n");
    for (int i = 0; i < room_count; i++) {
        printf("%s: %s, Brightness: %d%%\n", rooms[i].name, 
            rooms[i].is_on ? "On" : "Off", rooms[i].brightness);
    }
}

void toggle_light(Room *room) {
    room->is_on = !room->is_on;
    printf("%s has been turned %s\n", room->name, room->is_on ? "On" : "Off");
}

void set_brightness(Room *room, int level) {
    if (level >= 0 && level <= 100) {
        room->brightness = level;
        printf("Brightness of %s set to %d%%\n", room->name, room->brightness);
    } else {
        printf("Invalid brightness level. Please choose between 0 and 100.\n");
    }
}

void calming_mode(Room *room) {
    if (room->is_on) {
        // Gradually change brightness to a comfortable level for relaxation
        for (int i = 100; i >= 20; i -= 10) {
            set_brightness(room, i);
            printf("Adjusting lights for a calming effect. Current brightness: %d%%\n", i);
            sleep(1); // Sleep for a second to simulate dimming effect
        }
        printf("Calming mode activated in %s.\n", room->name);
    } else {
        printf("%s is off. Please turn it on first.\n", room->name);
    }
}

int main() {
    Room rooms[MAX_ROOMS];
    int room_count = 3; // Example: 3 rooms
    initialize_rooms(rooms, room_count);
    
    int choice, room_index, brightness_level;

    while (1) {
        display_rooms(rooms, room_count);
        
        printf("\nChoose an option:\n");
        printf("1. Toggle Light\n");
        printf("2. Set Brightness\n");
        printf("3. Calming Mode\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Select room (1 to %d): ", room_count);
                scanf("%d", &room_index);
                if (room_index > 0 && room_index <= room_count) {
                    toggle_light(&rooms[room_index - 1]);
                } else {
                    printf("Invalid room selection. Please try again.\n");
                }
                break;
            case 2:
                printf("Select room (1 to %d): ", room_count);
                scanf("%d", &room_index);
                if (room_index > 0 && room_index <= room_count) {
                    printf("Enter brightness level (0 to 100): ");
                    scanf("%d", &brightness_level);
                    set_brightness(&rooms[room_index - 1], brightness_level);
                } else {
                    printf("Invalid room selection. Please try again.\n");
                }
                break;
            case 3:
                printf("Select room for calming mode (1 to %d): ", room_count);
                scanf("%d", &room_index);
                if (room_index > 0 && room_index <= room_count) {
                    calming_mode(&rooms[room_index - 1]);
                } else {
                    printf("Invalid room selection. Please try again.\n");
                }
                break;
            case 4:
                printf("Exiting the program. Have a great day!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}