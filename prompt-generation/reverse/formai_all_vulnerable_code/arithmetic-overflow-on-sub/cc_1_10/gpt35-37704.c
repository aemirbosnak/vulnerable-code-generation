//FormAI DATASET v1.0 Category: Smart home light control ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ROOMS 5
#define MAX_LIGHTS_PER_ROOM 10

typedef struct {
    bool isOn;
    int brightness;
} Light;

typedef struct {
    char roomName[20];
    Light lights[MAX_LIGHTS_PER_ROOM];
    int numLights;
} Room;

typedef struct {
    Room rooms[MAX_ROOMS];
    int numRooms;
} SmartHome;

void printMenu() {
    printf("==========\n");
    printf("SMART HOME\n");
    printf("==========\n");
    printf("1. Add Room\n");
    printf("2. Add Light\n");
    printf("3. Turn Light On\n");
    printf("4. Turn Light Off\n");
    printf("5. Set Light Brightness\n");
    printf("6. Print Smart Home\n");
    printf("Enter your choice (1-6): ");
}

void addRoom(SmartHome* smartHome, char roomName[]) {
    Room newRoom;
    strcpy(newRoom.roomName, roomName);
    newRoom.numLights = 0;
    
    smartHome->rooms[smartHome->numRooms++] = newRoom;
}

void addLight(SmartHome* smartHome, char roomName[]) {
    int roomIndex = -1;
    for (int i = 0; i < smartHome->numRooms; i++) {
        if (strcmp(smartHome->rooms[i].roomName, roomName) == 0) {
            roomIndex = i;
            break;
        }
    }
    
    if (roomIndex == -1) {
        printf("Error: Room not found\n");
        return;
    }
    
    if (smartHome->rooms[roomIndex].numLights == MAX_LIGHTS_PER_ROOM) {
        printf("Error: Room already has maximum number of lights\n");
        return;
    }
    
    Light newLight;
    newLight.isOn = false;
    newLight.brightness = 0;
    
    smartHome->rooms[roomIndex].lights[smartHome->rooms[roomIndex].numLights++] = newLight;
}

void turnLightOn(SmartHome* smartHome, char roomName[], int lightIndex) {
    int roomIndex = -1;
    for (int i = 0; i < smartHome->numRooms; i++) {
        if (strcmp(smartHome->rooms[i].roomName, roomName) == 0) {
            roomIndex = i;
            break;
        }
    }
    
    if (roomIndex == -1) {
        printf("Error: Room not found\n");
        return;
    }
    
    if (lightIndex < 0 || lightIndex >= smartHome->rooms[roomIndex].numLights) {
        printf("Error: Light not found\n");
        return;
    }
    
    smartHome->rooms[roomIndex].lights[lightIndex].isOn = true;
}

void turnLightOff(SmartHome* smartHome, char roomName[], int lightIndex) {
    int roomIndex = -1;
    for (int i = 0; i < smartHome->numRooms; i++) {
        if (strcmp(smartHome->rooms[i].roomName, roomName) == 0) {
            roomIndex = i;
            break;
        }
    }
    
    if (roomIndex == -1) {
        printf("Error: Room not found\n");
        return;
    }
    
    if (lightIndex < 0 || lightIndex >= smartHome->rooms[roomIndex].numLights) {
        printf("Error: Light not found\n");
        return;
    }
    
    smartHome->rooms[roomIndex].lights[lightIndex].isOn = false;
}

void setLightBrightness(SmartHome* smartHome, char roomName[], int lightIndex, int brightness) {
    int roomIndex = -1;
    for (int i = 0; i < smartHome->numRooms; i++) {
        if (strcmp(smartHome->rooms[i].roomName, roomName) == 0) {
            roomIndex = i;
            break;
        }
    }
    
    if (roomIndex == -1) {
        printf("Error: Room not found\n");
        return;
    }
    
    if (lightIndex < 0 || lightIndex >= smartHome->rooms[roomIndex].numLights) {
        printf("Error: Light not found\n");
        return;
    }
    
    if (brightness < 0 || brightness > 100) {
        printf("Error: Invalid brightness level\n");
        return;
    }
    
    smartHome->rooms[roomIndex].lights[lightIndex].brightness = brightness;
}

void printSmartHome(SmartHome* smartHome) {
    printf("=======================\n");
    printf("SMART HOME CONFIGURATION\n");
    printf("=======================\n");
    
    for (int i = 0; i < smartHome->numRooms; i++) {
        printf("%s:\n", smartHome->rooms[i].roomName);
        for (int j = 0; j < smartHome->rooms[i].numLights; j++) {
            printf("Light %d: ", j+1);
            if (smartHome->rooms[i].lights[j].isOn) {
                printf("On, Brightness %d\n", smartHome->rooms[i].lights[j].brightness);
            } else {
                printf("Off\n");
            }
        }
    }
}

int main() {
    SmartHome smartHome;
    smartHome.numRooms = 0;
    
    int choice;
    char roomName[20];
    int lightIndex, brightness;
    
    while (true) {
        printMenu();
        
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter new room name: ");
                scanf("%s", roomName);
                addRoom(&smartHome, roomName);
                break;
            case 2:
                printf("Enter room name: ");
                scanf("%s", roomName);
                addLight(&smartHome, roomName);
                break;
            case 3:
                printf("Enter room name: ");
                scanf("%s", roomName);
                printf("Enter light index (starting from 1): ");
                scanf("%d", &lightIndex);
                turnLightOn(&smartHome, roomName, lightIndex-1);
                break;
            case 4:
                printf("Enter room name: ");
                scanf("%s", roomName);
                printf("Enter light index (starting from 1): ");
                scanf("%d", &lightIndex);
                turnLightOff(&smartHome, roomName, lightIndex-1);
                break;
            case 5:
                printf("Enter room name: ");
                scanf("%s", roomName);
                printf("Enter light index (starting from 1): ");
                scanf("%d", &lightIndex);
                printf("Enter brightness level (0-100): ");
                scanf("%d", &brightness);
                setLightBrightness(&smartHome, roomName, lightIndex-1, brightness);
                break;
            case 6:
                printSmartHome(&smartHome);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    
    return 0;
}