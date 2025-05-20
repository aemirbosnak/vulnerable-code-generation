//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: systematic
#include <stdio.h>

// Structure for Candidate Information
struct Candidate {
    char name[50];
    int votes;
};

int main() {
    int numCandidates, numVoters;

    printf("Welcome to the Electronic Voting System!\n");
    printf("Enter the number of candidates: ");
    scanf("%d", &numCandidates);

    struct Candidate candidates[numCandidates];

    for(int i=0; i<numCandidates; i++) {
        printf("\nEnter Candidate %d's name: ", i+1);
        scanf("%s", &candidates[i].name);
        candidates[i].votes = 0;
    }

    printf("\nEnter the number of voters: ");
    scanf("%d", &numVoters);

    for(int i=0; i<numVoters; i++) {
        printf("\nVoting for candidate...\n");
        for(int j=0; j<numCandidates; j++) {
            printf("%d. %s\n", j+1, candidates[j].name);
        }
        int vote;
        printf("Enter your vote: ");
        scanf("%d", &vote);
        candidates[vote-1].votes++;
        printf("\nThank you for voting!\n");
    }

    printf("\nVote Summary:\n");
    for(int i=0; i<numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    int maxVotes = 0;
    int winnerIndex;
    for(int i=0; i<numCandidates; i++) {
        if(candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            winnerIndex = i;
        }
    }

    printf("\nThe winner is: %s\n", candidates[winnerIndex].name);

    return 0;
}