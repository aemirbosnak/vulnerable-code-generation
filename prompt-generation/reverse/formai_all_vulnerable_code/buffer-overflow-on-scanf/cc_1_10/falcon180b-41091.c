//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000

typedef struct {
    char name[50];
    int votes;
} Candidate;

typedef struct {
    int voterID;
    int choice;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];

void addCandidate(Candidate* c) {
    int i;
    for (i = 0; i < MAX_CANDIDATES; i++) {
        if (candidates[i].name[0] == '\0') {
            strcpy(candidates[i].name, c->name);
            candidates[i].votes = 0;
            return;
        }
    }
}

void addVoter(Voter* v) {
    int i;
    for (i = 0; i < MAX_VOTERS; i++) {
        if (voters[i].voterID == -1) {
            voters[i].voterID = v->voterID;
            voters[i].choice = -1;
            return;
        }
    }
}

void vote(int voterID, int choice) {
    int i;
    for (i = 0; i < MAX_VOTERS; i++) {
        if (voters[i].voterID == voterID) {
            voters[i].choice = choice;
            return;
        }
    }
}

void countVotes() {
    int i, j;
    for (i = 0; i < MAX_CANDIDATES; i++) {
        candidates[i].votes = 0;
    }
    for (i = 0; i < MAX_VOTERS; i++) {
        if (voters[i].voterID!= -1 && voters[i].choice!= -1) {
            candidates[voters[i].choice].votes++;
        }
    }
}

void printResults() {
    int i;
    for (i = 0; i < MAX_CANDIDATES; i++) {
        if (candidates[i].votes > 0) {
            printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
        }
    }
}

int main() {
    srand(time(0));
    int numCandidates, numVoters;
    printf("Enter number of candidates: ");
    scanf("%d", &numCandidates);
    printf("Enter number of voters: ");
    scanf("%d", &numVoters);

    printf("Enter candidate names:\n");
    for (int i = 0; i < numCandidates; i++) {
        Candidate c;
        scanf("%s", c.name);
        addCandidate(&c);
    }

    printf("Enter voter IDs and choices:\n");
    for (int i = 0; i < numVoters; i++) {
        Voter v;
        scanf("%d %d", &v.voterID, &v.choice);
        addVoter(&v);
    }

    countVotes();
    printResults();

    return 0;
}