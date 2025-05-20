//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of years we can travel
#define MAX_YEARS 100

// Function to generate a random year
int generate_random_year() {
    // Get the current year
    time_t current_time = time(NULL);
    struct tm *current_time_struct = localtime(&current_time);
    int current_year = current_time_struct->tm_year + 1900;

    // Generate a random year within the range [current_year - MAX_YEARS, current_year + MAX_YEARS]
    int random_year = current_year - MAX_YEARS + rand() % (2 * MAX_YEARS + 1);

    return random_year;
}

// Function to simulate time travel
void time_travel(int year) {
    // Check if the year is within the allowed range
    if (year < 1900 || year > 2100) {
        printf("Error: Invalid year. Please enter a year between 1900 and 2100.\n");
        return;
    }

    // Print a message to the user
    printf("Traveling to the year %d...\n", year);

    // Sleep for a random amount of time to simulate the time travel experience
    sleep(rand() % 10 + 1);

    // Print a message to the user
    printf("You have arrived in the year %d.\n", year);

    // Simulate the experience of being in the year
    printf("The year is %d. The world is a very different place than it is today.\n", year);
    printf("There are flying cars, robots, and artificial intelligence everywhere.\n");
    printf("The climate has changed dramatically, and the sea levels have risen.\n");

    // Allow the user to explore the year
    printf("What would you like to do? You can explore the city, visit historical landmarks, or meet famous people.\n");
    char input;
    scanf(" %c", &input);

    switch (input) {
        case '1':
            // Explore the city
            printf("You explore the city and see all the amazing new things.\n");
            break;
        case '2':
            // Visit historical landmarks
            printf("You visit historical landmarks and learn about the past.\n");
            break;
        case '3':
            // Meet famous people
            printf("You meet famous people and learn about their lives.\n");
            break;
        default:
            // Do nothing
            printf("You decide to do nothing and just enjoy the experience.\n");
            break;
    }

    // Print a message to the user
    printf("Your time travel experience is now complete.\n");
    printf("Returning to the present...\n");

    // Sleep for a random amount of time to simulate the return trip
    sleep(rand() % 10 + 1);

    // Print a message to the user
    printf("You have returned to the present.\n");
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random year
    int year = generate_random_year();

    // Simulate time travel
    time_travel(year);

    return 0;
}