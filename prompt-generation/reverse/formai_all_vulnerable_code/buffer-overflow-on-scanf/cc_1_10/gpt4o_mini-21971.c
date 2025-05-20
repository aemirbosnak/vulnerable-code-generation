//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10

typedef struct {
    char name[30];
    int is_on;
} Room;

Room rooms[MAX_ROOMS];
int room_count = 0;

void add_room(const char *name) {
    if (room_count < MAX_ROOMS) {
        strcpy(rooms[room_count].name, name);
        rooms[room_count].is_on = 0; // Light is off by default
        room_count++;
        printf("Thank you for adding the %s room! Your home is becoming smarter.\n", name);
    } else {
        printf("Oh no! We've reached the limit of rooms. Please remove a room first.\n");
    }
}

void toggle_light(const char *room_name) {
    for (int i = 0; i < room_count; i++) {
        if (strcmp(rooms[i].name, room_name) == 0) {
            rooms[i].is_on = !rooms[i].is_on; // Toggle the light state
            if (rooms[i].is_on) {
                printf("The light in %s is now ON. Thank you for brightening the space!\n", rooms[i].name);
            } else {
                printf("The light in %s is now OFF. Thank you for saving energy!\n", rooms[i].name);
            }
            return;
        }
    }
    printf("There is no room named %s in the system. Please check and try again!\n", room_name);
}

void display_rooms() {
    printf("Here's a list of your smart rooms:\n");
    for (int i = 0; i < room_count; i++) {
        printf("%d. %s - Light is %s\n", i + 1, rooms[i].name, rooms[i].is_on ? "ON" : "OFF");
    }
}

int main() {
    int choice;
    char room_name[30];

    while (1) {
        printf("\nSmart Home Light Control System\n");
        printf("1. Add Room\n");
        printf("2. Toggle Light\n");
        printf("3. Display Rooms\n");
        printf("4. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the room to add: ");
                scanf("%s", room_name);
                add_room(room_name);
                break;
            case 2:
                printf("Enter the name of the room to toggle light: ");
                scanf("%s", room_name);
                toggle_light(room_name);
                break;
            case 3:
                display_rooms();
                break;
            case 4:
                printf("Thank you for using the Smart Home Light Control System. Have a brilliant day ahead!\n");
                exit(0);
            default:
                printf("Invalid choice. Please choose again!\n");
        }
    }

    return 0;
}