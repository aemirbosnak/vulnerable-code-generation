//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the fitness tracker structure
typedef struct {
    int steps;
    int distance;
    int calories;
    time_t timestamp;
} fitness_tracker;

// Define the puzzle string
const char *puzzle = "Tnhf jvguf cnegf nffn fvzcyr. Wb vg fgrrevfvgl jurer be vna fhpprff pbhyq ernpgvba bhg bs fbzrbar vf vagb gung yvsr.";

// Define the decipher function
char decipher(char c) {
    if (c >= 'a' && c <= 'z') {
        return (c - 'a' + 13) % 26 + 'a';
    } else if (c >= 'A' && c <= 'Z') {
        return (c - 'A' + 13) % 26 + 'A';
    } else {
        return c;
    }
}

// Define the main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create a fitness tracker instance
    fitness_tracker tracker;

    // Set the initial values of the fitness tracker
    tracker.steps = 0;
    tracker.distance = 0;
    tracker.calories = 0;
    tracker.timestamp = time(NULL);

    // Loop forever
    while (1) {
        // Get the current time
        time_t now = time(NULL);

        // Calculate the time difference between now and the last timestamp
        int time_diff = now - tracker.timestamp;

        // If the time difference is greater than or equal to 1 second, update the fitness tracker
        if (time_diff >= 1) {
            // Increment the steps by a random number between 1 and 10
            tracker.steps += rand() % 10 + 1;

            // Increment the distance by a random number between 1 and 100 meters
            tracker.distance += rand() % 100 + 1;

            // Increment the calories by a random number between 1 and 10
            tracker.calories += rand() % 10 + 1;

            // Update the timestamp to the current time
            tracker.timestamp = now;
        }

        // Decipher the puzzle string
        char deciphered_puzzle[strlen(puzzle) + 1];
        for (int i = 0; i < strlen(puzzle); i++) {
            deciphered_puzzle[i] = decipher(puzzle[i]);
        }
        deciphered_puzzle[strlen(puzzle)] = '\0';

        // Print the fitness tracker data and the deciphered puzzle string
        printf("Steps: %d\n", tracker.steps);
        printf("Distance: %d meters\n", tracker.distance);
        printf("Calories: %d\n", tracker.calories);
        printf("Puzzle: %s\n", deciphered_puzzle);
    }

    return 0;
}