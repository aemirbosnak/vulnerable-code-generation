//Code Llama-13B DATASET v1.0 Category: Smart home automation ; Style: Claude Shannon
// Smart Home Automation Example Program
#include <stdio.h>
#include <stdlib.h>

// Define struct for device
struct device {
    char name[30];
    int state;
};

// Define struct for room
struct room {
    char name[30];
    struct device *devices[10];
    int num_devices;
};

// Define struct for smart home
struct smart_home {
    struct room *rooms[10];
    int num_rooms;
};

// Function to add a device to a room
void add_device_to_room(struct smart_home *home, char *room_name, struct device *device) {
    // Find room by name
    for (int i = 0; i < home->num_rooms; i++) {
        if (strcmp(home->rooms[i]->name, room_name) == 0) {
            // Add device to room
            home->rooms[i]->devices[home->rooms[i]->num_devices] = device;
            home->rooms[i]->num_devices++;
            return;
        }
    }
}

// Function to turn on/off a device
void turn_device_on_off(struct smart_home *home, char *room_name, char *device_name, int on_off) {
    // Find room by name
    for (int i = 0; i < home->num_rooms; i++) {
        if (strcmp(home->rooms[i]->name, room_name) == 0) {
            // Find device by name in room
            for (int j = 0; j < home->rooms[i]->num_devices; j++) {
                if (strcmp(home->rooms[i]->devices[j]->name, device_name) == 0) {
                    // Set device state
                    home->rooms[i]->devices[j]->state = on_off;
                    return;
                }
            }
        }
    }
}

int main() {
    // Initialize smart home
    struct smart_home *home = malloc(sizeof(struct smart_home));
    home->num_rooms = 0;

    // Add rooms to smart home
    struct room *kitchen = malloc(sizeof(struct room));
    strcpy(kitchen->name, "Kitchen");
    kitchen->num_devices = 0;
    home->rooms[home->num_rooms++] = kitchen;

    struct room *bedroom = malloc(sizeof(struct room));
    strcpy(bedroom->name, "Bedroom");
    bedroom->num_devices = 0;
    home->rooms[home->num_rooms++] = bedroom;

    // Add devices to rooms
    struct device *light = malloc(sizeof(struct device));
    strcpy(light->name, "Light");
    light->state = 0;
    add_device_to_room(home, "Kitchen", light);

    struct device *tv = malloc(sizeof(struct device));
    strcpy(tv->name, "TV");
    tv->state = 0;
    add_device_to_room(home, "Bedroom", tv);

    // Turn devices on/off
    turn_device_on_off(home, "Kitchen", "Light", 1);
    turn_device_on_off(home, "Bedroom", "TV", 1);

    // Print smart home state
    printf("Smart Home State:\n");
    for (int i = 0; i < home->num_rooms; i++) {
        printf("\t%s\n", home->rooms[i]->name);
        for (int j = 0; j < home->rooms[i]->num_devices; j++) {
            printf("\t\t%s: %s\n", home->rooms[i]->devices[j]->name, home->rooms[i]->devices[j]->state ? "on" : "off");
        }
    }

    // Free memory
    free(home);
    free(kitchen);
    free(bedroom);
    free(light);
    free(tv);

    return 0;
}