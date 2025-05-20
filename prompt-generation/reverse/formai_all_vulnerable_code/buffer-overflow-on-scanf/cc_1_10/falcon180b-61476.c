//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 50

// Structure for a candidate
typedef struct {
    char name[50];
    int votes;
} Candidate;

// Structure for a voter
typedef struct {
    char name[50];
    int voterID;
} Voter;

// Function to add a candidate
void addCandidate(Candidate candidates[], int numCandidates, char name[]) {
    if (numCandidates == MAX_CANDIDATES) {
        printf("Maximum number of candidates reached.\n");
        return;
    }
    strcpy(candidates[numCandidates].name, name);
    candidates[numCandidates].votes = 0;
    numCandidates++;
}

// Function to add a voter
void addVoter(Voter voters[], int numVoters, char name[], int voterID) {
    if (numVoters == MAX_VOTERS) {
        printf("Maximum number of voters reached.\n");
        return;
    }
    strcpy(voters[numVoters].name, name);
    voters[numVoters].voterID = voterID;
    numVoters++;
}

// Function to display candidates
void displayCandidates(Candidate candidates[], int numCandidates) {
    printf("Candidates:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

// Function to cast vote
void castVote(Voter voters[], int numVoters, Candidate candidates[], int numCandidates, int choice) {
    char name[50];
    int voterID;
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your voter ID: ");
    scanf("%d", &voterID);

    // Check if voter already exists
    for (int i = 0; i < numVoters; i++) {
        if (strcmp(voters[i].name, name) == 0 && voters[i].voterID == voterID) {
            printf("You have already voted.\n");
            return;
        }
    }

    // Check if choice is valid
    if (choice < 1 || choice > numCandidates) {
        printf("Invalid choice.\n");
        return;
    }

    // Add voter if not already present
    addVoter(voters, numVoters, name, voterID);

    // Increment votes for chosen candidate
    candidates[choice-1].votes++;
}

// Function to display results
void displayResults(Candidate candidates[], int numCandidates, Voter voters[], int numVoters) {
    printf("Results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];
    int numCandidates = 0, numVoters = 0;

    // Add candidates
    addCandidate(candidates, numCandidates, "John");
    addCandidate(candidates, numCandidates, "Jane");
    addCandidate(candidates, numCandidates, "Bob");

    // Add voters and cast votes
    addVoter(voters, numVoters, "Alice", 1);
    castVote(voters, numVoters, candidates, numCandidates, 1);
    addVoter(voters, numVoters, "Bob", 2);
    castVote(voters, numVoters, candidates, numCandidates, 2);
    addVoter(voters, numVoters, "Charlie", 3);
    castVote(voters, numVoters, candidates, numCandidates, 3);

    // Display results
    displayResults(candidates, numCandidates, voters, numVoters);

    return 0;
}