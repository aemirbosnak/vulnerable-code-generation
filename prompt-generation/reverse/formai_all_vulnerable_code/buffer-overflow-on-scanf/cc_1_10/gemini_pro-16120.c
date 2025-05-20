//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The candidates we can vote for
#define NUM_CANDIDATES 3
char *candidates[] = {"Homer Simpson", "Peter Griffin", "Charlie Brown"};

// The number of votes each candidate has
int votes[NUM_CANDIDATES] = {0, 0, 0};

// The main function
int main() {
    // Print a welcome message
    printf("Welcome to the Electronic Voting System!\n");

    // Get the user's vote
    int vote;
    printf("Who do you want to vote for? (Enter a number between 1 and %d)\n", NUM_CANDIDATES);
    scanf("%d", &vote);

    // Check if the user's vote is valid
    if (vote < 1 || vote > NUM_CANDIDATES) {
        printf("Invalid vote. Please enter a number between 1 and %d\n", NUM_CANDIDATES);
        return 1;
    }

    // Increment the vote count for the user's candidate
    votes[vote - 1]++;

    // Print a confirmation message
    printf("Thank you for voting!\n");

    // Find the winner
    int winner = 0;
    for (int i = 1; i < NUM_CANDIDATES; i++) {
        if (votes[i] > votes[winner]) {
            winner = i;
        }
    }

    // Print the winner
    printf("The winner is %s!\n", candidates[winner]);

    // Print a funny message
    switch (winner) {
        case 0:
            printf("D'oh!");
            break;
        case 1:
            printf("Giggity!");
            break;
        case 2:
            printf("Good grief!");
            break;
    }

    return 0;
}