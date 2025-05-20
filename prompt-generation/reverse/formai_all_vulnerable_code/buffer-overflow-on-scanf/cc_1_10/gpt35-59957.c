//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Define candidate structure
struct candidate {
    char name[50];
    int votes;
};

// Function to display voting options
void displayOptions(struct candidate candidates[], int numberOfCandidates) {
    printf("\n\n*** Voting Options ***\n");
    for (int i = 0; i < numberOfCandidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

// Function to get user's vote
int getVote(int numberOfCandidates) {
    int vote;
    printf("Enter your vote: ");
    scanf("%d", &vote);
    while (vote < 1 || vote > numberOfCandidates) {
        printf("Invalid vote! Enter your vote again: ");
        scanf("%d", &vote);
    }
    return vote;
}

int main() {
    int numberOfCandidates, numberOfVoters;
    printf("Enter the number of candidates: ");
    scanf("%d", &numberOfCandidates);
    struct candidate candidates[numberOfCandidates];
    for (int i = 0; i < numberOfCandidates; i++) {
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
    printf("Enter the number of voters: ");
    scanf("%d", &numberOfVoters);
    printf("\n\n*** Voting Starts ***");
    for (int i = 0; i < numberOfVoters; i++) {
        printf("\n\n*** Voter %d ***", i+1);
        displayOptions(candidates, numberOfCandidates);
        int vote = getVote(numberOfCandidates);
        candidates[vote-1].votes++;
        printf("Thank you for voting!");
    }
    printf("\n\n*** Voting Ends ***\n\n");
    printf("Vote Count:\n");
    for (int i = 0; i < numberOfCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
    return 0;
}