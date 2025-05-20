//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} Candidate;

typedef struct {
    char voterID[10];
    int voted; // 0 for not voted, 1 for voted
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int candidateCount = 0;
int voterCount = 0;

void initializeCandidates() {
    printf("Enter number of candidates: ");
    scanf("%d", &candidateCount);
    for (int i = 0; i < candidateCount; i++) {
        printf("Enter candidate %d name: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
}

void initializeVoters() {
    printf("Enter number of voters: ");
    scanf("%d", &voterCount);
    for (int i = 0; i < voterCount; i++) {
        printf("Enter voter %d ID: ", i + 1);
        scanf("%s", voters[i].voterID);
        voters[i].voted = 0;
    }
}

int findVoter(char *voterID) {
    for (int i = 0; i < voterCount; i++) {
        if (strcmp(voters[i].voterID, voterID) == 0) {
            return i;
        }
    }
    return -1; // Not found
}

void castVote() {
    char voterID[10];
    printf("Enter your voter ID: ");
    scanf("%s", voterID);
    
    int voterIndex = findVoter(voterID);
    
    if (voterIndex == -1) {
        printf("Voter ID not found.\n");
        return;
    }
    
    if (voters[voterIndex].voted) {
        printf("You have already voted.\n");
        return;
    }

    int vote;
    printf("Vote for candidate (1-%d): ", candidateCount);
    scanf("%d", &vote);

    if (vote < 1 || vote > candidateCount) {
        printf("Invalid vote.\n");
        return;
    }
    
    candidates[vote - 1].votes++;
    voters[voterIndex].voted = 1;
    printf("Vote cast successfully!\n");
}

void displayResults() {
    printf("\nElection Results:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int choice;

    initializeCandidates();
    initializeVoters();

    do {
        printf("\nMenu:\n");
        printf("1. Cast Vote\n");
        printf("2. Display Results\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                castVote();
                break;
            case 2:
                displayResults();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}