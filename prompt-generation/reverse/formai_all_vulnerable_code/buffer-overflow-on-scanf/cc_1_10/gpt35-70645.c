//FormAI DATASET v1.0 Category: Smart home automation ; Style: paranoid
#include <stdio.h>
#include <stdbool.h>

#define MAX_ROOMS 5

typedef struct {
    bool lights_on;
    bool door_locked;
    bool windows_closed;
} room;

void print_status(room r);
void toggle_lights(room *r);
void toggle_door(room *r);
void toggle_windows(room *r);
void toggle_all(room *rooms[]);

int main() {

    room living_room = { false, false, true };
    room kitchen = { false, false, true };
    room bedroom = { false, true, true };
    room bathroom = { false, true, true };
    room study = { false, true, true };

    room *rooms[MAX_ROOMS] = { &living_room, &kitchen, &bedroom, &bathroom, &study };

    int option;
    while (true) {
        printf("----------\n");
        printf("Smart Home Automation\n");
        printf("----------\n");
        printf("1. Toggle Lights\n");
        printf("2. Toggle Door Locked\n");
        printf("3. Toggle Windows Closed\n");
        printf("4. Toggle All Rooms\n");
        printf("5. Exit\n");
        printf("----------\n");

        printf("Enter option (1-5):\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                toggle_lights(&living_room);
                print_status(living_room);
                break;
            case 2:
                toggle_door(&living_room);
                print_status(living_room);
                break;
            case 3:
                toggle_windows(&living_room);
                print_status(living_room);
                break;
            case 4:
                toggle_all(rooms);
                print_status(living_room);
                print_status(kitchen);
                print_status(bedroom);
                print_status(bathroom);
                print_status(study);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid option.\n");
                break;
        }
    }
}

void print_status(room r) {
    printf("Lights: %s, Door: %s, Windows: %s\n", r.lights_on ? "On" : "Off", r.door_locked ? "Locked" : "Unlocked", r.windows_closed ? "Closed" : "Open");
}

void toggle_lights(room *r) {
    r->lights_on = !r->lights_on;
}

void toggle_door(room *r) {
    r->door_locked = !r->door_locked;
}

void toggle_windows(room *r) {
    r->windows_closed = !r->windows_closed;
}

void toggle_all(room *rooms[]) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        toggle_lights(rooms[i]);
        toggle_door(rooms[i]);
        toggle_windows(rooms[i]);
    }
}