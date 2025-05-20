//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of years to travel
#define MAX_YEARS 100

// Define the minimum number of years to travel
#define MIN_YEARS -100

// Define the number of possible destinations
#define NUM_DESTINATIONS 5

// Define the possible destinations
char *destinations[] = {
    "The past",
    "The future",
    "A parallel universe",
    "A distant planet",
    "A mythical realm"
};

// Get a random number between two values
int get_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Get a random destination
char *get_random_destination() {
    return destinations[get_random_number(0, NUM_DESTINATIONS - 1)];
}

// Get the current year
int get_current_year() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    return tm->tm_year + 1900;
}

// Get the year to travel to
int get_year_to_travel_to() {
    int year = get_random_number(MIN_YEARS, MAX_YEARS);
    if (year < 0) {
        year = get_current_year() + year;
    }
    return year;
}

// Print the time travel results
void print_time_travel_results(int year, char *destination) {
    printf("You have traveled to %s in the year %d.\n", destination, year);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the year to travel to
    int year = get_year_to_travel_to();

    // Get the destination
    char *destination = get_random_destination();

    // Print the time travel results
    print_time_travel_results(year, destination);

    return 0;
}