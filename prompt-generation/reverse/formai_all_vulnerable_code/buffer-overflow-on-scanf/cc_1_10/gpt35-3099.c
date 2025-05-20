//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SPEED 100 // Maximum possible speed
#define MAX_ANGLE 180 // Maximum possible angle

enum direction { FORWARD, BACKWARD, LEFT, RIGHT}; // Directions for the remote control vehicle 
enum mode { AUTO, MANUAL }; // Modes for the remote control vehicle

// Function to generate random speed and angle between 0 and maximum
void generate_random_values(int *speed, int *angle) {
    *speed = rand() % (MAX_SPEED + 1);
    *angle = rand() % (MAX_ANGLE + 1);
}

int main() {
    srand(time(NULL)); // Initialize random number generator with current time
    
    enum direction current_direction = FORWARD; // Start with default direction
    enum mode current_mode = MANUAL; // Start with manual mode
 
    int current_speed = 0; // Start with zero speed
    int current_angle = 0; // Start with zero angle

    while(1) { // Run infinite loop to keep the program running
        if(current_mode == MANUAL) { // If currently in manual mode
            // Prompt user to enter direction and speed
            printf("Enter direction (0 for forward, 1 for backward, 2 for left, 3 for right): ");
            scanf("%d", &current_direction);
            printf("Enter speed (0 to %d): ", MAX_SPEED);
            scanf("%d", &current_speed);
            // Clamp speed within maximum possible speed
            if(current_speed > MAX_SPEED) {
                current_speed = MAX_SPEED;
            }
            // Output current direction and speed
            printf("Current direction: %d, current speed: %d\n", current_direction, current_speed);
        }
        else if(current_mode == AUTO) { // If currently in auto mode
            generate_random_values(&current_speed, &current_angle); // Generate random speed and angle
            // Output current speed and angle
            printf("Current speed: %d, current angle: %d\n", current_speed, current_angle);
        }
        
        // Sleep for one second
        sleep(1);
    }
    
    return 0;
}