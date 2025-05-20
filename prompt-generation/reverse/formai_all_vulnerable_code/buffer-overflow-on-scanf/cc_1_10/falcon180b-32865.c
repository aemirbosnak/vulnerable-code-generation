//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

// Function to print the current state of the traffic light
void print_state(int state) {
    switch(state) {
        case RED:
            printf("Traffic light is red\n");
            break;
        case YELLOW:
            printf("Traffic light is yellow\n");
            break;
        case GREEN:
            printf("Traffic light is green\n");
            break;
        default:
            printf("Invalid state\n");
            break;
    }
}

// Function to change the state of the traffic light
void change_state(int* state) {
    int new_state;
    // Randomly choose a new state
    new_state = rand() % 3;
    // Change the state only if it's different from the current state
    while(new_state == *state) {
        new_state = rand() % 3;
    }
    // Update the state
    *state = new_state;
}

// Function to simulate the traffic light
void traffic_light_simulator(int duration) {
    int state = RED;
    int i;
    srand(time(NULL));
    // Simulate the traffic light for the specified duration
    for(i = 0; i < duration; i++) {
        // Wait for 1 second
        sleep(1);
        // Change the state of the traffic light
        change_state(&state);
        // Print the current state of the traffic light
        print_state(state);
    }
}

int main() {
    int duration;
    // Get the duration of the simulation from the user
    printf("Enter the duration of the simulation in seconds: ");
    scanf("%d", &duration);
    // Simulate the traffic light
    traffic_light_simulator(duration);
    return 0;
}