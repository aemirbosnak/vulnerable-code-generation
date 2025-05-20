//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define GREEN 1
#define YELLOW 2
#define RED 3

bool is_pedestrian_requested = false;
bool is_pedestrian_walk = false;

void delay(int seconds) {
    clock_t start_time = clock();
    while(clock() < start_time + seconds * CLOCKS_PER_SEC);
}

void switch_state(int current_state) {
    switch(current_state) {
        case GREEN:
            printf("Green Light: All Clear\n");
            delay(10);
            if(is_pedestrian_requested) {
                printf("Yellow Light: Pedestrians Prepare to Cross\n");
                delay(3);
                printf("Red Light: Pedestrians Cross\n");
                is_pedestrian_walk = true;
                is_pedestrian_requested = false;
                delay(8);
            }
            else {
                printf("Yellow Light: Prepare to Stop\n");
                delay(3);
                printf("Red Light: Stop\n");
                delay(10);
            }
            switch_state(RED);
            break;
        case YELLOW:
            printf("Yellow Light: Slow Down\n");
            delay(3);
            if(is_pedestrian_requested) {
                printf("Red Light: Pedestrians Cross\n");
                is_pedestrian_walk = true;
                is_pedestrian_requested = false;
                delay(8);
            }
            else {
                printf("Red Light: Stop\n");
                delay(10);
            }
            switch_state(GREEN);
            break;
        case RED:
            is_pedestrian_walk = false;
            printf("Red Light: Stop\n");
            delay(10);
            if(is_pedestrian_requested) {
                printf("Green Light: Pedestrians Prepare to Cross\n");
                delay(3);
                printf("Yellow Light: Pedestrians Cross\n");
                is_pedestrian_walk = true;
                is_pedestrian_requested = false;
                delay(8);
            }
            else {
                printf("Green Light: Go\n");
                delay(10);
            }
            switch_state(YELLOW);
            break;
    }
}

int main() {
    int current_state = GREEN;
    switch_state(current_state);
    return 0;
}