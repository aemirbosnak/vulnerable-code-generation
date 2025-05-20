//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Configuration options
#define MIN_NUMBER 1   // Minimum number for the random range
#define MAX_NUMBER 100 // Maximum number for the random range
#define NUM_GUESSES 5  // Maximum number of guesses allowed
#define YES_FIRST   1  // Display "Yes" or "No" first in response
#define YES_PERCENT 70 // Percentage chance of "Yes" being the first response

int main() {
    int answer, guess, num_guesses, num_yes, num_no;
    char response[20];
    srand(time(NULL)); // Seed random number generator with current time

    // Generate random answer
    answer = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;

    // Initialize guess counter and response counters
    num_guesses = 0;
    num_yes = 0;
    num_no = 0;

    // Loop until maximum number of guesses is reached
    while (num_guesses < NUM_GUESSES) {
        // Prompt user for guess
        printf("Make a guess between %d and %d: ", MIN_NUMBER, MAX_NUMBER);
        scanf("%d", &guess);

        // Check if guess is correct
        if (guess == answer) {
            printf("Congratulations! You guessed the correct number in %d guess(es).\n", num_guesses+1);
            break;
        }
        else {
            num_guesses++;
            printf("Sorry, that was not the correct number. You have %d guess(es) remaining.\n", NUM_GUESSES-num_guesses);

            // Generate random response
            if (YES_FIRST && rand() % 100 < YES_PERCENT || !YES_FIRST && rand() % 100 >= 50) {
                strcpy(response, "Yes");
                num_yes++;
            }
            else {
                strcpy(response, "No");
                num_no++;
            }

            printf("The fortune teller says: %s\n", response);
        }
    }

    // If maximum number of guesses is reached
    if (num_guesses == NUM_GUESSES) {
        printf("Sorry, you have exceeded the maximum number of guesses. The correct number was %d.\n", answer);
    }

    // Display response statistics
    printf("The fortune teller said \"Yes\" %d time(s) and \"No\" %d time(s).\n", num_yes, num_no);

    return 0;
}