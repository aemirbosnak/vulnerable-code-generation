//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 10

typedef struct {
    char name[50];
    int votes;
} Candidate;

typedef struct {
    char voterId[10];
    int voted; // 0 means not voted, 1 means voted
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int candidateCount = 0;
int voterCount = 0;

void printCandidates() {
    printf("\nCandidates:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%d: %s, Votes: %d\n", i + 1, candidates[i].name, candidates[i].votes);
    }
}

void addCandidate() {
    if (candidateCount < MAX_CANDIDATES) {
        printf("Enter candidate name: ");
        scanf("%s", candidates[candidateCount].name);
        candidates[candidateCount].votes = 0;
        candidateCount++;
        printf("Candidate %s added successfully!\n", candidates[candidateCount - 1].name);
    } else {
        printf("Maximum candidates reached!\n");
    }
}

void addVoter() {
    if (voterCount < MAX_VOTERS) {
        printf("Enter voter ID: ");
        scanf("%s", voters[voterCount].voterId);
        voters[voterCount].voted = 0;
        voterCount++;
        printf("Voter %s added successfully!\n", voters[voterCount - 1].voterId);
    } else {
        printf("Maximum voters reached!\n");
    }
}

void castVote() {
    char voterId[10];
    printf("Enter voter ID: ");
    scanf("%s", voterId);

    for (int i = 0; i < voterCount; i++) {
        if (strcmp(voters[i].voterId, voterId) == 0 && voters[i].voted == 0) {
            printCandidates();
            int choice;
            printf("Choose a candidate (1 - %d): ", candidateCount);
            scanf("%d", &choice);
            if (choice >= 1 && choice <= candidateCount) {
                candidates[choice - 1].votes++;
                voters[i].voted = 1;
                printf("Vote for %s recorded successfully!\n", candidates[choice - 1].name);
            } else {
                printf("Invalid choice!\n");
            }
            return;
        }
    }
    printf("Voter ID not found or already voted!\n");
}

void displayResults() {
    printf("\nElection Results:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

void menu() {
    int choice;
    do {
        printf("\nElectronic Voting System\n");
        printf("1. Add Candidate\n");
        printf("2. Add Voter\n");
        printf("3. Cast Vote\n");
        printf("4. Display Results\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCandidate();
                break;
            case 2:
                addVoter();
                break;
            case 3:
                castVote();
                break;
            case 4:
                displayResults();
                break;
            case 5:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    printf("Welcome to the Electronic Voting System!\n");
    menu();
    return 0;
}