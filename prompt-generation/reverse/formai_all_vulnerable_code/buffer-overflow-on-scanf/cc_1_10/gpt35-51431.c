//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: rigorous
#include <stdio.h>

// Define constants for maximum throttle and steering values
#define MAX_THROTTLE 100
#define MAX_STEERING 45

// Function to limit the inputs within their maximum values
int limitInput(int input, int maxInput) {
    if (input > maxInput) {
        return maxInput;
    } else if (input < -maxInput) {
        return -maxInput;
    } else {
        return input;
    }
}

// Function to control the drone using the remote
void controlDrone(int throttle, int steering) {

    // Limit the inputs within their maximum values
    throttle = limitInput(throttle, MAX_THROTTLE);
    steering = limitInput(steering, MAX_STEERING);

    // Print the inputs to the console
    printf("Throttle: %d\n", throttle);
    printf("Steering: %d\n", steering);

    // Send the control signals to the drone
    // This function is not implemented as it is specific to the drone used

}

int main() {

    // Initialize throttle and steering to 0
    int throttle = 0;
    int steering = 0;

    // Loop indefinitely to continuously receive inputs from the remote
    while (1) {

        // Receive inputs from the remote
        printf("Enter throttle value (-100 to 100): ");
        scanf("%d", &throttle);
        printf("Enter steering value (-45 to 45): ");
        scanf("%d", &steering);

        // Control the drone using the inputs received
        controlDrone(throttle, steering);

    }

    return 0;

}