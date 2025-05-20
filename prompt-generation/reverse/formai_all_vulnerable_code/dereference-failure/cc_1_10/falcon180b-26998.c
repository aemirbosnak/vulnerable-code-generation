//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: romantic
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>

#define MAX_ROOMS 10
#define MAX_SENSORS 10
#define MAX_LIGHTS 10
#define MAX_DEVICES 10

enum device_type {
    LIGHT = 0,
    SENSOR = 1,
    OTHER = 2
};

typedef struct {
    char name[50];
    enum device_type type;
    int room;
    int state;
} device;

typedef struct {
    char name[50];
    int num_devices;
    device devices[MAX_DEVICES];
} room;

typedef struct {
    char name[50];
    int num_rooms;
    room rooms[MAX_ROOMS];
} house;

house* init_house() {
    house* h = (house*)malloc(sizeof(house));
    h->num_rooms = 0;
    return h;
}

room* init_room(char* name) {
    room* r = (room*)malloc(sizeof(room));
    strcpy(r->name, name);
    r->num_devices = 0;
    return r;
}

void add_device(room* r, char* name, enum device_type type, int room, int state) {
    device* d = &r->devices[r->num_devices];
    strcpy(d->name, name);
    d->type = type;
    d->room = room;
    d->state = state;
    r->num_devices++;
}

int main() {
    house* h = init_house();
    room* living_room = init_room("Living Room");
    add_device(living_room, "Light", LIGHT, 1, 0);
    add_device(living_room, "Sensor", SENSOR, 1, 0);
    room* bedroom = init_room("Bedroom");
    add_device(bedroom, "Light", LIGHT, 2, 0);
    add_device(bedroom, "Sensor", SENSOR, 2, 0);
    h->rooms[0] = *living_room;
    h->rooms[1] = *bedroom;
    h->num_rooms = 2;
    return 0;
}