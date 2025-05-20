//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: grateful
#include <stdio.h>

// define the maximum number of candidates
#define MAX_CANDIDATES 10 

int main(void) {
    // define the variables 
    int num_candidates, num_voters, i, j, vote;
    char candidates[MAX_CANDIDATES][20];
    int votes[MAX_CANDIDATES];

    // initialize the votes to zero
    for (i = 0; i < MAX_CANDIDATES; i++) {
        votes[i] = 0;
    }

    // get the number of candidates
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    // get the candidate names
    printf("Enter the candidate names:\n");
    for (i = 0; i < num_candidates; i++) {
        scanf("%s", candidates[i]);
    }

    // get the number of voters
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    // get the votes from each voter
    for (i = 0; i < num_voters; i++) {
        printf("Voter %d, please enter your vote:\n", i+1);
        for (j = 0; j < num_candidates; j++) {
            printf("%d. %s\n", j+1, candidates[j]);
        }
        scanf("%d", &vote);
        votes[vote-1]++;
    }

    // print the election results
    printf("Election Results:\n");
    for (i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i], votes[i]);
    }

    // determine the winner
    int max_votes = votes[0];
    int winner = 0;
    for (i = 1; i < num_candidates; i++) {
        if (votes[i] > max_votes) {
            max_votes = votes[i];
            winner = i;
        }
    }
    printf("The winner is %s!\n", candidates[winner]);

    return 0;
}