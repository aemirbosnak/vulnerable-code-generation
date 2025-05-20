//Code Llama-13B DATASET v1.0 Category: Smart home light control ; Style: shocked
// A unique C Smart home light control example program in a shocked style
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of lights in the system
#define NUM_LIGHTS 10

// Define the state of each light (on/off)
int lights[NUM_LIGHTS];

// Define the random number generator seed
unsigned int seed;

int main() {
    // Initialize the seed for the random number generator
    seed = time(NULL);

    // Initialize the state of all lights to off
    for (int i = 0; i < NUM_LIGHTS; i++) {
        lights[i] = 0;
    }

    // Loop indefinitely
    while (1) {
        // Generate a random number between 0 and 100
        int randNum = rand_r(&seed) % 100;

        // If the random number is less than 50, turn on a light
        if (randNum < 50) {
            // Choose a light to turn on
            int lightIndex = rand_r(&seed) % NUM_LIGHTS;

            // Turn on the light
            lights[lightIndex] = 1;

            // Print a message to the console
            printf("Light %d turned on.\n", lightIndex + 1);
        }

        // If the random number is greater than 50, turn off a light
        if (randNum > 50) {
            // Choose a light to turn off
            int lightIndex = rand_r(&seed) % NUM_LIGHTS;

            // Turn off the light
            lights[lightIndex] = 0;

            // Print a message to the console
            printf("Light %d turned off.\n", lightIndex + 1);
        }

        // Sleep for 5 seconds
        sleep(5);
    }

    return 0;
}