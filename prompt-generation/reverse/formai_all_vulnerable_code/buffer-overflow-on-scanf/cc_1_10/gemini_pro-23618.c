//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
 * Defines the types of events that can occur.
 */
typedef enum {
    EVENT_NO_INVASION,
    EVENT_INVASION,
    EVENT_MAX
} event_type;

/*
 * Defines the probability of each event occurring.
 */
static const double PROBABILITIES[EVENT_MAX] = {
    0.999,
    0.001,
};

/*
 * Calculates the probability of an alien invasion occurring.
 *
 * @param num_iterations The number of iterations to run the simulation.
 *
 * @return The probability of an alien invasion occurring.
 */
double calculate_invasion_probability(int num_iterations) {
    int num_invasions = 0;

    for (int i = 0; i < num_iterations; i++) {
        // Generate a random number to determine the event that occurs.
        double rand_num = (double)rand() / RAND_MAX;

        event_type event;
        if (rand_num < PROBABILITIES[EVENT_INVASION]) {
            event = EVENT_INVASION;
        } else {
            event = EVENT_NO_INVASION;
        }

        // Increment the number of invasions if an invasion occurs.
        if (event == EVENT_INVASION) {
            num_invasions++;
        }
    }

    // Calculate the probability of an invasion occurring.
    double probability = (double)num_invasions / num_iterations;

    return probability;
}

int main(void) {
    // Get the number of iterations from the user.
    int num_iterations;
    printf("Enter the number of iterations: ");
    scanf("%d", &num_iterations);

    // Calculate the probability of an alien invasion occurring.
    double probability = calculate_invasion_probability(num_iterations);

    // Print the probability to the console.
    printf("The probability of an alien invasion occurring is: %f\n", probability);

    return 0;
}