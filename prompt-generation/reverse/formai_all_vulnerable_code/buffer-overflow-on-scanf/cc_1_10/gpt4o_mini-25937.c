//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];
int candidateCount = 0;

void addCandidate() {
    if (candidateCount >= MAX_CANDIDATES) {
        printf("Cannot add more candidates. Maximum limit reached.\n");
        return;
    }
    
    printf("Enter candidate name: ");
    scanf(" %[^\n]", candidates[candidateCount].name);
    candidates[candidateCount].votes = 0; // Initialize votes to zero
    candidateCount++;
    printf("Candidate '%s' added successfully!\n", candidates[candidateCount - 1].name);
}

void displayCandidates() {
    printf("Candidates:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

void castVote() {
    int choice;
    printf("Enter the number of the candidate you wish to vote for: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > candidateCount) {
        printf("Invalid choice! Please try again.\n");
    } else {
        candidates[choice - 1].votes++;
        printf("Vote cast for %s!\n", candidates[choice - 1].name);
    }
}

void displayResults() {
    printf("\nVoting Results:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

void menu() {
    int choice;
    do {
        printf("\nElectronic Voting System\n");
        printf("1. Add Candidate\n");
        printf("2. Display Candidates\n");
        printf("3. Cast Vote\n");
        printf("4. Display Results\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCandidate();
                break;
            case 2:
                displayCandidates();
                break;
            case 3:
                castVote();
                break;
            case 4:
                displayResults();
                break;
            case 5:
                printf("Exiting the system. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 5);
}

int main() {
    printf("Welcome to the Electronic Voting System!\n");
    menu();
    return 0;
}