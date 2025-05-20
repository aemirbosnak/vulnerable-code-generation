//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_NAME_LENGTH 50
#define MAX_VOTERS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    char name[MAX_NAME_LENGTH];
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int totalCandidates = 0;
int totalVoters = 0;

void addCandidate();
void castVote();
void displayResults();
void displayMenu();
int hasVoted(char *voterName);

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
                printf("Exiting the voting system. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);
    return 0;
}

void displayMenu() {
    printf("\n--- Electronic Voting System ---\n");
    printf("1. Add Candidate\n");
    printf("2. Cast Vote\n");
    printf("3. Display Results\n");
    printf("4. Exit\n");
    printf("--------------------------------\n");
}

void addCandidate() {
    if (totalCandidates < MAX_CANDIDATES) {
        printf("Enter candidate name: ");
        scanf("%s", candidates[totalCandidates].name);
        candidates[totalCandidates].votes = 0;
        totalCandidates++;
        printf("Candidate added successfully!\n");
    } else {
        printf("Maximum candidate limit reached.\n");
    }
}

void castVote() {
    char voterName[MAX_NAME_LENGTH];
    printf("Enter your name: ");
    scanf("%s", voterName);

    if (hasVoted(voterName)) {
        printf("You have already voted!\n");
        return;
    }

    int candidateIndex;
    printf("Select a candidate to vote for:\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
    printf("Your choice (1-%d): ", totalCandidates);
    scanf("%d", &candidateIndex);

    if (candidateIndex < 1 || candidateIndex > totalCandidates) {
        printf("Invalid candidate selection.\n");
        return;
    }

    candidates[candidateIndex - 1].votes++;
    strncpy(voters[totalVoters].name, voterName, MAX_NAME_LENGTH);
    totalVoters++;
    printf("Vote cast successfully for %s!\n", candidates[candidateIndex - 1].name);
}

int hasVoted(char *voterName) {
    for (int i = 0; i < totalVoters; i++) {
        if (strcmp(voters[i].name, voterName) == 0) {
            return 1; // Voter has voted
        }
    }
    return 0; // Voter has not voted
}

void displayResults() {
    printf("\n--- Voting Results ---\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
    printf("----------------------\n");
}