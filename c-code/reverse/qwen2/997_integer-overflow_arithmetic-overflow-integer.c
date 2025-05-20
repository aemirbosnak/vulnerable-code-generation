#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIMER 60

typedef struct {
    int id;
    int current_timer;
} TrafficLight;

void update_traffic_light(TrafficLight *light) {
    if (light->current_timer > 0) {
        light->current_timer--;
    } else {
        light->current_timer = MAX_TIMER;
    }
}

int main() {
    srand(time(NULL));
    TrafficLight lights[3] = {{1, rand() % (MAX_TIMER + 1)}, {2, rand() % (MAX_TIMER + 1)}, {3, rand() % (MAX_TIMER + 1)}};

    while (1) {
        for (int i = 0; i < 3; i++) {
            update_traffic_light(&lights[i]);
            printf("Traffic Light %d: Timer = %d\n", lights[i].id, lights[i].current_timer);
        }
        sleep(1);
    }

    return 0;
}
