//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 10

typedef struct {
    char name[50];
    int votes;
} Candidate;

typedef struct {
    char name[50];
    int voted;
} Voter;

int main() {
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];
    int numCandidates, numVoters;
    int i, j, k, vote;

    // Get user input for number of candidates
    printf("Enter the number of candidates: ");
    scanf("%d", &numCandidates);

    // Input candidate names and initialize their votes to zero
    for(i = 0; i < numCandidates; i++) {
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    // Get user input for number of voters
    printf("Enter the number of voters: ");
    scanf("%d", &numVoters);

    // Input voter names
    for(i = 0; i < numVoters; i++) {
        printf("Enter name of voter %d: ", i+1);
        scanf("%s", voters[i].name);
        voters[i].voted = 0;
    }

    // Loop through each voter and ask their vote
    for(i = 0; i < numVoters; i++) {
        printf("%s, please make your vote:\n", voters[i].name);
        for(j = 0; j < numCandidates; j++) {
            printf("%d. %s\n", j+1, candidates[j].name);
        }

        // Get voter's vote
        scanf("%d", &vote);

        // Check if vote is valid
        if(vote >= 1 && vote <= numCandidates) {
            // Check if voter has already voted
            if(voters[i].voted) {
                printf("Sorry, you have already voted.\n");
                i--; // Readjust loop counter to account for invalid vote
            } else {
                candidates[vote-1].votes++; // Increment vote count for candidate
                voters[i].voted = 1; // Update voter's voted status
                printf("Thank you for your vote!\n");
            }
        } else {
            printf("Invalid vote.\n");
            i--; // Readjust loop counter to account for invalid vote
        }
    }

    // Display election results
    printf("\nElection Results:\n");
    printf("-----------------\n");
    for(i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    // Determine winner
    int maxVotes = candidates[0].votes;
    int winnerIndex = 0;
    for(i = 1; i < numCandidates; i++) {
        if(candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            winnerIndex = i;
        }
    }

    // Display winner
    printf("-----------------\n");
    printf("%s is the winner with %d votes!\n", candidates[winnerIndex].name, maxVotes);

    return 0;
}