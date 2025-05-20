//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: Donald Knuth
/* Electronic Voting System, a la Donald Knuth */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[256];
    int votes;
} Candidate;

Candidate candidates[100];
int numCandidates;

void readCandidates() {
    FILE *fp;
    int i;

    fp = fopen("candidates.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening candidates file\n");
        exit(1);
    }
    fscanf(fp, "%d\n", &numCandidates);
    for (i = 0; i < numCandidates; i++) {
        fscanf(fp, "%s %d\n", candidates[i].name, &candidates[i].votes);
    }
    fclose(fp);
}

void readVotes() {
    FILE *fp;
    int i, numVotes, vote;

    fp = fopen("votes.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening votes file\n");
        exit(1);
    }
    fscanf(fp, "%d\n", &numVotes);
    for (i = 0; i < numVotes; i++) {
        fscanf(fp, "%d\n", &vote);
        candidates[vote].votes++;
    }
    fclose(fp);
}

void printResults() {
    int i, winner, maxVotes = 0;

    for (i = 0; i < numCandidates; i++) {
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            winner = i;
        }
    }
    printf("Winner: %s\n", candidates[winner].name);
}

int main() {
    readCandidates();
    readVotes();
    printResults();
    return 0;
}