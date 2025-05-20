//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to convert milliseconds to seconds
double millisToSeconds(clock_t millis) {
    return ((double)millis)/CLOCKS_PER_SEC;
}

// Function to simulate time travel
void timeTravel(int years) {
    const int secondsPerYear = 31557600;   // Number of seconds in a year
    clock_t startTimeMillis = clock();     // Get current time
    int secondsToTravel = years * secondsPerYear;     // Calculate seconds to travel
    double totalTravelTime;     // Time traveled in seconds

    // Loop until time travel is complete
    while (totalTravelTime < (double)secondsToTravel) {
        // Calculate time elapsed
        clock_t currentTimeMillis = clock();
        double elapsedMillis = (double)(currentTimeMillis - startTimeMillis);
        double elapsedSeconds = millisToSeconds(elapsedMillis);

        // Add elapsed time to total travel time
        totalTravelTime += elapsedSeconds;

        // Output progress every 10 seconds
        if (((int)totalTravelTime % 10) == 0) {
            printf("Time traveled: %d/%d seconds\n", (int)totalTravelTime, secondsToTravel);
        }

        // Sleep for 1 millisecond before checking again
        usleep(1000);
    }

    // Time travel complete!
    printf("Time travel complete! %d years have passed.\n", years);
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Get input from user
    int yearsToTravel;
    printf("Enter number of years to travel: ");
    scanf("%d", &yearsToTravel);

    // Generate a random number to determine success chance
    int successChance = rand() % 100;

    // If success chance is less than 50%, time travel fails
    if (successChance < 50) {
        printf("Time travel failed!\n");
        return 0;
    }

    // Time travel success!
    printf("Time travel successful! \n");
    printf("Initiating time travel to the year %d...\n", (2021 + yearsToTravel));

    // Simulate time travel
    timeTravel(yearsToTravel);

    return 0;
}