//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the colors of the traffic light
#define RED 1
#define YELLOW 2
#define GREEN 3

// Define the time intervals for each color
#define RED_TIME 10
#define YELLOW_TIME 5
#define GREEN_TIME 15

// Define the current state of the traffic light
int current_state = RED;

// Define the time when the state of the traffic light will change
time_t next_state_time;

// Function to initialize the traffic light
void init_traffic_light() {
    time(&next_state_time);
    next_state_time += RED_TIME;
}

// Function to change the state of the traffic light
void change_state() {
    if (current_state == RED) {
        current_state = YELLOW;
        next_state_time += YELLOW_TIME;
    } else if (current_state == YELLOW) {
        current_state = GREEN;
        next_state_time += GREEN_TIME;
    } else {
        current_state = RED;
        next_state_time += RED_TIME;
    }
}

// Function to print the current state of the traffic light
void print_state() {
    if (current_state == RED) {
        printf("Traffic light is red\n");
    } else if (current_state == YELLOW) {
        printf("Traffic light is yellow\n");
    } else {
        printf("Traffic light is green\n");
    }
}

// Function to simulate the traffic light
void simulate_traffic_light() {
    init_traffic_light();
    while (1) {
        print_state();
        sleep(1);
        if (time(NULL) >= next_state_time) {
            change_state();
        }
    }
}

int main() {
    simulate_traffic_light();
    return 0;
}