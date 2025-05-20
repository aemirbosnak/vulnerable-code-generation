//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define ROOM_NAME_LENGTH 30

typedef struct {
    char name[ROOM_NAME_LENGTH];
    int is_on;
} Room;

void display_menu() {
    printf("\n--- Smart Home Light Control ---\n");
    printf("1. Add Room\n");
    printf("2. Control Room Light\n");
    printf("3. Display Room Status\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

void add_room(Room *rooms, int *room_count) {
    if (*room_count >= MAX_ROOMS) {
        printf("Room limit reached. Cannot add more rooms.\n");
        return;
    }
    
    printf("Enter room name: ");
    scanf("%s", rooms[*room_count].name);
    rooms[*room_count].is_on = 0;  // light is off by default
    (*room_count)++;
    printf("Room '%s' added!\n", rooms[*room_count - 1].name);
}

void control_room_light(Room *rooms, int room_count) {
    char room_name[ROOM_NAME_LENGTH];
    printf("Enter room name to control: ");
    scanf("%s", room_name);

    for (int i = 0; i < room_count; i++) {
        if (strcmp(rooms[i].name, room_name) == 0) {
            rooms[i].is_on = !rooms[i].is_on;  // toggle light state
            printf("The light in room '%s' is now %s.\n", rooms[i].name, rooms[i].is_on ? "ON" : "OFF");
            return;
        }
    }
    printf("Room '%s' not found.\n", room_name);
}

void display_room_status(Room *rooms, int room_count) {
    printf("\n--- Current Room Status ---\n");
    for (int i = 0; i < room_count; i++) {
        printf("Room '%s': Light is %s\n", rooms[i].name, rooms[i].is_on ? "ON" : "OFF");
    }
}

int main() {
    Room rooms[MAX_ROOMS];
    int room_count = 0;
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_room(rooms, &room_count);
                break;
            case 2:
                control_room_light(rooms, room_count);
                break;
            case 3:
                display_room_status(rooms, room_count);
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please select again.\n");
                break;
        }
    }
    return 0;
}