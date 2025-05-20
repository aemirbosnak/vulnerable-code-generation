//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000
#define MAX_VOTE_OPTIONS 10

typedef struct {
    char name[50];
    int votes;
} candidate;

typedef struct {
    int voterID;
    int voteOption;
} vote;

candidate candidates[MAX_CANDIDATES];
vote votes[MAX_VOTERS][MAX_VOTE_OPTIONS];
int numOfCandidates, numOfVoters;

void readCandidates() {
    printf("Enter the number of candidates: ");
    scanf("%d", &numOfCandidates);

    for (int i = 0; i < numOfCandidates; i++) {
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
}

void readVotes() {
    printf("Enter the number of voters: ");
    scanf("%d", &numOfVoters);

    for (int i = 0; i < numOfVoters; i++) {
        printf("Enter the voter ID of voter %d: ", i+1);
        scanf("%d", &votes[i][0].voterID);

        printf("Enter the vote options for voter %d: ", i+1);
        for (int j = 1; j <= MAX_VOTE_OPTIONS; j++) {
            int voteOption;
            scanf("%d", &voteOption);
            votes[i][j].voteOption = voteOption;
        }
    }
}

void countVotes() {
    for (int i = 0; i < numOfVoters; i++) {
        for (int j = 1; j <= MAX_VOTE_OPTIONS; j++) {
            if (votes[i][j].voteOption == 1) {
                candidates[votes[i][0].voteOption-1].votes++;
            }
        }
    }
}

void printResults() {
    printf("\nElection Results:\n");
    for (int i = 0; i < numOfCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    readCandidates();
    readVotes();
    countVotes();
    printResults();

    return 0;
}