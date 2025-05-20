//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* Define the speed of light */
#define C 299792458.0

/* Define the maximum number of time travel attempts */
#define MAX_ATTEMPTS 10

/* Define the maximum number of years that can be traveled */
#define MAX_YEARS 100

int main() {
    int attempts = 0;
    int success = 0;
    int year = 0;

    /* Initialize the random number generator */
    srand(time(NULL));

    /* Loop until the user has successfully traveled through time */
    while (attempts < MAX_ATTEMPTS && success == 0) {
        /* Ask the user for the year they want to travel to */
        printf("Enter the year you want to travel to (0-100): ");
        scanf("%d", &year);

        /* Check if the year is within the valid range */
        if (year < 0 || year > MAX_YEARS) {
            printf("Invalid year. Try again.\n");
            continue;
        }

        /* Generate a random number between 0 and 1 */
        double rand_num = rand() / (double)RAND_MAX;

        /* Calculate the distance from the present year to the target year */
        double distance = fabs(year - 2021);

        /* Calculate the time required to travel through time */
        double time = distance / C;

        /* Determine if the time travel was successful */
        if (rand_num < 0.5) {
            printf("Time travel successful. You have traveled %d years into the future.\n", year);
            success = 1;
        } else {
            printf("Time travel failed. You are still in the year 2021.\n");
        }

        /* Increment the number of attempts */
        attempts++;
    }

    /* Print the number of attempts it took to travel through time */
    if (success == 1) {
        printf("You successfully traveled through time in %d attempts.\n", attempts);
    } else {
        printf("You were unable to travel through time after %d attempts.\n", MAX_ATTEMPTS);
    }

    return 0;
}