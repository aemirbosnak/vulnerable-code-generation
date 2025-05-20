//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 1000
#define MAX_YEAR 10000

int main() {
    int tries = 0;
    int year = 0;
    int invasion_year = 0;
    double probability = 0.0;
    double invasion_probability = 0.0;
    srand(time(NULL));

    // Loop until the user decides to quit
    while (1) {
        printf("Alien Invasion Probability Calculator\n");
        printf("=====================================\n");
        printf("Enter the number of tries: ");
        scanf("%d", &tries);
        printf("Enter the current year: ");
        scanf("%d", &year);

        // Calculate the probability of an alien invasion based on the number of tries and the current year
        for (int i = 0; i < MAX_TRIES; i++) {
            if (year == invasion_year) {
                invasion_probability = 1.0;
                break;
            } else if (i == MAX_TRIES - 1) {
                invasion_probability = 0.0;
            } else {
                invasion_probability += 1.0 / (double)MAX_YEAR;
            }
        }

        // Print the results
        printf("The probability of an alien invasion in %d is: %.2f%%\n", year, invasion_probability * 100.0);
        printf("Press enter to try again or type quit to exit.\n");

        // Read the user's choice
        char choice;
        scanf(" %c", &choice);

        // Quit the program if the user types "quit"
        if (choice == 'q' || choice == 'Q') {
            break;
        }
    }

    return 0;
}