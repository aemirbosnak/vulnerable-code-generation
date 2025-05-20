//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DEVICES 10
#define MAX_ROOMS 10
#define MAX_USERS 10

typedef struct {
    char name[20];
    bool state;
} Device;

typedef struct {
    char name[20];
    int num_devices;
    Device devices[MAX_DEVICES];
} Room;

typedef struct {
    char name[20];
    Room rooms[MAX_ROOMS];
} Home;

void add_device(Device* device, char* name) {
    strcpy(device->name, name);
    device->state = false;
}

void add_room(Room* room, char* name) {
    strcpy(room->name, name);
    room->num_devices = 0;
}

void add_home(Home* home, char* name) {
    strcpy(home->name, name);
}

void print_devices(Device* devices, int num_devices) {
    printf("Devices:\n");
    for (int i = 0; i < num_devices; i++) {
        printf("%s: %s\n", devices[i].name, devices[i].state? "On" : "Off");
    }
}

void print_rooms(Room* rooms, int num_rooms) {
    printf("Rooms:\n");
    for (int i = 0; i < num_rooms; i++) {
        printf("%s:\n", rooms[i].name);
        print_devices(rooms[i].devices, rooms[i].num_devices);
    }
}

void print_home(Home* home) {
    printf("Home:\n");
    printf("%s\n", home->name);
    print_rooms(home->rooms, MAX_ROOMS);
}

int main() {
    Home home;
    add_home(&home, "My Home");

    Room living_room;
    add_room(&living_room, "Living Room");
    add_device(living_room.devices, "TV");
    add_device(living_room.devices, "Lamp");

    Room kitchen;
    add_room(&kitchen, "Kitchen");
    add_device(kitchen.devices, "Fridge");
    add_device(kitchen.devices, "Microwave");

    Room bedroom;
    add_room(&bedroom, "Bedroom");
    add_device(bedroom.devices, "Fan");
    add_device(bedroom.devices, "Light");

    print_home(&home);

    return 0;
}