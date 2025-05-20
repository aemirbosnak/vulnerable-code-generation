//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GREEN 0
#define YELLOW 1
#define RED 2

void wait(int seconds) { // helper function to simulate time delay
    clock_t end_wait = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < end_wait) {}
}

int get_random_state() { // randomly generates a state for the traffic light
    return rand() % 3;
}

int main() {
    srand(time(NULL)); // initialize random number generator
    
    int state = GREEN; // start at green
    int timer = 0; // initialize timer
    
    while (1) { // continuously loop
        
        // print current state of traffic light
        if (state == GREEN) {
            printf("\nG\n\n");
        } else if (state == YELLOW) {
            printf("\nY\n\n");
        } else {
            printf("\nR\n\n");
        }
        
        // update state based on timer
        if (state == GREEN && timer == 10) { // green to yellow
            state = YELLOW;
            timer = 0;
        } else if (state == YELLOW && timer == 3) { // yellow to red
            state = RED;
            timer = 0;
        } else if (state == RED && timer == 15) { // red to green
            state = GREEN;
            timer = 0;
        }
        
        // randomly change state (10% chance per loop)
        if (rand() % 10 == 0) {
            state = get_random_state();
            printf("\nRandomly changed state\n\n");
            timer = 0; // reset timer
        }
        
        timer++; // increment timer
        
        wait(1); // wait one second
    }
    
    return 0;
}