//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100
#define MAX_NAME_LENGTH 50

// Structure for a candidate
typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

// Structure for a voter
typedef struct {
    char name[MAX_NAME_LENGTH];
    int voterID;
} Voter;

// Function prototypes
void createCandidates(Candidate candidates[]);
void createVoters(Voter voters[]);
void castVote(Candidate candidates[], Voter voters[], int numVoters);
void countVotes(Candidate candidates[], int numCandidates, Voter voters[], int numVoters);

int main() {
    // Initialize candidates and voters
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];

    // Create candidates
    createCandidates(candidates);

    // Create voters
    createVoters(voters);

    // Cast votes
    castVote(candidates, voters, MAX_VOTERS);

    // Count votes
    countVotes(candidates, MAX_CANDIDATES, voters, MAX_VOTERS);

    return 0;
}

// Function to create candidates
void createCandidates(Candidate candidates[]) {
    int i;

    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
}

// Function to create voters
void createVoters(Voter voters[]) {
    int i;

    for (i = 0; i < MAX_VOTERS; i++) {
        printf("Enter the name of voter %d: ", i+1);
        scanf("%s", voters[i].name);
        voters[i].voterID = i+1;
    }
}

// Function to cast vote
void castVote(Candidate candidates[], Voter voters[], int numVoters) {
    int i, j, choice;

    for (i = 0; i < numVoters; i++) {
        printf("Voter %d, please enter your choice (1-%d): ", voters[i].voterID, MAX_CANDIDATES);
        scanf("%d", &choice);

        while (choice < 1 || choice > MAX_CANDIDATES) {
            printf("Invalid choice. Please enter your choice again: ");
            scanf("%d", &choice);
        }

        candidates[choice-1].votes++;
    }
}

// Function to count votes
void countVotes(Candidate candidates[], int numCandidates, Voter voters[], int numVoters) {
    int i, j;

    printf("\nElection Results:\n");
    for (i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}