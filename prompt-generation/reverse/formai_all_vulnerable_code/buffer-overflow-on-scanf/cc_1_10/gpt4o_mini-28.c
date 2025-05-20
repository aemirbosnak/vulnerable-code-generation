//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: thoughtful
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
    char voterID[20];
    int votedFor; // Index of the candidate voted for
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];

int candidateCount = 0;
int voterCount = 0;

void initializeCandidates() {
    printf("Enter the number of candidates (max %d): ", MAX_CANDIDATES);
    scanf("%d", &candidateCount);
    if (candidateCount > MAX_CANDIDATES) {
        candidateCount = MAX_CANDIDATES;
    }
    for (int i = 0; i < candidateCount; i++) {
        printf("Enter name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
}

void castVote() {
    if (voterCount >= MAX_VOTERS) {
        printf("Voting limit reached. Cannot accept more votes.\n");
        return;
    }
    
    char voterID[20];
    printf("Enter your voter ID: ");
    scanf("%s", voterID);

    // Check if voter has already voted
    for (int i = 0; i < voterCount; i++) {
        if (strcmp(voters[i].voterID, voterID) == 0) {
            printf("You have already voted!\n");
            return;
        }
    }

    printf("Candidates available:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }

    int vote;
    printf("Vote for candidate number (1 to %d): ", candidateCount);
    scanf("%d", &vote);
    
    if (vote < 1 || vote > candidateCount) {
        printf("Invalid choice.\n");
        return;
    }

    // Store the vote
    strcpy(voters[voterCount].voterID, voterID);
    voters[voterCount].votedFor = vote - 1;
    candidates[vote - 1].votes++;
    voterCount++;

    printf("Vote cast successfully for %s!\n", candidates[vote - 1].name);
}

void displayResults() {
    printf("\n--- Election Results ---\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

void mainMenu() {
    int choice;
    do {
        printf("\n--- E-Voting System ---\n");
        printf("1. Initialize Candidates\n");
        printf("2. Cast a Vote\n");
        printf("3. Display Results\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                initializeCandidates();
                break;
            case 2:
                castVote();
                break;
            case 3:
                displayResults();
                break;
            case 4:
                printf("Exiting the system. Thank you for participating!\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
    } while (choice != 4);
}

int main() {
    mainMenu();
    return 0;
}