//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000
#define MAX_VOTES 1000

// Candidate structure
typedef struct {
    char name[50];
    int votes;
} Candidate;

// Voter structure
typedef struct {
    int voterID;
    int vote;
} Voter;

// Function prototypes
void initialize(Candidate candidates[], int numCandidates);
void registerVoter(Voter voters[], int numVoters);
void castVote(Voter voters[], int numVoters, Candidate candidates[], int numCandidates);
void countVotes(Candidate candidates[], int numCandidates);

// Main function
int main() {
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];
    int numCandidates, numVoters;

    // Initialize random seed
    srand(time(NULL));

    // Get number of candidates
    printf("Enter the number of candidates: ");
    scanf("%d", &numCandidates);

    // Initialize candidates
    initialize(candidates, numCandidates);

    // Get number of voters
    printf("Enter the number of voters: ");
    scanf("%d", &numVoters);

    // Register voters
    registerVoter(voters, numVoters);

    // Cast votes
    castVote(voters, numVoters, candidates, numCandidates);

    // Count votes
    countVotes(candidates, numCandidates);

    // Print results
    printf("\nElection Results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}

// Function to initialize candidates
void initialize(Candidate candidates[], int numCandidates) {
    for (int i = 0; i < numCandidates; i++) {
        candidates[i].votes = 0;
        sprintf(candidates[i].name, "Candidate %d", i+1);
    }
}

// Function to register voters
void registerVoter(Voter voters[], int numVoters) {
    for (int i = 0; i < numVoters; i++) {
        voters[i].voterID = i+1;
        voters[i].vote = 0;
    }
}

// Function to cast vote
void castVote(Voter voters[], int numVoters, Candidate candidates[], int numCandidates) {
    printf("\nVoting is now open.\n");
    for (int i = 0; i < numVoters; i++) {
        printf("Voter %d, please enter your vote (1-%d): ", voters[i].voterID, numCandidates);
        scanf("%d", &voters[i].vote);
    }
}

// Function to count votes
void countVotes(Candidate candidates[], int numCandidates) {
    for (int i = 0; i < numCandidates; i++) {
        for (int j = 0; j < numCandidates; j++) {
            if (candidates[i].name == candidates[j].name) {
                candidates[i].votes += candidates[j].votes;
                candidates[j].votes = 0;
            }
        }
    }
}