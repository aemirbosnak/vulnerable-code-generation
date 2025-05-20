//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_VOTERS 1000
#define MAX_CANDIDATES 5

typedef struct {
    char name[50];
    int votes;
} Candidate;

typedef struct {
    int voterID;
    int candidateID;
} Vote;

Candidate candidates[MAX_CANDIDATES];
Vote votes[MAX_VOTERS];
int numVoters = 0, numCandidates = 0;

void registerCandidate(char* name) {
    if (numCandidates >= MAX_CANDIDATES) {
        printf("Max number of candidates reached.\n");
        return;
    }

    strcpy(candidates[numCandidates].name, name);
    candidates[numCandidates].votes = 0;
    numCandidates++;
}

void vote(int voterID, int candidateID) {
    if (numVoters >= MAX_VOTERS) {
        printf("Max number of voters reached.\n");
        return;
    }

    votes[numVoters].voterID = voterID;
    votes[numVoters].candidateID = candidateID;
    candidates[candidateID].votes++;
    numVoters++;
}

void displayResults() {
    int i;

    printf("\n-------------------------\n");
    printf("Results of the Election:\n");
    printf("-------------------------\n");

    for (i = 0; i < numCandidates; i++) {
        printf("\n%s: %d votes", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int i, choice, voterID, candidateID;
    char name[50];
    clock_t start, end;

    printf("\nWelcome to the Romantic E-Voting System!\n");

    // Register Candidates
    printf("\nRegistering Candidates...\n");
    start = clock();
    for (i = 0; i < 5; i++) {
        printf("\nEnter Name of Candidate %d: ", i + 1);
        scanf("%s", name);
        registerCandidate(name);
    }
    end = clock();
    printf("\nRegistration completed in %fs.\n", (float)(end - start) / CLOCKS_PER_SEC);

    // Voting Process
    printf("\nVoting Process...\n");
    start = clock();
    for (i = 0; i < numVoters; i++) {
        printf("\nEnter Voter ID: ");
        scanf("%d", &voterID);
        printf("Enter Candidate ID: ");
        scanf("%d", &candidateID);
        vote(voterID, candidateID);
    }
    end = clock();
    printf("\nVoting process completed in %fs.\n", (float)(end - start) / CLOCKS_PER_SEC);

    // Display Results
    displayResults();

    return 0;
}