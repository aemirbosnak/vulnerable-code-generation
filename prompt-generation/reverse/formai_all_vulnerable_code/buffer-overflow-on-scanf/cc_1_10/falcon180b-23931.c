//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEAR 9999
#define MIN_YEAR 1900

// Function to generate a random year between min and max
int get_random_year() {
    int min = MIN_YEAR;
    int max = MAX_YEAR;
    return rand() % (max - min + 1) + min;
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    // Loop until the user wants to quit
    while (1) {
        int year;

        // Get a random year
        year = get_random_year();

        // Print the current year
        printf("Current year: %d\n", year);

        // Ask the user if they want to time travel
        char choice;
        printf("Do you want to time travel? (y/n): ");
        scanf(" %c", &choice);

        // If the user chooses to time travel, get the destination year
        if (choice == 'y' || choice == 'Y') {
            int dest_year;
            printf("Enter the destination year: ");
            scanf("%d", &dest_year);

            // Check if the destination year is valid
            if (dest_year < MIN_YEAR || dest_year > MAX_YEAR) {
                printf("Invalid destination year.\n");
            } else {
                // Travel to the destination year
                printf("Traveling to %d...\n", dest_year);
                year = dest_year;
            }
        }

        // Ask the user if they want to quit
        printf("Do you want to quit? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            break;
        }
    }

    return 0;
}