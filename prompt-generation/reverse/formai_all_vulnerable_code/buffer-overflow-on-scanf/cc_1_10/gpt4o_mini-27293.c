//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: cheerful
#include <stdio.h>
#include <string.h>

#define MAX_ROOMS 5
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int is_on;
    int brightness; // 0 to 100
} Room;

void display_menu() {
    printf("\n~~~ Welcome to the Smart Home Light Control System! ~~~\n");
    printf("1. Turn light ON\n");
    printf("2. Turn light OFF\n");
    printf("3. Set brightness\n");
    printf("4. Display light status\n");
    printf("5. Exit\n");
    printf("Select an option (1-5): ");
}

void turn_on_light(Room *room) {
    room->is_on = 1;
    printf("The light in the %s is now ON! 🎉\n", room->name);
}

void turn_off_light(Room *room) {
    room->is_on = 0;
    printf("The light in the %s is now OFF. 🌙\n", room->name);
}

void set_brightness(Room *room) {
    int brightness;
    printf("Enter brightness level for %s (0-100): ", room->name);
    scanf("%d", &brightness);
    if (brightness < 0 || brightness > 100) {
        printf("Oops! Please enter a valid brightness level. 😅\n");
    } else {
        room->brightness = brightness;
        printf("The brightness in the %s is set to %d%%. ✨\n", room->name, brightness);
    }
}

void display_status(Room *room) {
    printf("Light status in %s: %s\n", room->name, room->is_on ? "ON" : "OFF");
    if (room->is_on) {
        printf("Brightness level: %d%%\n", room->brightness);
    }
}

int main() {
    Room rooms[MAX_ROOMS] = {
        {"Living Room", 0, 0},
        {"Kitchen", 0, 0},
        {"Bedroom", 0, 0},
        {"Bathroom", 0, 0},
        {"Hallway", 0, 0},
    };

    int choice;
    int room_number;

    printf("Welcome to your cheerful smart home! 🌈 Let's control the lights!\n");

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Choose room number (0: Living Room, 1: Kitchen, 2: Bedroom, 3: Bathroom, 4: Hallway): ");
                scanf("%d", &room_number);
                if (room_number < 0 || room_number >= MAX_ROOMS) {
                    printf("Oops! Invalid room number. Please try again.\n");
                } else {
                    turn_on_light(&rooms[room_number]);
                }
                break;

            case 2:
                printf("Choose room number (0: Living Room, 1: Kitchen, 2: Bedroom, 3: Bathroom, 4: Hallway): ");
                scanf("%d", &room_number);
                if (room_number < 0 || room_number >= MAX_ROOMS) {
                    printf("Oops! Invalid room number. Please try again.\n");
                } else {
                    turn_off_light(&rooms[room_number]);
                }
                break;

            case 3:
                printf("Choose room number (0: Living Room, 1: Kitchen, 2: Bedroom, 3: Bathroom, 4: Hallway): ");
                scanf("%d", &room_number);
                if (room_number < 0 || room_number >= MAX_ROOMS) {
                    printf("Oops! Invalid room number. Please try again.\n");
                } else {
                    set_brightness(&rooms[room_number]);
                }
                break;

            case 4:
                printf("Choose room number (0: Living Room, 1: Kitchen, 2: Bedroom, 3: Bathroom, 4: Hallway): ");
                scanf("%d", &room_number);
                if (room_number < 0 || room_number >= MAX_ROOMS) {
                    printf("Oops! Invalid room number. Please try again.\n");
                } else {
                    display_status(&rooms[room_number]);
                }
                break;

            case 5:
                printf("Exiting the Smart Home Light Control System. Have a bright day! 🌞\n");
                return 0;

            default:
                printf("Invalid option! Please try again. 🎈\n");
        }
    }

    return 0;
}