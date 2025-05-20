//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEAR 9999
#define MIN_YEAR 1000

// Function to validate user input for year
int isValidYear(int year) {
    if (year >= MIN_YEAR && year <= MAX_YEAR) {
        return 1;
    } else {
        return 0;
    }
}

// Function to generate a random year within the given range
int generateRandomYear(int minYear, int maxYear) {
    return rand() % (maxYear - minYear + 1) + minYear;
}

// Function to simulate time travel
void timeTravel(int currentYear, int destinationYear) {
    int i;
    for (i = currentYear; i!= destinationYear; i++) {
        printf("%d: ", i);
        if (i % 100 == 0) {
            printf("A new century has begun!\n");
        } else if (i % 10 == 0) {
            printf("A new decade has begun!\n");
        }
        sleep(1); // Pause for 1 second
    }
    printf("%d: We have arrived at our destination!\n", destinationYear);
    sleep(2); // Pause for 2 seconds
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    int currentYear, destinationYear;

    // Get the current year from the user
    printf("Enter the current year: ");
    scanf("%d", &currentYear);

    // Validate user input
    while (!isValidYear(currentYear)) {
        printf("Invalid year. Please enter a year between %d and %d: ", MIN_YEAR, MAX_YEAR);
        scanf("%d", &currentYear);
    }

    // Get the destination year from the user
    printf("Enter the destination year: ");
    scanf("%d", &destinationYear);

    // Validate user input
    while (!isValidYear(destinationYear)) {
        printf("Invalid year. Please enter a year between %d and %d: ", MIN_YEAR, MAX_YEAR);
        scanf("%d", &destinationYear);
    }

    // Simulate time travel
    timeTravel(currentYear, destinationYear);

    return 0;
}