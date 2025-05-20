//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_NAME_LENGTH 50
#define MAX_VOTE_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int vote[MAX_CANDIDATES];
} Voter;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int voteCount;
} Candidate;

void readCandidates(Candidate candidates[], int numCandidates) {
    for (int i = 0; i < numCandidates; i++) {
        printf("Enter name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
    }
}

void readVoters(Voter voters[], int numVoters) {
    for (int i = 0; i < numVoters; i++) {
        printf("Enter name of voter %d: ", i + 1);
        scanf("%s", voters[i].name);
        printf("Enter votes for candidates (separated by spaces): ");
        for (int j = 0; j < MAX_CANDIDATES; j++) {
            if (scanf("%d", &voters[i].vote[j])!= 1) {
                break;
            }
        }
    }
}

void countVotes(Candidate candidates[], Voter voters[], int numCandidates, int numVoters) {
    for (int i = 0; i < numVoters; i++) {
        for (int j = 0; j < numCandidates; j++) {
            if (strcmp(candidates[j].name, voters[i].name) == 0) {
                candidates[j].voteCount = voters[i].vote[j];
            }
        }
    }
}

void printResults(Candidate candidates[], int numCandidates) {
    printf("Election Results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].voteCount);
    }
}

int main() {
    int numCandidates, numVoters;
    printf("Enter number of candidates: ");
    scanf("%d", &numCandidates);
    printf("Enter number of voters: ");
    scanf("%d", &numVoters);

    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];

    readCandidates(candidates, numCandidates);
    readVoters(voters, numVoters);
    countVotes(candidates, voters, numCandidates, numVoters);
    printResults(candidates, numCandidates);

    return 0;
}