//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    char voterID[NAME_LENGTH];
    int votedCandidateIndex;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int candidateCount = 0;
int voterCount = 0;

void addCandidate() {
    if (candidateCount < MAX_CANDIDATES) {
        printf("Enter the name of the candidate: ");
        scanf(" %[^\n]", candidates[candidateCount].name);
        candidates[candidateCount].votes = 0; // Initialize votes to 0
        candidateCount++;
        printf("Candidate %s added!\n", candidates[candidateCount - 1].name);
    } else {
        printf("Maximum candidates reached. Cannot add more.\n");
    }
}

void displayCandidates() {
    printf("Candidates List:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

void castVote() {
    if (voterCount >= MAX_VOTERS) {
        printf("Voting limit reached. Cannot accept more voters.\n");
        return;
    }

    char voterID[NAME_LENGTH];
    printf("Enter your voter ID: ");
    scanf(" %[^\n]", voterID);

    // Check if the voter has already voted
    for (int i = 0; i < voterCount; i++) {
        if (strcmp(voters[i].voterID, voterID) == 0) {
            printf("You have already voted!\n");
            return;
        }
    }

    displayCandidates();
    int choice;
    printf("Select candidate number to vote: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > candidateCount) {
        printf("Invalid candidate number.\n");
        return;
    }

    // Register the vote
    candidates[choice - 1].votes++;
    strcpy(voters[voterCount].voterID, voterID);
    voters[voterCount].votedCandidateIndex = choice - 1;
    voterCount++;

    printf("Vote cast successfully for %s!\n", candidates[choice - 1].name);
}

void displayResults() {
    printf("\nElection Results:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int choice;
    do {
        printf("\n** Electronic Voting System **\n");
        printf("1. Add Candidate\n");
        printf("2. Cast Vote\n");
        printf("3. Display Results\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
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
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}