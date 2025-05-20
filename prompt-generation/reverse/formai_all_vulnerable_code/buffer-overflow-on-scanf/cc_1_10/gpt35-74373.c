//FormAI DATASET v1.0 Category: Smart home automation ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// define a structure for the rooms
struct Room {
    char name[20];
    int temperature;
    int lights;
};

// declare global variables
struct Room rooms[3];
int numRooms = 3;

// function to print all rooms' temperature and light status
void printRooms() {
    printf("All Rooms Status:\n");
    for (int i = 0; i < numRooms; i++) {
        printf("%s: Temperature = %d, Light Status = %d\n", rooms[i].name, rooms[i].temperature, rooms[i].lights);
    }
}

// function to change temperature of a room
void changeTemperature(int roomIndex, int temperature) {
    rooms[roomIndex].temperature = temperature;
    printf("Temperature of %s room updated to %d\n", rooms[roomIndex].name, temperature);
}

// function to turn on/off lights of a room
void changeLights(int roomIndex, int lights) {
    rooms[roomIndex].lights = lights;
    if (lights == 1) {
        printf("%s lights on\n", rooms[roomIndex].name);
    } else {
        printf("%s lights off\n", rooms[roomIndex].name);
    }
}

int main() {
    // initialize default room values
    strcpy(rooms[0].name, "Living Room");
    rooms[0].temperature = 72;
    rooms[0].lights = 0;
    strcpy(rooms[1].name, "Kitchen");
    rooms[1].temperature = 68;
    rooms[1].lights = 0;
    strcpy(rooms[2].name, "Bedroom");
    rooms[2].temperature = 70;
    rooms[2].lights = 0;

    // print initial room status
    printRooms();

    int choice;
    do {
        // display menu
        printf("\nChoose an action:\n");
        printf("1. Change room temperature\n");
        printf("2. Turn room lights on/off\n");
        printf("3. Print all rooms status\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        int roomIndex;
        int temperature;
        int lights;
        switch (choice) {
            case 1:
                // prompt user for room index and new temperature
                printf("Enter room index (0-2): ");
                scanf("%d", &roomIndex);
                printf("Enter new temperature: ");
                scanf("%d", &temperature);

                // call changeTemperature function
                changeTemperature(roomIndex, temperature);
                break;
            case 2:
                // prompt user for room index and lights status
                printf("Enter room index (0-2): ");
                scanf("%d", &roomIndex);
                printf("Turn lights on or off (1/0): ");
                scanf("%d", &lights);

                // call changeLights function
                changeLights(roomIndex, lights);
                break;
            case 3:
                // call printRooms function
                printRooms();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}