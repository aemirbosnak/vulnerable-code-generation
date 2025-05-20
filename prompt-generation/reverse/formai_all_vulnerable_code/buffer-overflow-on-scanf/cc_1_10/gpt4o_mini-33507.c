//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: minimalist
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

void registerCandidate() {
    if (candidateCount >= MAX_CANDIDATES) {
        printf("Maximum candidates reached.\n");
        return;
    }
    printf("Enter candidate name: ");
    scanf(" %[^\n]", candidates[candidateCount].name);
    candidates[candidateCount].votes = 0;
    candidateCount++;
    printf("Candidate '%s' registered successfully.\n", candidates[candidateCount - 1].name);
}

void castVote() {
    int choice;
    printf("Vote for candidates (0 to %d):\n", candidateCount - 1);
    for (int i = 0; i < candidateCount; i++) {
        printf("%d. %s\n", i, candidates[i].name);
    }
    printf("Enter your vote: ");
    scanf("%d", &choice);
    if (choice >= 0 && choice < candidateCount) {
        candidates[choice].votes++;
        printf("Thank you for voting for '%s'.\n", candidates[choice].name);
    } else {
        printf("Invalid choice, voting failed.\n");
    }
}

void displayResults() {
    printf("Voting Results:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int option;
    do {
        printf("\nElectronic Voting System\n");
        printf("1. Register Candidate\n");
        printf("2. Cast Vote\n");
        printf("3. Display Results\n");
        printf("0. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                registerCandidate();
                break;
            case 2:
                if (candidateCount == 0) {
                    printf("No candidates available for voting.\n");
                } else {
                    castVote();
                }
                break;
            case 3:
                if (candidateCount == 0) {
                    printf("No results to display. No candidates registered.\n");
                } else {
                    displayResults();
                }
                break;
            case 0:
                printf("Exiting the system...\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    } while (option != 0);

    return 0;
}