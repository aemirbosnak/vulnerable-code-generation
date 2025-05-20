//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    int light_status;
} Room;

void init_room(Room* room, char* name, int light_status) {
    room->name = strdup(name);
    room->light_status = light_status;
}

int main() {
    Room living_room = {0};
    Room bedroom = {0};
    Room kitchen = {0};

    init_room(&living_room, "Living Room", 1);
    init_room(&bedroom, "Bedroom", 0);
    init_room(&kitchen, "Kitchen", 1);

    printf("Current status:\n");
    printf("Living Room: %s\n", living_room.light_status? "On" : "Off");
    printf("Bedroom: %s\n", bedroom.light_status? "On" : "Off");
    printf("Kitchen: %s\n", kitchen.light_status? "On" : "Off");

    printf("\nEnter the room name to control:\n");
    char room_name[50];
    scanf("%s", room_name);

    Room* target_room = NULL;
    if (strcmp(room_name, living_room.name) == 0) {
        target_room = &living_room;
    } else if (strcmp(room_name, bedroom.name) == 0) {
        target_room = &bedroom;
    } else if (strcmp(room_name, kitchen.name) == 0) {
        target_room = &kitchen;
    } else {
        printf("Invalid room name.\n");
        return 1;
    }

    printf("\nEnter the desired light status (0: Off, 1: On):\n");
    int desired_status;
    scanf("%d", &desired_status);

    if (target_room->light_status == desired_status) {
        printf("The light is already %s.\n", desired_status? "on" : "off");
    } else {
        target_room->light_status = desired_status;
        printf("The light in %s has been set to %s.\n", target_room->name, desired_status? "on" : "off");
    }

    printf("\nCurrent status:\n");
    printf("Living Room: %s\n", living_room.light_status? "On" : "Off");
    printf("Bedroom: %s\n", bedroom.light_status? "On" : "Off");
    printf("Kitchen: %s\n", kitchen.light_status? "On" : "Off");

    return 0;
}