//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

void initializeCandidates(Candidate candidates[], int *numCandidates) {
    strcpy(candidates[0].name, "Alice");
    candidates[0].votes = 0;
    
    strcpy(candidates[1].name, "Bob");
    candidates[1].votes = 0;

    strcpy(candidates[2].name, "Charlie");
    candidates[2].votes = 0;

    *numCandidates = 3;
}

void castVote(Candidate candidates[], int numCandidates) {
    int choice;

    printf("Vote for your candidate:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }

    printf("Enter the candidate number (1-%d): ", numCandidates);
    scanf("%d", &choice);

    if (choice < 1 || choice > numCandidates) {
        printf("Invalid choice. Vote not counted.\n");
    } else {
        candidates[choice - 1].votes++;
        printf("Thank you for voting for %s!\n", candidates[choice - 1].name);
    }
}

void displayResults(Candidate candidates[], int numCandidates) {
    printf("\nElection Results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    Candidate candidates[MAX_CANDIDATES];
    int numCandidates = 0;

    initializeCandidates(candidates, &numCandidates);

    int moreVotes = 1;

    while (moreVotes) {
        castVote(candidates, numCandidates);
        printf("Would you like to cast another vote? (1-Yes, 0-No): ");
        scanf("%d", &moreVotes);
    }

    displayResults(candidates, numCandidates);
    return 0;
}