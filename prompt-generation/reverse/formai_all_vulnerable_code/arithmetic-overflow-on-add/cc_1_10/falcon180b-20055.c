//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define time constants
#define RED_TIME 10
#define YELLOW_TIME 3
#define GREEN_TIME 15

// Define traffic light states
#define RED 0
#define YELLOW 1
#define GREEN 2

// Define traffic light state variables
int current_state = RED;
int next_state = GREEN;
int state_change_time = 0;

// Function to change the traffic light state
void change_state() {
    switch(current_state) {
        case RED:
            printf("Traffic light is red.\n");
            break;
        case YELLOW:
            printf("Traffic light is yellow.\n");
            break;
        case GREEN:
            printf("Traffic light is green.\n");
            break;
    }
    current_state = next_state;
    state_change_time = time(NULL) + (current_state == RED? RED_TIME : current_state == YELLOW? YELLOW_TIME : GREEN_TIME);
}

// Function to check if it's time to change the traffic light state
void check_state_change() {
    if(state_change_time <= time(NULL)) {
        change_state();
    }
}

int main() {
    srand(time(NULL));
    int random_state = rand() % 3;

    if(random_state == 0) {
        next_state = RED;
    } else if(random_state == 1) {
        next_state = YELLOW;
    } else {
        next_state = GREEN;
    }

    while(1) {
        change_state();
        sleep(1);
        check_state_change();
    }

    return 0;
}