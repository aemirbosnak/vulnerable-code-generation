//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// function to generate a random integer between min and max
int random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    srand(time(NULL)); // initialize random seed
    
    // set up the remote control vehicle
    int speed = 0;
    int direction = 0; // 0 = forward, 1 = backward
    bool engine_on = false;
    
    // main loop
    while (true) {
        // print current state of vehicle
        printf("Speed: %d\n", speed);
        printf("Direction: %s\n", (direction == 0) ? "forward" : "backward");
        printf("Engine: %s\n", (engine_on) ? "on" : "off");
        
        // get user input
        char user_input;
        printf("Enter command (s = speed, d = direction, e = engine, q = quit): ");
        scanf(" %c", &user_input);
        
        // process user input
        switch (user_input) {
            case 's':
                if (engine_on) {
                    printf("Enter desired speed (0-100): ");
                    scanf("%d", &speed);
                    speed = (speed < 0) ? 0 : (speed > 100) ? 100 : speed; // ensure speed is within range
                } else {
                    printf("Cannot adjust speed when engine is off.\n");
                }
                break;
            case 'd':
                if (engine_on) {
                    direction = (direction == 0) ? 1 : 0; // toggle direction
                } else {
                    printf("Cannot change direction when engine is off.\n");
                }
                break;
            case 'e':
                engine_on = !engine_on; // toggle engine state
                break;
            case 'q':
                printf("Shutting down.\n");
                return 0;
            default:
                printf("Invalid command.\n");
                break;
        }
        
        // simulate movement of vehicle
        int distance_traveled = random_number(speed / 2, speed); // generate random distance traveled based on speed
        if (direction == 1) {
            distance_traveled *= -1; // reverse distance traveled if going backwards
        }
        printf("Vehicle traveled %d meters.\n", distance_traveled);
    }
}