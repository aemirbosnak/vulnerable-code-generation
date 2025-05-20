//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>

typedef enum {
    LIGHT_OFF = 0,
    LIGHT_ON = 1,
    LIGHT_DIM = 2
} light_state_t;

typedef struct {
    light_state_t state;
    time_t last_changed;
} light_t;

typedef struct {
    light_t living_room;
    light_t bedroom;
    light_t kitchen;
} smart_home_t;

void light_on(light_t* light) {
    light->state = LIGHT_ON;
    light->last_changed = time(NULL);
}

void light_off(light_t* light) {
    light->state = LIGHT_OFF;
    light->last_changed = time(NULL);
}

void light_dim(light_t* light) {
    light->state = LIGHT_DIM;
    light->last_changed = time(NULL);
}

void smart_home_init(smart_home_t* home) {
    light_off(&home->living_room);
    light_off(&home->bedroom);
    light_off(&home->kitchen);
}

void smart_home_update(smart_home_t* home, int delta_time) {
    if (home->living_room.state == LIGHT_ON &&
        home->living_room.last_changed + 5 * 60 < time(NULL)) {
        light_off(&home->living_room);
    }

    if (home->bedroom.state == LIGHT_DIM &&
        home->bedroom.last_changed + 30 * 60 < time(NULL)) {
        light_off(&home->bedroom);
    }
}

int main() {
    smart_home_t home;
    smart_home_init(&home);

    while (true) {
        time_t current_time = time(NULL);
        int delta_time = current_time - home.living_room.last_changed;
        smart_home_update(&home, delta_time);

        printf("Living room light: %s\n", home.living_room.state == LIGHT_ON? "on" : "off");
        printf("Bedroom light: %s\n", home.bedroom.state == LIGHT_ON? "on" : "off");
        printf("Kitchen light: %s\n", home.kitchen.state == LIGHT_ON? "on" : "off");

        sleep(1);
    }

    return 0;
}