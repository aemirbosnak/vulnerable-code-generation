//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    int state;
} light_t;

light_t* create_light(char* name, int state) {
    light_t* light = (light_t*)malloc(sizeof(light_t));
    light->name = strdup(name);
    light->state = state;
    return light;
}

void turn_on_light(light_t* light) {
    printf("Turning on light '%s'\n", light->name);
    light->state = 1;
}

void turn_off_light(light_t* light) {
    printf("Turning off light '%s'\n", light->name);
    light->state = 0;
}

void toggle_light(light_t* light) {
    if (light->state == 0) {
        turn_on_light(light);
    } else {
        turn_off_light(light);
    }
}

int main() {
    light_t* living_room_light = create_light("Living Room Light", 0);
    light_t* bedroom_light = create_light("Bedroom Light", 1);

    printf("Initial state:\n");
    printf("Living Room Light: %s\n", living_room_light->name);
    printf("Bedroom Light: %s\n", bedroom_light->name);

    turn_on_light(living_room_light);
    turn_off_light(bedroom_light);

    printf("\nState after turning on/off:\n");
    printf("Living Room Light: %s\n", living_room_light->name);
    printf("Bedroom Light: %s\n", bedroom_light->name);

    toggle_light(living_room_light);
    toggle_light(bedroom_light);

    printf("\nState after toggling:\n");
    printf("Living Room Light: %s\n", living_room_light->name);
    printf("Bedroom Light: %s\n", bedroom_light->name);

    free(living_room_light->name);
    free(living_room_light);
    free(bedroom_light->name);
    free(bedroom_light);

    return 0;
}