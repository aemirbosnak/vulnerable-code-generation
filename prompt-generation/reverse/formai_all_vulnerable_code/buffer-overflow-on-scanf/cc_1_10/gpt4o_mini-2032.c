//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int votes;
} Candidate;

typedef struct {
    int totalVoters;
    Candidate *candidates;
} Election;

void initializeElection(Election *election, int numCandidates) {
    election->totalVoters = 0;
    election->candidates = (Candidate *)malloc(numCandidates * sizeof(Candidate));
    for (int i = 0; i < numCandidates; i++) {
        election->candidates[i].votes = 0;
    }
}

void addCandidate(Election *election, char *name, int index) {
    strncpy(election->candidates[index].name, name, MAX_NAME_LEN);
}

void castVote(Election *election) {
    int choice;
    printf("Enter candidate number to vote (0 to %d): ", MAX_CANDIDATES - 1);
    scanf("%d", &choice);
    if (choice >= 0 && choice < MAX_CANDIDATES) {
        election->candidates[choice].votes++;
        election->totalVoters++;
        printf("Vote casted for %s\n", election->candidates[choice].name);
    } else {
        printf("Invalid choice. Please choose a valid candidate number.\n");
    }
}

void showResults(Election *election) {
    printf("\nElection Results:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: %d votes\n", election->candidates[i].name, election->candidates[i].votes);
    }
    printf("Total voters: %d\n", election->totalVoters);
}

void freeResources(Election *election) {
    free(election->candidates);
}

int main() {
    Election election;
    int numCandidates;

    printf("Enter the number of candidates (up to %d): ", MAX_CANDIDATES);
    scanf("%d", &numCandidates);
    
    if (numCandidates < 1 || numCandidates > MAX_CANDIDATES) {
        printf("Error: Number of candidates must be between 1 and %d.\n", MAX_CANDIDATES);
        return -1;
    }

    initializeElection(&election, numCandidates);

    for (int i = 0; i < numCandidates; i++) {
        char name[MAX_NAME_LEN];
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", name);
        addCandidate(&election, name, i);
    }

    int keepVoting = 1;
    while (keepVoting) {
        castVote(&election);
        printf("Do you want to cast another vote? (1 for Yes, 0 for No): ");
        scanf("%d", &keepVoting);
    }

    showResults(&election);
    freeResources(&election);
    
    return 0;
}