//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define RED 1
#define YELLOW 2
#define GREEN 3

int main() {
    int state = RED;
    int duration = 10; // in seconds
    int wait_time = 0;
    time_t start_time, end_time;

    printf("Traffic Light Controller\n");
    printf("Initial state: %s\n", state == RED? "Red" : state == YELLOW? "Yellow" : "Green");

    start_time = time(NULL);
    while (1) {
        switch (state) {
            case RED:
                printf("State: Red\n");
                wait_time = rand() % 5 + 5; // wait between 5 and 10 seconds
                printf("Wait time: %d seconds\n", wait_time);
                end_time = start_time + wait_time;
                break;
            case YELLOW:
                printf("State: Yellow\n");
                wait_time = rand() % 3 + 3; // wait between 3 and 6 seconds
                printf("Wait time: %d seconds\n", wait_time);
                end_time = start_time + wait_time;
                break;
            case GREEN:
                printf("State: Green\n");
                wait_time = rand() % 15 + 10; // wait between 10 and 25 seconds
                printf("Wait time: %d seconds\n", wait_time);
                end_time = start_time + wait_time;
                break;
        }
        if (state == RED) {
            state = GREEN;
        } else if (state == YELLOW) {
            state = RED;
        } else {
            state = YELLOW;
        }
        end_time += duration;
        time_t current_time = time(NULL);
        if (current_time >= end_time) {
            printf("State change: %s -> %s\n", state == RED? "Red" : state == YELLOW? "Yellow" : "Green", state == RED? "Green" : state == YELLOW? "Red" : "Yellow");
            state = (state + 1) % 3;
            start_time = current_time;
        }
        fflush(stdout);
        sleep(1);
    }

    return 0;
}