//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 0
#define YELLOW 1
#define GREEN 2
#define PEDESTRIAN_RED 3
#define PEDESTRIAN_GREEN 4
#define PEDESTRIAN_YELLOW 5

void traffic_light(int direction, int pedestrian) {
    switch(direction) {
        case RED:
            printf("Red light for vehicles\n");
            break;
        case YELLOW:
            printf("Yellow light for vehicles\n");
            break;
        case GREEN:
            printf("Green light for vehicles\n");
            break;
        case PEDESTRIAN_RED:
            printf("Red light for pedestrians\n");
            break;
        case PEDESTRIAN_GREEN:
            printf("Green light for pedestrians\n");
            break;
        case PEDESTRIAN_YELLOW:
            printf("Yellow light for pedestrians\n");
            break;
    }
}

int main() {
    int direction = RED;
    int pedestrian = PEDESTRIAN_RED;
    int cycle_time = 10; // in seconds
    int cycle_count = 0;
    time_t start_time, current_time, next_time;

    start_time = time(NULL);
    next_time = start_time + (cycle_time * (direction + pedestrian));

    while(1) {
        current_time = time(NULL);
        if(current_time >= next_time) {
            cycle_count++;
            if(cycle_count % 2 == 0) {
                direction++;
                if(direction > GREEN) {
                    direction = RED;
                }
            } else {
                pedestrian++;
                if(pedestrian > PEDESTRIAN_GREEN) {
                    pedestrian = PEDESTRIAN_RED;
                }
            }
            next_time = current_time + (cycle_time * (direction + pedestrian));
        }
        traffic_light(direction, pedestrian);
        sleep(1);
    }

    return 0;
}