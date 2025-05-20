//Code Llama-13B DATASET v1.0 Category: Traffic Flow Simulation ; Style: funny
// A funny traffic flow simulation program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize the traffic lights
    int lights[] = {1, 2, 3};
    int num_lights = sizeof(lights) / sizeof(int);

    // Initialize the traffic cars
    int cars[] = {1, 2, 3, 4, 5};
    int num_cars = sizeof(cars) / sizeof(int);

    // Initialize the traffic lights' states
    int states[] = {0, 0, 0};

    // Initialize the car's states
    int car_states[] = {0, 0, 0, 0, 0};

    // Loop until all cars have arrived
    while (1) {
        // Get the current time
        time_t now = time(NULL);

        // Get the current car's state
        int current_car_state = car_states[now % num_cars];

        // Get the current light's state
        int current_light_state = states[now % num_lights];

        // If the current car is waiting and the light is green, move the car
        if (current_car_state == 0 && current_light_state == 1) {
            // Move the car
            car_states[now % num_cars] = 1;
        }

        // If the current car is moving and the light is red, stop the car
        if (current_car_state == 1 && current_light_state == 0) {
            // Stop the car
            car_states[now % num_cars] = 0;
        }

        // Update the light's state
        states[now % num_lights] = !states[now % num_lights];

        // Print the current state
        printf("Car %d: %s\nLight %d: %s\n",
            now % num_cars + 1,
            car_states[now % num_cars] == 0 ? "waiting" : "moving",
            now % num_lights + 1,
            states[now % num_lights] == 0 ? "green" : "red");

        // Sleep for 1 second
        sleep(1);
    }

    return 0;
}