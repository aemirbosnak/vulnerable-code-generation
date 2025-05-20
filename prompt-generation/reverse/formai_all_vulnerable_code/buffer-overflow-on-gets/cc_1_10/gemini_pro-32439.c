//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of years that the user can travel
#define MAX_YEARS 100

// Define the minimum year that the user can travel to
#define MIN_YEAR 1900

// Define the maximum year that the user can travel to
#define MAX_YEAR 2100

// Define the number of possible events that can occur during time travel
#define NUM_EVENTS 10

// Define the probability of each event occurring
#define EVENT_PROBABILITY 0.1

// Define the possible events that can occur during time travel
char *events[] = {
    "You meet a famous historical figure.",
    "You witness a major historical event.",
    "You learn a valuable lesson about history.",
    "You make a new friend from another time period.",
    "You experience a technological marvel from the future.",
    "You accidentally change the course of history.",
    "You get lost in time.",
    "You return to the present with a new perspective on life.",
    "You find a treasure from the past.",
    "You have an encounter with a supernatural being."
};

// Function to generate a random year within the specified range
int generate_random_year(int min_year, int max_year) {
    return (rand() % (max_year - min_year + 1)) + min_year;
}

// Function to generate a random event from the list of possible events
char *generate_random_event() {
    int event_index = rand() % NUM_EVENTS;
    return events[event_index];
}

// Function to simulate the user's time travel experience
void simulate_time_travel(int year) {
    // Print the year that the user has traveled to
    printf("You have traveled to the year %d.\n", year);

    // Generate a random event and print it to the console
    char *event = generate_random_event();
    printf("%s\n", event);

    // Ask the user if they want to travel to another year
    printf("Do you want to travel to another year? (y/n) ");
    char answer = getchar();

    // If the user wants to travel to another year, generate a new year and call the simulate_time_travel function again
    if (answer == 'y') {
        int new_year = generate_random_year(MIN_YEAR, MAX_YEAR);
        simulate_time_travel(new_year);
    }
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Ask the user for the year they want to travel to
    printf("What year do you want to travel to? ");
    int year = atoi(gets(stdin));

    // Validate the user's input
    if (year < MIN_YEAR || year > MAX_YEAR) {
        printf("Invalid year. Please enter a year between %d and %d.\n", MIN_YEAR, MAX_YEAR);
        return 1;
    }

    // Simulate the user's time travel experience
    simulate_time_travel(year);

    return 0;
}