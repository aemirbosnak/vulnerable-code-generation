//GEMINI-pro DATASET v1.0 Category: Traffic Light Controller ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#define GREEN_TIME 30 // in seconds
#define YELLOW_TIME 3 // in seconds
#define RED_TIME 30 // in seconds

enum TrafficLightColor {
    GREEN,
    YELLOW,
    RED
};

void set_light(enum TrafficLightColor color) {
    switch (color) {
        case GREEN:
            printf("GREEN\n");
            break;
        case YELLOW:
            printf("YELLOW\n");
            break;
        case RED:
            printf("RED\n");
            break;
    }
}

int main() {
    // Get the current time
    struct timeval tv;
    gettimeofday(&tv, NULL);
    
    // Initialize the current time to the next green light time
    tv.tv_sec += GREEN_TIME;
    
    // Loop forever
    while (1) {
        // Get the current time
        gettimeofday(&tv, NULL);
        
        // Check if it's time to change the light
        if (tv.tv_sec >= (tv.tv_sec + GREEN_TIME)) {
            // Change the light to yellow
            set_light(YELLOW);
            
            // Update the next green light time
            tv.tv_sec += YELLOW_TIME;
        } else if (tv.tv_sec >= (tv.tv_sec + YELLOW_TIME)) {
            // Change the light to red
            set_light(RED);
            
            // Update the next green light time
            tv.tv_sec += RED_TIME;
        }
        
        // Sleep until the next time to change the light
        usleep((tv.tv_sec - time(NULL)) * 1000000);
    }
    
    return 0;
}