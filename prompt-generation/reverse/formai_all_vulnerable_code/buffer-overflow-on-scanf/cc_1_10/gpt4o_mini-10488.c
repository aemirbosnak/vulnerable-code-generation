//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

void displayCandidates(Candidate candidates[], int numCandidates) {
    printf("\nAvailable Candidates:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

int castVote(Candidate candidates[], int numCandidates) {
    int vote;
    printf("\nEnter the number of the candidate you want to vote for (1-%d): ", numCandidates);
    if (scanf("%d", &vote) != 1 || vote < 1 || vote > numCandidates) {
        printf("Invalid input. Please enter a valid candidate number.\n");
        return -1;
    }
    candidates[vote - 1].votes++;
    printf("Thank you for voting for %s!\n", candidates[vote - 1].name);
    return 0;
}

void displayResults(Candidate candidates[], int numCandidates) {
    printf("\nVoting Results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    Candidate candidates[MAX_CANDIDATES];
    int numCandidates = 0;
    char choice[10];

    printf("Welcome to the Electronic Voting System!\n");

    // Input candidates
    printf("Enter the number of candidates: ");
    scanf("%d", &numCandidates);
    if (numCandidates <= 0 || numCandidates > MAX_CANDIDATES) {
        printf("Invalid number of candidates. Exiting.\n");
        return 1;
    }
    for (int i = 0; i < numCandidates; i++) {
        printf("Enter name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    // Voting process
    do {
        displayCandidates(candidates, numCandidates);
        if (castVote(candidates, numCandidates) == -1) {
            continue;
        }
        printf("Do you want to cast another vote? (yes/no): ");
        scanf("%s", choice);
    } while (strcmp(choice, "yes") == 0);

    // Display results
    displayResults(candidates, numCandidates);

    return 0;
}