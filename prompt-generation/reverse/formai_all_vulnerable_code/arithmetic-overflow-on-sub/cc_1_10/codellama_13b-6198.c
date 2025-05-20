//Code Llama-13B DATASET v1.0 Category: Traffic Light Controller ; Style: invasive
// Invasive Traffic Light Controller Example Program

#include <stdio.h>

int main() {
    // Initialize variables
    int state = 0;
    int previous_state = 0;
    int current_time = 0;
    int previous_time = 0;
    int red_time = 10; // 10 seconds
    int yellow_time = 5; // 5 seconds
    int green_time = 15; // 15 seconds

    // Set initial state
    state = 0; // Red

    // Loop forever
    while (1) {
        // Get current time
        current_time = time(NULL);

        // Check if state has changed
        if (state != previous_state) {
            // Print state
            printf("State changed: %d\n", state);

            // Update previous state
            previous_state = state;
        }

        // Check if it's time to change state
        if (current_time - previous_time >= red_time) {
            // Change state
            state = 1; // Yellow

            // Update previous time
            previous_time = current_time;
        } else if (current_time - previous_time >= yellow_time) {
            // Change state
            state = 2; // Green

            // Update previous time
            previous_time = current_time;
        } else if (current_time - previous_time >= green_time) {
            // Change state
            state = 0; // Red

            // Update previous time
            previous_time = current_time;
        }

        // Sleep for 1 second
        sleep(1);
    }

    return 0;
}