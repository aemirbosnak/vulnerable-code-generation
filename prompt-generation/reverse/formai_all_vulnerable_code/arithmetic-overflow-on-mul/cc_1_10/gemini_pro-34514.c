//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of time jumps
#define MAX_JUMPS 10

// Define the maximum number of years to jump
#define MAX_YEARS 100

// Define the minimum number of years to jump
#define MIN_YEARS 1

// Define the seed for the random number generator
#define SEED 12345

// Declare the main function
int main()
{
    // Set the seed for the random number generator
    srand(SEED);

    // Get the current time
    time_t now = time(NULL);

    // Print the current time
    printf("Current time: %s", ctime(&now));

    // Get the number of time jumps from the user
    int numJumps;
    printf("Enter the number of time jumps (1-%d): ", MAX_JUMPS);
    scanf("%d", &numJumps);

    // Validate the number of time jumps
    if (numJumps < 1 || numJumps > MAX_JUMPS)
    {
        printf("Invalid number of time jumps. Please enter a number between 1 and %d.\n", MAX_JUMPS);
        return 1;
    }

    // Get the number of years to jump from the user
    int years;
    printf("Enter the number of years to jump (1-%d): ", MAX_YEARS);
    scanf("%d", &years);

    // Validate the number of years to jump
    if (years < MIN_YEARS || years > MAX_YEARS)
    {
        printf("Invalid number of years to jump. Please enter a number between %d and %d.\n", MIN_YEARS, MAX_YEARS);
        return 1;
    }

    // Perform the time jumps
    for (int i = 0; i < numJumps; i++)
    {
        // Generate a random number of years to jump
        int randYears = rand() % years + 1;

        // Add the random number of years to the current time
        now += randYears * 60 * 60 * 24 * 365;

        // Print the new time
        printf("Time jump %d: %s\n", i + 1, ctime(&now));
    }

    // Return 0 to indicate success
    return 0;
}