//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} Candidate;

typedef struct {
    int id;
    int hasVoted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int candidateCount = 0;
int voterCount = 0;

void registerCandidate() {
    if (candidateCount >= MAX_CANDIDATES) {
        printf("Candidate limit reached! Can't register more candidates.\n");
        return;
    }
    
    Candidate newCandidate;
    printf("Enter candidate name: ");
    scanf("%s", newCandidate.name);
    newCandidate.votes = 0;

    candidates[candidateCount++] = newCandidate;
    printf("Candidate %s registered successfully!\n", newCandidate.name);
}

void castVote() {
    if (voterCount >= MAX_VOTERS) {
        printf("Voter limit reached! Can't register more voters.\n");
        return;
    }

    int voterId;
    printf("Enter Voter ID (0-%d): ", MAX_VOTERS - 1);
    scanf("%d", &voterId);
    
    if (voterId < 0 || voterId >= MAX_VOTERS) {
        printf("Invalid Voter ID. Please try again.\n");
        return;
    }

    if (voters[voterId].hasVoted) {
        printf("Voter ID %d has already voted.\n", voterId);
        return;
    }

    printf("Available candidates:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }

    int candidateChoice;
    printf("Choose a candidate (1-%d): ", candidateCount);
    scanf("%d", &candidateChoice);

    if (candidateChoice < 1 || candidateChoice > candidateCount) {
        printf("Invalid choice. Please try again.\n");
        return;
    }

    candidates[candidateChoice - 1].votes++;
    voters[voterId].hasVoted = 1;
    printf("Vote casted successfully for %s!\n", candidates[candidateChoice - 1].name);
}

void displayResults() {
    printf("\nVoting Results:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

void displayMenu() {
    int choice;
    do {
        printf("\n--- Electronic Voting System ---\n");
        printf("1. Register Candidate\n");
        printf("2. Cast Vote\n");
        printf("3. Display Results\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerCandidate();
                break;
            case 2:
                castVote();
                break;
            case 3:
                displayResults();
                break;
            case 4:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}

int main() {
    printf("Welcome to the Electronic Voting System!\n");
    displayMenu();
    return 0;
}