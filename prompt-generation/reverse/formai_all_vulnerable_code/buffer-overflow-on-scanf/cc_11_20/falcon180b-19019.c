//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int voterID;
} Voter;

int main() {
    int numVoters, numCandidates;
    char choice;
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];

    // Initialize candidates
    numCandidates = 0;
    printf("Enter number of candidates: ");
    scanf("%d", &numCandidates);
    for (int i = 0; i < numCandidates; i++) {
        printf("Enter candidate name: ");
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    // Initialize voters
    numVoters = 0;
    printf("Enter number of voters: ");
    scanf("%d", &numVoters);
    for (int i = 0; i < numVoters; i++) {
        printf("Enter voter name: ");
        scanf("%s", voters[i].name);
        voters[i].voterID = i;
    }

    // Voting process
    printf("Voting has begun...\n");
    while (1) {
        printf("Enter your voter ID: ");
        scanf("%d", &choice);
        if (choice >= 0 && choice < numVoters) {
            printf("Enter candidate name: ");
            scanf("%s", candidates[choice].name);
            candidates[choice].votes++;
            break;
        } else {
            printf("Invalid voter ID.\n");
        }
    }

    // Counting votes
    printf("Counting votes...\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    // Declaring winner
    int maxVotes = 0;
    for (int i = 0; i < numCandidates; i++) {
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
        }
    }
    for (int i = 0; i < numCandidates; i++) {
        if (candidates[i].votes == maxVotes) {
            printf("Winner: %s\n", candidates[i].name);
        }
    }

    return 0;
}