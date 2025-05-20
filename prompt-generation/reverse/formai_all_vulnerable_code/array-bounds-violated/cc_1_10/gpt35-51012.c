//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// Define the structure for candidate with name and vote counters
struct Candidate {
    char name[50];
    int votes;
};

// Define the structure for voter with name and candidate ID
struct Voter {
    char name[50];
    int candidateID;
};

// Define function getVote to get the vote of a voter
int getVote() {
    int vote;

    // Get vote ID from the user
    printf("Please enter the ID of the candidate you want to vote for: ");
    scanf("%d", &vote);

    // Return the vote ID
    return vote;
}

// Define function main
int main() {
    int numCandidates, numVoters;
    struct Candidate candidates[MAX_CANDIDATES];
    struct Voter voters[MAX_VOTERS];

    // Get the number of candidates from the user
    printf("Please enter the number of candidates: ");
    scanf("%d", &numCandidates);

    // Get the names of the candidates from the user
    for (int i = 0; i < numCandidates; i++) {
        printf("Please enter the name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);

        // initialize vote counters to 0
        candidates[i].votes = 0;
    }

    // Get the number of voters from the user
    printf("Please enter the number of voters: ");
    scanf("%d", &numVoters);

    // Get the names of the voters and their votes
    for (int i = 0; i < numVoters; i++) {
        printf("Please enter the name of voter %d: ", i+1);
        scanf("%s", voters[i].name);

        // Get the vote for this voter
        voters[i].candidateID = getVote();

        // Increment the vote counter for the chosen candidate
        candidates[voters[i].candidateID - 1].votes++;
    }

    // Print the results
    printf("\nVoting results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d\n", candidates[i].name, candidates[i].votes);
    }

    // Find the candidate with the most votes
    int winner = 0;
    for (int i = 1; i < numCandidates; i++) {
        if (candidates[i].votes > candidates[winner].votes) {
            winner = i;
        }
    }

    // Print the name of the winner
    printf("The winner is %s with %d votes!\n", candidates[winner].name, candidates[winner].votes);

    return 0;
}