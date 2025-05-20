//FormAI DATASET v1.0 Category: Smart home automation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_DEVICES 10
#define MAX_ROOMS 5

typedef struct device {
    int id;
    char* name;
    char* type;
    bool status;
} Device;

typedef struct room {
    int id;
    char* name;
    Device devices[MAX_DEVICES];
} Room;

int currentRoom = 0;

Room rooms[MAX_ROOMS] = {
    {
        .id = 1,
        .name = "Living Room",
        .devices = {
            {
                .id = 1,
                .name = "TV",
                .type = "Entertainment",
                .status = false
            },
            {
                .id = 2,
                .name = "Lights",
                .type = "Lighting",
                .status = false
            }
        }
    },
    
    {
        .id = 2,
        .name = "Bedroom",
        .devices = {
            {
                .id = 1,
                .name = "Bedside Lamp",
                .type = "Lighting",
                .status = false
            },
            {
                .id = 2,
                .name = "Air Conditioner",
                .type = "HVAC",
                .status = false
            }
        }
    },
    
    {
        .id = 3,
        .name = "Kitchen",
        .devices = {
            {
                .id = 1,
                .name = "Fridge",
                .type = "Appliances",
                .status = false
            },
            {
                .id = 2,
                .name = "Oven",
                .type = "Appliances",
                .status = false
            }
        }
    },
    
    {
        .id = 4,
        .name = "Bathroom",
        .devices = {
            {
                .id = 1,
                .name = "Bathtub",
                .type = "Bathroom",
                .status = false
            },
            {
                .id = 2,
                .name = "Shower",
                .type = "Bathroom",
                .status = false
            }
        }
    },
    
    {
        .id = 5,
        .name = "Office",
        .devices = {
            {
                .id = 1,
                .name = "Computer",
                .type = "Office",
                .status = false
            },
            {
                .id = 2,
                .name = "Printer",
                .type = "Office",
                .status = false
            }
        }
    }
};

void printRooms() {
    int numRooms = sizeof(rooms) / sizeof(rooms[0]);
    
    printf("Available rooms:\n");
    
    for(int i = 0; i < numRooms; i++) {
        printf("%d. %s\n", rooms[i].id, rooms[i].name);
    }
    
    printf("\n");
}

void printDevices(Room room) {
    int numDevices = sizeof(room.devices) / sizeof(room.devices[0]);
    
    printf("%s devices:\n", room.name);
    
    for(int i = 0; i < numDevices; i++) {
        printf("%d. %s (%s): %s\n", room.devices[i].id, room.devices[i].name, room.devices[i].type, room.devices[i].status ? "ON" : "OFF");
    }
    
    printf("\n");
}

void switchDevice(Room* room, int id) {
    int numDevices = sizeof(room->devices) / sizeof(room->devices[0]);
    
    for(int i = 0; i < numDevices; i++) {
        if(room->devices[i].id == id) {
            room->devices[i].status = !room->devices[i].status;
        }
    }
}

void controlDevices() {
    printDevices(rooms[currentRoom]);
    
    int choice;
    
    printf("Enter device id you want to switch ON/OFF: ");
    scanf("%d", &choice);
    
    switchDevice(&rooms[currentRoom], choice);
    
    printf("Device switched %s\n\n", rooms[currentRoom].devices[choice - 1].status ? "ON" : "OFF");
}

void changeRoom() {
    printRooms();
    
    int choice;
    
    printf("Enter room id you want to enter: ");
    scanf("%d", &choice);
    
    currentRoom = choice - 1;
    
    printf("Entered %s\n\n", rooms[currentRoom].name);
}

void menu() {
    int choice;
    
    do {
        printf("1. Control Devices\n");
        printf("2. Change Room\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                controlDevices();
                break;
            case 2:
                changeRoom();
                break;
            case 3:
                printf("Thank you for using Smart Home Automation program.\n");
                break;
            default:
                printf("Invalid choice. Please enter again.\n\n");
        }
    } while(choice != 3);
}

int main() {
    menu();
    
    return 0;
}