//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to display the current state of traffic lights
void display_light_state(int light_state[]) {
    printf("Red Light: %s, Yellow Light: %s, Green Light: %s\n",
           light_state[0] == 0 ? "OFF" : "ON",
           light_state[1] == 0 ? "OFF" : "ON",
           light_state[2] == 0 ? "OFF" : "ON");
}

// Main function
int main() {
    // Initialization
    int light_state[3] = {0, 0, 0}; // 0 means OFF, 1 means ON
    int timer = 0;
    int random_time;
    char start;

    // Welcome message
    printf("Welcome to the Traffic Light Controller!\n");
    printf("Press y/Y to start the traffic light simulation: ");
    scanf("%c", &start);

    // If user selected 'y' or 'Y'
    if (start == 'y' || start == 'Y') {
        // Loop for 10 times
        for (int i=0; i < 10; i++) {
            printf("\n\nTraffic Light Simulation #%d\n", i+1);
            // Set timer to 0
            timer = 0;
            // Generate random time between 20 and 30 seconds
            srand(time(NULL));
            random_time = rand() % 11 + 20;
            // Loop until timer reaches the random time
            while (timer < random_time) {
                display_light_state(light_state);
                printf("Timer: %d\n", timer);
                // If timer is less than or equal to 10, turn on red light and turn off other lights
                if (timer <= 10) {
                    light_state[0] = 1;
                    light_state[1] = 0;
                    light_state[2] = 0;
                } 
                // If timer is greater than 10 but less than or equal to 15, turn on yellow light and turn off other lights
                else if (timer > 10 && timer <= 15) {
                    light_state[0] = 0;
                    light_state[1] = 1;
                    light_state[2] = 0;
                } 
                // If timer is greater than 15 but less than or equal to 30, turn on green light and turn off other lights
                else if (timer > 15 && timer <= 30) {
                    light_state[0] = 0;
                    light_state[1] = 0;
                    light_state[2] = 1;
                }
                // Wait for 1 second
                sleep(1);
                // Increment timer by 1 second
                timer++;
            }
        }
        printf("\nTraffic Light Simulation has ended.\n");
    } 
    // If user did not select 'y' or 'Y'
    else {
        printf("Traffic Light Simulation is cancelled. Goodbye!\n");
    }
    return 0;
}