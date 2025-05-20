//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    int brightness;  // 0 to 100 scale
    char color[20];  // e.g., "Red", "Green", "Blue", etc.
    int is_on;       // 1 for ON, 0 for OFF
} Room;

void initializeRoom(Room *room, const char *name) {
    strncpy(room->name, name, MAX_NAME_LENGTH);
    room->brightness = 100;
    strncpy(room->color, "White", 20);
    room->is_on = 0; // off initially
}

void displayRoomStatus(const Room *room) {
    printf("Room: %s\n", room->name);
    printf("Status: %s\n", room->is_on ? "ON" : "OFF");
    if (room->is_on) {
        printf("Brightness: %d%%\n", room->brightness);
        printf("Color: %s\n", room->color);
    }
    printf("\n");
}

void turnOn(Room *room) {
    room->is_on = 1;
}

void turnOff(Room *room) {
    room->is_on = 0;
}

void setBrightness(Room *room, int brightness) {
    if (brightness < 0) brightness = 0;
    if (brightness > 100) brightness = 100;
    room->brightness = brightness;
}

void setColor(Room *room, const char *color) {
    strncpy(room->color, color, 20);
}

void listRooms(Room *rooms, int count) {
    for (int i = 0; i < count; ++i) {
        displayRoomStatus(&rooms[i]);
    }
}

int main() {
    Room rooms[MAX_ROOMS];
    int roomCount = 0;
    int choice;

    char roomName[MAX_NAME_LENGTH];
    char color[20];
    int brightness;

    while (1) {
        printf("Smart Home Light Control\n");
        printf("-------------------------\n");
        printf("1. Add room\n");
        printf("2. Turn ON a room\n");
        printf("3. Turn OFF a room\n");
        printf("4. Set brightness\n");
        printf("5. Set color\n");
        printf("6. List rooms\n");
        printf("7. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear newline from input buffer

        switch (choice) {
            case 1:
                if (roomCount < MAX_ROOMS) {
                    printf("Enter room name: ");
                    fgets(roomName, MAX_NAME_LENGTH, stdin);
                    roomName[strcspn(roomName, "\n")] = 0; // Remove newline
                    initializeRoom(&rooms[roomCount], roomName);
                    roomCount++;
                    printf("Room '%s' added.\n", roomName);
                } else {
                    printf("Maximum room limit reached.\n");
                }
                break;

            case 2:
                printf("Enter room name to turn ON: ");
                fgets(roomName, MAX_NAME_LENGTH, stdin);
                roomName[strcspn(roomName, "\n")] = 0;
                for (int i = 0; i < roomCount; i++) {
                    if (strcmp(rooms[i].name, roomName) == 0) {
                        turnOn(&rooms[i]);
                        printf("Room '%s' is now ON.\n", roomName);
                        break;
                    }
                }
                break;

            case 3:
                printf("Enter room name to turn OFF: ");
                fgets(roomName, MAX_NAME_LENGTH, stdin);
                roomName[strcspn(roomName, "\n")] = 0;
                for (int i = 0; i < roomCount; i++) {
                    if (strcmp(rooms[i].name, roomName) == 0) {
                        turnOff(&rooms[i]);
                        printf("Room '%s' is now OFF.\n", roomName);
                        break;
                    }
                }
                break;

            case 4:
                printf("Enter room name for brightness adjustment: ");
                fgets(roomName, MAX_NAME_LENGTH, stdin);
                roomName[strcspn(roomName, "\n")] = 0;
                printf("Set brightness (0-100): ");
                scanf("%d", &brightness);
                for (int i = 0; i < roomCount; i++) {
                    if (strcmp(rooms[i].name, roomName) == 0) {
                        setBrightness(&rooms[i], brightness);
                        printf("Brightness of room '%s' set to %d%%.\n", roomName, brightness);
                        break;
                    }
                }
                break;

            case 5:
                printf("Enter room name to set color: ");
                fgets(roomName, MAX_NAME_LENGTH, stdin);
                roomName[strcspn(roomName, "\n")] = 0;
                printf("Set color (e.g. Red, Green, Blue): ");
                fgets(color, 20, stdin);
                color[strcspn(color, "\n")] = 0;
                for (int i = 0; i < roomCount; i++) {
                    if (strcmp(rooms[i].name, roomName) == 0) {
                        setColor(&rooms[i], color);
                        printf("Color of room '%s' set to %s.\n", roomName, color);
                        break;
                    }
                }
                break;

            case 6:
                listRooms(rooms, roomCount);
                break;

            case 7:
                printf("Exiting Smart Home Control. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}