//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Declare candidates and their vote counts
char candidates[][20] = {"Alice", "Bob", "Carol", "Dave", "Eve"};
int voteCount[] = {0, 0, 0, 0, 0};

// Declare the total number of candidates
int numCandidates = sizeof(candidates) / sizeof(candidates[0]);

// Declare the total number of votes
int numVotes = 0;

// Main function
int main() {
    // Welcome the user
    printf("Welcome to the Electronic Voting System!\n");

    // Get the number of votes from the user
    printf("How many people will be voting? ");
    scanf("%d", &numVotes);

    // Loop through each voter
    for (int i = 0; i < numVotes; i++) {
        // Get the voter's choice
        printf("\nVoter %d, please enter your choice (1-%d): ", i + 1, numCandidates);
        int choice;
        scanf("%d", &choice);

        // Increment the vote count for the selected candidate
        voteCount[choice - 1]++;
    }

    // Find the winner
    int winner = 0;
    int maxVotes = 0;
    for (int i = 0; i < numCandidates; i++) {
        if (voteCount[i] > maxVotes) {
            maxVotes = voteCount[i];
            winner = i;
        }
    }

    // Announce the winner
    printf("\nThe winner is %s!\n", candidates[winner]);

    // Thank the voters
    printf("Thank you for voting!");

    return 0;
}