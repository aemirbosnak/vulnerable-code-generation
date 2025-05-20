//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of years that can be traveled
#define MAX_YEARS 100

// Define the minimum number of years that can be traveled
#define MIN_YEARS -100

// Define the number of possible outcomes for each year
#define NUM_OUTCOMES 5

// Define the possible outcomes for each year
char *outcomes[] = {
    "You win the lottery!",
    "You become a famous inventor.",
    "You meet the love of your life.",
    "You travel to the future.",
    "You travel to the past."
};

// Get a random number between two values
int get_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Simulate time travel
void time_travel(int years) {
    // Get a random outcome for the year
    int outcome = get_random_number(0, NUM_OUTCOMES - 1);

    // Print the outcome
    printf("You traveled %d years into the future and %s\n", years, outcomes[outcome]);
}

// Get the number of years to travel
int get_years() {
    // Get the number of years from the user
    int years;
    printf("How many years do you want to travel?\n");
    scanf("%d", &years);

    // Validate the number of years
    if (years < MIN_YEARS || years > MAX_YEARS) {
        printf("Invalid number of years. Please enter a number between %d and %d.\n", MIN_YEARS, MAX_YEARS);
        return get_years();
    }

    return years;
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Get the number of years to travel
    int years = get_years();

    // Simulate time travel
    time_travel(years);

    return 0;
}