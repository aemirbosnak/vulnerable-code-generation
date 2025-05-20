//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define ROOM_NAME_LENGTH 30

typedef struct {
    char name[ROOM_NAME_LENGTH];
    int isOn;
    int brightness; // 0 to 100
} Room;

Room rooms[MAX_ROOMS];
int roomCount = 0;

void initializeRooms() {
    strcpy(rooms[0].name, "Living Room");
    rooms[0].isOn = 0;
    rooms[0].brightness = 0;

    strcpy(rooms[1].name, "Bedroom");
    rooms[1].isOn = 0;
    rooms[1].brightness = 0;

    strcpy(rooms[2].name, "Kitchen");
    rooms[2].isOn = 0;
    rooms[2].brightness = 0;

    roomCount = 3;
}

void displayRoomStatus() {
    printf("\nRoom Status:\n");
    for (int i = 0; i < roomCount; i++) {
        printf(" - %s: %s, Brightness: %d%%\n", 
            rooms[i].name,
            rooms[i].isOn ? "On" : "Off",
            rooms[i].brightness);
    }
}

void turnOnLight(int roomIndex) {
    rooms[roomIndex].isOn = 1;
    printf("The light in the %s is now ON.\n", rooms[roomIndex].name);
}

void turnOffLight(int roomIndex) {
    rooms[roomIndex].isOn = 0;
    printf("The light in the %s is now OFF.\n", rooms[roomIndex].name);
}

void setBrightness(int roomIndex, int brightness) {
    if (brightness < 0 || brightness > 100) {
        printf("Brightness must be between 0 and 100.\n");
        return;
    }
    rooms[roomIndex].brightness = brightness;
    printf("Brightness in the %s is set to %d%%.\n", rooms[roomIndex].name, brightness);
}

void controlLights() {
    int choice, roomIndex, brightness;

    do {
        printf("\nSmart Home Light Control\n");
        printf("1. Display room status\n");
        printf("2. Turn ON light\n");
        printf("3. Turn OFF light\n");
        printf("4. Set Brightness\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayRoomStatus();
                break;
            case 2:
                printf("Select room (0: Living Room, 1: Bedroom, 2: Kitchen): ");
                scanf("%d", &roomIndex);
                if (roomIndex >= 0 && roomIndex < roomCount) {
                    turnOnLight(roomIndex);
                } else {
                    printf("Invalid room selection.\n");
                }
                break;
            case 3:
                printf("Select room (0: Living Room, 1: Bedroom, 2: Kitchen): ");
                scanf("%d", &roomIndex);
                if (roomIndex >= 0 && roomIndex < roomCount) {
                    turnOffLight(roomIndex);
                } else {
                    printf("Invalid room selection.\n");
                }
                break;
            case 4:
                printf("Select room (0: Living Room, 1: Bedroom, 2: Kitchen): ");
                scanf("%d", &roomIndex);
                if (roomIndex >= 0 && roomIndex < roomCount) {
                    printf("Enter brightness (0-100): ");
                    scanf("%d", &brightness);
                    setBrightness(roomIndex, brightness);
                } else {
                    printf("Invalid room selection.\n");
                }
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    initializeRooms();
    controlLights();

    return 0;
}