//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Create a list of random words
char words[10][10] = {
    "Survive",
    "Radiation",
    "Mutation",
    "Desolate",
    "Scavenger",
    "Pandemic",
    "Apocalypse",
    "Anarchy",
    "Infected",
    "Catastrophe"
};

int main() {
    // Seed the random number generator
    srand(time(NULL)); 

    // Print instructions
    printf("Welcome to the Typing Speed Test. "
           "Type each word as fast as you can.\n");

    // Initialize variables
    char input[10];
    int count = 0;
    double time_taken = 0;

    // Loop through each word in the list
    for (int i = 0; i < 10; i++) {
        // Print the current word and get input
        printf("%s: ", words[i]);
        scanf("%s", input);

        // Check if input is correct
        if (strcmp(input, words[i]) == 0) {
            printf("Correct!\n");
            count++;
        } else {
            printf("Incorrect.\n");
        }

        // Wait a random amount of time before proceeding
        int wait_time = rand() % 3 + 1; // Random number between 1 and 3
        printf("Waiting %d seconds...\n", wait_time);
        sleep(wait_time);

        // Calculate total time taken
        time_taken += wait_time;
    }

    // Print results
    printf("You typed %d words in %.2f seconds. ", count, time_taken);
    double wpm = (count / time_taken) * 60;
    printf("That's %.2f words per minute!\n", wpm);

    return 0;
}