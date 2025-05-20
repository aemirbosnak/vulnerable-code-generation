//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 5

int main() {
    int voters[MAX_VOTERS][MAX_CANDIDATES];
    int candidates[MAX_CANDIDATES];
    int num_voters, num_candidates, choice, i, j;
    char confirm_vote;

    printf("Welcome to the Electronic Voting System!\n\n");

    // Get number of voters and candidates
    printf("Enter the total number of voters: ");
    scanf("%d", &num_voters);

    printf("Enter the total number of candidates: ");
    scanf("%d", &num_candidates);

    // Initialize candidates array
    for (i = 0; i < num_candidates; i++) {
        candidates[i] = 0;
    }

    // Collect votes from each voter
    for (i = 0; i < num_voters; i++) {
        
        // Clear the screen for each voter
        system("clear");

        printf("Voter #%d, please select your candidate:\n", i+1);

        // Display list of candidates
        printf("Candidates:\n");
        for (j = 0; j < num_candidates; j++) {
            printf("%d. Candidate #%d\n", j+1, j+1);
        }

        // Get voter's choice of candidate
        printf("Choice: ");
        scanf("%d", &choice);

        // Confirm voter's choice
        printf("Are you sure you want to vote for Candidate #%d? (Y/N) ", choice);
        scanf(" %c", &confirm_vote);

        if (confirm_vote == 'Y' || confirm_vote == 'y') {
            // Record vote
            voters[i][choice-1] = 1;
            candidates[choice-1]++;
            printf("Thank you for voting!\n\n");
        } else {
            printf("Vote cancelled.\n\n");
        }

        // Wait for voter to acknowledge their vote has been recorded
        char acknowledge_vote;
        printf("Press any key to continue...");
        scanf(" %c", &acknowledge_vote);
    }

    // Display election results
    system("clear");
    printf("Election Results:\n");
    for (i = 0; i < num_candidates; i++) {
        printf("Candidate #%d: %d votes\n", i+1, candidates[i]);
    }

    printf("\nThank you for using the Electronic Voting System!\n\n");

    return 0;
}