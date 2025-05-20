//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

void displayCandidates(Candidate candidates[], int numCandidates) {
    printf("\n=== Candidates List ===\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
    printf("=======================\n");
}

void vote(Candidate candidates[], int numCandidates) {
    int choice;

    printf("\nPlease enter the number of the candidate you want to vote for (1-%d): ", numCandidates);
    scanf("%d", &choice);
    
    if (choice >= 1 && choice <= numCandidates) {
        candidates[choice - 1].votes++;
        printf("Thank you for voting! Your vote has been counted for %s.\n", candidates[choice - 1].name);
    } else {
        printf("Invalid choice! Vote not counted.\n");
    }
}

void displayResults(Candidate candidates[], int numCandidates) {
    printf("\n=== Election Results ===\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d vote(s)\n", candidates[i].name, candidates[i].votes);
    }
    printf("========================\n");
}

int main() {
    Candidate candidates[MAX_CANDIDATES] = {
        {"Alice", 0},
        {"Bob", 0},
        {"Charlie", 0},
        {"Diana", 0},
        {"Eddie", 0}
    };
    
    int numCandidates = 5;
    int continueVoting = 1;

    printf("Welcome to the Electronic Voting System!\n");

    while (continueVoting) {
        displayCandidates(candidates, numCandidates);
        vote(candidates, numCandidates);

        printf("Would you like to cast another vote? (1 for Yes, 0 for No): ");
        scanf("%d", &continueVoting);
    }

    displayResults(candidates, numCandidates);

    // Find the winner
    int maxVotes = 0;
    char winner[MAX_NAME_LENGTH];
    for (int i = 0; i < numCandidates; i++) {
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            strcpy(winner, candidates[i].name);
        }
    }
    
    printf("\nCongratulations to %s for winning the election with %d votes!\n", winner, maxVotes);
    printf("Thank you for participating in the voting process!\n");

    return 0;
}