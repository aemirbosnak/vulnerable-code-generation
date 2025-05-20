//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];
int candidateCount = 0;

// Function prototypes
void addCandidate();
void castVote();
void displayResults();
void clearVotes();
void displayMenu();

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCandidate();
                break;
            case 2:
                castVote();
                break;
            case 3:
                displayResults();
                break;
            case 4:
                clearVotes();
                break;
            case 5:
                printf("Exiting the voting system. Thank you!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    printf("\n----- Electronic Voting System -----\n");
    printf("1. Add Candidate\n");
    printf("2. Cast Vote\n");
    printf("3. Display Results\n");
    printf("4. Clear Votes\n");
    printf("5. Exit\n");
}

void addCandidate() {
    if (candidateCount < MAX_CANDIDATES) {
        printf("Enter candidate name: ");
        scanf(" %[^\n]%*c", candidates[candidateCount].name); // Read string with spaces
        candidates[candidateCount].votes = 0; // Initialize votes
        candidateCount++;
        printf("Candidate '%s' added successfully.\n", candidates[candidateCount - 1].name);
    } else {
        printf("Maximum candidate limit reached.\n");
    }
}

void castVote() {
    if (candidateCount == 0) {
        printf("No candidates available to vote for.\n");
        return;
    }

    printf("Available candidates:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }

    int vote;
    printf("Enter candidate number to vote for: ");
    scanf("%d", &vote);

    if (vote > 0 && vote <= candidateCount) {
        candidates[vote - 1].votes++;
        printf("Vote cast for %s successfully.\n", candidates[vote - 1].name);
    } else {
        printf("Invalid candidate number.\n");
    }
}

void displayResults() {
    if (candidateCount == 0) {
        printf("No results available. Please add candidates first.\n");
        return;
    }

    printf("\n----- Voting Results -----\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

void clearVotes() {
    for (int i = 0; i < candidateCount; i++) {
        candidates[i].votes = 0;
    }
    printf("All votes have been cleared.\n");
}