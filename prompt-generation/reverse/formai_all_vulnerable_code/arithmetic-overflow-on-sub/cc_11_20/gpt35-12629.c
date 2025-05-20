//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the states of the traffic light
typedef enum {
    RED,
    YELLOW,
    GREEN,
    YELLOW_GREEN,
} State;

// Define a struct to hold the current state and time for each light
typedef struct {
    State state;
    time_t time;
} Light;

int main(void) {
    // Initialize the lights
    Light north_south = { RED, time(NULL) };
    Light east_west = { GREEN, time(NULL) };
    
    // Loop forever
    while (1) {
        // Print the current state of each light
        printf("North/South: %d (%ld s)\n", north_south.state, time(NULL) - north_south.time);
        printf("East/West: %d (%ld s)\n", east_west.state, time(NULL) - east_west.time);
        
        // Delay for one second
        sleep(1);
        
        // Update the state of each light based on the current state and time
        switch (north_south.state) {
            case RED:
                if (time(NULL) - north_south.time >= 10) {
                    north_south.state = GREEN;
                    north_south.time = time(NULL);
                }
                break;
            case YELLOW:
                if (time(NULL) - north_south.time >= 2) {
                    north_south.state = RED;
                    north_south.time = time(NULL);
                }
                break;
            case GREEN:
                if (time(NULL) - north_south.time >= 15) {
                    north_south.state = YELLOW;
                    north_south.time = time(NULL);
                }
                break;
            case YELLOW_GREEN:
                if (time(NULL) - north_south.time >= 2) {
                    north_south.state = RED;
                    north_south.time = time(NULL);
                }
                break;
        }
        
        switch (east_west.state) {
            case RED:
                if (time(NULL) - east_west.time >= 10) {
                    east_west.state = YELLOW;
                    east_west.time = time(NULL);
                }
                break;
            case YELLOW:
                if (time(NULL) - east_west.time >= 2) {
                    east_west.state = GREEN;
                    east_west.time = time(NULL);
                }
                break;
            case GREEN:
                if (time(NULL) - east_west.time >= 15) {
                    east_west.state = YELLOW_GREEN;
                    east_west.time = time(NULL);
                }
                break;
            case YELLOW_GREEN:
                if (time(NULL) - east_west.time >= 2) {
                    east_west.state = RED;
                    east_west.time = time(NULL);
                }
                break;
        }
    }
    
    return 0;
}