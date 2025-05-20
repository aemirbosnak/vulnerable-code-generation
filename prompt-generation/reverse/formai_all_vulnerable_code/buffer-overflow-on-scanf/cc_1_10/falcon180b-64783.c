//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 100
int generateRandomNumber() {
    return rand() % 100 + 1;
}

// Function to determine if an alien invasion is likely
int isAlienInvasionLikely(int numSightings, int numAbductions) {
    if (numSightings > 10 && numAbductions > 5) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int numSightings, numAbductions;
    int totalSightings = 0, totalAbductions = 0;
    int invasionLikely = 0;
    int i;

    // Seed the random number generator
    srand(time(NULL));

    // Loop until the user decides to quit
    while (1) {
        // Generate a random number of sightings and abductions
        numSightings = generateRandomNumber();
        numAbductions = generateRandomNumber();

        // Add the current sightings and abductions to the totals
        totalSightings += numSightings;
        totalAbductions += numAbductions;

        // Print the current results
        printf("Total sightings: %d\n", totalSightings);
        printf("Total abductions: %d\n", totalAbductions);

        // Determine if an alien invasion is likely
        invasionLikely = isAlienInvasionLikely(numSightings, numAbductions);

        // Print the likelihood of an alien invasion
        if (invasionLikely == 1) {
            printf("An alien invasion is likely!\n");
        } else {
            printf("An alien invasion is not likely.\n");
        }

        // Ask the user if they want to continue
        printf("Do you want to continue? (y/n) ");
        scanf("%c", &i);

        // If the user doesn't want to continue, exit the loop
        if (i!= 'y') {
            break;
        }
    }

    return 0;
}