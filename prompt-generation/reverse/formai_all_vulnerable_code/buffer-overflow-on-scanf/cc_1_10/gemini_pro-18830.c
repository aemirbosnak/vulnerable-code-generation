//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The maximum number of years that the user can travel into the past or future.
#define MAX_YEARS 100

// The minimum number of years that the user can travel into the past or future.
#define MIN_YEARS 1

// The number of different events that can occur during time travel.
#define NUM_EVENTS 10

// The probability of each event occurring during time travel.
#define EVENT_PROBABILITY 0.1

// The different events that can occur during time travel.
char *events[] = {
    "You meet a dinosaur.",
    "You win the lottery.",
    "You become president of the United States.",
    "You travel to a parallel universe.",
    "You meet your future self.",
    "You discover the cure for cancer.",
    "You invent a new technology.",
    "You become a famous artist.",
    "You write a best-selling book.",
    "You find true love."
};

// The function that simulates time travel.
void time_travel(int years) {
    // Check if the number of years is valid.
    if (years < MIN_YEARS || years > MAX_YEARS) {
        printf("Invalid number of years. Please enter a number between 1 and 100.\n");
        return;
    }

    // Seed the random number generator.
    srand(time(NULL));

    // Generate a random event.
    int event = rand() % NUM_EVENTS;

    // Print the event that occurred.
    printf("You traveled %d years into the %s.\n", years, years > 0 ? "future" : "past");
    printf("Event: %s\n", events[event]);
}

// The main function.
int main() {
    // Get the number of years that the user wants to travel.
    int years;
    printf("How many years do you want to travel?\n");
    scanf("%d", &years);

    // Simulate time travel.
    time_travel(years);

    return 0;
}