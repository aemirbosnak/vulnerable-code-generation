//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct {
    char name[100];
    int votes;
} candidate;

void addCandidate(candidate* candidates, int numCandidates, char* name) {
    int i;
    for (i = 0; i < numCandidates; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            candidates[i].votes++;
            return;
        }
    }
    strcpy(candidates[numCandidates].name, name);
    candidates[numCandidates].votes = 1;
    numCandidates++;
}

void printCandidateList(candidate* candidates, int numCandidates) {
    int i;
    for (i = 0; i < numCandidates; i++) {
        printf("%s - %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

void printWinner(candidate* candidates, int numCandidates) {
    int i, maxVotes = 0;
    for (i = 0; i < numCandidates; i++) {
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
        }
    }
    printf("The winner is: %s with %d votes\n", candidates[0].name, maxVotes);
}

int main() {
    int numCandidates = 0;
    candidate candidates[100];
    char choice;
    do {
        printf("Enter a candidate's name (or 'q' to quit): ");
        scanf("%s", candidates[numCandidates].name);
        if (tolower(candidates[numCandidates].name[0])!= 'q') {
            addCandidate(candidates, numCandidates, candidates[numCandidates].name);
            numCandidates++;
        }
    } while (tolower(candidates[numCandidates-1].name[0])!= 'q');
    srand(time(NULL));
    int numVotes = rand() % 1000 + 1;
    int i;
    for (i = 0; i < numVotes; i++) {
        int index = rand() % numCandidates;
        candidates[index].votes++;
    }
    printf("\nCandidate List:\n");
    printCandidateList(candidates, numCandidates);
    printf("\nVoting complete!\n");
    sleep(2);
    printf("\nThe winner is: %s with %d votes\n", candidates[0].name, candidates[0].votes);
    return 0;
}