//FormAI DATASET v1.0 Category: Smart home automation ; Style: scalable
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define MAX_DEVICES 10
#define MAX_ROOMS 5

typedef struct {
    int id;
    char name[20];
    bool state;
} Device;

typedef struct {
    int id;
    char name[20];
    Device devices[MAX_DEVICES];
    int num_devices;
} Room;

Room rooms[MAX_ROOMS];
int num_rooms = 0;

void add_room() {
    if (num_rooms >= MAX_ROOMS) {
        printf("Maximum rooms reached\n");
        return;
    }

    rooms[num_rooms].id = num_rooms + 1;
    printf("Enter room name: ");
    scanf("%s", rooms[num_rooms].name);
    num_rooms++;
}

void add_device() {
    int room_id, device_id;
    if (num_rooms == 0) {
        printf("No rooms added yet\n");
        return;
    }
    printf("Enter room id to add device: ");
    scanf("%d", &room_id);

    if (room_id < 1 || room_id > num_rooms) {
        printf("Invalid room id\n");
        return;
    }

    Room *room = &rooms[room_id - 1];
    if (room->num_devices >= MAX_DEVICES) {
        printf("Maximum devices reached for this room\n");
        return;
    }

    room->devices[room->num_devices].id = room->num_devices + 1;
    printf("Enter device name: ");
    scanf("%s", room->devices[room->num_devices].name);
    room->devices[room->num_devices].state = false;
    room->num_devices++;
}

void toggle_device() {
    int room_id, device_id;
    if (num_rooms == 0) {
        printf("No rooms added yet\n");
        return;
    }

    printf("Enter room id: ");
    scanf("%d", &room_id);
    if (room_id < 1 || room_id > num_rooms) {
        printf("Invalid room id\n");
        return;
    }

    Room *room = &rooms[room_id - 1];
    if (room->num_devices == 0) {
        printf("No devices added yet\n");
        return;
    }

    printf("Enter device id: ");
    scanf("%d", &device_id);
    if (device_id < 1 || device_id > room->num_devices) {
        printf("Invalid device id\n");
        return;
    }

    Device *device = &room->devices[device_id - 1];
    device->state = !device->state;
    printf("%s has been turned %s\n", device->name, device->state ? "on" : "off");
}

void print_status() {
    if (num_rooms == 0) {
        printf("No rooms added yet\n");
        return;
    }

    for (int i = 0; i < num_rooms; i++) {
        Room *room = &rooms[i];
        printf("Room %d: %s\n", room->id, room->name);
        for (int j = 0; j < room->num_devices; j++) {
            Device *device = &room->devices[j];
            printf("   Device %d: %s, Status: %s\n", device->id, device->name, device->state ? "on" : "off");
        }
    }
}

int main() {
    int choice;
    do {
        printf("\n1. Add Room\n2. Add Device\n3. Toggle Device\n4. Print Status\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_room();
                break;
            case 2:
                add_device();
                break;
            case 3:
                toggle_device();
                break;
            case 4:
                print_status();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}