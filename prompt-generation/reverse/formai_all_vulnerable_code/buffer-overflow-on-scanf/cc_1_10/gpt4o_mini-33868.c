//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int lightStatus; // 0: off, 1: on
    float temperature; // in Celsius
} Room;

Room rooms[MAX_ROOMS];
int totalRooms = 0;

void addRoom(char *roomName) {
    if (totalRooms >= MAX_ROOMS) {
        printf("Maximum rooms limit reached!\n");
        return;
    }
    
    strcpy(rooms[totalRooms].name, roomName);
    rooms[totalRooms].lightStatus = 0; // light off by default
    rooms[totalRooms].temperature = 22.0; // default temperature
    totalRooms++;
    printf("Room %s added successfully!\n", roomName);
}

void toggleLight(char *roomName) {
    for (int i = 0; i < totalRooms; i++) {
        if (strcmp(rooms[i].name, roomName) == 0) {
            rooms[i].lightStatus = !rooms[i].lightStatus; // Toggle light status
            printf("Light in room %s is now %s.\n", roomName, rooms[i].lightStatus ? "ON" : "OFF");
            return;
        }
    }
    printf("Room %s not found!\n", roomName);
}

void setTemperature(char *roomName, float temp) {
    for (int i = 0; i < totalRooms; i++) {
        if (strcmp(rooms[i].name, roomName) == 0) {
            rooms[i].temperature = temp;
            printf("Temperature in room %s set to %.1f°C.\n", roomName, temp);
            return;
        }
    }
    printf("Room %s not found!\n", roomName);
}

void displayStatus() {
    printf("Current Smart Home Status:\n");
    for (int i = 0; i < totalRooms; i++) {
        printf("Room: %s | Light: %s | Temperature: %.1f°C\n", rooms[i].name, 
               rooms[i].lightStatus ? "ON" : "OFF", rooms[i].temperature);
    }
}

void userMenu() {
    printf("Smart Home Automation Menu:\n");
    printf("1. Add Room\n");
    printf("2. Toggle Light\n");
    printf("3. Set Temperature\n");
    printf("4. Display Status\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    char roomName[MAX_NAME_LENGTH];
    float temperature;

    while (1) {
        userMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter room name: ");
                scanf("%s", roomName);
                addRoom(roomName);
                break;

            case 2:
                printf("Enter room name to toggle light: ");
                scanf("%s", roomName);
                toggleLight(roomName);
                break;

            case 3:
                printf("Enter room name to set temperature: ");
                scanf("%s", roomName);
                printf("Enter temperature (°C): ");
                scanf("%f", &temperature);
                setTemperature(roomName, temperature);
                break;

            case 4:
                displayStatus();
                break;

            case 5:
                printf("Exiting Smart Home Automation...\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}