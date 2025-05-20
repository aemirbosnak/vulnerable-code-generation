//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 1
#define YELLOW 2
#define GREEN 3

int main() {
    int state = RED;
    int cycle_time = 10; // in seconds
    time_t start_time, end_time;

    printf("Traffic Light Controller\n");
    printf("Initial state: %s\n", (state == RED)? "RED" : (state == YELLOW)? "YELLOW" : "GREEN");

    while(1) {
        switch(state) {
            case RED:
                printf("RED light on\n");
                start_time = time(NULL);
                while(difftime(time(NULL), start_time) < cycle_time) {
                    end_time = start_time + cycle_time;
                    sleep(end_time - time(NULL));
                }
                state = GREEN;
                printf("RED light off\n");
                break;
            case YELLOW:
                printf("YELLOW light on\n");
                start_time = time(NULL);
                while(difftime(time(NULL), start_time) < cycle_time/2) {
                    end_time = start_time + cycle_time/2;
                    sleep(end_time - time(NULL));
                }
                state = RED;
                printf("YELLOW light off\n");
                break;
            case GREEN:
                printf("GREEN light on\n");
                start_time = time(NULL);
                while(difftime(time(NULL), start_time) < cycle_time) {
                    end_time = start_time + cycle_time;
                    sleep(end_time - time(NULL));
                }
                state = YELLOW;
                printf("GREEN light off\n");
                break;
        }
    }

    return 0;
}