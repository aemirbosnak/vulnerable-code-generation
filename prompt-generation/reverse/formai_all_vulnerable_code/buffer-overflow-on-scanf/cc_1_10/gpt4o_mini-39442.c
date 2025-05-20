//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 10

typedef struct {
    int id;
    char name[50];
    int votes;
} Candidate;

typedef struct {
    int id;
    char name[50];
    int hasVoted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int candidateCount = 0, voterCount = 0;

void registerVoter() {
    if (voterCount >= MAX_VOTERS) {
        printf("Voter registration is full.\n");
        return;
    }
    Voter newVoter;
    newVoter.id = voterCount + 1;
    newVoter.hasVoted = 0;

    printf("Enter voter name: ");
    scanf("%s", newVoter.name);

    voters[voterCount++] = newVoter;
    printf("Voter registered successfully.\n");
}

void addCandidate() {
    if (candidateCount >= MAX_CANDIDATES) {
        printf("Candidate registration is full.\n");
        return;
    }
    Candidate newCandidate;
    newCandidate.id = candidateCount + 1;
    newCandidate.votes = 0;

    printf("Enter candidate name: ");
    scanf("%s", newCandidate.name);

    candidates[candidateCount++] = newCandidate;
    printf("Candidate added successfully.\n");
}

void castVote() {
    int voterId;
    printf("Enter your voter ID: ");
    scanf("%d", &voterId);

    if (voterId <= 0 || voterId > voterCount) {
        printf("Invalid voter ID.\n");
        return;
    }

    if (voters[voterId - 1].hasVoted) {
        printf("You have already voted.\n");
        return;
    }

    printf("Available candidates:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%d. %s\n", candidates[i].id, candidates[i].name);
    }

    int candidateId;
    printf("Enter the candidate ID you want to vote for: ");
    scanf("%d", &candidateId);

    if (candidateId <= 0 || candidateId > candidateCount) {
        printf("Invalid candidate ID.\n");
        return;
    }

    voters[voterId - 1].hasVoted = 1;
    candidates[candidateId - 1].votes++;
    printf("Vote casted successfully for %s.\n", candidates[candidateId - 1].name);
}

void viewResults() {
    printf("\nElection Results:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

void displayMenu() {
    printf("\n=== Electronic Voting System ===\n");
    printf("1. Register Voter\n");
    printf("2. Add Candidate\n");
    printf("3. Cast Vote\n");
    printf("4. View Results\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                registerVoter();
                break;
            case 2:
                addCandidate();
                break;
            case 3:
                castVote();
                break;
            case 4:
                viewResults();
                break;
            case 5:
                printf("Exiting the voting system.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}