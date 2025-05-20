//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

void displayCandidates(Candidate candidates[], int totalCandidates) {
    printf("\nAvailable Candidates:\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
    printf("\n");
}

void castVote(Candidate candidates[], int totalCandidates) {
    int choice;
    printf("Please enter the number corresponding to your candidate of choice: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= totalCandidates) {
        candidates[choice - 1].votes++;
        printf("Thank you for voting for %s! Your vote has been counted.\n", candidates[choice - 1].name);
    } else {
        printf("Oops! That's not a valid choice. Please try again.\n");
    }
}

void displayResults(Candidate candidates[], int totalCandidates) {
    printf("\n---- Voting Results ----\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("%s: %d vote(s)\n", candidates[i].name, candidates[i].votes);
    }
    printf("------------------------\n");
}

int main() {
    Candidate candidates[MAX_CANDIDATES] = {
        {"Alice", 0},
        {"Bob", 0},
        {"Charlie", 0},
        {"Diana", 0},
        {"Ethan", 0}
    };
    
    int totalCandidates = 5;
    char continueVoting = 'y';
    
    printf("🌟 Welcome to the Electronic Voting System! 🌟\n");
    
    while (continueVoting == 'y') {
        displayCandidates(candidates, totalCandidates);
        castVote(candidates, totalCandidates);

        printf("Would you like to cast another vote? (y/n): ");
        scanf(" %c", &continueVoting);
    }
    
    displayResults(candidates, totalCandidates);
    
    printf("Thank you for participating in the voting process! 🎉\n");
    
    return 0;
}