//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define RED_LIGHT 1
#define YELLOW_LIGHT 2
#define GREEN_LIGHT 3

#define NUM_LANES 4
#define LANE_DURATION 10
#define TOTAL_DURATION (NUM_LANES * LANE_DURATION)
#define RED_GREEN_DURATION (TOTAL_DURATION / 2)
#define YELLOW_DURATION (TOTAL_DURATION / 4)

typedef struct {
    int lane;
    int light;
    int duration;
    int start_time;
    int end_time;
} Lane;

Lane lanes[NUM_LANES];

void *traffic_light(void *arg) {
    int lane = *(int *) arg;
    int light = RED_LIGHT;
    int duration = LANE_DURATION;
    int start_time = time(NULL);
    int end_time = start_time + duration;

    while (time(NULL) <= end_time) {
        if (light == RED_LIGHT) {
            printf("Lane %d: Red light\n", lane);
            fflush(stdout);
        } else if (light == YELLOW_LIGHT) {
            printf("Lane %d: Yellow light\n", lane);
            fflush(stdout);
        } else {
            printf("Lane %d: Green light\n", lane);
            fflush(stdout);
        }

        light++;
        if (light > GREEN_LIGHT) {
            light = RED_LIGHT;
        }

        usleep(100000);
    }

    return NULL;
}

int main() {
    int i;
    pthread_t threads[NUM_LANES];

    srand(time(NULL));

    for (i = 0; i < NUM_LANES; i++) {
        lanes[i].lane = i + 1;
        lanes[i].light = RED_LIGHT;
        lanes[i].duration = LANE_DURATION;
        lanes[i].start_time = time(NULL) + i * LANE_DURATION;
        lanes[i].end_time = lanes[i].start_time + lanes[i].duration;
    }

    for (i = 0; i < NUM_LANES; i++) {
        pthread_create(&threads[i], NULL, traffic_light, &i);
    }

    for (i = 0; i < NUM_LANES; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}