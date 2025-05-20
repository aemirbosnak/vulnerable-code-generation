//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 1000

// Function to generate a random number between min and max (inclusive)
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to simulate an alien invasion and return the probability of success
double simulate_invasion(int num_ships, int num_defenders) {
    int i, j;
    double prob_success = 0.0;
    for (i = 0; i < MAX_TRIES; i++) {
        // Reset the simulation
        int num_ships_left = num_ships;
        int num_defenders_left = num_defenders;

        // Simulate the battle until one side is defeated
        while (num_ships_left > 0 && num_defenders_left > 0) {
            // Each ship attacks a random defender
            for (j = 0; j < num_ships_left; j++) {
                int defender_index = rand_int(0, num_defenders_left - 1);
                num_defenders_left--;
            }

            // Each defender attacks a random ship
            for (j = 0; j < num_defenders_left; j++) {
                int ship_index = rand_int(0, num_ships_left - 1);
                num_ships_left--;
            }
        }

        // If the aliens win, increment the probability of success
        if (num_ships_left > 0) {
            prob_success += 1.0 / MAX_TRIES;
        }
    }

    return prob_success;
}

int main() {
    int num_ships, num_defenders;

    // Get the number of alien ships and Earth defenders from the user
    printf("Enter the number of alien ships: ");
    scanf("%d", &num_ships);
    printf("Enter the number of Earth defenders: ");
    scanf("%d", &num_defenders);

    // Simulate the invasion and print the probability of success
    double prob_success = simulate_invasion(num_ships, num_defenders);
    printf("The probability of a successful alien invasion is %.2f%%\n", prob_success * 100.0);

    return 0;
}