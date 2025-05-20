//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_NAME_LENGTH 50
#define MAX_VOTERS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int hasVoted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int candidateCount = 0;
int voterCount = 0;

void registerCandidate() {
    if (candidateCount >= MAX_CANDIDATES) {
        printf("Cannot register more candidates.\n");
        return;
    }
    
    printf("Enter the name of the candidate: ");
    scanf("%s", candidates[candidateCount].name);
    candidates[candidateCount].votes = 0;
    candidateCount++;
}

void registerVoter() {
    if (voterCount >= MAX_VOTERS) {
        printf("Cannot register more voters.\n");
        return;
    }

    printf("Enter your name: ");
    scanf("%s", voters[voterCount].name);
    voters[voterCount].hasVoted = 0;
    voterCount++;
}

void castVote() {
    char voterName[MAX_NAME_LENGTH];
    printf("Enter your name to vote: ");
    scanf("%s", voterName);

    // Check if the voter is registered
    int voterIndex = -1;
    for (int i = 0; i < voterCount; i++) {
        if (strcmp(voters[i].name, voterName) == 0) {
            voterIndex = i;
            break;
        }
    }

    if (voterIndex == -1) {
        printf("Voter not registered!\n");
        return;
    }

    if (voters[voterIndex].hasVoted) {
        printf("You have already voted!\n");
        return;
    }

    printf("Available candidates:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%d: %s\n", i + 1, candidates[i].name);
    }

    int candidateChoice;
    printf("Enter the candidate number to vote for: ");
    scanf("%d", &candidateChoice);

    if (candidateChoice < 1 || candidateChoice > candidateCount) {
        printf("Invalid candidate choice!\n");
        return;
    }

    // Cast the vote
    candidates[candidateChoice - 1].votes++;
    voters[voterIndex].hasVoted = 1;
    printf("Vote successfully cast for %s!\n", candidates[candidateChoice - 1].name);
}

void displayResults() {
    printf("Voting Results:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

void displayMenu() {
    printf("Electronic Voting System\n");
    printf("1. Register Candidate\n");
    printf("2. Register Voter\n");
    printf("3. Cast Vote\n");
    printf("4. Display Results\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                registerCandidate();
                break;
            case 2:
                registerVoter();
                break;
            case 3:
                castVote();
                break;
            case 4:
                displayResults();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}