//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The two candidates
#define ROMEO "Romeo"
#define JULIET "Juliet"

// The number of voters
#define NUM_VOTERS 10

// The array of voters
char *voters[NUM_VOTERS] = {"Montague", "Capulet", "Tybalt", "Mercutio", "Benvolio", "Paris", "Friar Laurence", "Nurse", "Peter", "Abraham"};

// The array of votes
int votes[NUM_VOTERS];

// The main function
int main() {
    // Initialize the votes to 0
    for (int i = 0; i < NUM_VOTERS; i++) {
        votes[i] = 0;
    }

    // Get the votes from the voters
    for (int i = 0; i < NUM_VOTERS; i++) {
        printf("Who do you vote for, %s? ", voters[i]);
        char *vote = malloc(sizeof(char) * 100);
        scanf("%s", vote);

        // Increment the vote count for the candidate
        if (strcmp(vote, ROMEO) == 0) {
            votes[0]++;
        } else if (strcmp(vote, JULIET) == 0) {
            votes[1]++;
        } else {
            printf("Invalid vote! Please try again.\n");
            i--;
        }

        free(vote);
    }

    // Print the results
    printf("The results of the election are:\n");
    printf("%s: %d votes\n", ROMEO, votes[0]);
    printf("%s: %d votes\n", JULIET, votes[1]);

    // Determine the winner
    int winner = 0;
    if (votes[0] > votes[1]) {
        winner = 0;
    } else if (votes[1] > votes[0]) {
        winner = 1;
    } else {
        winner = -1;
    }

    // Print the winner
    if (winner == -1) {
        printf("There is a tie!\n");
    } else {
        printf("The winner is %s!\n", winner == 0 ? ROMEO : JULIET);
    }

    return 0;
}