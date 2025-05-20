//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define GREEN 0
#define YELLOW 1
#define RED 2

// function to pause the program for a specified number of seconds
void delay(int sec) {
    time_t start_time = time(NULL);
    while (time(NULL) < start_time + sec);
}

int main() {
    // initialize the traffic light to green
    int traffic_light = GREEN;
    
    // loop indefinitely
    while (true) {
        // check the current state of the traffic light
        if (traffic_light == GREEN) {
            printf("Traffic Light: Green\n");
            
            // wait for a specified number of seconds
            delay(10);
            
            // change the traffic light to yellow
            traffic_light = YELLOW;
        }
        else if (traffic_light == YELLOW) {
            printf("Traffic Light: Yellow\n");
            
            // wait for a specified number of seconds
            delay(5);
            
            // change the traffic light to red
            traffic_light = RED;
        }
        else if (traffic_light == RED) {
            printf("Traffic Light: Red\n");
            
            // wait for a specified number of seconds
            delay(12);
            
            // change the traffic light to green
            traffic_light = GREEN;
        }
    }
    
    return 0;
}