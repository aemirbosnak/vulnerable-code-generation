//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} candidate;

typedef struct {
    int voterID;
    int choice;
} vote;

candidate candidates[MAX_CANDIDATES];
vote votes[MAX_VOTERS];
int numCandidates, numVoters;

void readCandidates() {
    FILE *fptr;
    fptr = fopen("candidates.txt", "r");
    if (fptr == NULL) {
        printf("Error: Unable to open candidates file.\n");
        exit(1);
    }

    fscanf(fptr, "%d", &numCandidates);
    for (int i = 0; i < numCandidates; i++) {
        fscanf(fptr, "%s", candidates[i].name);
    }

    fclose(fptr);
}

void readVotes() {
    FILE *fptr;
    fptr = fopen("votes.txt", "r");
    if (fptr == NULL) {
        printf("Error: Unable to open votes file.\n");
        exit(1);
    }

    fscanf(fptr, "%d", &numVoters);
    for (int i = 0; i < numVoters; i++) {
        fscanf(fptr, "%d %d", &votes[i].voterID, &votes[i].choice);
    }

    fclose(fptr);
}

void countVotes() {
    for (int i = 0; i < numVoters; i++) {
        for (int j = 0; j < numCandidates; j++) {
            if (votes[i].choice == j + 1) {
                candidates[j].votes++;
            }
        }
    }
}

void printResults() {
    printf("\nElection Results:\n");
    printf("-----------------\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    srand(time(NULL));

    readCandidates();
    readVotes();
    countVotes();
    printResults();

    return 0;
}